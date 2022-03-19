// ofstream => 파일에 쓸때마다, 파일을 초기화하는 듯?

#include <iostream>
#include <fstream>
#include <string>


void Write() {
	// ofstream => path 에 해당하는 file 을 연다
	// 없으면 만들어서 연다
	std::ofstream out{ R"(./Files/123 data.txt)" };
	if (!out) { // ofstream 이 file 여는 데 실패한 경우
		std::cout << "Could not open file for writing" << std::endl;
		return;
	}


	std::string message{ "C++ was invented by Bjarne" };
	// string => iterator 지원 => Range Base For Loop 로 각 문자를 가리킬 수 있다
	for (auto ch : message)
		// ofstream :: put() => char 하나씩 ofstream 에 넣는다
		out.put(ch);

	// ofstrea :: seekp() => seek to put
	// ofstream 이 입력할 pointer 위치 지정
	out.seekp(5);

	// put() 를 이용하면, ofstream pointer 가 가리키는 위치에 character 를 넣을 수 있다
	out.put('@'); // 포인터 위치에 char 덮어쓰기
	// 입력 후 포인터는 자동으로 다음 위치로 이동한다
	out.put('*'); // 다음 위치에 char 덮어쓰기
}



void Read() {
	std::ifstream input{ R"(./Files/123 data.txt)" };
	if (!input)	{
		std::cout << "Source file not found" << std::endl;
		return;
	}

	
	// ifstream :: seekg() => seek to get
	// ifstream 이 읽어올 pointer 위치를 지정할 수 있다
	// 절대 위치, 인덱스
	input.seekg(10);

	// 상대적 위치를 지정할 수도 있다
	input.seekg(10, std::ios::beg);		// 파일의 처음 기준
	input.seekg(10, std::ios::cur);		// 현재 pointer 위치 기준
	input.seekg(-12, std::ios::end);	// 파일 끝 기준

	// ifstream :: tellg()
	// 현재 ifstream 의 get pointer 위치 찾기
	std::cout << "Current position is: " << input.tellg() << std::endl;

	//input.seekg(5);

	char ch{};
	// ifstream :: get()
	// 현재 포인터가 가리키는 위치의 char 를 가져와서, 저장한다
	while (input.get(ch)) {
		std::cout << ch;
	}

	std::cout << std::endl << "Data text done" << std::endl << std::endl;
}



// fstream => 혼자서 input, output 모두 가능
void UsingFstream() {

	// file 과 stream 을 연결
	std::fstream stream{ R"(./Files/123 file.txt)"};
	

	// 그냥 stream 의 경우, 파일이 존재하지 않으면 자동으로 만들지 않는다
	if (!stream) {
		std::cout << "FILE DOSE NOT EXIST. CREATE ONE" << std::endl;

		// 파일 직접 생성
		std::ofstream out{ R"(./Files/123 file.txt)" };
		out.close();
		

		// file stream 생성 후, open() 로 파일 연결
		stream.open(R"(./Files/123 file.txt)");
	}


	// ofstream 처럼, 자연스럽게 << 연산자로 문자열을 쓸 수 있다
	stream << "File text : Hello World" << std::endl;
	stream << "This is my text" << std::endl;
	// fstream 에 쓰고 난 후,
	// 현재 get, put pointers 모두 eof 에 있다


	stream.seekg(0); // get pointer 맨 앞에 세팅
	// 가져오기
	std::string line;
	while(!std::getline(stream, line).eof())
		std::cout << line << std::endl;
}

int main()
{
	Write();
	Read();

	UsingFstream();

	return 0;
}