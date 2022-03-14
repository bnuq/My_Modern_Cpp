#include <iostream>

class Test {
	int data{};
public:
	/*
		Primitive -> User Defined Type
		�ش� primitive type �� �޴� ������ �����ڰ� ������ �����ϴ�
		������ �����ڰ� �ִٸ�, compiler �� implicit conversion ���
		�ش� Primitive �� �޴� �����ڸ� �ڵ����� ���� => �ش� Ŭ���� ��ü�� ���� ����Ѵ�
	*/
	Test(int n) : data{ n } {}
	Test(float n) : data{ static_cast<int>(n) } {}
	/*
		�����ڿ� explicit keyword ���
		�����Ϸ��� �ڵ����� primitive => �ش� ��ü�� ����� �۾��� ���ϰ� ���´�
		��������� �ش� �����ڸ� ȣ���� ����, �����ڸ� ����ϵ��� �Ѵ�
	*/
	explicit Test(double d) {
		std::cout << "Test(double)" << std::endl;
	}


	/*
		User -> Primitive
		Type Operator �� ���
		No return type
		No arguments
		return Primitive type
	*/
	operator double() {
		std::cout << "operator double" << std::endl;
		return static_cast<double>(data);
	}
	/*
		���ó� explicit keyword �� ����� �� �ִ�
		=> �����Ϸ��� �ڵ����� Ÿ�Ժ�ȯ�� ������ �ʴ´�.
		��������� Ÿ�Ժ�ȯ�� ����Ѵ�
	*/
	explicit operator int() {
		std::cout << "operator int" << std::endl;
		return data;
	}
};


void func1(const Test& t) {
	
}
void func2(Test t) { // �Լ����� ���ڷ� ���� 9.9f �� �̿��ؼ� Test{9.9f} �� ����� ���

}

int main() {
	// Initializaion
	Test t = 5; // Test(int) ���
	Test tt = 5.5f; // Test(float) ��� or flaot->int ��ȯ ��, Test(int) ���

	const Test ttt = 10; 

	// Assignment
	tt = 10.1f; // Test{10.1f} �� �������, Assignment ����

	func1(10); // Test{ 10 } �� �����, func �� t �� �� ��ü�� ����Ű�� ���
	func2(9.9f);

	// �׳� double Ÿ������ �ʱ�ȭ �Ϸ� �� ���
	// ���� ������ �����Ϸ��� �ڵ����� 9.9 => Test{ 9.9 } �� ������־�� ������
	// double �� �޴� �������� ��� explicit => ��������� �����ڸ� ȣ���ؾ߸� ��밡���ϰ� ������ �ɷȴ�
	// ���� ������ �߻�
	// double -> float �� �ڵ����� ��ȯ������ �ʴ±���
	// 
	// Test t1 = 9.9;
	Test t2{ 8.8 }; // ��������� �����ڸ� �����


	// User -> Primitive
	double a = t; // �ڵ����� �����Ϸ��� t->double type ���� ��ȯ����
	int n = static_cast<int>(t); // int �� �ٲٷ��� ���, explicit => static_cast �� ���� ��������� Ÿ�Ժ�ȯ ���
	int m{ t }; // �ٵ� uniform initialization ���� Ÿ�Ժ�ȯ���� ��������� �ȴ�...
}