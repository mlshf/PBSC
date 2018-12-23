#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <atomic>

//Вынужден интерпретировать текст задания, поскольку не хватает информации о том,
//как в данном примере должна работать пара продьюсер-консьюмер.

//Предполагаю, что заполнение и чтение очереди происходит "параллельно",
//то есть консьюмер может доставать элементы из очереди ещё до того, как 
//завершится цикл в продьюсере.

//Консьюмер считывает данные из очереди поэлементно, то есть в то время, как 
//консьюмер читает данные (в цикле), продьюсер может их добавлять в очередь, но 
//операции чтения и записи не могут выполняться одновременно. 

//Альтернативно, можно было бы блокировать продьюсеру доступ к items и count до тех пор,
//пока консьюмер не считает всё, что накопилось в очереди.

//Консьюмер считывает все данные с того момента, как он начал читать, и до тех пор,
//пока очередь не опустеет. Даже если done станет равно true, если консьюмер начал читать данные из
//очереди, он остановится только после её опустошения.

//Если хотелось, чтобы консьюмер читал только тогда, когда очередь непуста И done != true,
//то вместо while + while должен стоять один while c условиями проверки done И пустоты очереди.

//done  = true находится за пределами цикла в продьюсере, соответственно, даже если продьюсер завершил цикл, 
//консьюмер может успеть начать чтение из очереди и дочитает всё до конца.

//в файле main_alt.cpp я описал код, изменённый так, чтобы продьюсер и консьюмер работали параллельно, но 
//продьюсер ставил бы флаг done сразу после записи последнего элемента, а консьюмер читал очередь поэлементно
//и не мог бы читать тогда, когда done == true.

int main() {
	std::atomic<size_t> count = 0;
	std::atomic<bool> done = false;
	bool isDone = true;
	std::queue<int> items;
	std::mutex mutex, doneMutex;	
	std::thread producer([&]() {
		for (int i = 0; i < 10000; ++i) {
			// ... some code may be here ...
			mutex.lock();//lock to push and increase count simultaneosly
			items.push(i);
			count++;
			mutex.unlock();
			//mutex released
		}
		done = true;
	});

	std::thread consumer([&]() {
		while ( !done.compare_exchange_weak(isDone, isDone) ) {
			isDone = true;//because when false expected is replaced with actual value
			while (!items.empty()) {	
				mutex.lock();//lock to pop and decrease count simultaneously
				items.pop();
				// ...
				count--;
				mutex.unlock();
				//mutex released
			}
		}
	});
	
	producer.join();
	consumer.join();
	std::cout << count << std::endl;
}
