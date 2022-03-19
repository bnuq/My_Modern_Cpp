/*
	122 Copy Utility.cpp ���� ������
	�״�� �����Դ�
*/
#include <iostream>
#include <string>

// ifstream, ofstream ���
#include <fstream>

// path ���
#include <filesystem>

int main()
{
	using namespace std::filesystem;

	// filesystem :: current_path() => ���� ������ ���� ��� ����
	// visual studio ������ �ַ���� ���� ��� ����
	std::cout << "Current path is " << current_path() << std::endl;

	// ���� ���丮
	path source{ current_path() };

	// �����ϰ��� �ϴ� ������ ��θ� ��������
	// /= �����ڸ� ���� / �� �߰��� �� �ִ�
	// ���丮 ���� �� ���� ���
	source /= R"(122 Source.cpp)"; // raw string literal ���


	// ���� ����Ǵ� ������ ��θ� �����Ѵ�
	path dest{ current_path() };
	dest /= R"(122 Copy.cpp)";


	std::cout << "Source file path is " << source << std::endl;


	/*
		source file path �� �����ϴ� file ��
		input file stream �� ����
		file -> stream ���� input ~
		���� ������ �д´�
	*/
	std::ifstream input{ source };
	if (!input.is_open()) { // �ش� ��ΰ� �������� �ʾƼ�, ������ �� �� ���
		std::cout << "Source file not found" << std::endl;
		return -1;
	}


	/*
		output file path �� �����ϴ� file ��
		output file stream �� ����
		file <- stream, output ~
		���Ͽ� ������ ����
	*/
	std::ofstream output{ dest };


	std::string line{};
	// ifstream => stream �� ���ؼ� ���� ������ �д´�
	// string �� ���� ���� �����ؼ� �� ��������, getline()
	while (!std::getline(input, line).eof()) { // getline :: eof() => ������ ���� �����ߴ� �� Ȯ��
		// ofstream => stream �� ���ؼ� ���Ϸ� ������ ��������
		// output file stream �� string �� �Է��Ѵ�
		output << line << std::endl;
	}


	// �������� ���� �ݱ�
	input.close();
	output.close();
}
