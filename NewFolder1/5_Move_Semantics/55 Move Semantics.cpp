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
};


/* Integer.cpp */
Integer::Integer() {	// Default Constructor
	std::cout << "Integer()" << std::endl;
	m_pInt = new int(0);
}
Integer::Integer(int value) {	// Parameterized Constructor
	std::cout << "Integer(int)" << std::endl;
	m_pInt = new int(value);
}
Integer::Integer(const Integer& obj) {	// Copy Constructor
	std::cout << "Integer(const Integer&)" << std::endl;
	m_pInt = new int(*obj.m_pInt); // Deep Copy => 메모리에 들어있는 값을 복사한다
}
Integer::Integer(Integer&& obj) noexcept {	// Move Constructor => r-value 전용
	std::cout << "Integer(int&&)" << std::endl;
	m_pInt = obj.m_pInt;	// 내가 r-value 메모리를 가리키고
	obj.m_pInt = nullptr;	// r-value 는 아무것도 가리키지 않는다
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


// Temporary Object, r-value 를 리턴하는 함수
Integer Add(const Integer& a, const Integer& b) {
	Integer temp;
	temp.SetValue(a.GetValue() + b.GetValue());
	return temp;
}



int main() {
	Integer a(1), b(3);

	/*
		Add 함수의 결과 값을 받으려면, 해당 결과 값을 가지는 임시 객체를 만들어야 한다
		그러면 임시 객체를 어떻게 만들 것이냐
		Add 함수의 리턴 값이 r-value 니까, r-value 를 받는 constructor 를 이용 => 임시 객체를 만드는데
		== Move Constructor
	*/
	a.SetValue(Add(a, b).GetValue());
	return 0;
}