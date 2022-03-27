#include <iostream>
using namespace std;

class A { // Abstract Class = pure virtual function 을 가지는 클래스
		  // Abstract Class cannot be instantiated
public:
	// pure virtual function => 정의를 하지 않는다, child class 가 반드시 재정의 하도록 한다
	// 그래서 반드시 child class 의 멤버함수가 실행되도록 한다
	virtual void func1() = 0;
};

class B final : public A {
public:
	// child class 입장에서는, 반드시 이 멤버함수를 재정의하도록 강요받는다
	void func1() override final
	{
		cout << "B :: func1" << endl;
	}
};



int main() {
	B bb{};
	A& refA = bb;

	// base class 를 가리키는 레퍼런스 => virtual function 호출 => child class 의 멤버함수 호출
	refA.func1();

	cout << typeid(refA).name() << endl;
}