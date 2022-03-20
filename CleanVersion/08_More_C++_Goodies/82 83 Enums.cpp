#include <iostream>
using namespace std;


/*
	Enumerated Type
	���� ���� �̸��� �ٿ��� ���
	��ũ�γ� ��� ���� ���� �ѹ��� ����� �� �ִ�
	������ ������ ���� ������
*/

/*
	enum ���� -> { } �߰�ȣ�� �ʱ�ȭ = uniform initialization
	enum type = Color
	enumulator = RED, GREEN, BLUE
	enumulator �� �ٸ� enum type �� enumulator �� �̸��� �ߺ��Ǹ� �ȵȴ�
 */
enum Color { RED, GREEN, BLUE };

// enumulator �̸� �ߺ� ����
// �׷��� �̷��� unscoped enum �� ���̻� ������� �ʴ´�
// enum Traffic { RED, GREEN, BLUE };


// �ռ� ������ Color = enumulated type = Ÿ��ó�� ����Ѵ� -> ���������δ� ���� ���
// enumerator �� enum type ���� ȥ�� ����� �� �ִ�
// => enumerator �� ������ enum type �� ����sksek => ��� �˶��� �ߴ� ����
void FillColor(Color color)
{
	// enumerator �� RED, GREEN, BLUE �� enum type Color ����, �ܵ������� ����� �� �ִ� => ����
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
	scoped enum => enumerator �� ������ ���ܳ���,
	enumerator �� ������ enumerated type ���η� �����ȴ�, enum type �� ����ؾ� �Ѵ�
	�ٱ����� enumerator �� �� �� ���� �ȴ�
	�ݵ�� enum type �� ���ؼ� enumerator ����

	enum class

	��ȣ���
*/
enum class Color2 {RED, GREEN, BLUE}; // ���� enumerator �� ���ĵ� ������ => enum type �� ���� ������ ����ϱ� ������
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

	FillColor2(c);
	// FillColor2(x);  integer -> enum type ���� �ڵ���ȯ �Ұ���
}


// enumerator �� ����Ǵ� Ÿ���� int �� �ƴ�, �ٸ� ������ Ÿ������ ������ �� �ִ�
// : => enum type �� ����Ǵ� Ÿ�� ����
// assignment => enumerator �� ���� ������ �� �ִ�, ���� ������ ������ 1 �� ����
enum class Color3 : long {RED = 100, GREEN, BLUE = 105};
// ��¥ ���� ������ �ƴϰ�, �ƽ�Ű �ڵ� ������ ����
enum class Color4 : char { RED = 'e', GREEN = 'g', BLUE };



int main()
{
	num_1();
	num_2();

	Color c1 = RED;
	std::cout << c1 << std::endl; // unscoped enum �� �Ͻ������� int �� �ڵ���ȯ => ����� ������

	Color3 c = Color3::GREEN;
	// std::cout << c << std::endl;  scoped enum ������,  enumerator �� ������ Ÿ������ ����ǵ� �ڵ����� int �� ��ȯ���� �ʴ´�
	std::cout << static_cast<int>(c) << std::endl; // 100 + 1 = 101 ���

}