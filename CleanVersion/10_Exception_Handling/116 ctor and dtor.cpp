#include <iostream>
#include <memory>
#include <vector>


class A {
public:
	A() {
		std::cout << "A()" << std::endl;
	}
	~A() {
		std::cout << "~A()" << std::endl;
	}
};
class B {
public:
	B() {
		std::cout << "B()" << std::endl;
	}
	~B() {
		std::cout << "~B()" << std::endl;
	}
};




class Test {
	std::unique_ptr<A> pA{};
	B b{};
	std::unique_ptr<int> pInt{};
	std::string pStr{};
	std::vector<int> pArr{};
public:
	/*
		생성자 내에서, exception 이 발생하는 경우
		생성자 함수에 대해서만 stack unwinding
		소멸자는 호출하지 않는다 => 만약 멤버 변수가 리소스를 할당한다면 정리가 되지 않는다
		
		따라서 멤버 변수에는 smart pointer 와 container 를 사용 => 리소스를 사용한다
		RAII concept 사용
	*/
	Test() {
		std::cout << "Test():Acquire resources" << std::endl;
		pA.reset(new A);

		/*
		* 직접 메모리를 할당하는 안좋은 예 => 예외 발생 시 memory leak
			pA = new A;
			pInt = new int;
			pStr = new char[1000];
			pArr = new int[50000];
		*/
	}
	/*
		소멸자 내에서 exception 이 발생하는 경우 => 그런 경우가 있어서는 안된다
		소멸자에서는 exception 이 발생해서는 안된다

		왜냐하면 stack unwinding 때 소멸자가 실행 => 그러면 또 exception 발생
		=> stack unwinding => 소멸자 호출 ...
	*/
	~Test() {
		std::cout << "~Test():Release resources" << std::endl;
		
		// 만약 소멸자 내에서 예외가 발생하더라도, 소멸자 내에서 처리를 반드시 해야한다
		try {
			throw std::runtime_error("Failed to initialize");
		}
		catch (std::exception& ex) {
			std::cout << "Processing an exception : " << ex.what() << std::endl;
		}
				
		/*
			delete pA;
			delete pInt;
			delete[]pStr;
			delete[] pArr;
		*/
	}
};

int main() {
	try {
		Test t;

		// exception 발생 => stack unwinding => Test t 객체를 정리한다
		throw std::runtime_error{ "Exception" };
	}
	catch (std::runtime_error& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}