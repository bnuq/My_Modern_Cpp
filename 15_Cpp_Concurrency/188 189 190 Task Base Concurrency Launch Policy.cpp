#include <future>
#include <iostream>


// Task
int Operation(int count) {
	// 시간을 의미하는 리터럴 사용
	using namespace std::chrono_literals;
	int sum{};

	for (int i = 0; i < count; i++) {
		sum += i;
		std::cout << '.';
		// 이 task 를 담당하는 스레드가 잠시 멈추도록 한다
		std::this_thread::sleep_for(300ms); // std::chrono::milisecons(300)
	}
	
	return sum;
}




int main() {
	using namespace std::chrono_literals;
	std::cout << "Main() thread start" << std::endl;
	/*
	* high level concurrency, async 이용 => std::promise return => std::future return
	* std::launch::async => execute asynchronously, 스레드를 새로 만들고 거기서 진행
	* main thread 와 따로 진행하게 된다
	*/
	std::future<int> result_async{ std::async(std::launch::async, Operation, 10) };

	std::this_thread::sleep_for(1s);
	std::cout << "async future make" << std::endl;

	if (result_async.valid()) {	// future::valid() => future object 에 접근이 가능한 상태인지 확인하는 메서드
		
		// future::get() => join() 과 같은 역할, 이 스레드가 끝날 때까지 메인 스레드가 기다려준다
		// task 가 끝이나면 그 결과 값을 리턴해준다
		// 이후엔 해당 future object 나 task 에 접근할 수 없다 => invalid 상태
		auto sum = result_async.get();
		std::cout << sum << std::endl;
	}


	/*
	* std::launch::deferred => execute synchronously, 메인 스레드 안에서 같이 실행
	* get() 메서드를 통해서, 원하는 값을 요구할 때 실행이 된다
	*/
	std::future<int> result_deferred{ std::async(std::launch::deferred, Operation, 10) };
	std::this_thread::sleep_for(1s);
	std::cout << "deferred future make" << std::endl;

	if (result_deferred.valid()) {
		auto sum = result_deferred.get(); // 이때 task 실행 => 사실상 함수 호출과 동일하다
		std::cout << sum << std::endl;
	}
}