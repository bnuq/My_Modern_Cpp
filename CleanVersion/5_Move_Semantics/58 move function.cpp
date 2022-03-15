#include <iostream>

class Integer {
	int data{};
public:
	//Default constructor
	Integer() { std::cout << "Default Ctor" << std::endl; }
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


void Print(Integer a) {

}


int main() {
	/*
		std::move function
		l-value �� �̿��ؼ� ��ü�� ���� ��, 
		���������� l-value �� ���ؼ� move constructor �� ����ϰ� �ϴ� ��
		== static_cast<Integer&&>(obj)

		���� l-value �� ����� �ӽ� ��üó��, ���̻� ������� ���ϰ� �ȴ�
	*/
	Integer i1{ 9 }; // Para Ctor

	Integer i2{ i1 }; // Copy Ctor

	Integer i3{ std::move(i1) }; // Move Ctor
	// ���� ���̻� i1 �� ����� �� ����, r-value ó�� ���Ʊ� ������ => ����� ���̳� ��������

	Print(std::move(i2)); // Print function �� �μ� Integer a �� ����� ��, i2 �� r-value ó�� ���ƴ�
	// ���� ���� i2 �� ����� �� ����
}