/*
	�ؽ�Ʈ ������ �����ϴ� �ڵ�
	.cpp, .txt �� ���ڿ��� ����Ǵ� ���� = �ؽ�Ʈ ����
	����� ���� �� �ִ� ���ڿ� �״�� �����Ѵ�

	������ �����͸� �аų� �� ��, �׻� ���ڿ� ���·� �̵�
	���� ���Ŀ� ���� �������� ��ȯ�� �Ͼ��

	�����͸� ���ڿ��� �ٲپ, ���ڿ� ���·� �����Ѵ�
*/
#include <iostream>
#include <string>

// ifstream, ofstream ���
#include <fstream>

// path ���
#include <filesystem>

int main() {
	using namespace std::filesystem;

	// filesystem :: current_path() => ���� ������ ���� ��� ����
	// visual studio ������ �ַ���� ���� ��� ����
	std::cout << "Current path is " << current_path() << std::endl;

	// ���� ���丮
	path source{ current_path() };

	// �����ϰ��� �ϴ� ������ ��θ� ��������
	// /= �����ڸ� ���� / �� �߰��� �� �ִ�
	// ���丮 ���� �� ���� ���
	// raw string �� raw string literal ȥ�� ����
	source /= "Files";
	source /= R"(122 Source.cpp)"; // raw string literal ���

	std::cout << "Source file path is " << source << std::endl;


	// ���� ����Ǵ� ������ ��θ� �����Ѵ�
	path dest{ current_path() };
	dest /= "Files";
	dest /= R"(122 Copy.cpp)";
	


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
	// getline() �� ���п��ΰ� �ƴ�, getline :: eof() �� ���� ������ �� Ȯ��
	while (!std::getline(input, line).eof()) { // getline :: eof() => ������ ���� �����ߴ� �� Ȯ��
		// ofstream => stream �� ���ؼ� ���Ϸ� ������ ��������
		// output file stream �� string �� �Է��Ѵ�
		output << line << std::endl;
	}


	// �������� ���� �ݱ�
	input.close();
	output.close();
}
