#include <iostream>
#include <fstream> // write/read file stream
#include <string>


void Write() {
	/*
		ofstream, ouput stream
		file �� output => �������� ����, ���Ͽ� ���� ����
	*/
	// �ʱ�ȭ�� �ϸ鼭 path �� �����ϰų�
	//std::ofstream out{ "data.txt" };

	// ���� ��, open() method => path ����
	std::ofstream out{};
	// �ش� path �� ���ϴ� file �� ������,
	// output �ϱ� ���ؼ� �ϳ� �����
	out.open(R"(./Files/120 data.txt)");

	// << operator �� ���ϴ� ���� ���Ϸ� ��������, out
	out << "Hello world" << std::endl;
	out << 100 << std::endl;
	
	out.close(); // file stream �ݱ�
}


void Read() {
	/*
		ifstrem, input stream
		file ���� input => ���Ͽ��� ���� �о���� ����
	*/
	// ���� path �� ó������ �����ϰų�, open() �� �̿��ؼ� ���߿� ����
	//std::ifstream input{ "data.txt" };
	std::ifstream input{};
	input.open(R"(./Files/120 data.txt)");
	
	std::string message;
	// string �� ���������ؼ�, �� �� �� �о�� ���� getline() ���
	std::getline(input, message);

	int value{};
	input >> value;
	
	input.close(); // file stream �ݱ�

	std::cout << message << ":" << value << std::endl;
}



int main() {

	Write();
	Read();
	
	return 0;
}