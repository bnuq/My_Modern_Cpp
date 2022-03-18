#include <iostream>
#include <list>
#include <thread>
#include <string>
#include <mutex>

std::list<int> g_Data;
const int SIZE = 10000;

std::mutex g_Mutex;
/*
	g_Mutex.lock(), .unlock() 으로 서로 다른 스레드에서 동일 자원에 동시에 접근하는 것을 막을 수 있다
	하지만 lock 후 exception 등에 의해 스레드가 갑자기 종료하는 경우, unlock 되지 않아 다른 스레드에서 접근하지 못할 때가 있다 == deadlock
	그래서 mutex 를 직접 다루지 않는다
*/


void Download() {
	for (int i = 0; i < SIZE; ++i) {

		// g_Mutex.lock();

		// Use std::lock_guard to lock a mutex (RAII)
		/*
			lock_guard => mutex 를 내부에 가지는 객체
			이 객체가 생성될 때, 자동으로 lock 하고
			이 객체가 파괴될 때, 자동으로 unlock 되게 만들어
			예상치 못하게 종료하더라도, mutex.unlock() 이 반드시 일어나도록 한다
		*/
		std::lock_guard<std::mutex> mtx(g_Mutex);
		g_Data.push_back(i);
		if (i == 500)
			return;

		// g_Mutex.unlock();
	}
}
void Download2() {
	for (int i = 0; i < SIZE; ++i) {
		std::lock_guard<std::mutex> mtx(g_Mutex);
		g_Data.push_back(i);
	}
}


int main() {
	std::thread thDownloader(Download);
	std::thread thDownloader2(Download2);
	thDownloader.join();
	thDownloader2.join();
	std::cout << g_Data.size() << std::endl; 
	return 0;
}