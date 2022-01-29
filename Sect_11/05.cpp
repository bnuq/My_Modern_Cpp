/*
	txt 파일 복사
*/
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

int main()
{
	using namespace std::filesystem;

	// 현재 디렉토리
	path source{ current_path() };
	// 디렉토리 추가
	source /= "Sect_11";
	// 현재 파일 추가
	source /= "05.cpp";

	path dest{ current_path() };
	dest /= "Sect_11";
	dest /= "05_Copy.cpp";

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

	// 수동으로 파일 닫기
	input.close();
	output.close();
}
