#include <iostream>
using namespace std;

class A { // Abstract Class = pure virtual function �� ������ Ŭ����
		  // Abstract Class cannot be instantiated
public:
	// pure virtual function => ���Ǹ� ���� �ʴ´�, child class �� �ݵ�� ������ �ϵ��� �Ѵ�
	// �׷��� �ݵ�� child class �� ����Լ��� ����ǵ��� �Ѵ�
	virtual void func1() = 0;
};

class B final : public A {
public:
	// child class ���忡����, �ݵ�� �� ����Լ��� �������ϵ��� ����޴´�
	void func1() override final
	{
		cout << "B :: func1" << endl;
	}
};



int main() {
	B bb{};
	A& refA = bb;

	// base class �� ����Ű�� ���۷��� => virtual function ȣ�� => child class �� ����Լ� ȣ��
	refA.func1();

	cout << typeid(refA).name() << endl;
}