#include <future>
#include <iostream>

int Operation(std::promise<int> & data) {
	using namespace std::chrono_literals;

	// data promise �� ¦�̵Ǵ� future �� ���Ѵ�
	auto dataFuture = data.get_future() ;

	try {
	
		std::cout << "[Task] Waiting for count\n";
		
		// promise �� ���� ������ ������ ��ٸ��� == Wait the shared state
		// promise �� ���� ���ͼ�, shared state �� �ǰ� && future �� waiting ���¶��
		// communication channel �� ���ؼ� �����͸� �����´� => get() �̿�
		// shared state �� �ƴ϶��, ���� ���� ������ ��ٸ���
		auto count = dataFuture.get(); // get �� ���Ŀ� dataFuture �� invalid �ϴ�
		std::cout << "[Task] Count acquired.\n";

		int sum{};
		for (int i = 0; i < count; ++i) {
			sum += i;
			std::cout << '.';
			std::this_thread::sleep_for(300ms);//std::chrono::seconds(1) 
		}
		return sum;

	// future::get() �� ���� exception �� ���
	}catch(std::exception &ex) {
		std::cout << "[Task] Exception:" << ex.what() << std::endl; 
	}
}
int main() {
	using namespace std::chrono_literals ;

	/*
		promise �� future �� �׻� ¦���� Ȱ���Ѵ�
		��, promise �� �����ص� ~ �ڵ����� �� future �� �����
		�ݴ�� future �� ������ �� ���̴� async ~ ������ promise �� ���� ������ �� ���Ŀ� future �� �����
	*/
	std::promise<int> data; // �������� �ʾ����� data �� future �� ����� ������ �Ŵ�
	std::future<int> result = std::async(std::launch::async, Operation, std::ref(data)); // �ռ� ������ promise �� pass by reference

	std::this_thread::sleep_for(1s) ;
	std::cout << "[main] Setting the data in promise\n";

	try {
		//throw std::runtime_error{"Data not available"} ;

		// promise �� ���� �־��� => �ݴ��� future �ʿ��� ���� ���� �� �ִ�
		// ������ Ŀ�� �����ϸ� �ȴ� => �Ա� Ŀ�ΰ� �ⱸ Ŀ���� ���� �ٸ� �����忡 �����Ѵ�
		// �Ϲ� ������ or task return value or exception �� ������ �� �ִ�
		data.set_value(10);
		if (result.valid()) {
			auto sum = result.get();
			std::cout << sum << std::endl;
		}

	// exception �� �߻��� ���
	}catch(std::exception &ex) {
		// promise �� exception �� �ִ´� => set_exception() method
		// shared pointer �� ������ exception pointer �� �̿��ؼ� promise �� exception �� �ִ´�
		data.set_exception(std::make_exception_ptr(ex)) ;
	}
	
}