#include <iostream>

class Integer {
	int data{};
public:
	//Default constructor
	Integer() {	std::cout << "Default Ctor" << std::endl; }
	//Parameterized constructor
	Integer(int value) : data{ value } { std::cout << "Parameterized constructor" << std::endl; }

	//Copy constructor
	Integer(const Integer& obj) { std::cout << "Copy constructor" << std::endl; }
	Integer& operator=(const Integer& obj) = default;

	//Move constructor
	Integer(Integer&& obj) noexcept { std::cout << "Move constructor" << std::endl; }
	Integer& operator=(Integer&& obj) = default;

	~Integer() = default;
};


Integer Func1(int a, int b) {
	Integer temp{ a + b };
	return temp;	// Named Return Value Optimization
}
Integer Func2(int a, int b) {
	return Integer{ a + b };	// Return Value Optimization
}

int main() {
	/*
		Copy Elision = 불필요한 임시 객체 생성을 막는 것
		원래는, Func 함수 리턴을 받기 위해서 임시 객체를 만들어야 한다 = Move Ctor
		그리고 값을 받은 임시객체를 이용해서 객체 생성 = Move Ctor
	*/	
	/*
		하지만 기본적인 Copy Elision 이용하면,
		함수가 리턴하는 값을 받는 임시 객체를 만들지 않고,
		함수가 리턴하는 값을 그대로 이용해서 바로 객체 A 를 생성 = Move Ctor
	*/
	Integer A = Func1(1, 1);

	/*
		아니면 아예 Func2 가 리턴하려고 만드는 임시 객체 자체를 만들지 않고,
		인수만 사용, 바로 객체 B 를 만들어 버린다 = Parameterized Ctor
	*/
	Integer B = Func2(1, 1);

	/*
		Release Mode 를 사용하는 경우,
		함수에서 리턴하기 위해 만드려는 임시 객체를 미리 파악, 임시 객체는 만들지 않고
		인수만 사용해서, 바로 객체 A, B 를 만들어 버린다 = Para Ctor 를 각각 한번만 사용한다
	*/
}