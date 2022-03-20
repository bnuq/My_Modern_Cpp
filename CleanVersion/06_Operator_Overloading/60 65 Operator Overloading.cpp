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
		pre-increment �� post-increment �� ����
		pre-increment => �μ��� �ϳ��� �ʿ��ϴ�
		post-increment => �����ڰ� �ڿ� ��ġ�ؾ� �Ѵ�
					   => ���� ��¥ �μ��� �ϳ� ����,
					   �ݵ�� �����ڰ� ������Ű���� �ϴ� ��ü �ڿ� ������ �����
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
		= �ٸ� ��ü�� ���� �̿��ؼ�, ���� ��ü�� ���� �ٲ۴�
		= ���� �ٲ� ���� ��ü�� �����Ѵ� => return by reference
	*/
	//Copy assignment
	Integer& operator =(const Integer& a);
	//Move assignment
	Integer& operator =(Integer&& a) noexcept;


	/*
		friend function
		Ŭ������ ����Լ��� �ƴ�, �ܺ� �Լ� �߿���
		Ŭ������ ��� ����� ���� �����ϵ��� ������ �� �ִ�
		friend �ܺ��Լ� => �ܺ��Լ��� �� Ŭ������ ������ �� �ִٴ� ���� �˸�
		������ ���� ���� ���� => �� ���� �������� �� ������ �� �ִ�

		friend �� Ÿ�Կ� ������ �ʾ� => declaration ������ �����ش�
	*/
	friend std::istream& operator >> (std::istream& input, Integer& a);

	// freidn class �� ������ �� �ִ�
	friend class Printer;
};
Integer operator +(int x, const Integer& y);
std::ostream& operator <<(std::ostream& out, const Integer& a);

class Printer {
	Integer temp{};
public:
	void testFunc() {
		// Printer Ŭ���� ������ Integer �� ��� ����� ������ �� �ִ�
		// Printer Ŭ����, ����Լ� ��ü�� �� ����~ �׳� ������ ������ �� �ְ� �ȴ�
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
	return *this; // ���� ������ ���� ��ü ��ü�� ����
}
Integer  Integer::operator++(int) {
	Integer temp(*this);
	++(*m_pInt);
	return temp; // �����ص� ���� ��ü�� ����
}

// Assignment Operator
Integer& Integer::operator=(const Integer& a) {
	if (this != &a) { // �ڱ� �ڽſ��� �����ϴ� ���� �����Ѵ�
		delete m_pInt;
		m_pInt = new int(*a.m_pInt);
	}
	return *this;
}
Integer& Integer::operator=(Integer&& a) noexcept {
	if (this != &a) { // �ڱ� �ڽſ��� �����ϴ� ���� �����Ѵ�
		delete m_pInt;
		/*
			move �� ���ؼ� ���� ��ü�� ���ο� ���� �����ϴ� ����
			shallow copy => ������ �Ҵ��� �޸𸮸� �״�� �̿��Ѵ�
			r-value �� �ٸ� �޸𸮸� ������ ���ϵ��� �ʱ�ȭ �Ѵ�
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
// �����
std::ostream& operator <<(std::ostream& out, const Integer& a) {
	out << a.GetValue();
	return out;
}
// �ܺ��Լ� ������, Integer Class �� friend function => ��� ��� ������ ������ �����ϴ�
std::istream& operator >> (std::istream& input, Integer& a) {
	int x;
	input >> x;
	*a.m_pInt = x;
	// a.SetValue(x);
	return input;
}


/*
	Smart Pointer Basic
	smart pointer = ��ü, �ε� �����͸� ������ �ִ� ��ü��
	��ü�� ���ŵ� ��, �ڵ����� �����͸� �������ش� => memory leak �� ���´�
*/
class IntPtr {
	// Heap Memory �ּҸ� �����ϴ� �����͸�, ��ü ���ο� ������ �ִ�
	Integer* m_p;

public:
	IntPtr(Integer* p) : m_p{ p } {

	}
	~IntPtr() { // dtor �� ���ؼ� �����͸� �����Ѵ� => �ڵ����� ����
		delete m_p;
	}

	// ��ü�� �̿��ؼ�, ���������� �����Ϳ� �����Ѵ�
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


// smart pointer ���
#include <memory> // smart pointer header file

int main() {
	// template argument => �����ͷ� �����ϰ��� �ϴ� Ÿ���� ����Ѵ�
	// ��ü�� ��ü�� �����Ѵ�, �̶� ���������� �ٷ���� �ϴ� ��ü�� �����ΰ�?
	// �׸��� ����Ʈ ������ ��ü�� ������ ������ �ּҸ� �ѱ��
	std::unique_ptr<Integer> up{ new Integer };
	//auto p2{ up };  unique pointer => copy �� �����Ǿ� �ִ�
	auto p3{ std::move(up) }; // move �� ���ؼ���, �ٸ� ������ ���� �̵���ų �� �ִ�
	// ���� ���̻� up �� ��ȿ���� �ʴ�


	// shared pointer => �ϳ��� �޸𸮸� ���� ����Ʈ �����Ͱ� ������ �� �ִ�
	// reference count ���� ����, ���� �޸𸮸� ����Ű�� ��ü�� �þ ������ ���� ����
	// reference count �� 0 �� �Ǵ� ����, �޸𸮸� �����Ѵ�
	std::shared_ptr<Integer> sp{ new Integer };
	auto p4{ sp };
	// use_count() => reference count ���� Ȯ���� �� �ִ�
	std::cout << p4.use_count() << std::endl;

	auto p5{ p4 };
	std::cout << p4.use_count() << std::endl;
}
