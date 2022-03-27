#include <future>
#include <iostream>

int Operation(std::promise<int> & data) {
	using namespace std::chrono_literals;

	/*
		promise::get_future()

		인자로 받은 data promise 의 짝이되는 future 를 구한다
	*/
	auto dataFuture = data.get_future() ;

	try {
		std::cout << "[Task] Waiting for count\n";
		
		
		/*
			future::get()

			앞에서 까지는 Task 가 작업을 마치는 것을 기다리고, 리턴 값을 리턴하는 메서드

			promise 와 future 가 확연히 나눠져 있는 경우,
			promise 에 값이 들어올 때까지 기다린다
			promise 가 shared state 가 되는 것을 기다린다
			future = Waiting
			
			promise 에 값이 들어오면 => shared state 가 되고
			future 가 waiting 상태라면

			communication channel 을 통해서 데이터를 가져온다 => get() 이용
		*/
		auto count = dataFuture.get(); // get 한 이후에 dataFuture 는 invalid 해진다
		std::cout << "[Task] Count acquired.\n";

		int sum{};
		for (int i = 0; i < count; ++i) {
			sum += i;
			std::cout << '.';
			std::this_thread::sleep_for(300ms);//std::chrono::seconds(1) 
		}
		return sum;

	//future::get() 한 것이 exception 인 경우
	}catch(std::exception &ex) {
		std::cout << "[Task] Exception:" << ex.what() << std::endl; 
	}
}



int main() {
	using namespace std::chrono_literals ;

	/*
		promise => future

		promise 와 future 는 항상 짝으로 활동한다
		즉, promise 만 정의해도 ~ 자동으로 그 future 가 생긴다

		반대로 future 를 정의할 때 쓰이는 async 
			~ 무조건 promise 가 먼저 리턴되고
			  그 이후에 future 가 생긴다
	*/
	std::promise<int> data; // 나오지는 않았지만 data 의 future 도 만드시 존재할 거다

	//앞서 정의한 promise 를 pass by reference => Task 에 넣는다
	std::future<int> result = std::async(std::launch::async, Operation, std::ref(data)); 
	

	std::this_thread::sleep_for(1s) ;
	std::cout << "[main] Setting the data in promise\n";

	try {
		//throw std::runtime_error{"Data not available"} ;

		/*
			promise 에 값을 넣으면 => 반대편 future 쪽에서 값을 얻을 수 있다

			저그의 커널 생각하면 된다 => 입구 커널과 출구 커널이 서로 다른 스레드에 존재한다
			일반 데이터 / task return value / exception 등을 
			promise => future 를 통해서 전달할 수 있다
		*/
		/*
			promise::set_value()

			promise 를 통해서 값을 집어 넣음
		*/
		data.set_value(10); //main thread 에서 promise 를 통해 값을 집어넣는다

		if (result.valid()) { //future 에서 값을 한번도 꺼내지 않았다, 아직 유효하다
			auto sum = result.get(); //future 가 리턴하기를 기다린다
			std::cout << sum << std::endl;
		}

	// exception 이 발생한 경우
	}catch(std::exception &ex) {
		
		/*
			promise::set_exception()

			promise 에 exception 을 넣는다

			exception 을 넣을 때, 그냥 복사하지 않고
			make_exception_ptr() 사용
				shared pointer 의 일종인 exception pointer 를 이용해서 promise 에 exception 을 넣는다
				같은 exception 을 가리키게 하는 건가?
		*/
		data.set_exception(std::make_exception_ptr(ex)) ;
	}
	
}