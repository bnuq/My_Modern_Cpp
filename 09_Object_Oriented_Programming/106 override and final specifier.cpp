#include <iostream>


class A {};
/*
	final keyword
	Ŭ������ ����ϸ�
		�� Ŭ������ �������̴�, �� Ŭ���� �ؿ���, ���� �޴� Ŭ������ �������� �ʴ´ٴ� ��

	����Լ��� ����ϸ�
		�� ����Լ��� �������̴�, ���̻� �����Ǵ� �Ұ����ϴ�
*/
class B final {};

class C : public A {};
//class D : public B {}; final class �� B Ŭ������ ��� ���� �� ����


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
		�� ����Լ��� override �ϴ� ���̶�� ��, Ȯ���ϰ� ǥ���ϴ� ���
		�Լ��� �ñ״�ó�� Ȯ�� -> base class �� override �Ҹ��� �Լ��� �ִ� �� Ȯ�����ش�
		+ override �ϴ� ���� virtual function ���� Ȯ�����ش�

		virtual function �� �ƴϿ��� �����Ǵ� �� �� ������,
		override keyword �� ���� virtual function �� ����� �������ϰ� �ִ� ���� Ȯ�����ش�

		override = ���� virtual function �� �� �������ϰ� �ִ� ���� Ȯ�ν�Ű�� ����
	*/
	void serialize(int v) override {
		using namespace std;
		cout << "Text::serialize(int version)" << endl;
	}

	// virtual function �� �ƴϴ���, �����Ǵ� �� �� �ִ�
	// ��� base class �� ����Ű�� �����ͳ� ���۷����� �̿��� ��, ȣ������ ���� ��
	void serialize(float v)	{
		using namespace std;
		cout << "Text::serialize(float version)" << endl;
	}

	/*
	virtual function �� �ƴѵ� override �� ���� ������ �߻��Ѵ�
	virtual function �߿���, �ش� �Լ� �ñ״�ó�� �������� �ʱ� ������

	void serialize(float v) override { 
		using namespace std;
		cout << "Text::serialize(float version)" << endl;
	}
	*/
};
class HyperText : public Text {
public:
	/*
		����Լ��� final keyword
		���̻��� �����Ǵ� �Ұ����ϴٴ� ��
		override ó��, virtual function �� ���ؼ��� final �� ����� �� �ִ�
			�� ����Լ��� virtual �̶� �� child class ���� �������� �� �־�����,
			��������, �� �ؿ������ʹ� �������� �� ���ٴ� ��
	*/
	void serialize(int v) override final	{
		using namespace std;
		cout << "HyperText::serialize" << endl;
	}
};
class HyperHyperText : public HyperText {
public:
	/*
	��ӹ��� HyperText ���� �ش� ����Լ��� final �� ���±� ������,
	���̻� �����Ǵ� �Ұ����ϴ�

	void serialize(int v) override {
		using namespace std;
		cout << "HyperText::serialize" << endl;
	}
	*/
};



int main()
{
	Text t{};		  // child class
	Documnet& p{ t }; // base class �� child class �� ����Ŵ

	// virtual function ȣ�� => base class �� ���Ե� child class version �� ȣ��� ��
	/*
		float => child class ���� ������ ������, ���� base class �� ����Ű�� ������
		non-virtual ��� �Լ��� ȣ�������Ƿ�,
		base class �� ����Լ��� ȣ��ȴ�
	*/
	p.serialize(0.9f);  
	p.serialize(10);	// int => virtual function => child class ������ ȣ��ȴ�


	HyperText h{};		// child child class
	Documnet& q = h;	// base class
	q.serialize(10);	// int => virtual function => child class ������ ȣ��ȴ�


	HyperHyperText hht{};
	// int => virtual function, ������ ������ final �� �����߱� ������, ���������� ���ߴ�
	hht.serialize(9); // �ٷ� �� �θ��� HyperText :: serialize �� ȣ��ȴ�
	// virtual table ���� ����� �����, ���� �������� ����� HyperText �� ����Լ���?

}