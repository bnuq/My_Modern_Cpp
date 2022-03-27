#include <iostream>

int ProcessRecords(int count) {
	//int* pArray = (int*)malloc(count * sizeof(int));
	int* pArray{ nullptr };

	// 조건에 따라서 여러 종류의 exception 이 발생할 수 있다
	if (count < 10) throw std::out_of_range("Count should be greater than 10");
	if (count < 0) throw std::bad_alloc{};

	// malloc 이 메모리 할당에 실패했을 경우
	if (pArray == nullptr) {
		// exception 을 throw 하게 한다
		// 프로그램이 절대 무시할 수 없다
		throw std::runtime_error("Failed to allocat memory");
	}
	else {
		free(pArray);
		return 0;
	}
}


int main() {
	// exception 이 발생할 수 있는 코드는 try block 에서 처리한다
	try {
		// int 값의 범위 중 가장 큰 값을 이용
		//ProcessRecords(std::numeric_limits<int>::max());
		ProcessRecords(2);
	}
	// exception 이 발생한 경우 catch block 에서 잡는다
	/*
		Multiple Catch Blocks
		어떤 종류의 exception 이 발생할 지 모르니, 발생할 수 있는 모든 exception 에 대해서
		받는 catch block 을 모두 적을 수도 있다
	
	catch (std::runtime_error& ex) {
		// exception :: what() 메소드 => exception 의 이름을 리턴
		std::cout << ex.what() << std::endl;
	}
	catch (std::out_of_range& ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (std::bad_alloc& ex) {
		std::cout << ex.what() << std::endl;
	}

	*/
	/*
		근데 모든 exception 들은 std::exception class 의 child class 다
		따라서 std::exception class 의 포인터, 레퍼런스를 이용하면 모든 exception 을 
		가리킬 수 있다 => 이거 하나로 사실 모든 exception 을 받을 수 있다
	*/
	catch (std::exception& ex) {
		// exception :: what() 메소드 => exception 의 이름을 리턴
		std::cout << ex.what() << std::endl;
	}
	// 최후의 방법, ellipsis 사용 => 무엇을 받는 지는 모르지만, 받는 건 가능하다
	// 피하는 것이 좋다
	catch (...) {
		std::cout << "Exception" << std::endl;
	}
}