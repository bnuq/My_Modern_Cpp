#include <iostream>
using namespace std;


/*
	Enumerated Type
	���� ���� �̸��� �ٿ��� ���
	��ũ�γ� ��� ���� ���� �ѹ��� ����� �� �ִ�
	������ ������ ���� ������

	use 'enum' keyword
	restricted range of values
	called symobolic constants, enumerator
		internally represented as undefined integral types
		enumerator -> integer, but not the other way
			Color c = Red; �� ��
			c = 1; -> �Ұ���
			c = static_cast<Color>(1);
			int x = Red; -> ����
	Defalut value = 0, but users can assign any value
	������ �������� 1 �� ����
	Enumerator visible in which defined
*/


// enum ���� -> { } �߰�ȣ�� �ʱ�ȭ = uniform initialization
// enum type �� enumulator �� ������ ���� -> enumulator �̸��� ������ �ߺ��̴�
enum Color { RED, GREEN, BLUE };

// enumulator �̸� �ߺ� ����
// �׷��� unscoped enum �� ���̻� ������� �ʴ´�
// enum Traffic { RED, GREEN, BLUE };


// �ռ� ������ enum = enumulated type = Ÿ��ó�� ����Ѵ� -> ���������δ� ���� ���
// enumerator �� ������ Ÿ���� ����ϱ�, ��� �˶��� ���Դ�
void FillColor(Color color)
{
	if (color == RED) {
		cout << "RED" << endl;
	}
	if (color == GREEN) {
		cout << "GREEN" << endl;
	}
	if (color == BLUE) {
		cout << "BLUE" << endl;
	}
}


void num_1() {
	// Enumulator ����
	
	Color c = RED;
	
	// ���ǵ� enum type �� �ѱ� �� �ִ�
	FillColor(c);
	FillColor(GREEN);

	// integer -> enum �� �����Ǿ� �־, �������� �ѱ� �� ����
	// FillColor(1);

	// �ƴϸ� static_cast �� ���� ��������� Ÿ�Ժ�ȯ�� ����
	FillColor(static_cast<Color>(2));

}



/*
	scoped enum
	enumerator �� ������ enumerated type ���η� �����Ǵ� ��
	�ٱ����� enumerator �� �� �� ���� �ȴ�
	�ݵ�� enum type �� ���ؼ� enumerator ����

	enum class

	��ȣ
*/
enum class Color2 {RED, GREEN, BLUE}; // ���� enumerator �� ���ĵ� ������
enum class Traffic { RED, GREEN, BLUE };


void FillColor2(Color2 color)
{
	// scoped enum's enumerator ����� ���ؼ��� ��� Ÿ�Կ� ���ϴ� ���� �˷��� �Ѵ�
	if (color == Color2::RED) {
		cout << "RED" << endl;
	}
	if (color == Color2::GREEN) {
		cout << "GREEN" << endl;
	}
	if (color == Color2::BLUE) {
		cout << "BLUE" << endl;
	}
}


void num_2() {
	// scoped enum => enumerator, doesn't implicitly convert to integer
	// int x = Color2::RED; compile error

	// ����� Ÿ�� ��ȯ�� ���
	int x = static_cast<int>(Color2::RED);
	Color2 c = static_cast<Color2>(2);
}



// enumerator �� ����Ǵ� Ÿ���� int �� �ƴ�, �ٸ� Ÿ�����ε� ������ �� �ִ�
// �׷��� �ϴ� ������ Ÿ���̿��� ����
// : => enum type �� ����Ǵ� Ÿ�� ����
// assignment => enumerator �� ���� ������ �� �ִ�, ���� ������ ������ 1 �� ����
enum class Color3 : long {RED = 100, GREEN, BLUE = 105};
// ��¥ ���� ������ �ƴϰ�, �ƽ�Ű �ڵ� ������ ����
enum class Color4 : char { RED = 'e', GREEN = 'g', BLUE };



int main()
{
	num_1();
	num_2();
}