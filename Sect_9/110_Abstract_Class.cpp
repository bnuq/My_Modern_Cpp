#include <iostream>
using namespace std;

class A 
{
public:
	virtual void func1() = 0;
	
};

class B final : public A
{
public:
	void func1() override final
	{
		cout << "B :: func1" << endl;
	}
};



int main()
{
	B bb{};
	bb.func1();
}