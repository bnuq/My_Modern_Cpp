#include <iostream>
#include <list>
#include <thread>
#include <string>
#include <mutex>

std::list<int> g_Data;
const int SIZE = 10000;

std::mutex g_Mutex;
/*
	g_Mutex.lock(), .unlock() ���� ���� �ٸ� �����忡�� ���� �ڿ��� ���ÿ� �����ϴ� ���� ���� �� �ִ�
	������ lock �� exception � ���� �����尡 ���ڱ� �����ϴ� ���, unlock ���� �ʾ� �ٸ� �����忡�� �������� ���� ���� �ִ� == deadlock
	�׷��� mutex �� ���� �ٷ��� �ʴ´�
*/


void Download() {
	for (int i = 0; i < SIZE; ++i) {

		// g_Mutex.lock();

		// Use std::lock_guard to lock a mutex (RAII)
		/*
			lock_guard => mutex �� ���ο� ������ ��ü
			�� ��ü�� ������ ��, �ڵ����� lock �ϰ�
			�� ��ü�� �ı��� ��, �ڵ����� unlock �ǰ� �����
			����ġ ���ϰ� �����ϴ���, mutex.unlock() �� �ݵ�� �Ͼ���� �Ѵ�
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