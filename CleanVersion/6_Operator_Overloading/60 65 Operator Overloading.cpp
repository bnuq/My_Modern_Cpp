#include <iostream>

/* Integer.h */
class Integer {
	int* m_pInt;
public:
	//Default constructor
	Integer();
	//Parameterized constructor
	Integer(int value);
	//Copy constructor
	Integer(const Integer& obj);
	//Move constructor
	Integer(Integer&& obj) noexcept;

	int GetValue()const;
	void SetValue(int value);
	~Integer();

	/*
		pre-increment 와 post-increment 의 차이
		pre-increment => 인수가 하나만 필요하다
		post-increment => 연산자가 뒤에 위치해야 한다
					   => 따라서 가짜 인수를 하나 만들어서,
					   반드시 연산자가 증가시키고자 하는 객체 뒤에 오도록 만든다
					   ==> Integer ++ (int)
	*/
	Integer& operator ++();
	Integer operator ++(int);

	// Operator Overloading
	bool operator ==(const Integer& a)const;
	Integer operator +(const Integer& a)const;
	// function call operator
	void operator ()();

	/*
		Assignment Operator
		= 다른 객체의 값을 이용해서, 현재 객체의 값을 바꾼다
		= 값을 바꾼 현재 객체를 리턴한다 => return by reference
	*/
	//Copy assignment
	Integer& operator =(const Integer& a);
	//Move assignment
	Integer& operator =(Integer&& a) noexcept;


	/*
		friend function
		클래스의 멤버함수가 아닌, 외부 함수 중에서
		클래스의 모든 멤버에 접근 가능하도록 지정할 수 있다
		friend 외부함수 => 외부함수가 이 클래스에 접근할 수 있다는 것을 알림
		일종의 장판 같은 거지 => 이 장판 위에서는 다 접근할 수 있다

		friend 는 타입에 속하지 않아 => declaration 에서만 적어준다
	*/
	friend std::istream& operator >> (std::istream& input, Integer& a);

	// freidn class 도 지정할 수 있다
	friend class Printer;
};
Integer operator +(int x, const Integer& y);
std::ostream& operator <<(std::ostream& out, const Integer& a);

class Printer {
	Integer temp{};
public:
	void testFunc() {
		// Printer 클래스 내에서 Integer 의 모든 멤버에 접근할 수 있다
		// Printer 클래스, 멤버함수 전체가 다 장판~ 그냥 무조건 접근할 수 있게 된다
		*temp.m_pInt = 100;
	}
	void test2(Integer& i) {
		*i.m_pInt = 999;
	}
};


/* Integer.cpp */
Integer::Integer() {
	std::cout << "Integer()" << std::endl;
	m_pInt = new int(0);
}
Integer::Integer(int value) {
	std::cout << "Integer(int)" << std::endl;
	m_pInt = new int(value);
}
Integer::Integer(const Integer& obj) {
	std::cout << "Integer(const Integer&)" << std::endl;
	m_pInt = new int(*obj.m_pInt);
}
Integer::Integer(Integer&& obj) noexcept {
	std::cout << "Integer(int&&)" << std::endl;
	m_pInt = obj.m_pInt;
	obj.m_pInt = nullptr;
}

int Integer::GetValue() const {
	return *m_pInt;
}
void Integer::SetValue(int value) {
	*m_pInt = value;
}
Integer::~Integer() {
	std::cout << "~Integer()" << std::endl;
	delete m_pInt;
}

Integer& Integer::operator++() {
	++(*m_pInt);
	return *this; // 값을 변경한 현재 객체 자체를 리턴
}
Integer  Integer::operator++(int) {
	Integer temp(*this);
	++(*m_pInt);
	return temp; // 복사해둔 복사 객체를 리턴
}

// Assignment Operator
Integer& Integer::operator=(const Integer& a) {
	if (this != &a) { // 자기 자신에게 대입하는 경우는 제외한다
		delete m_pInt;
		m_pInt = new int(*a.m_pInt);
	}
	return *this;
}
Integer& Integer::operator=(Integer&& a) noexcept {
	if (this != &a) { // 자기 자신에게 대입하는 경우는 제외한다
		delete m_pInt;
		/*
			move 를 통해서 현재 객체에 새로운 값을 대입하는 과정
			shallow copy => 기존에 할당한 메모리를 그대로 이용한다
			r-value 가 다른 메모리를 가지지 못하도록 초기화 한다
		*/
		m_pInt = a.m_pInt;
		a.m_pInt = nullptr;
	}
	return *this;
}

// Operator Overloading
bool Integer::operator==(const Integer& a) const {
	return *m_pInt == *a.m_pInt;
}
// Integer + int = Integer.operator+(int) => Integer.operator+(Integer{int})
Integer Integer::operator+(const Integer& a) const {
	Integer temp;
	*temp.m_pInt = *m_pInt + *a.m_pInt;
	return temp;
}
// function call operator
void Integer::operator()() {
	std::cout << *m_pInt << std::endl;
}


// Global Overloads
// int + Integer => operator+(int, Integer)
Integer operator +(int x, const Integer& y) { 
	Integer temp;
	temp.SetValue(x + y.GetValue());
	return temp;
}
// 입출력
std::ostream& operator <<(std::ostream& out, const Integer& a) {
	out << a.GetValue();
	return out;
}
// 외부함수 이지만, Integer Class 의 friend function => 모든 멤버 변수에 접근이 가능하다
std::istream& operator >> (std::istream& input, Integer& a) {
	int x;
	input >> x;
	*a.m_pInt = x;
	// a.SetValue(x);
	return input;
}


/*
	Smart Pointer Basic
	smart pointer = 객체, 인데 포인터를 가지고 있는 객체다
	객체가 제거될 때, 자동으로 포인터를 정리해준다 => memory leak 을 막는다
*/
class IntPtr {
	// Heap Memory 주소를 저장하는 포인터를, 객체 내부에 가지고 있다
	Integer* m_p;

public:
	IntPtr(Integer* p) : m_p{ p } {

	}
	~IntPtr() { // dtor 를 통해서 포인터를 관리한다 => 자동으로 해제
		delete m_p;
	}

	// 객체를 이용해서, 간접적으로 포인터에 접근한다
	Integer* operator->() {
		return m_p;
	}
	Integer& operator*() {
		return *m_p;
	}
};


void func1() {
	Integer i{ 9 };

	// std::cout << i << std::endl
	operator<<(std::cout, i).operator<<(std::endl);

	i(); // function call operator

	Printer p{};
	p.testFunc();
	p.test2(i);

	IntPtr ip{ new Integer() };
	ip->GetValue();
}


// smart pointer 사용
#include <memory> // smart pointer header file

int main() {
	// template argument => 포인터로 관리하고자 하는 타입을 명시한다
	// 객체로 객체를 관리한다, 이때 최종적으로 다루고자 하는 객체가 무엇인가?
	// 그리고 스마트 포인터 객체에 저장할 포인터 주소를 넘긴다
	std::unique_ptr<Integer> up{ new Integer };
	//auto p2{ up };  unique pointer => copy 가 금지되어 있다
	auto p3{ std::move(up) }; // move 를 통해서만, 다른 변수로 값을 이동시킬 수 있다
	// 이제 더이상 up 는 유효하지 않다


	// shared pointer => 하나의 메모리를 여러 스마트 포인터가 접근할 수 있다
	// reference count 값이 존재, 같은 메모리를 가리키는 객체가 늘어날 때마다 같이 증가
	// reference count 가 0 이 되는 순간, 메모리를 해제한다
	std::shared_ptr<Integer> sp{ new Integer };
	auto p4{ sp };
	// use_count() => reference count 값을 확인할 수 있다
	std::cout << p4.use_count() << std::endl;

	auto p5{ p4 };
	std::cout << p4.use_count() << std::endl;
}
