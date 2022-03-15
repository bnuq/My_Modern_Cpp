#include <iostream>

void num_1() {
	/*
		Modern C++ discourages manual memory management
		= Avoid using new and delete operators directly

		smart pointer 를 만들 때, heap memory 에 직접 접근해서 ~ 메모리 주소를 가져와야 하는데
		
		직접 접근하지 않고 메모리 주소를 할당해주는 역할을 하는 global function 이 있다
		= Make Function
		= provied for unique_ptr and shared_ptr
	*/

	// Heap 에 직접 접근하는 방식
	std::unique_ptr<int> p1{ new int }; // new operator 로 메모리를 직접 할당한다

	// Make Function 사용
	// Factory Function 처럼 동작한다 = 객체를 반환하는 함수, create an instance of a class
	/*
		make_unique = unique_ptr 을 만들어서 리턴
		<> = heap 에 할당하고자 하는 타입, 리소스에 저장해 관리하고자 하는 타입을 명시
		() = 해당 타입 constructor 에 필요한 arguments
		
		heap 에 메모리를 할당하고, 그 메모리를 가리키는 포인터를 포함하는
		스마트 포인터를 만든 다음, 스마트 포인터 객체를 리턴한다
	*/
	auto p2 = std::make_unique<int>(9);
}


class Point {
public:
	Point(int x, int y) {
		std::cout << "Point Constructor needs two arguments" << std::endl;
	}
};


void num_2() {
	// Point 타입을 가리키는 unique_ptr 을 만들자
	// put arguments passed to constructor
	// Any constructor of the type can be invoked
	auto p = std::make_unique<Point>(10, 100);


	// For dynamic array with unique pointer
	// arguments 에 size 지정
	// 초기화 arguments 는 못 넣는다, cannot initialze
	auto pArr = std::make_unique<int[]>(5);
	pArr[0] = 10;
}


void num_3() {
	// shared pointer 에서도 똑같이 적용할 수 있다
	auto p = std::make_shared<Point>(10, 100);


	// For dynamic array with shared pointer
	// arguments 에 size 지정
	// 초기화 arguments 는 못 넣는다, cannot initialze
	// std::make_shared for arrays was added in C++20 standard
	auto pArr = std::make_shared<int[]>(5);
	pArr[0] = 10;


	/*
		shared pointer is implemented differently than a unique pointer
		= store extra information related to the underlying pointer
		= the control block 이 추가적으로 생성
		
		make_shared 를 사용하면, underlying pointer 를 위한 메모리와
		control block 을 위한 메모리를 동시에 할당
		= new 를 한번만 사용한다
		= delete 도 한번만 사용한다
		=> 호출 횟수가 감소한다
	*/
}


/*
	Make Function 의 단점
	
	deleter 를 custom 할 수 없다
*/