#include <iostream>
#include <future>

int CalculateMid(std::promise<std::pair<int, int>>& intPair) {
	using namespace std::chrono_literals;

	int mid{};
	
	//promise 에 연결되어 있는 future object
	auto intPairFuture = intPair.get_future();
	
	std::cout << "Calculating" << std::endl;

	if (intPairFuture.valid()) {
		
		//future object 를 이용해서, promise 를 통해 들어오는 값을 받는다
		auto value = intPairFuture.get();
		mid = (value.first + value.second) / 2;
	}	
	
	std::cout << "Calculation Finish" << std::endl;

	/*
		이 task 가 끝나고, 값을 리턴하면 ~ 
		그 값이 async 가 자동으로 만든 promise 에 들어간다

		그러면 자동으로 만들어진 promise = shared state
		=> waiting 하고 있는 future 에게 값을 보내

		future = 앞서 정의됐던 res 인 거고

		그래서 res.get() 을 통해 Task 계산 값이 리턴된다
	*/
	return mid;
}

int main() {

	//pair 타입을 입력할 promise 객체
	std::promise<std::pair<int, int>> intPair{};

	//CalculateMid Task 를 진행할 future 객체
	std::future<int> res{ std::async(std::launch::async, CalculateMid, std::ref(intPair)) };

	using namespace std::chrono_literals;
	std::this_thread::sleep_for(1s);
	std::cout << "Give intPair Data now" << std::endl;

	//promise 를 통해 값 입력
	intPair.set_value(std::make_pair(1, 9));

	std::this_thread::sleep_for(1s);
	std::cout << "Giving Data finish" << std::endl;


	if (res.valid()) {
		std::cout << res.get() << std::endl;
	}
}