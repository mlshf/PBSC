#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <atomic>

int main() {
	std::atomic<size_t> count = 0;
	std::atomic<bool> done = false;
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
		while ( !done.load() ) {//will attempt to read until knows that done == true	
			while ( !items.empty() && !done.load() ) {//will read while items is not empty AND done is not true
				if( mutex.try_lock() ) {
					//Lock to pop and decrease count simultaneously.
					//Using try_lock to avoid getting in the cycle just before
					//	done is true, stopping and popping an item after mutex is unlocked in producer,
					//	when it shoudln't happen.
					//If LOCK would be used, then consumer would stop and wait, reading
					//	an element it shoudln't after mutex is unlocked in producer.
					items.pop();
					// ...
					count--;
					//mutex released
					mutex.unlock();
				}
			}
		}
	});
	
	producer.join();
	consumer.join();
	std::cout << count << std::endl;
}
