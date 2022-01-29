/*
	txt ���� ����
*/
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

int main()
{
	using namespace std::filesystem;

	// ���� ���丮
	path source{ current_path() };
	// ���丮 �߰�
	source /= "Sect_11";
	// ���� ���� �߰�
	source /= "122_CopyUtility.cpp";

	path dest{ current_path() };
	dest /= "Sect_11";
	dest /= "122_Copy.cpp";

	std::cout << source << std::endl;

	std::ifstream input{ source };
	if (!input.is_open())
	{
		std::cout << "Source file not found" << std::endl;
		return -1;
	}

	std::ofstream output{ dest };

	std::string line;
	while (!std::getline(input, line).eof())
	{
		output << line << std::endl;
	}

	// �������� ���� �ݱ�
	input.close();
	output.close();
}
