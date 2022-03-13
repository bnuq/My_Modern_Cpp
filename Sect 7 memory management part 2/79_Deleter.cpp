#include <iostream>
#include <memory>


void SmartPointerWithLegacy()
{
	// malloc 으로 할당한 메모리를 스마트 포인터로 관리할 수 있다
	// 원래는 new 로 메모리 할당
	std::unique_ptr<int> p{ (int*)malloc(4) };
	*p = 100;
	std::cout << *p << '\n';
	// smart pointer -> scope 가 끝나면서 자동으로 메모리 정리
	// free(p);
	// 하지만 스마트 포인터는 delete 로 메모리 정리 => malloc 과 맞지 않다
}


/*
	smart pointer, scope 가 끝이 나면
	destructor -> invoke 'deleter'
	deleter = a callback that releases the resources
	unique_ptr, shared_ptr -> 'default deleter' = delete 사용

	deleter 를 마음대로 설정할 수 있다 by any kind of callable
		global function
		function object
			= state 를 가지는 function
			= create by overloading the function call operator
		lambda expression
*/


// 1. Function Object
struct Free { // == 이 structure가 deleter
	// Overload function call operator
	// underlying pointer, 해제 하고자 하는 포인터를 argument 로 받는다
	void operator()(int* up) {
		// malloc memory ~ free 로 정리한다
		free(up);
		std::cout << "free memory by function object" << std::endl;
	}
};


// 2. Global Function
void MallocFree(int* up) { // = 함수가 deleter
	// 해제하려는 메모리 주소를 argument 로 받는다
	free(up);
	std::cout << "free memory by global function" << std::endl;
}


// unique_ptr 에서 deleter 지정하는 방법
void UniquePtrDeleters()
{
	// unique_ptr -> "type"

	/* 1 */
	// 이걸 쓰는 것을 추천
	// smart pointer 에 deleter type, deleter object 를 명시 => specify deleter
	std::unique_ptr<int, Free> p1{ (int*)malloc(sizeof(int)), Free{} };
	*p1 = 10;
	std::cout << "unique_ptr " << "Function Object = deleter " << *p1 << std::endl;


	/* 2 */
	// smart pointer 에 function pointer 와 function address 를 명시
	// function type 을 알리는 것
	// function pointer = return type ( * 이름 ) (arguments)
	// function pointer 가 들어가면서, smart pointer 의 크기가 증가한다?
	std::unique_ptr<int, void (*) (int*)> p2{ (int*)malloc(sizeof(int)), MallocFree };
	*p2 = 20;
	std::cout << "unique_ptr " << "Global Function = deleter " << *p2 << std::endl;
}


// shared_ptr 에서 deleter 지정하는 방법
void SharedPtrDeleters()
{
	/* 1 */
	// 이걸 쓰는 것을 추천
	// smart pointer 에 deleter object 를 명시 => specify deleter
	std::shared_ptr<int> p1{ (int*)malloc(sizeof(int)), Free{} };
	*p1 = 10;
	std::cout << "shared_ptr " << "Function Object = deleter " << *p1 << std::endl;


	/* 2 */
	// smart pointer 에 function address 를 명시
	std::shared_ptr<int> p2{ (int*)malloc(sizeof(int)), MallocFree };
	*p2 = 20;
	std::cout << "shared_ptr " << "Global Function = deleter " << *p2 << std::endl;
}



int main()
{
	UniquePtrDeleters();
	SharedPtrDeleters();
}