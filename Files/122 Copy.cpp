/*
	122 Copy Utility.cpp 파일 내용을
	그대로 가져왔다
*/
#include <iostream>
#include <string>

// ifstream, ofstream 사용
#include <fstream>

// path 사용
#include <filesystem>

int main()
{
	using namespace std::filesystem;

	// filesystem :: current_path() => 현재 파일의 절대 경로 리턴
	// visual studio 에서는 솔루션의 절대 경로 리턴
	std::cout << "Current path is " << current_path() << std::endl;

	// 현재 디렉토리
	path source{ current_path() };

	// 복사하고자 하는 파일의 경로를 지정하자
	// /= 연산자를 통해 / 를 추가할 수 있다
	// 디렉토리 구분 및 파일 명시
	source /= R"(122 Source.cpp)"; // raw string literal 사용


	// 이제 복사되는 파일의 경로를 지정한다
	path dest{ current_path() };
	dest /= R"(122 Copy.cpp)";


	std::cout << "Source file path is " << source << std::endl;


	/*
		source file path 에 존재하는 file 을
		input file stream 에 연결
		file -> stream 으로 input ~
		파일 내용을 읽는다
	*/
	std::ifstream input{ source };
	if (!input.is_open()) { // 해당 경로가 존재하지 않아서, 파일을 못 연 경우
		std::cout << "Source file not found" << std::endl;
		return -1;
	}


	/*
		output file path 에 존재하는 file 을
		output file stream 에 연결
		file <- stream, output ~
		파일에 내용을 쓴다
	*/
	std::ofstream output{ dest };


	std::string line{};
	// ifstream => stream 을 통해서 파일 내용을 읽는다
	// string 한 줄을 공백 포함해서 다 받으려면, getline()
	while (!std::getline(input, line).eof()) { // getline :: eof() => 파일의 끝에 도달했는 지 확인
		// ofstream => stream 을 통해서 파일로 내용을 내보낸다
		// output file stream 에 string 을 입력한다
		output << line << std::endl;
	}


	// 수동으로 파일 닫기
	input.close();
	output.close();
}
