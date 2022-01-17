/*
	String Stream
		IOstream �� ���
		internally maintain the string buffer
		all operations performed in string buffer

	#include <sstream>
	stringstream
	istringstream		only read
	ostringstream		only write
*/

#include <iostream>
#include <sstream>

void num1() {
	int a{ 5 }, b{ 6 };
	int sum{ a + b };

	std::stringstream ss;

	// string stream => can convert a primitive type to a string object
	// << operator �� �̿��ؼ� string buffer �� �ִ´�
	// create formatted string
	ss << "Sum of " << a << " and " << b << " is : " << sum << std::endl;

	// str method => 2���� ��� ���
	std::string s = ss.str();		// 1. string buffer's string return
	std::cout << s << std::endl;

	ss.str("abcdef");				// 2. string buffer �� �缳��
	std::cout << ss.str() << std::endl;

	ss.str("");						// => string buffer clear
	ss << sum;
	auto ssum = ss.str();
	std::cout << ssum << std::endl; // int => string ���� ��ȯ

	// to_string �Լ��� �̿��ϸ� ��� primitive type -> string ��ȯ ����
	auto ssum2 = std::to_string(sum);
	std::cout << ssum2 << std::endl;
}


void num2() {
	/*
		�ݴ�� string stream ���� string �� �д� ���
		parsing �ϴµ� ���δ�
	*/
	std::string data = "12 89 21";
	int a;
	std::stringstream ss;
	ss.str(data);	// set data string to string stream

	// fail method => fail bit check = set when fail to read any more input
	// �д� ���� �����ϰ� ����, fail bit ���� �ٲ�� �װ� Ȯ��
	ss.fail();
	while (ss >> a) { // string buffer ���� string �� �ϳ� �о� ��
					  // space �� delimiter �� ���
					  // ���� �� �ٷ� return false, fail bit �� �����Ѵ�
		// int a => stringstream ���� ���� ���� int �� �����Ѵ�
		std::cout << a << std::endl;

		// ��������� string buffer �� ����Ǿ� �ִ� string �� int �� �ٲپ���
	}


	// �׷��� ��� �̹� string => primitive type ���� �ٲٴ� �Լ��� �����Ѵ�
	// stoi, �׸��� ��Ÿ ���
	int x = std::stoi("122");
	std::cout << x << std::endl;
}


int main() {
	num2();
}