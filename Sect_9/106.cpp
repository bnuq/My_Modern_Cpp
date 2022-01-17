#include <iostream>

class Zip final
{

};

class A {};
class B final {};

class C : public A {};
//class D : public B {};


class Documnet
{
public:
	virtual void serialize(int v)
	{
		using namespace std;
		cout << "Overrided Document::serialize" << endl;
	}
	
	void serialize(float v)
	{
		using namespace std;
		cout << "Document::serialize" << endl;
	}
};

class Text : public Documnet
{
public:
	void serialize(int v) override final
	{
		using namespace std;
		cout << "Text::serialize" << endl;
	}
};


class HyperText : public Text 
{
public:
	void serialize(int v) override
	{
		using namespace std;
		cout << "HyperText::serialize" << endl;
	}
};
int main()
{
	Text t{};
	Documnet& p = t;

	p.serialize(0.9f);
	p.serialize(10);

	HyperText h{};
	Documnet& q = h;

	q.serialize(10);

}