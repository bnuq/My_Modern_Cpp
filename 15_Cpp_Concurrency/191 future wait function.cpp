#include <future>
#include <iostream>
#include <thread>

int Operation(int count) {
	using namespace std::chrono_literals;
	int sum{};
	for (int i = 0; i < count; ++i) {
		sum += i;
		std::cout << '.';
		std::this_thread::sleep_for(300ms);//std::chrono::seconds(1) 
	}
	return sum;
}



int main() {
	using namespace std::chrono_literals ;

	// make new thread
	std::future<int> result = std::async(std::launch::async, Operation, 10);
	std::this_thread::sleep_for(1s) ;
	std::cout << "main() thread continues execution...\n";

	if (result.valid()) {

		// 현재 시각 알아내기
		auto timepoint = std::chrono::system_clock::now() ;
		timepoint += 1s ; // chrono_literals 통해서 새로운 시각 얻어내
		
		// wait_until, wait_for => future object 가 task 실행하는 것을 기다리고, 이후 상태를 리턴한다
		// timepoint 까지 기다린다
		auto status = result.wait_until(timepoint) ;
		//auto status = result.wait_for(4s) ; = 4s 간 기다린다
		
		// 기다린 이후 상태는 총 3가지
		switch(status) {
			// deferred future object 를 기다린 경우 => 사실 실행도 안한 상태일 것
			// 따라서 이 경우 기다리지 않고 바로 리턴한다
			case std::future_status::deferred:
				std::cout << "Task is synchronous\n" ;
				break ;
			// 기다리는 동안 task 가 완료됐다
			case std::future_status::ready:
				std::cout << "Result is ready\n" ;
				break ;
			// 기다렸지만, 아직 task 는 완료되지 않았다
			case std::future_status::timeout:
				std::cout << "Task is still running\n" ;
				break ;
		}

		// result.wait() ; => 아예 task 가 끝날 때까지 main thread 가 기다린다 => 진행 막힘
		//Operation(10) ;
		auto sum = result.get();
		std::cout << sum << std::endl;
	}
}