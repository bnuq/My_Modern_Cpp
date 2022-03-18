#include <iostream>
#include <string>

int main() {

	/*
		���� string literal ��� => const char[] Ÿ��
		\ �� ���� Ư�����ڴ� ���Ұ� => escape sequence �� ���־�� �Ѵ�
	*/
	std::string oldfilename{ "C:\\temp\\newfile.txt" };
	std::cout << oldfilename << std::endl;

	/*
		Raw String Literal
		R"( -- )" �� ���� ���
		���� "" �� �տ� R �� �����ְ�
		() �ȿ� ���ϴ� ���ڿ��� ���´� 
		escape ���ڸ� �������� �ʾƵ� �ȴ�
	*/
	std::string filename{ R"(C:\temp\newfile.txt)"};
	std::cout << filename << std::endl;

	/*
		Raw String Literal with Delimiter
		����ǥ�� ��ȣ ���̿� Ư�� ����, delimiter �� ������ �� �ִ�
		�׷��� ���ڿ� ���ͷ� �߰��� ����ǥ�� ��ȣ�� ����, ���� ���� �� �� �ִ�
			delimiter ���п� ��谡 ��Ȯ�ϰ� ǥ���Ǵϱ�
	*/
	std::string message{ R"msgg(C++ indroduced filesystem API"(In C++17)")msgg" };
	std::cout << message << std::endl;


	return 0;
}