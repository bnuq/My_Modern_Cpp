#include <iostream>
#include <thread>

// Windows 10 ���� �߰��� window api �������
#include <Windows.h>


void Process() {
	// std::this_thread ��� namespace => ���� thread function �� ����ϴ� �����忡 ���� ������ ���� �� �ִ�
	
	// std::this_thread::get_id() => ���� ���ư��� �������� id ����
	std::cout << "Threadid:" << std::this_thread::get_id() << std::endl;
	for (int i = 0; i < 10; ++i) {
		// std::this_thread::sleep_for => ������ ���߰� �Ѵ�, �Ͻ� ����
		// std::chrono::seconds(1) => 1�ʶ�� �ð�
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << i << ' ';
	}
}

int main() {
	std::thread t1(Process);

	// thread::native_handle() => Returns the native type of the thread, �����쿡���� HANDLE
	// On Linux, the native type is pthread_t
	HANDLE handle = t1.native_handle(); // ���� HANDLE �� ���ؼ� �����带 ������ �� �ִ�
	
	// window api => handle, �����忡 �̸����̱� => wide character ���
	SetThreadDescription(handle, L"MyThread");
	
	auto id = t1.get_id(); // thread::get_id() => �����忡 �ο��� ��ȣ ���, id class
	std::cout << "t1.get_id()" << id << std::endl; 

	int cores = std::thread::hardware_concurrency(); // CPU core ���� ����

	std::cout << "Cores:" << cores << std::endl;
	t1.join();
	return 0;
}