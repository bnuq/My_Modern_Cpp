#include <iostream>

//Future 와 Thread 둘을 동시에 사용
#include <future>	//High Level Concurrency
//#include <thread>	//Low Level Concurrency


//실행하고자 하는 Task
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

	//async future => make new thread 하고 시행
	std::future<int> result = std::async(std::launch::async, Operation, 10);

	std::this_thread::sleep_for(1s) ;
	std::cout << "main() thread continues execution...\n";

	if (result.valid()) { //future 에 접근가능한가?

		// 현재 시각 알아내기
		auto timepoint = std::chrono::system_clock::now() ;
		timepoint += 1s ; // chrono_literals 통해서 새로운 시각 얻어내
		
		
		/*
			future::wait_until( timepoint )
			future::wait_for( time )
			=> future object 가 task 실행하는 것을 기다리고, 이후 future의 상태를 리턴한다
																future status
			
			wait_until => timepoint 까지 기다린다
			wait_for => time 동안 기다린다
		*/
		auto status = result.wait_until(timepoint) ; //1초 뒤 까지를 기다린다
		//auto status = result.wait_for(4s) ; = 4s 간 기다린다
		

		//기다린 이후 상태는 총 3가지
		switch(status) {
			//deferred future object 를 기다린 경우 => 사실 실행도 안한 상태일 것
			//deferred future 는 get() 가 호출될 때 실행하니까
			//따라서 이 경우 기다리지 않고 바로 리턴한다
			case std::future_status::deferred:
				std::cout << "Task is synchronous\n" ;
				break ;

			//기다리는 동안 task 가 완료됐다
			case std::future_status::ready:
				std::cout << "Result is ready\n" ;
				break ;

			//기다렸지만, 아직 task 는 완료되지 않았다
			case std::future_status::timeout:
				std::cout << "Task is still running\n" ;
				break ;
		}

		
		/*
			future::wait()

			=> 아예 task 가 끝날 때까지 main thread 가 기다린다 => 진행 막힘

			그러면 Task 의 리턴 값을 내지 않는다는 것
			Task 의 결과가 available 할 때까지 기다리기만 하고 future 를 끝내지 않는다는 점이
				wait 이 끝나도 future.valid() == true 이다

			future::get() 과 다른점인가봐
		*/
		result.wait();
		
		int sum{ 0 };

		if(result.valid())
			sum = result.get(); //future::get(), 메인 스레드가 Task 가 끝나는 것을 기다리고 결과를 리턴
		
		std::cout << sum << std::endl;
	}
}