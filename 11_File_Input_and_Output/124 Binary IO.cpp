/*
	binary file
	�������� ����� ó���� �������� ��
	0, 1 �� ������������ ���ڵ��� ����
	
	������ �����͸� �аų� �� ��, ��� ��ȯ�� �Ͼ�� �ʴ´�
	�޸𸮿� ����� ������ ������ => �� ��ü�� ���Ͽ� ����ȴ�

	data �� binary form ���� �����Ѵ�, �޸𸮿� �����ϵ���

	binary file ���� eof �� ����
	�׷��� �������� �����Ͱ� ������, binary file �� ��ü ������ �ݵ�� �˾ƾ� �Ѵ�
*/
#include <iostream>
#include <fstream>
#include <string>



// User Defined Data Type �� ���̳ʸ� �������� �а� ���� �ʹ�
struct Record {
	int id;
	char name[10]; // string type �� �̹� �ƽ�Ű �ڵ� �� => ���̳ʸ��� �����ص� string �̴�
};


// Record type ����
void WriteRecord(Record* p)
{
	std::ofstream binstream{ R"(./Files/124 record.bin)", std::ios::binary | std::ios::out};
	// char = 1byte
	// �����ͷ� ����Ű�� �����͸� �����ؼ� -> ���Ϸ� output
	binstream.write((const char*)p, sizeof(Record));

	// Record �����͸� �ϳ� �� �ִ´�
	p->id = 999;
	strcpy_s(p->name, 10, "Uhyo");
	binstream.write((const char*)p, sizeof(Record));
}

Record GetRecord() {
	std::ifstream input{ R"(./Files/124 record.bin)", std::ios::binary | std::ios::in };
	
	// Record ��ü �ϳ���ŭ, �����͸� �о�´�
	Record r{};
	input.read((char*)&r, sizeof(Record));
	return r;
}

void PrintRecord(int count) {
	std::ifstream input{ R"(./Files/124 record.bin)", std::ios::binary | std::ios::in };

	// Record ��ü �ϳ���ŭ, �����͸� �о�´�
	Record r{};

	// binary file => eof �� ��� �󸶳� �о��� �� ����
	// �� ���� �����Ͱ� ��� �� �ִ� ���� ��Ȯ�� �˾ƾ� �Ѵ�
	for (int i = 0; i < count; i++) { // count �� ��ŭ Record �� �д´�
		input.read((char*)&r, sizeof(Record));
		std::cout << r.id << ":" << r.name << std::endl;
	}
	
	return;
}



int main() {

	// text file <- stream �� ���
	// �����͸� ���ڿ� ���·� �����ϰ� �д´�
	std::ofstream textStream{ R"(./Files/124 text)" }; 
	// std::ofstream textStream{ R"(./Files/124 text.txt)" }; => .txt Ȯ���ڰ� ��� �Ȱ��� text file �� �����
	
	// text �� ���� = ���ڸ� ���ڿ��� �ν�, ���� �״�� ���Ͽ� ����
	textStream << 12345678 << std::endl;
	//textStream << dfk; �׳� ���ڴ� ���� �̸����� �νĵż� �ȵǰ�
	
	int textNum{ 10 };
	// ������ 2�������� ����� 10 �̶�� ����, ���ڿ��� �ٲپ �ؽ�Ʈ ���Ͽ� �����Ѵ�
	textStream << textNum << std::endl;
	
	/*
		���� => �� ���ڸ� ��Ÿ���� �ƽ�Ű �ڵ� ������ ���� 
		=> 2�������� ��Ÿ�� �ƽ�Ű �ڵ� ���� ����

		���� ���� ��, �ƽ�Ű �ڵ� => ���� �� �ٲ�鼭, ����� ���� �� �ִ� ���ڿ��� �ȴ�
	*/

	textStream.close();


	// binary file <- stream �� ���
	// binary file �� ���� ���̶�� �� �˷��� �Ѵ�
	// �׸��� out stream �̶� �� �ٽ� �˷��� �Ѵ�
	// .bin Ȯ���� => 2���� �����͸� 16���� �����ͷ� �� �� �ִ�, hexaviewer
	std::ofstream binStream{ R"(./Files/124 binary.bin)", std::ios::binary | std::ios::out };
	
	
	
	// ������ �� ���� => �޸𸮿� 2�������� ������ �ǰ�
	// �� 2�������� �ٲ� �����͸� => ���Ͽ� �״�� ���� == ���̳ʸ� ����
	int num{ 12345678 };

	// ofstream :: write(���� �ּ�, �� ������ ũ��) => ���Ͽ� binary �Է¿� ���
	// 1 ����Ʈ �� ���ٴ� �ǹ̿��� const char* �� Ÿ�� ��ȯ
	// 010110111010 .. �̷� ������ ���Ͽ� ���δ�
	binStream.write((const char*)(&num), sizeof(num));

	// binary �� ���� = �������� ��ȯ�� ���� ����, �޸𸮿� ����ȴ�
	binStream.close();


	
	/*
		���̳ʸ� ���Ͽ��� �� �б�
		binary file -> stream, input
		���� binray file �̶�� �� �˸��� in �̶�� �� �ٽ� �˸�
	*/
	std::ifstream input{ R"(./Files/124 binary.bin)", std::ios::binary | std::ios::in };
	/*
		binary data �� ���� ���� ifstream :: read(���� �ּ�, ���� �� ������)
		���� ����Ʈ ������ �б� ����, char* �� ��ȯ�Ѵ�

		���̳ʸ� �����Ͱ� �״�� �Ѿ�ͼ�, ������ ����
		���� ������ �׳� ����ϸ� �ȴ�, ������ 2�������� ����� �Ŵϱ�
	*/
	int num2{};
	input.read((char*)(&num2), sizeof(num2));

	std::cout << num2 << std::endl;

	input.close();



	/* User Defined Type ��� */
	Record r{};
	// struct Record �� assignment
	r.id = 1001;
	strcpy_s(r.name, 10, "umar");


	// records bunary file �� ���µ�
	// 2���� ���� ������ ����
	WriteRecord(&r);

	// records binary file ���� �о�´�
	/*Record r2 = GetRecord();
	std::cout << r2.id << ":" << r2.name << std::endl;*/

	// Record type �� 2�� �д� ������ ����
	PrintRecord(2);
	
	return 0;
}