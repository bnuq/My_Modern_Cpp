#include <iostream>
#include <fstream>
#include <string>
void Write() {
	std::ofstream out{"data.txt"};
	out << "Hello world" << std::endl;
	out << 10 << std::endl; 
	out.close(); // ���� �ݱ�
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

	// ���� �б�
	std::string message;
	std::getline(input, message);
	int value{};
	input >> value;


	// �� �̻� ���� �� ���µ� �д´�
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

	// fallbit �� ���� Ȱ��ȭ
	input.setstate(std::ios::failbit);
	
	// ���ο��� good state �� ��Ʈ �ʱ�ȭ
	input.clear(); 

	input.close();
	std::cout << message << ":" << value << std::endl; 
}
int main() {
	Write();
	Read();
	return 0;
}