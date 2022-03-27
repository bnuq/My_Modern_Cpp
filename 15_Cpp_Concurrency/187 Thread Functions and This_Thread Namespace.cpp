#include <iostream>
#include <thread>

//Window 운영체제 에서만 사용 가능한, Window api 헤더파일
#include <Windows.h>


void Process() {
	
	/*
		std::this_thread namespace

		현재 동작중인 스레드에 대한 정보를 알려준다
	*/
	
	/*
		std::this_thread::get_id()

		현재 코드가 속한 스레드의 id 를 리턴
	*/
	std::cout << "Thread id:" << std::this_thread::get_id() << std::endl;


	for (int i = 0; i < 5; ++i) {
		
		/*
			std::this_thread::sleep_for()

			초 단위로 실행을 지연시킬 수 있다

			std::chrono::seconds(1) => 1초를 의미
		*/		
		std::this_thread::sleep_for(std::chrono::seconds(1));

		std::cout << i << ' ';
	}
}



//Main Thread
int main() {

	//Joinable Thread 를 만들고
	std::thread t1{ Process };

	
	
	/*
		thread::native_handle()

		returns a type that represents the thread on the corresponding platform
		현재 프로그램이 실행중인 플랫폼에서, thread 를 다루는 타입을 리턴한다
		return native handle type

		On Window => HANDLE
		On Linux, the native type is pthread_t
	*/
	HANDLE handle = t1.native_handle();
	

	/*
		SetThreadDescription => thread 에 이름을 붙이는, window api function
		window handle type 을 가지고 있기 때문에, window api 를 사용할 수 있다
		붙여진 이름은 Debug => thread 창에서 확인할 수 있다
	*/
	SetThreadDescription(handle, L"MyThread"); //Wide String, 8bits 보다 큰 문자
	

	/*
		thread::get_id()
		스레드의 고유 id 를 리턴한다
		return thread::id class => 출력 가능
	*/
	auto id = t1.get_id();
	std::cout << "t1.get_id()" << id << std::endl; 


	/*
		thread::hardware_concurrency()

		returns the number of cores that are present in the CPU

		스레드가 최고의 성능을 내기 위해서는, CPU 의 코어 수와 같은 개수까지만 존재해야 한다
	*/
	int cores = std::thread::hardware_concurrency();
	std::cout << "Cores:" << cores << std::endl;


	t1.join();
	return 0;
}