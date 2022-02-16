#include <iostream>
#include <list>
#include <thread>

//std::list<int> gData{};
const int SIZE = 500000;

struct downObj
{
	std::list<int> list{};
	void operator()() {
		std::cout << "Donwload operator Start" << std::endl;

		for (int i = 0; i < SIZE; i++)
			list.push_back(i);

		std::cout << "Donwload operator Finish" << std::endl;
	}
};

void Download(std::list<int> ll) {
	std::cout << "Donwload func Start" << std::endl;

	for (int i = 0; i < SIZE; i++)
		ll.push_back(i);

	std::cout << "Donwload func Finish" << std::endl;
}


// Main Thread, Primary Thread => 이게 끝나면 전체 프로그램이 끝난다
int main() {
	std::cout << "Main Start" << std::endl;
	
	//Download();

	std::list<int> list1{};
	// std;;thread => callable 과 함께 생성, 생성되자마자 Callable 로 넘겨받은 것을 실행한다
	// child thread, joinable thread
	std::thread thDownloader{ Download, list1 };

	
	downObj dObj{}; // Callable 로 function object 를 넘김
	std::thread thDownloader2{ dObj };
	// 스레드의 실행이 끝나기를 기다리고 싶지 않을 때 = 니 혼자 알아서 잘 실행해라, 하고 놔두고 싶을때
	// 스레드를 detach 할 수 있다 = detached thread => main thread 가 기다리지 않고 그냥 끝낼 수 있다
	// 한번 떼어내지면, 다시는 joinable 로 돌릴 수 없다
	thDownloader2.detach();

	std::cout << "Main Finish" << std::endl;

	// main thread 가 끝나기 전에 다른 스레드가 끝나는 것을 기다림
	// invoke join on the joinable thread
	// joinable 함수를 통해서, join 이 가능한지 아닌지를 알 수 있다
	if(thDownloader.joinable())	thDownloader.join();
	if (!thDownloader2.joinable()) std::cout << "Detached thread is not joinable" << std::endl;

	system("Pause");
}