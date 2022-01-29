/*
	쓸 때마다, 파일에 덮어쓰나봐
*/
#include <iostream>
#include <fstream>
#include <string>

void Write()
{
	std::ofstream out{ R"(./Sect_11/06_data.txt)" };
	if (!out)
	{
		std::cout << "Could not open file for writing" << std::endl;
		return;
	}

	std::string message{ "C++ was invented by Bjarne" };
	for (auto ch : message)
		out.put(ch); // 한 글자씩 ofstream 에 넣는다 = put

	// put pointer 위치 지정
	out.seekp(5);
	// character 넣기
	out.put('@');
}

void Read()
{
	std::ifstream input{ R"(./Sect_11/06_data.txt)" };
	if (!input)
	{
		std::cout << "Source file not found" << std::endl;
		return;
	}

	// put pointer 위치 설정
	input.seekg(10);
	input.seekg(10, std::ios::beg);
	input.seekg(10, std::ios::cur);
	input.seekg(-10, std::ios::end);

	// 현재 get pointer 위치 찾기
	std::cout << "Current position is: " << input.tellg() << std::endl;

	input.seekg(5);

	char ch{};
	while (input.get(ch)) // 한 글자씩 가져온다 = get 함수
	{
		std::cout << ch;
	}

	std::cout << std::endl << "Data text done" << std::endl << std::endl;
}

void UsingFstream()
{
	std::fstream stream{ R"(./Sect_11/06_file.txt)"};
	// 파일이 존재하지 않으면, 자동으로 만들지 않는다
	if (!stream)
	{
		std::cout << "FILE DOSE NOT EXIST. CREATE ONE" << std::endl;

		// 파일 직접 생성
		std::ofstream out{ R"(./Sect_11/06_file.txt)" };
		out.close();
		
		stream.open(R"(./Sect_11/06_file.txt)");
	}

	stream << "File text : Hello World" << std::endl;
	// fstream 에 쓰고 난 후,
	// 현재 get, put pointers 모두 eof 에 있다

	stream.seekg(0); // get pointer 맨 앞에 세팅

	// 가져오기
	std::string line;
	std::getline(stream, line);

	std::cout << line << std::endl;
}

int main()
{
	Write();
	Read();

	UsingFstream();

	return 0;
}