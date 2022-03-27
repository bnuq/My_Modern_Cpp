/*
	String Stream
		IOstream �� ���
		internally maintain the string buffer
		all operations performed in string buffer

	#include <sstream> => �Ʒ� �͵��� ��� ���Եȴ�
		stringstream
		istringstream		only read
		ostringstream		only write
*/
#include <iostream>
#include <sstream> // String Stream

void num1() {
	int a{ 5 }, b{ 6 };
	int sum{ a + b };

	std::stringstream ss{};

	// string stream => can convert a primitive type to a string object
	// << operator �� �̿��ؼ� string buffer �� �������μ�
	// ������ primitive type �� string ���� �ٲ� �� �ִ�
	// create formatted string => ���ϴ� ������ string �� ����� �� ����
	ss << "Sum of " << a << " and " << b << " is : " << sum << std::endl;

	// ���� string stream �ȿ� ����ִ�, string �� ���� �� => str() method ���
	// str() method �� 2���� ��� ���
	std::string s = ss.str();		// 1. string buffer's string return
	std::cout << s << std::endl;

	ss.str("abcdef");				// 2. string buffer �� �缳��
	std::cout << ss.str() << std::endl;

	ss.str("");						// => string buffer clear
	ss << sum;	// string stream �� ���鼭, int => string ���� �ڵ� ��ȯ
	auto ssum = ss.str();
	std::cout << ssum << std::endl;

	// �ƴϸ� �Լ��� �̿�
	// to_string �Լ��� �̿��ϸ� ��� primitive type -> string ��ȯ ����
	auto ssum2 = std::to_string(sum);
	std::cout << ssum2 << std::endl;
}


void num2() {
	/*
		�ݴ�� string stream ���� string �� ���� �� �ִµ�
		�ַ� parsing �ϴµ� ����Ѵ�
	*/
	std::string data = "12 89 21";
	int a;
	std::stringstream ss;
	ss.str(data);	// set data string to string stream

	// fail method => fail bit check = set when fail to read any more input
	// �д� ���� �����ϸ� fail bit ���� �ٲ�µ�, �� ���� Ȯ��
	if (ss.fail()) return;

	while (ss >> a) { // string buffer ���� string �� �ϳ� �о� ��
					  // space, ������� delimiter �� ���
					  // ���� �� �ٷ� return false, fail bit �� �����Ѵ�

		// ���� �޴� ���� a �� int type �̹Ƿ� => stringstream ���� ���� ���� int �� �����Ѵ�
		std::cout << a << std::endl;
		// ��������� string buffer �� ����Ǿ� �ִ� string �� int �� �ٲپ���
	}

	// �Լ� �̿��ϴ� ���
	// �׷��� ��� �̹� string => primitive type ���� �ٲٴ� �Լ��� �����Ѵ�
	// stoi, �׸��� ��Ÿ ���
	int x = std::stoi("122");
	std::cout << x << std::endl;
}


#include <typeinfo> // type Ȯ�ο� �ʿ�
int main() {
	num2();

	std::string data{ "12 345 67" };
	std::stringstream ss{ data }; // string stream �� ���۸� string ���� �ٷ� �ʱ�ȭ
	/*
		string stream ���� ���� �о�� ��
		���� �޴� ������ Ÿ�Կ� ���缭, string stream ���� ���� �����͸� �����Ѵ�

		�� int type �� ������, string -> int �� �ٲپ� ����
		char type �� ������, string -> char �� �ٲپ� ����

		12, 345, 67
		1, 2, 3, 4, 5, 6, 7
	*/
	//int c{};
	char c{};
	while (ss >> c) {
		std::cout << typeid(c).name() << " : " // ������ Ÿ���� ���
				  << c << std::endl;
	}
}