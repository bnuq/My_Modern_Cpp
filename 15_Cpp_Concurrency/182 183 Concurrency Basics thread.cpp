#include <iostream>
#include <list>

// thread ��뿡 �ʿ��� �������
#include <thread>

//std::list<int> gData{};

//�ٿ�ε� ����, ������
const int SIZE = 500000;



//Funcion Object => �ٿ�ε带 ����
struct downObj {
	std::list<int> data{};

	void operator()() {
		std::cout << "Donwload operator Start" << std::endl;

		for (int i = 0; i < SIZE; i++)
			data.push_back(i);

		std::cout << "Donwload operator Finish" << std::endl;
	}
};


//�ٿ�ε带 �����ϴ� �Լ�
void Download(std::list<int> ll) {
	std::cout << "Donwload func Start" << std::endl;

	for (int i = 0; i < SIZE; i++)
		ll.push_back(i);

	std::cout << "Donwload func Finish" << std::endl;
}



//main function => Main Thread, Primary Thread => �̰� ������ ��ü ���α׷��� ������
int main() {
	std::cout << "Main Start" << std::endl;
	
	//Download();

	std::list<int> list1{};

	/*
		std::thread( callable, callable ȣ�⿡ �ʿ��� arguments )
		
		thread �� callable �� �Բ� ����, �������� ���� arguments �� �̿��ؼ� callable �� �����Ѵ�
	*/
	//child thread, joinable thread
	std::thread thDownloader{ Download, list1 };

	
	downObj dObj{}; // Callable �� ����� function object ����
	std::thread thDownloader2{ dObj }; //�̹� function object �� ��������Ƿ� �ٸ� arguments �� �ʿ����

	
	/*
		�������� ������ �����⸦ ��ٸ��� ���� ���� �� = �� ȥ�� �˾Ƽ� �� �����ض�, �ϰ� ���ΰ� ������
		�����带 detach �� �� �ִ�
		
		detached thread => main thread ��, �� �����带 ��ٸ��� �ʰ� ���� �� �ִ�
		�ѹ� �������, �ٽô� joinable �� ���� �� ����
	*/
	//detached thread
	thDownloader2.detach();

	std::cout << "Main Finish" << std::endl;


	/*
		�⺻������ main thread �� �ٸ� child thread, joinable thread �� ���� ������ ��ٸ���		
		
		thread::joinable() => �ش� thread �� joinable thread ����, detached thread ���� �� �� �ִ�

		thread::join() => wait for the thread to return
						  main thread �� �帧�� ���߰�, ������ thread �� ������ ���� ��ٸ���
						  join() �� ȣ����� �ʰ� thread object �� �����Ǹ�, ������ �߻��Ѵ�
	*/
	//�� �����尡 joinable thread ���� Ȯ���ϰ�
	if(thDownloader.joinable())	
		thDownloader.join(); //joinable thread �� ���, join() => �ش� �����尡 �Ϸ�Ǵ� ���� ��ٸ���

	if (!thDownloader2.joinable()) //thDownloader2 thread = detached thread => join() ȣ���� �ʿ����
		std::cout << "Detached thread is not joinable" << std::endl;

	system("Pause");
}