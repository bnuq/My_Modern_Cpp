/*
	binary file
	데이터의 저장과 처리를 목적으로 함
	0, 1 의 이진형식으로 인코딩된 파일
	
	파일의 데이터를 읽거나 쓸 때, 어떠한 변환도 일어나지 않는다
	메모리에 저장된 변수의 데이터 => 그 자체가 파일에 저장된다

	data 를 binary form 으로 저장한다, 메모리에 저장하듯이

	binary file 에는 eof 가 없다
	그래서 읽으려는 데이터가 얼마인지, binary file 의 전체 구조를 반드시 알아야 한다
*/
#include <iostream>
#include <fstream>
#include <string>



// User Defined Data Type 을 바이너리 형식으로 읽고 쓰고 싶다
struct Record {
	int id;
	char name[10]; // string type 은 이미 아스키 코드 값 => 바이너리로 저장해도 string 이다
};


// Record type 쓰기
void WriteRecord(Record* p)
{
	std::ofstream binstream{ R"(./Files/124 record.bin)", std::ios::binary | std::ios::out};
	// char = 1byte
	// 포인터로 가리키는 데이터를 복사해서 -> 파일로 output
	binstream.write((const char*)p, sizeof(Record));

	// Record 데이터를 하나 더 넣는다
	p->id = 999;
	strcpy_s(p->name, 10, "Uhyo");
	binstream.write((const char*)p, sizeof(Record));
}

Record GetRecord() {
	std::ifstream input{ R"(./Files/124 record.bin)", std::ios::binary | std::ios::in };
	
	// Record 객체 하나만큼, 데이터를 읽어온다
	Record r{};
	input.read((char*)&r, sizeof(Record));
	return r;
}

void PrintRecord(int count) {
	std::ifstream input{ R"(./Files/124 record.bin)", std::ios::binary | std::ios::in };

	// Record 객체 하나만큼, 데이터를 읽어온다
	Record r{};

	// binary file => eof 가 없어서 얼마나 읽었는 지 몰라
	// 몇 개의 데이터가 어떻게 들어가 있는 지를 정확히 알아야 한다
	for (int i = 0; i < count; i++) { // count 개 만큼 Record 를 읽는다
		input.read((char*)&r, sizeof(Record));
		std::cout << r.id << ":" << r.name << std::endl;
	}
	
	return;
}



int main() {

	// text file <- stream 인 경우
	// 데이터를 문자열 형태로 저장하고 읽는다
	std::ofstream textStream{ R"(./Files/124 text)" }; 
	// std::ofstream textStream{ R"(./Files/124 text.txt)" }; => .txt 확장자가 없어도 똑같이 text file 에 생긴다
	
	// text 로 저장 = 숫자를 문자열로 인식, 쓰인 그대로 파일에 저장
	textStream << 12345678 << std::endl;
	//textStream << dfk; 그냥 문자는 변수 이름으로 인식돼서 안되고
	
	int textNum{ 10 };
	// 변수에 2진법으로 저장된 10 이라는 값도, 문자열로 바꾸어서 텍스트 파일에 저장한다
	textStream << textNum << std::endl;
	
	/*
		숫자 => 각 숫자를 나타내는 아스키 코드 값으로 변경 
		=> 2진법으로 나타낸 아스키 코드 값이 저장

		이후 읽을 때, 아스키 코드 => 문자 로 바뀌면서, 사람이 읽을 수 있는 문자열이 된다
	*/

	textStream.close();


	// binary file <- stream 의 경우
	// binary file 에 쓰는 것이라는 걸 알려야 한다
	// 그리고 out stream 이란 걸 다시 알려야 한다
	// .bin 확장자 => 2진법 데이터를 16진법 데이터로 볼 수 있다, hexaviewer
	std::ofstream binStream{ R"(./Files/124 binary.bin)", std::ios::binary | std::ios::out };
	
	
	
	// 변수에 값 저장 => 메모리에 2진법으로 저장이 되고
	// 이 2진법으로 바뀐 데이터를 => 파일에 그대로 저장 == 바이너리 파일
	int num{ 12345678 };

	// ofstream :: write(버퍼 주소, 총 데이터 크기) => 파일에 binary 입력에 사용
	// 1 바이트 씩 쓴다는 의미에서 const char* 로 타입 변환
	// 010110111010 .. 이런 식으로 파일에 쓰인다
	binStream.write((const char*)(&num), sizeof(num));

	// binary 로 저장 = 이진수로 변환된 숫자 값이, 메모리에 저장된다
	binStream.close();


	
	/*
		바이너리 파일에서 값 읽기
		binary file -> stream, input
		역시 binray file 이라는 걸 알리고 in 이라는 걸 다시 알림
	*/
	std::ifstream input{ R"(./Files/124 binary.bin)", std::ios::binary | std::ios::in };
	/*
		binary data 를 읽을 때는 ifstream :: read(버퍼 주소, 읽을 총 데이터)
		역시 바이트 단위로 읽기 위해, char* 로 변환한다

		바이너리 데이터가 그대로 넘어와서, 변수에 저장
		이후 변수를 그냥 사용하면 된다, 변수에 2진법으로 저장된 거니까
	*/
	int num2{};
	input.read((char*)(&num2), sizeof(num2));

	std::cout << num2 << std::endl;

	input.close();



	/* User Defined Type 사용 */
	Record r{};
	// struct Record 값 assignment
	r.id = 1001;
	strcpy_s(r.name, 10, "umar");


	// records bunary file 에 쓰는데
	// 2개를 쓰는 것으로 수정
	WriteRecord(&r);

	// records binary file 에서 읽어온다
	/*Record r2 = GetRecord();
	std::cout << r2.id << ":" << r2.name << std::endl;*/

	// Record type 을 2개 읽는 것으로 수정
	PrintRecord(2);
	
	return 0;
}