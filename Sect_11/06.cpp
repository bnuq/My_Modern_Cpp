/*
	�� ������, ���Ͽ� �������
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
		out.put(ch); // �� ���ھ� ofstream �� �ִ´� = put

	// put pointer ��ġ ����
	out.seekp(5);
	// character �ֱ�
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

	// put pointer ��ġ ����
	input.seekg(10);
	input.seekg(10, std::ios::beg);
	input.seekg(10, std::ios::cur);
	input.seekg(-10, std::ios::end);

	// ���� get pointer ��ġ ã��
	std::cout << "Current position is: " << input.tellg() << std::endl;

	input.seekg(5);

	char ch{};
	while (input.get(ch)) // �� ���ھ� �����´� = get �Լ�
	{
		std::cout << ch;
	}

	std::cout << std::endl << "Data text done" << std::endl << std::endl;
}

void UsingFstream()
{
	std::fstream stream{ R"(./Sect_11/06_file.txt)"};
	// ������ �������� ������, �ڵ����� ������ �ʴ´�
	if (!stream)
	{
		std::cout << "FILE DOSE NOT EXIST. CREATE ONE" << std::endl;

		// ���� ���� ����
		std::ofstream out{ R"(./Sect_11/06_file.txt)" };
		out.close();
		
		stream.open(R"(./Sect_11/06_file.txt)");
	}

	stream << "File text : Hello World" << std::endl;
	// fstream �� ���� �� ��,
	// ���� get, put pointers ��� eof �� �ִ�

	stream.seekg(0); // get pointer �� �տ� ����

	// ��������
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