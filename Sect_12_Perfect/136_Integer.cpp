#include "136_Integer.h"
#include <iostream>
// Default Constructor
Integer::Integer() {
	std::cout << "Integer()" << std::endl;
	m_pInt = new int{ 0 };
}

// Parameterized Constructor
Integer::Integer(int value) {
	std::cout << "Integer(int)" << std::endl;
	m_pInt = new int{ value };
}

// Copy Constructor
// 변수 객체나 const reference 를 이용할 때
Integer::Integer(const Integer& obj) {
	std::cout << "Integer(const Integer&)" << std::endl;
	// Deep Copy, 내용을 복사
	m_pInt = new int{ *obj.m_pInt };
}

// Move Constructor => noexcept => 선언, 정의 모두 적는다
// 함수 리턴 객체처럼, 임시 객체를 이용할 때
Integer::Integer(Integer && obj) noexcept {
	std::cout << "Integer(int&&)" << std::endl;
	// Shallow Copy, 주소 값을 가져오고
	// 기존 것을 null
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






