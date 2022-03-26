#include <iostream>
#include <list>
#include <thread>
#include <string>

//mutex 사용 헤더파일 => Thread Synchronization
#include <mutex>


std::list<int> g_Data{}; //공유자원
const int SIZE = 10000;


/*
	Mutex => Thread Synchronization 을 위해서 사용

	mutex::lock()
	mutex::unlock() 메서드를 이용해서

	서로 다른 스레드에서 동일 자원에 동시에 접근하는 것을 막을 수 있다

	하지만 한 스레드에서 lock 한 후, exception 등에 의해 스레드가 갑자기 종료되어 버린다면
	mutex 가 unlock 되지 않아 다른 스레드에서 계속 접근하지 못하는 경우가 발생한다 == deadlock
	
	그래서 mutex 에서 lock, unlock 을 직접 다루지 않는다
*/
std::mutex g_Mutex{};



//공유자원에 접근하는 스레드 2개가 존재한다
void Download() {
	for (int i = 0; i < SIZE; ++i) { //501 개 입력

		// g_Mutex.lock();  직접 mutex::lock() 호출
		//그런데 lock 한 이후에, 함수 실행 도중 exception 이 발생한다면
		//함수는 그대로 정리 => mutex 는 unlock 되지 않게 된다 => deadlock
		

		/*
			따라서 RAII 개념을 mutex 에 적용한다
			객체로 mutex 를 관리, lock, unlock 이
			객체의 생성, 소멸과 함께 자연스럽게 이루어지도록 한다
			
			Use std::lock_guard to lock a mutex (RAII)
			
			lock_guard => mutex 를 내부에 가지는 객체

			이 객체가 생성될 때, 자동으로 lock 하고
			이 객체가 파괴될 때, 자동으로 unlock 되게 만들어
			예상치 못하게 종료하더라도, mutex.unlock() 이 반드시 일어나도록 한다
		*/
		//mutex type 을 가지는 lock_guard
		std::lock_guard<std::mutex> mtx{ g_Mutex };

		//공유자원 접근
		g_Data.push_back(i);
		if (i == 500)
			return;

		// g_Mutex.unlock();  공유자원 사용 후, 직접 mutex::unlock() 호출
		//lock_guard 가 소멸되면서, 자동으로 mutex::unlock() 이 발생한다 => 안전
	}
}
void Download2() {

	for (int i = 0; i < SIZE; ++i) { //10000 개 입력

		//lock_guard 이용 => mutex 를 자연스럽게 이용한다
		std::lock_guard<std::mutex> mtx{ g_Mutex };
		
		g_Data.push_back(i);
	}
}


int main() {

	//joinable thread 2개를 정의
	std::thread thDownloader(Download);
	std::thread thDownloader2(Download2);

	//두 스레드 모두 완전히 종료되는 것을 기다린다
	thDownloader.join();
	thDownloader2.join();

	//공유자원 확인
	std::cout << g_Data.size() << std::endl; 

	return 0;
}