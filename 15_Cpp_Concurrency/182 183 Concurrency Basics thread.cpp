#include <iostream>
#include <list>

// thread 사용에 필요한 헤더파일
#include <thread>

//std::list<int> gData{};

//다운로드 개수, 사이즈
const int SIZE = 500000;



//Funcion Object => 다운로드를 진행
struct downObj {
	std::list<int> data{};

	void operator()() {
		std::cout << "Donwload operator Start" << std::endl;

		for (int i = 0; i < SIZE; i++)
			data.push_back(i);

		std::cout << "Donwload operator Finish" << std::endl;
	}
};


//다운로드를 진행하는 함수
void Download(std::list<int> ll) {
	std::cout << "Donwload func Start" << std::endl;

	for (int i = 0; i < SIZE; i++)
		ll.push_back(i);

	std::cout << "Donwload func Finish" << std::endl;
}



//main function => Main Thread, Primary Thread => 이게 끝나면 전체 프로그램이 끝난다
int main() {
	std::cout << "Main Start" << std::endl;
	
	//Download();

	std::list<int> list1{};

	/*
		std::thread( callable, callable 호출에 필요한 arguments )
		
		thread 가 callable 과 함께 생성, 생성되자 마자 arguments 를 이용해서 callable 을 실행한다
	*/
	//child thread, joinable thread
	std::thread thDownloader{ Download, list1 };

	
	downObj dObj{}; // Callable 로 사용할 function object 생성
	std::thread thDownloader2{ dObj }; //이미 function object 를 만들었으므로 다른 arguments 는 필요없다

	
	/*
		스레드의 실행이 끝나기를 기다리고 싶지 않을 때 = 니 혼자 알아서 잘 실행해라, 하고 놔두고 싶을때
		스레드를 detach 할 수 있다
		
		detached thread => main thread 는, 이 스레드를 기다리지 않고 끝날 수 있다
		한번 떼어내지면, 다시는 joinable 로 돌릴 수 없다
	*/
	//detached thread
	thDownloader2.detach();

	std::cout << "Main Finish" << std::endl;


	/*
		기본적으로 main thread 는 다른 child thread, joinable thread 가 끝날 때까지 기다린다		
		
		thread::joinable() => 해당 thread 가 joinable thread 인지, detached thread 인지 알 수 있다

		thread::join() => wait for the thread to return
						  main thread 의 흐름을 멈추고, 생성한 thread 가 끝나는 것을 기다린다
						  join() 이 호출되지 않고 thread object 가 정리되면, 에러가 발생한다
	*/
	//각 스레드가 joinable thread 인지 확인하고
	if(thDownloader.joinable())	
		thDownloader.join(); //joinable thread 인 경우, join() => 해당 스레드가 완료되는 것을 기다린다

	if (!thDownloader2.joinable()) //thDownloader2 thread = detached thread => join() 호출이 필요없다
		std::cout << "Detached thread is not joinable" << std::endl;

	system("Pause");
}