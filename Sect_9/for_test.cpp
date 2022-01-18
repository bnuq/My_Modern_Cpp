#include <iostream>
using namespace std;

class A
{

};

class B : public A
{
public:
	virtual void func()
	{
		cout << "B :: func" << endl;
	}
};

class C : virtual public B
{
public:
	
};

int main()
{
	B b1{};
	A& pa = b1;
	cout << typeid(pa).name() << endl;

	C c1{};
	B& pb = c1;
	cout << typeid(pb).name() << endl;


}