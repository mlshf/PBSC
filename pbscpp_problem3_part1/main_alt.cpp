#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <atomic>

int main() {
	std::atomic<size_t> count = 0;
	std::atomic<bool> done = false;
	bool isDone = true;
	std::queue<int> items;
	std::mutex mutex;
		
	std::thread producer([&]() {
		for (int i = 0; i < 10000; ++i) {
			// ... some code may be here ...
			mutex.lock();//lock to push and increase count simultaneosly
			items.push(i);
			count++;
			if( i == 9999 ) {
				done = true;
			}
			mutex.unlock();
			//mutex released
		}
	});

	std::thread consumer([&]() {
		while ( !done.compare_exchange_weak(isDone, true) && !items.empty() ) {	
			isDone = true;//because if false isDone is replaced with done, which is false
			if( mutex.try_lock() ) {
				//lock to pop and decrease count simultaneously
				//using try_lock to avoid getting in the cycle just before
				//done is true, stopping and popping an item
				//when it shoudln't happen
				items.pop();
				// ...
				count--;
				//mutex released
				mutex.unlock();
			}
		}
	});
	
	producer.join();
	consumer.join();
	std::cout << count << std::endl;
}
