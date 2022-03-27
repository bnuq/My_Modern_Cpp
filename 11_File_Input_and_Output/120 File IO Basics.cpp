#include <iostream>
#include <fstream> // write/read file stream
#include <string>


void Write() {
	/*
		ofstream, ouput stream
		file 에 output => 내보내는 역할, 파일에 쓰는 역할
	*/
	// 초기화를 하면서 path 를 지정하거나
	//std::ofstream out{ "data.txt" };

	// 생성 후, open() method => path 지정
	std::ofstream out{};
	// 해당 path 에 원하는 file 이 없으면,
	// output 하기 위해서 하나 만든다
	out.open(R"(./Files/120 data.txt)");

	// << operator 로 원하는 값을 파일로 내보낸다, out
	out << "Hello world" << std::endl;
	out << 100 << std::endl;
	
	out.close(); // file stream 닫기
}


void Read() {
	/*
		ifstrem, input stream
		file 에서 input => 파일에서 값을 읽어오는 역할
	*/
	// 역시 path 를 처음부터 지정하거나, open() 를 이용해서 나중에 지정
	//std::ifstream input{ "data.txt" };
	std::ifstream input{};
	input.open(R"(./Files/120 data.txt)");
	
	std::string message;
	// string 을 공백포함해서, 한 줄 다 읽어올 때는 getline() 사용
	std::getline(input, message);

	int value{};
	input >> value;
	
	input.close(); // file stream 닫기

	std::cout << message << ":" << value << std::endl;
}



int main() {

	Write();
	Read();
	
	return 0;
}