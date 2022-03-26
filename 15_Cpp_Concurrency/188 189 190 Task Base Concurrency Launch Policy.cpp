#include <future>
#include <iostream>


// Task
int Operation(int count) {
	// �ð��� �ǹ��ϴ� ���ͷ� ���
	using namespace std::chrono_literals;
	int sum{};

	for (int i = 0; i < count; i++) {
		sum += i;
		std::cout << '.';
		// �� task �� ����ϴ� �����尡 ��� ���ߵ��� �Ѵ�
		std::this_thread::sleep_for(300ms); // std::chrono::milisecons(300)
	}
	
	return sum;
}




int main() {
	using namespace std::chrono_literals;
	std::cout << "Main() thread start" << std::endl;
	/*
	* high level concurrency, async �̿� => std::promise return => std::future return
	* std::launch::async => execute asynchronously, �����带 ���� ����� �ű⼭ ����
	* main thread �� ���� �����ϰ� �ȴ�
	*/
	std::future<int> result_async{ std::async(std::launch::async, Operation, 10) };

	std::this_thread::sleep_for(1s);
	std::cout << "async future make" << std::endl;

	if (result_async.valid()) {	// future::valid() => future object �� ������ ������ �������� Ȯ���ϴ� �޼���
		
		// future::get() => join() �� ���� ����, �� �����尡 ���� ������ ���� �����尡 ��ٷ��ش�
		// task �� ���̳��� �� ��� ���� �������ش�
		// ���Ŀ� �ش� future object �� task �� ������ �� ���� => invalid ����
		auto sum = result_async.get();
		std::cout << sum << std::endl;
	}


	/*
	* std::launch::deferred => execute synchronously, ���� ������ �ȿ��� ���� ����
	* get() �޼��带 ���ؼ�, ���ϴ� ���� �䱸�� �� ������ �ȴ�
	*/
	std::future<int> result_deferred{ std::async(std::launch::deferred, Operation, 10) };
	std::this_thread::sleep_for(1s);
	std::cout << "deferred future make" << std::endl;

	if (result_deferred.valid()) {
		auto sum = result_deferred.get(); // �̶� task ���� => ��ǻ� �Լ� ȣ��� �����ϴ�
		std::cout << sum << std::endl;
	}
}