#include <iostream>

/*
	noexcept(true) => Not throw exception
		�׳� noexcept �� �ᵵ �ȴ�
		�׷��� ���ܰ� �߻��Ѵٸ� => ��� ����

	noexcept(false) => exception �� throw �� ���� �ִ�...
*/
void Test(int x)noexcept(false) {
	
	// library �Լ��� cout, endl �� ���
	// �ش� ���̺귯�� ��� �߿�, � exception �� �߻��� �� �˼� ����
	// ���� noexcept(true) ��� ������ �ȵȴ�
	std::cout << "x is " << x << std::endl;

	//throw x;
}


/*
	noexcept => operator �̱⵵ �ϴ�
			 => Ư�� �Լ��� noexcept true or noexcept false ������ �������ִ� �Լ�

	noexcept( Test(x) ) => ȣ���Ϸ��� Test(x) �Լ��� noexcept true ���� false ������
							�˷��ִ� ����

	�� ����� �ٽ� noexcept �� ��´� => �� Test �Լ��� noexcept ����� ���󰣴�
*/
int Sum(int x, int y)noexcept(noexcept(Test(x))) {
	
	// exception �� �߻��� ���� �ִ� ȣ��
	Test(x);

	return x + y; // ���⼭�� Ȯ���� exception �� �߻����� ���� ��
}


class A {
public:
	//Destructors are implicitly noexcept(true) in C++11
	~A() {
		// throw 3;
	}

	// Move Operations �� noexcept(true) ���� �Ѵ�
	// move constructor, move assignment
	// Containers �� Copy �� ��Ȳ���� Move �� �� ��ȣ�Ѵ�
	// ������, �̶� Move �� noexcpt(false) ��� Move �� ������� �ʰ� Copy �Ѵ�
};


int main() {
	A a;
	
	// boolalpha manipulator prints 0 & 1 as false & true
	// � �Լ�ȣ�⿡ noexcept operator ���� => noexcept true ���� false ���� Ȯ��
	// ������ �ش� �Լ��� ȣ������� �ʴ´�
	// �Ҹ��ڴ� �ݵ�� noexcept(true) �̴�
	std::cout << std::boolalpha << noexcept(Test(1)) << std::endl;
	std::cout << std::boolalpha << noexcept(a.~A()) << std::endl;


	try {
		Sum(3, 5);
		//Other statements
	}
	catch (int x) {
		std::cout << x << std::endl;
	}
}