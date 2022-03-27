#include <iostream>

//Task Base Concurrency �� ���� �������
#include <future>


//Task => Function that you want to execute in a separate thread
//�������� Callable �� �Ѱ��, �۾��ϰ��� �ϴ� ����
int Operation(int count) {

	//�ð��� �ǹ��ϴ� ���ͷ� ���
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
	std::cout << "Main() thread start" << std::endl; //Main Thread ������ �˸�

	/*
		high level concurrency ���
		async() �̿�
		=> std::promise return => std::future return

		std::launch::async ����
		=> execute asynchronously, �����带 ���� ����� �ű⼭ ����

		main thread �� ���� �����ϰ� �ȴ� => �ռ� std::thread object �� �̿��ϴ� �Ͱ� ����
	*/															//Task �� �ѱ�� �ʿ��� Arguments �ѱ�
	std::future<int> result_async{ std::async(std::launch::async, Operation, 10) };

	std::this_thread::sleep_for(1s); //��� ���

	std::cout << "async future make" << std::endl;

	if (result_async.valid()) {	// future::valid() => future object �� ������ �������� Ȯ���ϴ� �޼���
		
		/*
			future::get()
			=> thread::join() �� ���� ����, �� �����尡 ���� ������ ���� �����尡 ��ٷ��ش�
		
			task �� ���̳��� �� ��� ���� �������ش�
			���Ŀ� �ش� future object �� task �� ������ �� ���� => invalid ����
		*/
		auto sum = result_async.get();
		std::cout << sum << std::endl;
	}


	/*
		std::launch::deferred
		=> execute synchronously, ���� ������ �ȿ��� ���� ����, �����带 ���� ���� �� �ʴ´�

		future::get() �޼��带 ���ؼ�, ���ϴ� ���� �䱸�� �� ������ �ȴ�
	*/
	std::future<int> result_deferred{ std::async(std::launch::deferred, Operation, 10) };
	std::this_thread::sleep_for(1s);
	std::cout << "deferred future make" << std::endl;

	if (result_deferred.valid()) {
		
		/*
			future::get()

			deffered future ������
			�̶� task ���� => ��ǻ� �Լ� ȣ��� �����ϴ�
		*/
		auto sum = result_deferred.get();
		std::cout << sum << std::endl;
	}
}