#include <iostream>

class Test {
	int data{};
public:
	/*
		Primitive -> User Defined Type
		해당 primitive type 을 받는 적절한 생성자가 있으면 가능하다
		적절한 생성자가 있다면, compiler 가 implicit conversion 사용
		해당 Primitive 를 받는 생성자를 자동으로 실행 => 해당 클래스 객체를 만들어서 사용한다
	*/
	Test(int n) : data{ n } {}
	Test(float n) : data{ static_cast<int>(n) } {}
	/*
		생성자에 explicit keyword 사용
		컴파일러가 자동으로 primitive => 해당 객체를 만드는 작업을 못하게 막는다
		명시적으로 해당 생성자를 호출할 때만, 생성자를 사용하도록 한다
	*/
	explicit Test(double d) {
		std::cout << "Test(double)" << std::endl;
	}


	/*
		User -> Primitive
		Type Operator 를 사용
		No return type
		No arguments
		return Primitive type
	*/
	operator double() {
		std::cout << "operator double" << std::endl;
		return static_cast<double>(data);
	}
	/*
		역시나 explicit keyword 를 사용할 수 있다
		=> 컴파일러가 자동으로 타입변환을 해주지 않는다.
		명시적으로 타입변환을 써야한다
	*/
	explicit operator int() {
		std::cout << "operator int" << std::endl;
		return data;
	}
};


void func1(const Test& t) {
	
}
void func2(Test t) { // 함수에서 인자로 받은 9.9f 를 이용해서 Test{9.9f} 를 만들어 사용

}

int main() {
	// Initializaion
	Test t = 5; // Test(int) 사용
	Test tt = 5.5f; // Test(float) 사용 or flaot->int 변환 후, Test(int) 사용

	const Test ttt = 10; 

	// Assignment
	tt = 10.1f; // Test{10.1f} 를 만든다음, Assignment 실행

	func1(10); // Test{ 10 } 을 만들고, func 의 t 가 이 객체를 가리키는 방식
	func2(9.9f);

	// 그냥 double 타입으로 초기화 하려 한 경우
	// 원래 같으면 컴파일러가 자동으로 9.9 => Test{ 9.9 } 를 만들어주어야 하지만
	// double 을 받는 생성자의 경우 explicit => 명시적으로 생성자를 호출해야만 사용가능하게 제한이 걸렸다
	// 따라서 에러가 발생
	// double -> float 로 자동으로 변환해주지 않는구나
	// 
	// Test t1 = 9.9;
	Test t2{ 8.8 }; // 명시적으로 생성자를 사용함


	// User -> Primitive
	double a = t; // 자동으로 컴파일러가 t->double type 으로 변환해줌
	int n = static_cast<int>(t); // int 로 바꾸려는 경우, explicit => static_cast 를 통해 명시적으로 타입변환 명시
	int m{ t }; // 근데 uniform initialization 쓰면 타입변환까지 명시적으로 된다...
}