#include <future>
#include <iostream>

int Operation(std::promise<int> & data) {
	using namespace std::chrono_literals;

	/*
		promise::get_future()

		���ڷ� ���� data promise �� ¦�̵Ǵ� future �� ���Ѵ�
	*/
	auto dataFuture = data.get_future() ;

	try {
		std::cout << "[Task] Waiting for count\n";
		
		
		/*
			future::get()

			�տ��� ������ Task �� �۾��� ��ġ�� ���� ��ٸ���, ���� ���� �����ϴ� �޼���

			promise �� future �� Ȯ���� ������ �ִ� ���,
			promise �� ���� ���� ������ ��ٸ���
			promise �� shared state �� �Ǵ� ���� ��ٸ���
			future = Waiting
			
			promise �� ���� ������ => shared state �� �ǰ�
			future �� waiting ���¶��

			communication channel �� ���ؼ� �����͸� �����´� => get() �̿�
		*/
		auto count = dataFuture.get(); // get �� ���Ŀ� dataFuture �� invalid ������
		std::cout << "[Task] Count acquired.\n";

		int sum{};
		for (int i = 0; i < count; ++i) {
			sum += i;
			std::cout << '.';
			std::this_thread::sleep_for(300ms);//std::chrono::seconds(1) 
		}
		return sum;

	//future::get() �� ���� exception �� ���
	}catch(std::exception &ex) {
		std::cout << "[Task] Exception:" << ex.what() << std::endl; 
	}
}



int main() {
	using namespace std::chrono_literals ;

	/*
		promise => future

		promise �� future �� �׻� ¦���� Ȱ���Ѵ�
		��, promise �� �����ص� ~ �ڵ����� �� future �� �����

		�ݴ�� future �� ������ �� ���̴� async 
			~ ������ promise �� ���� ���ϵǰ�
			  �� ���Ŀ� future �� �����
	*/
	std::promise<int> data; // �������� �ʾ����� data �� future �� ����� ������ �Ŵ�

	//�ռ� ������ promise �� pass by reference => Task �� �ִ´�
	std::future<int> result = std::async(std::launch::async, Operation, std::ref(data)); 
	

	std::this_thread::sleep_for(1s) ;
	std::cout << "[main] Setting the data in promise\n";

	try {
		//throw std::runtime_error{"Data not available"} ;

		/*
			promise �� ���� ������ => �ݴ��� future �ʿ��� ���� ���� �� �ִ�

			������ Ŀ�� �����ϸ� �ȴ� => �Ա� Ŀ�ΰ� �ⱸ Ŀ���� ���� �ٸ� �����忡 �����Ѵ�
			�Ϲ� ������ / task return value / exception ���� 
			promise => future �� ���ؼ� ������ �� �ִ�
		*/
		/*
			promise::set_value()

			promise �� ���ؼ� ���� ���� ����
		*/
		data.set_value(10); //main thread ���� promise �� ���� ���� ����ִ´�

		if (result.valid()) { //future ���� ���� �ѹ��� ������ �ʾҴ�, ���� ��ȿ�ϴ�
			auto sum = result.get(); //future �� �����ϱ⸦ ��ٸ���
			std::cout << sum << std::endl;
		}

	// exception �� �߻��� ���
	}catch(std::exception &ex) {
		
		/*
			promise::set_exception()

			promise �� exception �� �ִ´�

			exception �� ���� ��, �׳� �������� �ʰ�
			make_exception_ptr() ���
				shared pointer �� ������ exception pointer �� �̿��ؼ� promise �� exception �� �ִ´�
				���� exception �� ����Ű�� �ϴ� �ǰ�?
		*/
		data.set_exception(std::make_exception_ptr(ex)) ;
	}
	
}