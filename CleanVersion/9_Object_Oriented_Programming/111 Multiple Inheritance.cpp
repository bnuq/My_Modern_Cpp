#include <iostream>
using namespace std;

class A
{
	int mA;
public:
	A(int m) : mA{m}
	{
		cout << "A constructor" << endl;
	}
	~A()
	{ 
		cout << "~A destructor" << endl;
	}


	virtual void func() = 0;
};

class Aa : virtual public A
{
	int mAa;

public:
	Aa(int ma, int mb) : mAa{ ma }, A{ mb }
	{
		cout << "Aa constructor" << endl;
	}
	~Aa()
	{
		cout << "~Aa destructor" << endl;
	}

	void func() override
	{
		cout << "Aa :: func" << endl;
	}
};


class Ab : virtual public A
{
	int mAa;

public:
	Ab(int ma, int mb) : mAa{ ma }, A{ mb }
	{
		cout << "Ab constructor" << endl;
	}
	~Ab()
	{
		cout << "~Ab destructor" << endl;
	}

	void func() override
	{
		cout << "Ab :: func" << endl;
	}
};



class C : public Aa, public Ab {
public:
	/*
		virtual inheritance 인 A class 에 대해서
		각 virtual pointer 가 A 객체를 가리켜야 한다
		따라서, 직접 생성자를 호출해서 => virtual pointer 가 하나의 A 객체를 가리키도록 한다
		
		이후 다른 base classes 생성자를 호출 => 이미 virtual pointer 가 가리키고 있으므로 A 생성자를 만들지는 않는다

		생성자들의 호출 순서는 상관없다
	*/
	C(int a, int b, int c) :  A{ a }, Aa{ b, a }, Ab{ c, a }
	{
		cout << "C constructor" << endl;
	}
	~C()
	{
		cout << "C destructor" << endl;
	}

	void func() override
	{
		cout << "C :: func()" << endl;
	}
};


int main()
{
	C temp{ 1,2,3 };
	A& refA = temp;

	refA.func();

	return 0;
}
