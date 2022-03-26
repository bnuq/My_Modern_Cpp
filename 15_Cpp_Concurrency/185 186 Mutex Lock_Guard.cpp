#include <iostream>
#include <list>
#include <thread>
#include <string>

//mutex ��� ������� => Thread Synchronization
#include <mutex>


std::list<int> g_Data{}; //�����ڿ�
const int SIZE = 10000;


/*
	Mutex => Thread Synchronization �� ���ؼ� ���

	mutex::lock()
	mutex::unlock() �޼��带 �̿��ؼ�

	���� �ٸ� �����忡�� ���� �ڿ��� ���ÿ� �����ϴ� ���� ���� �� �ִ�

	������ �� �����忡�� lock �� ��, exception � ���� �����尡 ���ڱ� ����Ǿ� �����ٸ�
	mutex �� unlock ���� �ʾ� �ٸ� �����忡�� ��� �������� ���ϴ� ��찡 �߻��Ѵ� == deadlock
	
	�׷��� mutex ���� lock, unlock �� ���� �ٷ��� �ʴ´�
*/
std::mutex g_Mutex{};



//�����ڿ��� �����ϴ� ������ 2���� �����Ѵ�
void Download() {
	for (int i = 0; i < SIZE; ++i) { //501 �� �Է�

		// g_Mutex.lock();  ���� mutex::lock() ȣ��
		//�׷��� lock �� ���Ŀ�, �Լ� ���� ���� exception �� �߻��Ѵٸ�
		//�Լ��� �״�� ���� => mutex �� unlock ���� �ʰ� �ȴ� => deadlock
		

		/*
			���� RAII ������ mutex �� �����Ѵ�
			��ü�� mutex �� ����, lock, unlock ��
			��ü�� ����, �Ҹ�� �Բ� �ڿ������� �̷�������� �Ѵ�
			
			Use std::lock_guard to lock a mutex (RAII)
			
			lock_guard => mutex �� ���ο� ������ ��ü

			�� ��ü�� ������ ��, �ڵ����� lock �ϰ�
			�� ��ü�� �ı��� ��, �ڵ����� unlock �ǰ� �����
			����ġ ���ϰ� �����ϴ���, mutex.unlock() �� �ݵ�� �Ͼ���� �Ѵ�
		*/
		//mutex type �� ������ lock_guard
		std::lock_guard<std::mutex> mtx{ g_Mutex };

		//�����ڿ� ����
		g_Data.push_back(i);
		if (i == 500)
			return;

		// g_Mutex.unlock();  �����ڿ� ��� ��, ���� mutex::unlock() ȣ��
		//lock_guard �� �Ҹ�Ǹ鼭, �ڵ����� mutex::unlock() �� �߻��Ѵ� => ����
	}
}
void Download2() {

	for (int i = 0; i < SIZE; ++i) { //10000 �� �Է�

		//lock_guard �̿� => mutex �� �ڿ������� �̿��Ѵ�
		std::lock_guard<std::mutex> mtx{ g_Mutex };
		
		g_Data.push_back(i);
	}
}


int main() {

	//joinable thread 2���� ����
	std::thread thDownloader(Download);
	std::thread thDownloader2(Download2);

	//�� ������ ��� ������ ����Ǵ� ���� ��ٸ���
	thDownloader.join();
	thDownloader2.join();

	//�����ڿ� Ȯ��
	std::cout << g_Data.size() << std::endl; 

	return 0;
}