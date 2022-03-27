#include <iostream>
#include <future>

int CalculateMid(std::promise<std::pair<int, int>>& intPair) {
	using namespace std::chrono_literals;

	int mid{};
	
	//promise �� ����Ǿ� �ִ� future object
	auto intPairFuture = intPair.get_future();
	
	std::cout << "Calculating" << std::endl;

	if (intPairFuture.valid()) {
		
		//future object �� �̿��ؼ�, promise �� ���� ������ ���� �޴´�
		auto value = intPairFuture.get();
		mid = (value.first + value.second) / 2;
	}	
	
	std::cout << "Calculation Finish" << std::endl;

	/*
		�� task �� ������, ���� �����ϸ� ~ 
		�� ���� async �� �ڵ����� ���� promise �� ����

		�׷��� �ڵ����� ������� promise = shared state
		=> waiting �ϰ� �ִ� future ���� ���� ����

		future = �ռ� ���ǵƴ� res �� �Ű�

		�׷��� res.get() �� ���� Task ��� ���� ���ϵȴ�
	*/
	return mid;
}

int main() {

	//pair Ÿ���� �Է��� promise ��ü
	std::promise<std::pair<int, int>> intPair{};

	//CalculateMid Task �� ������ future ��ü
	std::future<int> res{ std::async(std::launch::async, CalculateMid, std::ref(intPair)) };

	using namespace std::chrono_literals;
	std::this_thread::sleep_for(1s);
	std::cout << "Give intPair Data now" << std::endl;

	//promise �� ���� �� �Է�
	intPair.set_value(std::make_pair(1, 9));

	std::this_thread::sleep_for(1s);
	std::cout << "Giving Data finish" << std::endl;


	if (res.valid()) {
		std::cout << res.get() << std::endl;
	}
}