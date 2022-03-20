#include <iostream>
#include <string>

union Test {
	// 3 ���� ���� �ٸ� Ÿ���� �������, �ϳ��� �޸𸮿� ���ÿ� �����Ѵ�
	// => �׷��� ���� ū ��� ������ = Union ������, ���⼭�� double
	// ��� public
	int x;
	char ch;
	double d;

	// Default Constructor ����, �ϳ��� ����� �ʱ�ȭ�� �� �ִ�
	// ��ȿ�� ���� ������ ��� => Active member
	// �˼� ���� ���� ������ �ٸ� ����� => Inactive members
	Test() : ch{ 'a' } {
		// ���� �������� �Լ��� signiture �� ����ϴ� ��ũ��
		std::cout << __FUNCSIG__ << std::endl;
	}
	~Test() {
		std::cout << __FUNCSIG__ << std::endl;
	}
};


// ������ User Defined Types 2��
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

	// virtual function �� ������ �ִ�
	virtual void Foo() {}
};


// User Defined types �� ������ Union
union UDT {
	A a;
	B b;
	std::string s;

	/*
		Union �� �� ������� ��� default constructor �� default destructor �� ������ �ִ�
		=> �� �� ��� ���� ����ϴ� �� �𸣱� ������,
		Union �� default ctor, default dtor �� �����ȴ�
		���� ������ ���� ���־�� �Ѵ�
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
	// Union ��ü�� ���������, ����� ���忡���� �� Union �� � ���, � Ÿ���� ������ �ִ� �� �˼��� ����
	std::cout << t.ch << std::endl;
	// t �� int x ���� �����ߴ���
	t.x = 1000 ;
	// t �� �ٸ� ��� ���� �޶����� => ���� �޸𸮿� ����Ǵ� ���ϱ�, ������ �޴´�
	std::cout << t.ch << std::endl; 
	


	UDT udt{};
	// �׳� Union �� ����⸸ �ϸ�, ������� �������� �ʴ´�
	// ������� �����ڸ� ���� ȣ���ؼ�, user defined type members �� ���� ������ �Ѵ�
	
	// �޸𸮴� �̹� �Ҵ��߰�, �Ҵ��� �޸𸮿� �����ڸ� ȣ���ؾ� �ϴµ�
	// �� �۾��� new operator �� ���ؼ� �����Ѵ�
	new (&udt.a) A{}; // union �� a ����� ���� �޸𸮿���, A �����ڸ� ȣ��
	udt.a.~A();		  // destructor �� ȣ����� �ʱ� ������, ���� ȣ�����־�� �Ѵ�
	
	// string member �� ��
	// using namespace std::string_literals;
	// new(&udt.s) std::string{"Hello world"} ;
}