#include <iostream>


class A {};
/*
	final keyword
	클래스에 사용하면
		이 클래스가 마지막이다, 이 클레스 밑에서, 물려 받는 클래스는 존재하지 않는다는 뜻

	멤버함수에 사용하면
		이 멤버함수가 마지막이다, 더이상 재정의는 불가능하다
*/
class B final {};

class C : public A {};
//class D : public B {}; final class 인 B 클래스를 상속 받을 수 없다


class Documnet {
public:
	virtual void serialize(int v) {
		using namespace std;
		cout << "Document::serialize(int version)" << endl;
	}
	
	void serialize(float v)	{
		using namespace std;
		cout << "Document::serialize(float version)" << endl;
	}
};
class Text : public Documnet
{
public:
	/*
		override keyword
		이 멤버함수는 override 하는 것이라는 걸, 확실하게 표시하는 기능
		함수의 시그니처를 확인 -> base class 에 override 할만한 함수가 있는 지 확인해준다
		+ override 하는 것이 virtual function 인지 확인해준다

		virtual function 이 아니여도 재정의는 할 수 있지만,
		override keyword 는 내가 virtual function 을 제대로 재정의하고 있는 지를 확인해준다

		override = 내가 virtual function 을 잘 재정의하고 있는 지를 확인시키는 역할
	*/
	void serialize(int v) override {
		using namespace std;
		cout << "Text::serialize(int version)" << endl;
	}

	// virtual function 이 아니더라도, 재정의는 할 수 있다
	// 대신 base class 를 가리키는 포인터나 레퍼런스를 이용할 때, 호출하지 못할 뿐
	void serialize(float v)	{
		using namespace std;
		cout << "Text::serialize(float version)" << endl;
	}

	/*
	virtual function 이 아닌데 override 를 쓰면 에러가 발생한다
	virtual function 중에서, 해당 함수 시그니처가 존재하지 않기 때문에

	void serialize(float v) override { 
		using namespace std;
		cout << "Text::serialize(float version)" << endl;
	}
	*/
};
class HyperText : public Text {
public:
	/*
		멤버함수에 final keyword
		더이상의 재정의는 불가능하다는 뜻
		override 처럼, virtual function 에 대해서만 final 을 사용할 수 있다
			이 멤버함수가 virtual 이라 각 child class 에서 재정의할 수 있었지만,
			이제부터, 이 밑에서부터는 재정의할 수 없다는 뜻
	*/
	void serialize(int v) override final	{
		using namespace std;
		cout << "HyperText::serialize" << endl;
	}
};
class HyperHyperText : public HyperText {
public:
	/*
	상속받은 HyperText 에서 해당 멤버함수를 final 로 끝냈기 때문에,
	더이상 재정의는 불가능하다

	void serialize(int v) override {
		using namespace std;
		cout << "HyperText::serialize" << endl;
	}
	*/
};



int main()
{
	Text t{};		  // child class
	Documnet& p{ t }; // base class 로 child class 를 가리킴

	// virtual function 호출 => base class 가 포함된 child class version 이 호출될 것
	/*
		float => child class 에서 재정의 했지만, 현재 base class 를 가리키는 것으로
		non-virtual 멤버 함수를 호출했으므로,
		base class 의 멤버함수가 호출된다
	*/
	p.serialize(0.9f);  
	p.serialize(10);	// int => virtual function => child class 버전이 호출된다


	HyperText h{};		// child child class
	Documnet& q = h;	// base class
	q.serialize(10);	// int => virtual function => child class 버전이 호출된다


	HyperHyperText hht{};
	// int => virtual function, 이지만 위에서 final 을 정의했기 때문에, 재정의하지 못했다
	hht.serialize(9); // 바로 위 부모인 HyperText :: serialize 가 호출된다
	// virtual table 에서 덮어쓰고 덮어쓰다, 가장 마지막에 덮어쓴게 HyperText 의 멤버함수라서?

}