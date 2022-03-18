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


// Main Thread, Primary Thread => �̰� ������ ��ü ���α׷��� ������
int main() {
	std::cout << "Main Start" << std::endl;
	
	//Download();

	std::list<int> list1{};
	// std;;thread => callable �� �Բ� ����, �������ڸ��� Callable �� �Ѱܹ��� ���� �����Ѵ�
	// child thread, joinable thread
	std::thread thDownloader{ Download, list1 };

	
	downObj dObj{}; // Callable �� function object �� �ѱ�
	std::thread thDownloader2{ dObj };
	// �������� ������ �����⸦ ��ٸ��� ���� ���� �� = �� ȥ�� �˾Ƽ� �� �����ض�, �ϰ� ���ΰ� ������
	// �����带 detach �� �� �ִ� = detached thread => main thread �� ��ٸ��� �ʰ� �׳� ���� �� �ִ�
	// �ѹ� �������, �ٽô� joinable �� ���� �� ����
	thDownloader2.detach();

	std::cout << "Main Finish" << std::endl;

	// main thread �� ������ ���� �ٸ� �����尡 ������ ���� ��ٸ�
	// invoke join on the joinable thread
	// joinable �Լ��� ���ؼ�, join �� �������� �ƴ����� �� �� �ִ�
	if(thDownloader.joinable())	thDownloader.join();
	if (!thDownloader2.joinable()) std::cout << "Detached thread is not joinable" << std::endl;

	system("Pause");
}