/*
	Copying binary a binary file
	나는 이미지 파일을 사용했다
*/
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <exception>

using namespace std::filesystem;


// soucre path 에 있는 file 을 => dest path 에 복사한다
void Copy(const path& source, const path& dest);

void BinaryFileCopy() {
	// 복사하고자 하는 파일 경로, 복사 경로를 모두 지정한 다음
	path source{ R"(./Files/125 image.jpg)" };
	path dest{ R"(./Files/125 image Copied.jpg)" };

	// binary file copy
	Copy(source, dest);
}


void Copy(const path& source, const path& dest) {

	// input file 과 ifstream 연결
	std::ifstream input{ source, std::ios::binary | std::ios::in };
	if (!input)	throw std::runtime_error("Could not open the source file");

	// output file 과 ofstream 연결
	// ofstream 은 파일이 없으면, 자동으로 하나 만든다
	std::ofstream output{ dest, std::ios::binary | std::ios::out };
	if(!output)	throw std::runtime_error("Could not open the destination file");


	// std::filesystem :: file_size( path ) => path 의 파일의 크기를 리턴
	auto fileSize = file_size(source);


	// binary data를 옮길 버퍼를 만든다
	const unsigned int BUFFER_SIZE = 512;
	char buffer[BUFFER_SIZE]{}; // byte 단위로 옮김
	
	std::cout << "Copying " << source;

	// 파일 사이즈가 버퍼보다 작다
	if (fileSize < BUFFER_SIZE) {
		// Source file is small, so read completely and write into target
		// 앞서 정의한 버퍼를 이용 => ifstream and ofstream, 두 stream 간에 데이터를 공유한다
		// 한 쪽이 읽고 다른쪽에서 바로 출력이 가능하다
		// 실행과 동시에 실행여부 확인
		// read(), write() => 실패시 null return
		if (!input.read(buffer, fileSize)) {
			throw std::runtime_error("Error occurred during read operation");
		}
		if (!output.write(buffer, fileSize)) {
			throw std::runtime_error("Error occurred during write operation");
		}
	}
	// 파일 크기가 버퍼보다 크다
	else {
		//Split the file into chunks
		// 목과 나머지 모두 구한다
		auto chunks = fileSize / BUFFER_SIZE;
		int remaining = fileSize % BUFFER_SIZE;

		int progress{}, oldProgress{};

		// 먼저 몫에 해당하는 부분 복사
		for (int i = 0; i < chunks; i++) {
			if (!input.read(buffer, BUFFER_SIZE)) {
				throw std::runtime_error("Error occurred during read operation");
			}
			if (!output.write(buffer, BUFFER_SIZE)) {
				throw std::runtime_error("Error occurred during write operation");
			}
			/*
				진행도 표시를 위한 부분
				전체 진행도에서 현재 진행률을 계산
				0~1 구간 => 0~10 구간으로 바꾸기 위해, 10을 곱하고 int 로 type conversion
				progress == oldProgress -> 별로 진행이 안됐다 = 표시할 필요 없음
			*/
			progress = static_cast<int>((10 * static_cast<float>(i) / chunks));

			if (progress != oldProgress) // 어느정도 진행이 됐다고 판단
				std::cout << ".";
			oldProgress = progress; // 갱신
		}
		
		// 나머지 부분 복사하기 -> 버퍼보다 작은 사이즈이기 때문에, 버퍼를 초기화해야 한다
		// 그래야 예기치 않은 부분까지 복사가 안된다
		memset(buffer, '\0', BUFFER_SIZE); // 전체 버퍼를 \0 값으로 초기화

		//Read and write the remaining bytes
		if (remaining > 0) { // remaining 이 존재하는 경우에
			if (!input.read(buffer, remaining)) {
				throw std::runtime_error("Error occurred during read operation");
			}
			if (!output.write(buffer, remaining)) {
				throw std::runtime_error("Error occurred during write operation");
			}
			std::cout << ".";
		}
	}


	// 복사 완료
	std::cout << " Done!" << std::endl;
	input.close();
	output.close();

}


int main() {
	try	{
		BinaryFileCopy();
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}
