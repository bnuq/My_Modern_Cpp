#include <iostream>
#include <memory>


void num_1()
{
	/*
		dynamic array 를 smart pointer 로 관리하는 경우
		기존의 방법으로 할 수 없다
			delete[] 를 호출해야 하는데 delete 호출
			subscript, [] 연산자 사용 불가능
	*/
	// 기존 방식 사용 -> delete[] 를 호출하는 deleter 를 추가해야 한다
	std::unique_ptr<int> p1{ new int[5]{1,2,3,4,5} };
	// p1[0] = 10; [] compile error
	// 이런 식으로 접근하면 되나, 복잡하다
	p1.get()[0] = 10;
}

void num_2()
{
	using namespace std;
	/*
		그래서 partial specialization 을 이용?
		empty subscript, [] 를 타입에 추가
			-> cause the compiler to choose another class of smart pointer
			that provides the subscript operator
			=> can access the array elements
	*/
	// unique_ptr 의 타입이 int[] 로 지정
	// 이렇게 쓰기만 해도, delete[] 호출하는 deleter 가 자동 지정된다
	std::unique_ptr<int[]> p1{new int[5]{1,2,3,4,5}};
	// [] 를 통해서 요소에 접근 가능
	p1[0] = 10;
	cout << p1[0] << endl;
	
	// shared_ptr version 도 C++17 부터 추가
	std::shared_ptr<int[]> p2{ new int[5]{1,2,3,4,5} };
	p2[0] = 20;
	cout << p2[0] << endl;
}

/*
	그런데 사실 dynamic array 를 쓰는 것은 좋지 않다
	grow at runtime -> STL 에 있는 container 를 사용하자
						= 자동으로 메모리 관리가 된다

*/