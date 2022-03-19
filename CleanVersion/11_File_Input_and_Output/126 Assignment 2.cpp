/*
	Copying binary files and directories

*/
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <exception>

using namespace std::filesystem;

void Copy(const path&, const path&);


// path = file path, binary file 을 복사 위한 사전 준비
void CopyFileInDirectory(const path& fileName) {
	path source{ fileName };
	path dest{ fileName };
	
	
	// path.extension() => file 확장자를 리턴, ex)".txt
	path ext{ source.extension() };

	// path 에서 extension 만 제거
	dest.replace_extension("");

	// 같은 디렉토리 내에 존재하므로, /= 는 쓰지 않는다
	// dest += " Copied"; 확장자 뒤에 문자열이 붙는다
	// 파일 이름 수정하고
	dest += " Copied";

	// 기존 확장자 붙임
	// path 가 결국 문자열 형태로 저장되기 때문에, 문자열처럼 연산가능하다
	dest += ext;
	
	Copy(source, dest);
}


// Binary File 복사
void Copy(const path& source, const path& dest) {
	std::ifstream input{ source, std::ios::binary | std::ios::in };
	if (!input)
		throw std::runtime_error("Could not open the source file");

	// ofstream 은 파일이 없으면, 자동으로 하나 만든다
	std::ofstream output{ dest, std::ios::binary | std::ios::out };
	if(!output)
		throw std::runtime_error("Could not open the destination file");

	// file_size 함수 => binary file size return
	auto fileSize = file_size(source);

	// 데이터를 옮길 변수, 버퍼를 만든다
	const unsigned int BUFFER_SIZE = 512;
	char buffer[BUFFER_SIZE]{};
	
	std::cout << "Copying " << source;

	// 파일 사이즈가 버퍼보다 작다
	if (fileSize < BUFFER_SIZE) {
		if (!input.read(buffer, fileSize)) {
			throw std::runtime_error("Error occurred during read operation");
		}
		if (!output.write(buffer, fileSize)) {
			throw std::runtime_error("Error occurred during write operation");
		}
	}
	else {

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

			progress = static_cast<int>((10 * static_cast<float>(i) / chunks));
			if (progress != oldProgress)
				std::cout << ".";
			oldProgress = progress;
		}
		

		memset(buffer, '\0', BUFFER_SIZE);

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
	//std::cout << " Done!" << std::endl;
	input.close();
	output.close();

}



// directory path 안에 있는 모든 파일들을 복사
void MoveFiles(const path& source, const path& dest) {
	
	// dir path 내 모든 파일들을 가리키는 iterator
	directory_iterator beg{ source };
	directory_iterator end{};

	
	while (beg != end) { // 디렉토리 내 전체 파일에 대해서
		
		// 디렉토리 내 일반 파일
		if (!is_directory(*beg)) {
			path copiedFile{ *beg };
			// path :: filename() => path 의 경로 맨 마지막, 파일 이름 리턴
			path copiedFileName{ copiedFile.filename() };

			// 현재 디렉토리 내 파일을, 복사하려는 디렉토리 안에, 똑같은 이름으로 복사
			Copy(*beg, dest / copiedFileName);
		}
		// 디렉토리 내 디렉토리
		else {
			path copiedDir{ *beg };
			path copiedDirName{ copiedDir.filename() };

			//std::cout << "Copied Dir Path is " << (dest / copiedDirName) << std::endl;
			
			// 복사하려는 디렉토리 안에, 똑같은 이름의 디렉토리를 만들고
			if (!create_directory(dest / copiedDirName))
				throw std::runtime_error("Error occurred during making dest / copiedDirName");

			// Recursion, 디렉토리를 복사한다
			MoveFiles(copiedDir, dest / copiedDirName);
		}

		++beg;
	}
}


// dir = directory path
// 디렉토리 전체를 복사하는 함수
void DirectoryCopy(const path& dir) {
	path source{ dir };
	path dest{ dir };
	dest += " Copied"; // 복사하고자 하는 디렉토리를 만든 다음

	if(!create_directory(dest))
		throw std::runtime_error("Error occurred during making copied dir");

	// directory path 안에 있는 파일들을 모두 복사
	MoveFiles(source, dest);
}



path AcceptFileName() {
	// path 는 결국 string 을 경로 값으로 저장한다
	path fileName{};

	// cin 을 통해 바로 path 를 입력받을 수 있다
	// 이렇게 하면 path 를 바로 입력받을 수 있긴 한데, 공백포함 불가능
	// std::cin >> fileName;

	// string, 공백 포함하려면 => getline(), 대신 path 를 바로 사용은 못한다
	std::string p{};
	std::getline(std::cin, p);
	fileName = p;

	return fileName;
}


void BinaryCopy(const path& fileName) {

	// 존재하지 않는 파일의 이름 -> 해당 이름으로 디렉토리 생성
	if (!exists(fileName)) {
		// std::filesystem :: create_directory() => 디렉토리를 만든다
		create_directory(fileName);
		return;
	}
	else {
		// std::filesystem :: is_directory() => 해당 path 가 directory path 인지 확인
		// 존재 && 파일 경로
		if (!is_directory(fileName))
			CopyFileInDirectory(fileName); // binary file 을 복사한다
		// 존재 && 디렉토리
		else {
			std::cout << "is directory" << std::endl;
			DirectoryCopy(fileName);	// directory 를 복사한다
		}
	}
}


int main()
{
	path fileName = AcceptFileName();

	std::cout << fileName;


	try	{
		BinaryCopy(fileName);
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}
