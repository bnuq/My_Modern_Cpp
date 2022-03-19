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
	// 파일을 열어서, ifstream 에 연결
	input.open("data.txt");

	// ifstream :: s_open() method
	// 파일이 존재하는지, 그래서 ifstream 에 잘 연결돼서 열렸는 지 확인
	if (input.is_open()) {
		std::cout << "Open the file" << std::endl;
	}
	if (!input.is_open()) {
		std::cout << "Could not open the file" << std::endl;
	}

	if (input.good()) { // input, output 이 문제없이 잘 됐다
		std::cout << "File open good" << std::endl;
	}
	if (input.fail()) { // input, output 에 문제가 발생했다
		std::cout << "File open fail" << std::endl;
	}

	// 파일 읽기
	std::string message;
	std::getline(input, message);
	int value{};
	input >> value;


	// 더 이상 읽을 게 없는데 읽는다
	input >> value; // value 에 들어가는 값이 없다

	// input 에 문제 발생 => fail()
	// end of file 에 도달 => eof()
	if (input.eof()) {
		std::cout << "End of file encountered" << std::endl;
	}
	if (input.good()) {
		std::cout << "I/O operations are successful" << std::endl;
	}
	if (input.fail()) {
		std::cout << "Some I/O operations failed" << std::endl;
	}

	// Stream State Flags 값을 직접 지정할 수 있다
	// fallbit 를 직접 활성화
	input.setstate(std::ios::failbit);
	
	// clear() method => 내부에서 good state 로 비트 초기화
	input.clear(); 

	input.close();
	std::cout << message << ":" << value << std::endl; 
}



int main() {
	Write();
	Read();
	return 0;
}