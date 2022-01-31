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
// ���� ��ü�� const reference �� �̿��� ��
Integer::Integer(const Integer& obj) {
	std::cout << "Integer(const Integer&)" << std::endl;
	// Deep Copy, ������ ����
	m_pInt = new int{ *obj.m_pInt };
}

// Move Constructor => noexcept => ����, ���� ��� ���´�
// �Լ� ���� ��üó��, �ӽ� ��ü�� �̿��� ��
Integer::Integer(Integer && obj) noexcept {
	std::cout << "Integer(int&&)" << std::endl;
	// Shallow Copy, �ּ� ���� ��������
	// ���� ���� null
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






