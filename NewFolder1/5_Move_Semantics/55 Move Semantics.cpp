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
	m_pInt = new int(*obj.m_pInt); // Deep Copy => �޸𸮿� ����ִ� ���� �����Ѵ�
}
Integer::Integer(Integer&& obj) noexcept {	// Move Constructor => r-value ����
	std::cout << "Integer(int&&)" << std::endl;
	m_pInt = obj.m_pInt;	// ���� r-value �޸𸮸� ����Ű��
	obj.m_pInt = nullptr;	// r-value �� �ƹ��͵� ����Ű�� �ʴ´�
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


// Temporary Object, r-value �� �����ϴ� �Լ�
Integer Add(const Integer& a, const Integer& b) {
	Integer temp;
	temp.SetValue(a.GetValue() + b.GetValue());
	return temp;
}



int main() {
	Integer a(1), b(3);

	/*
		Add �Լ��� ��� ���� ��������, �ش� ��� ���� ������ �ӽ� ��ü�� ������ �Ѵ�
		�׷��� �ӽ� ��ü�� ��� ���� ���̳�
		Add �Լ��� ���� ���� r-value �ϱ�, r-value �� �޴� constructor �� �̿� => �ӽ� ��ü�� ����µ�
		== Move Constructor
	*/
	a.SetValue(Add(a, b).GetValue());
	return 0;
}