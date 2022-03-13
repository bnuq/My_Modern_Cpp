#include <iostream>
/* Test.h */
class Test {
	int data{ 10 };
	int value{ 100 };

public:
	Test();
	Test(int d);
	Test(int d, int v);
};

/* Test.cpp */
/*
	Delegating Constructor
	�ٸ� �����ڸ� �̿��ؼ�, �� ������ ������ �ϴ� ��
	������ ���� �ڵ带 �� ������ ����� �� �ִ�

	Delegating ctor �� ���� �����ϰ� => ���Ŀ� �� �����ڸ� �����Ѵ�
*/
Test::Test() : Test(20) { // Test(ind d) ctor �� �̿�
	std::cout << "Test()" << std::endl;
}
Test::Test(int d) : Test(d, 200) { // Test(ind d, int v) �̿�
	std::cout << "Test(int d)" << std::endl;
}
Test::Test(int d, int v) : data{ d }, value{ v } {
	std::cout << "Test(int d, int v)" << std::endl;
}


int main() {
	Test t{ 30, 300 };

	Test tt{ 40 };

	Test ttt{};
}