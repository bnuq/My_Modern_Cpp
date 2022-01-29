/*
	binary file = eof 가 없다
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
	// text 로 저장 = 숫자가 문자열로 인식, 숫자 그대로 메모리에 저장된다
	textStream.close();

	std::ofstream binStream{ R"(./Sect_11/124_binary)", std::ios::binary | std::ios::out };
	// bin => 16진법으로 확인가능
	int num{ 12345678 };
	// write 함수 사용, binary 입력
	// 버퍼, 버퍼 사이즈
	binStream.write((const char*)(&num), sizeof(num));
	// binary 로 저장 = 숫자의 값이 이진수로 변환되어, 메모리에 저장된다
	binStream.close();


	int num2{};
	std::ifstream input{ R"(./Sect_11/124_binary)", std::ios::binary | std::ios::in };
	input.read((char*)(&num2), sizeof(num2));
	std::cout << num2 << std::endl;
	input.close();



	Record r;
	r.id = 1001;
	strcpy_s(r.name, 10, "Umar");
	// Records bunary file 에 쓰고
	WriteRecord(&r);

	// Records binary file 에서 읽어온다
	Record r2 = GetRecord();
	std::cout << r2.id << ":" << r2.name << std::endl;
	
	return 0;
}