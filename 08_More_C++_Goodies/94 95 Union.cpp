#include <iostream>
#include <string>

union Test {
	// 3 가지 서로 다른 타입의 멤버들을, 하나의 메모리에 동시에 저장한다
	// => 그래서 가장 큰 멤버 사이즈 = Union 사이즈, 여기서는 double
	// 모두 public
	int x;
	char ch;
	double d;

	// Default Constructor 에서, 하나의 멤버만 초기화할 수 있다
	// 유효한 값을 가지는 멤버 => Active member
	// 알수 없는 값을 가지는 다른 멤버들 => Inactive members
	Test() : ch{ 'a' } {
		// 현재 실행중인 함수의 signiture 를 출력하는 매크로
		std::cout << __FUNCSIG__ << std::endl;
	}
	~Test() {
		std::cout << __FUNCSIG__ << std::endl;
	}
};


// 간단한 User Defined Types 2개
struct A {
	A() {
		std::cout << __FUNCSIG__ << std::endl;
	}
	~A() {
		std::cout << __FUNCSIG__ << std::endl;
	}

	A(const A& other) {
		std::cout << __FUNCSIG__ << std::endl;
	}

	A(A&& other) noexcept {
		std::cout << __FUNCSIG__ << std::endl;
	}

	A& operator=(const A& other) {
		std::cout << __FUNCSIG__ << std::endl;
		if (this == &other)
			return *this;
		return *this;
	}

	A& operator=(A&& other) noexcept {
		std::cout << __FUNCSIG__ << std::endl;
		if (this == &other)
			return *this;
		return *this;
	}
};
struct B {

	B() {
		std::cout << __FUNCSIG__ << std::endl;

	}
	~B() {
		std::cout << __FUNCSIG__ << std::endl;

	}

	B(const B& other) {
		std::cout << __FUNCSIG__ << std::endl;
	}

	B(B&& other) noexcept {
		std::cout << __FUNCSIG__ << std::endl;
	}

	B& operator=(const B& other) {
		std::cout << __FUNCSIG__ << std::endl;
		if (this == &other)
			return *this;
		return *this;
	}

	B& operator=(B&& other) noexcept {
		std::cout << __FUNCSIG__ << std::endl;
		if (this == &other)
			return *this;
		return *this;
	}

	// virtual function 을 가지고 있다
	virtual void Foo() {}
};


// User Defined types 를 가지는 Union
union UDT {
	A a;
	B b;
	std::string s;

	/*
		Union 의 각 멤버들이 모두 default constructor 와 default destructor 를 가지고 있다
		=> 둘 중 어느 것을 써야하는 지 모르기 때문에,
		Union 의 default ctor, default dtor 가 삭제된다
		따라서 유저가 직접 써주어야 한다
	*/
	UDT() {
		std::cout << __FUNCSIG__ << std::endl;
	}
	~UDT() {
		std::cout << __FUNCSIG__ << std::endl;
	}
};



int main() {
	std::cout << sizeof(Test) << std::endl;
	Test t ;
	// Union 객체를 만들었지만, 사용자 입장에서는 이 Union 이 어떤 멤버, 어떤 타입을 가지고 있는 지 알수가 없다
	std::cout << t.ch << std::endl;
	// t 의 int x 값을 수정했더니
	t.x = 1000 ;
	// t 의 다른 멤버 값이 달라진다 => 같은 메모리에 저장되다 보니까, 영향을 받는다
	std::cout << t.ch << std::endl; 
	


	UDT udt{};
	// 그냥 Union 을 만들기만 하면, 멤버들이 생성되지 않는다
	// 멤버들의 생성자를 직접 호출해서, user defined type members 를 직접 만들어야 한다
	
	// 메모리는 이미 할당했고, 할당한 메모리에 생성자를 호출해야 하는데
	// 이 작업을 new operator 를 통해서 진행한다
	new (&udt.a) A{}; // union 의 a 멤버를 위한 메모리에서, A 생성자를 호출
	udt.a.~A();		  // destructor 도 호출되지 않기 때문에, 직접 호출해주어야 한다
	
	// string member 의 예
	// using namespace std::string_literals;
	// new(&udt.s) std::string{"Hello world"} ;
}