#include <iostream>
#include <fstream>
#include <string>
void Write() {
	//std::ofstream out{ "data.txt" };
	std::ofstream out{};
	out.open(R"(./Sect_11/03_data.txt)");

	out << "Hello world" << std::endl;
	out << 100 << std::endl;
	
	out.close(); // ÆÄÀÏ ´Ý±â
}
void Read() {
	//std::ifstream input{ "data.txt" };
	std::ifstream input{};
	input.open(R"(./Sect_11/03_data.txt)");
	
	std::string message;
	std::getline(input, message);

	int value{};
	input >> value;
	
	input.close();
	std::cout << message << ":" << value << std::endl;
}
int main() {
	Write();
	Read();
	return 0;
}