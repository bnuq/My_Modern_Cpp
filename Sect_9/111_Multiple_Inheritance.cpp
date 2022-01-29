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



class C : public Aa, public Ab
{
public:
	C(int a, int b, int c) : A{ a }, Aa{ b, a }, Ab{ c, a }
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
