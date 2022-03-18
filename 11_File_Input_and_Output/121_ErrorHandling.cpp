#include <iostream>
#include <fstream>
#include <string>
void Write() {
	std::ofstream out{"data.txt"};
	out << "Hello world" << std::endl;
	out << 10 << std::endl; 
	out.close(); // 파일 닫기
}
void Read() {
	std::ifstream input{ };
	input.open("data.txt");

	if (input.is_open()) {
		std::cout << "Open the file" << std::endl;
	}
	if (!input.is_open()) {
		std::cout << "Could not open the file" << std::endl;
	}

	if (input.good()) {
		std::cout << "File open good" << std::endl;
	}
	if (input.fail()) {
		std::cout << "File open fail" << std::endl;
	}

	// 파일 읽기
	std::string message;
	std::getline(input, message);
	int value{};
	input >> value;


	// 더 이상 읽을 게 없는데 읽는다
	// fail and eof
	input >> value;
	if (input.eof()) {
		std::cout << "End of file encountered" << std::endl;
	}
	if (input.good()) {
		std::cout << "I/O operations are successful" << std::endl;
	}
	if (input.fail()) {
		std::cout << "Some I/O operations failed" << std::endl;
	}

	// fallbit 를 직접 활성화
	input.setstate(std::ios::failbit);
	
	// 내부에서 good state 로 비트 초기화
	input.clear(); 

	input.close();
	std::cout << message << ":" << value << std::endl; 
}
int main() {
	Write();
	Read();
	return 0;
}