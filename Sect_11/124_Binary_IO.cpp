/*
	binary file = eof �� ����
*/
#include <iostream>
#include <fstream>
#include <string>
struct Record {
	int id;
	char name[10];
};

void WriteRecord(Record* p)
{
	std::ofstream binstream{ R"(./Sect_11/124_Records)", std::ios::binary | std::ios::out};
	// char = 1byte
	binstream.write((const char*)p, sizeof(Record));
}

Record GetRecord() {
	std::ifstream input{ R"(./Sect_11/124_Records)", std::ios::binary | std::ios::in };
	Record r;
	input.read((char*)&r, sizeof(Record));
	return r;
}



int main()
{
	std::ofstream textStream{ R"(./Sect_11/124_text)" };
	textStream << 12345678;
	// text �� ���� = ���ڰ� ���ڿ��� �ν�, ���� �״�� �޸𸮿� ����ȴ�
	textStream.close();

	std::ofstream binStream{ R"(./Sect_11/124_binary)", std::ios::binary | std::ios::out };
	// bin => 16�������� Ȯ�ΰ���
	int num{ 12345678 };
	// write �Լ� ���, binary �Է�
	// ����, ���� ������
	binStream.write((const char*)(&num), sizeof(num));
	// binary �� ���� = ������ ���� �������� ��ȯ�Ǿ�, �޸𸮿� ����ȴ�
	binStream.close();


	int num2{};
	std::ifstream input{ R"(./Sect_11/124_binary)", std::ios::binary | std::ios::in };
	input.read((char*)(&num2), sizeof(num2));
	std::cout << num2 << std::endl;
	input.close();



	Record r;
	r.id = 1001;
	strcpy_s(r.name, 10, "Umar");
	// Records bunary file �� ����
	WriteRecord(&r);

	// Records binary file ���� �о�´�
	Record r2 = GetRecord();
	std::cout << r2.id << ":" << r2.name << std::endl;
	
	return 0;
}