#include <iostream>

/*
	noexcept(true) => Not throw exception
		그냥 noexcept 만 써도 된다
		그런데 예외가 발생한다면 => 즉시 종료

	noexcept(false) => exception 을 throw 할 수도 있다...
*/
void Test(int x)noexcept(false) {
	
	// library 함수는 cout, endl 을 사용
	// 해당 라이브러리 사용 중에, 어떤 exception 이 발생할 지 알수 없다
	// 따라서 noexcept(true) 라고 적으면 안된다
	std::cout << "x is " << x << std::endl;

	//throw x;
}


/*
	noexcept => operator 이기도 하다
			 => 특정 함수가 noexcept true or noexcept false 인지를 리턴해주는 함수

	noexcept( Test(x) ) => 호출하려는 Test(x) 함수가 noexcept true 인지 false 인지를
							알려주는 연산

	그 결과를 다시 noexcept 에 담는다 => 즉 Test 함수의 noexcept 결과를 따라간다
*/
int Sum(int x, int y)noexcept(noexcept(Test(x))) {
	
	// exception 이 발생할 수도 있는 호출
	Test(x);

	return x + y; // 여기서는 확실이 exception 이 발생하지 않을 것
}


class A {
public:
	//Destructors are implicitly noexcept(true) in C++11
	~A() {
		// throw 3;
	}

	// Move Operations 도 noexcept(true) 여야 한다
	// move constructor, move assignment
	// Containers 는 Copy 할 상황에서 Move 를 더 선호한다
	// 하지만, 이때 Move 가 noexcpt(false) 라면 Move 를 사용하지 않고 Copy 한다
};


int main() {
	A a;
	
	// boolalpha manipulator prints 0 & 1 as false & true
	// 어떤 함수호출에 noexcept operator 적용 => noexcept true 인지 false 인지 확인
	// 실제로 해당 함수가 호출되지는 않는다
	// 소멸자는 반드시 noexcept(true) 이다
	std::cout << std::boolalpha << noexcept(Test(1)) << std::endl;
	std::cout << std::boolalpha << noexcept(a.~A()) << std::endl;


	try {
		Sum(3, 5);
		//Other statements
	}
	catch (int x) {
		std::cout << x << std::endl;
	}
}