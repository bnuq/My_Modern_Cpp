#include "Integer.h"
#include <iostream>
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
//Copy Assignment Operator
Integer& Integer::operator=(const Integer& obj)
{
	std::cout << "operator=(const Integer&)" << std::endl;

	// 자기 자신에게는 대입하지 않는다
	if (this != &obj)
	{
		delete m_pInt;
		m_pInt = new int{ *obj.m_pInt };
	}
	return *this;
}



//Move Opearation => noexcept
Integer::Integer(Integer&& obj) noexcept {
	std::cout << "Integer(int&&)" << std::endl;
	m_pInt = obj.m_pInt;
	obj.m_pInt = nullptr;
}
Integer& Integer::operator=(Integer&& obj) noexcept
{
	std::cout << "operator=(Integer&&)" << std::endl;

	// 자기 자신에게는 대입하지 않는다
	if (this != &obj)
	{
		delete m_pInt;
		m_pInt = obj.m_pInt;
		obj.m_pInt = nullptr;
	}
	return *this;
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

std::ostream& operator<<(std::ostream& out, const Integer& obj)
{
	out << *obj.m_pInt;
	return out;
}
