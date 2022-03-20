#include <iostream>

class Test {
public:
	int data{ 100 };
	/*
		constant member function
		�����͸� �����غ�, const �� �̸� �ڿ� �����ϱ�
		�� ��� �Լ� ��ü�� constant => ��� �Լ��� ȣ���ϴ� ��ü ��ü�� constant ���
		this pointer �� ���ؼ� ��� ������ �ٲ� �� ����
	*/
	void constMemberFunc() const;

	void func() {
		std::cout << "func" << std::endl;
	}
};

void Test::constMemberFunc() const { // const ��ü�� Ÿ�Կ� ���ϱ� ������ => ���Ǹ� �� �� ���� ���־�� �Ѵ�
	// data++;	��� ������ �ٲٴ� ���� �Ұ���
	std::cout << "Constant Member Function Called" << std::endl;
}


int main() {
	Test t{};
	t.constMemberFunc();
	t.func();

	const Test tt{};
	tt.constMemberFunc();
	// tt.func();	const ��ü�� const member function �� ȣ�� ����
}