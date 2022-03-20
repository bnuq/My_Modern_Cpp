#include <iostream>

class Integer {
	int data{};
public:
	//Default constructor
	Integer() {	std::cout << "Default Ctor" << std::endl; }
	//Parameterized constructor
	Integer(int value) : data{ value } { std::cout << "Parameterized constructor" << std::endl; }

	//Copy constructor
	Integer(const Integer& obj) { std::cout << "Copy constructor" << std::endl; }
	Integer& operator=(const Integer& obj) = default;

	//Move constructor
	Integer(Integer&& obj) noexcept { std::cout << "Move constructor" << std::endl; }
	Integer& operator=(Integer&& obj) = default;

	~Integer() = default;
};


Integer Func1(int a, int b) {
	Integer temp{ a + b };
	return temp;	// Named Return Value Optimization
}
Integer Func2(int a, int b) {
	return Integer{ a + b };	// Return Value Optimization
}

int main() {
	/*
		Copy Elision = ���ʿ��� �ӽ� ��ü ������ ���� ��
		������, Func �Լ� ������ �ޱ� ���ؼ� �ӽ� ��ü�� ������ �Ѵ� = Move Ctor
		�׸��� ���� ���� �ӽð�ü�� �̿��ؼ� ��ü ���� = Move Ctor
	*/	
	/*
		������ �⺻���� Copy Elision �̿��ϸ�,
		�Լ��� �����ϴ� ���� �޴� �ӽ� ��ü�� ������ �ʰ�,
		�Լ��� �����ϴ� ���� �״�� �̿��ؼ� �ٷ� ��ü A �� ���� = Move Ctor
	*/
	Integer A = Func1(1, 1);

	/*
		�ƴϸ� �ƿ� Func2 �� �����Ϸ��� ����� �ӽ� ��ü ��ü�� ������ �ʰ�,
		�μ��� ���, �ٷ� ��ü B �� ����� ������ = Parameterized Ctor
	*/
	Integer B = Func2(1, 1);

	/*
		Release Mode �� ����ϴ� ���,
		�Լ����� �����ϱ� ���� ������� �ӽ� ��ü�� �̸� �ľ�, �ӽ� ��ü�� ������ �ʰ�
		�μ��� ����ؼ�, �ٷ� ��ü A, B �� ����� ������ = Para Ctor �� ���� �ѹ��� ����Ѵ�
	*/
}