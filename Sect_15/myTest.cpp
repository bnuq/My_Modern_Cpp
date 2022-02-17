#include <iostream>
#include <future>

int CalculateMid(std::promise<std::pair<int, int>>& intPair) {
	using namespace std::chrono_literals;

	int mid{};
	auto intPairFuture = intPair.get_future();
	
	std::cout << "Calculating" << std::endl;

	if (intPairFuture.valid()) {
		auto value = intPairFuture.get();
		mid = (value.first + value.second) / 2;
	}	
	
	std::cout << "Calculation Finish" << std::endl;

	/*
	* 이 task 가 끝나고, 값을 리턴하면 ~ 그 값이 async 가 자동으로 만든 promise 에 들어간다
	* 그러면 promise = shared state => waiting 하고 있는 future 에게 값을 보내
	* future = 앞서 정의됐던 res 인 거고
	*/
	return mid;
}

int main() {
	std::promise<std::pair<int, int>> intPair{};
	std::future<int> res{ std::async(std::launch::async, CalculateMid, std::ref(intPair)) };

	using namespace std::chrono_literals;
	std::this_thread::sleep_for(1s);
	std::cout << "Give intPair Data now" << std::endl;
	intPair.set_value(std::make_pair(1, 9));
	std::this_thread::sleep_for(1s);
	std::cout << "Giving Data finish" << std::endl;

	if (res.valid()) {
		std::cout << res.get() << std::endl;
	}
}