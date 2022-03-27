// ofstream => ���Ͽ� ��������, ������ �ʱ�ȭ�ϴ� ��?

#include <iostream>
#include <fstream>
#include <string>


void Write() {
	// ofstream => path �� �ش��ϴ� file �� ����
	// ������ ���� ����
	std::ofstream out{ R"(./Files/123 data.txt)" };
	if (!out) { // ofstream �� file ���� �� ������ ���
		std::cout << "Could not open file for writing" << std::endl;
		return;
	}


	std::string message{ "C++ was invented by Bjarne" };
	// string => iterator ���� => Range Base For Loop �� �� ���ڸ� ����ų �� �ִ�
	for (auto ch : message)
		// ofstream :: put() => char �ϳ��� ofstream �� �ִ´�
		out.put(ch);

	// ofstrea :: seekp() => seek to put
	// ofstream �� �Է��� pointer ��ġ ����
	out.seekp(5);

	// put() �� �̿��ϸ�, ofstream pointer �� ����Ű�� ��ġ�� character �� ���� �� �ִ�
	out.put('@'); // ������ ��ġ�� char �����
	// �Է� �� �����ʹ� �ڵ����� ���� ��ġ�� �̵��Ѵ�
	out.put('*'); // ���� ��ġ�� char �����
}



void Read() {
	std::ifstream input{ R"(./Files/123 data.txt)" };
	if (!input)	{
		std::cout << "Source file not found" << std::endl;
		return;
	}

	
	// ifstream :: seekg() => seek to get
	// ifstream �� �о�� pointer ��ġ�� ������ �� �ִ�
	// ���� ��ġ, �ε���
	input.seekg(10);

	// ����� ��ġ�� ������ ���� �ִ�
	input.seekg(10, std::ios::beg);		// ������ ó�� ����
	input.seekg(10, std::ios::cur);		// ���� pointer ��ġ ����
	input.seekg(-12, std::ios::end);	// ���� �� ����

	// ifstream :: tellg()
	// ���� ifstream �� get pointer ��ġ ã��
	std::cout << "Current position is: " << input.tellg() << std::endl;

	//input.seekg(5);

	char ch{};
	// ifstream :: get()
	// ���� �����Ͱ� ����Ű�� ��ġ�� char �� �����ͼ�, �����Ѵ�
	while (input.get(ch)) {
		std::cout << ch;
	}

	std::cout << std::endl << "Data text done" << std::endl << std::endl;
}



// fstream => ȥ�ڼ� input, output ��� ����
void UsingFstream() {

	// file �� stream �� ����
	std::fstream stream{ R"(./Files/123 file.txt)"};
	

	// �׳� stream �� ���, ������ �������� ������ �ڵ����� ������ �ʴ´�
	if (!stream) {
		std::cout << "FILE DOSE NOT EXIST. CREATE ONE" << std::endl;

		// ���� ���� ����
		std::ofstream out{ R"(./Files/123 file.txt)" };
		out.close();
		

		// file stream ���� ��, open() �� ���� ����
		stream.open(R"(./Files/123 file.txt)");
	}


	// ofstream ó��, �ڿ������� << �����ڷ� ���ڿ��� �� �� �ִ�
	stream << "File text : Hello World" << std::endl;
	stream << "This is my text" << std::endl;
	// fstream �� ���� �� ��,
	// ���� get, put pointers ��� eof �� �ִ�


	stream.seekg(0); // get pointer �� �տ� ����
	// ��������
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