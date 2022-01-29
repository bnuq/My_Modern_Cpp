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

void CopyFileInDirectory(const path& fileName) {
	path source{ fileName };
	path dest{ fileName };
	// dest += "_Copied"; 확장자 뒤에 문자열이 붙는다
	
	// path.extension() => file 확장자를 리턴, ex)".txt
	path ext{ source.extension() };
	// path 에서 extension 만 제거
	dest.replace_extension("");
	// 파일 이름 수정하고
	dest += "_Copied";
	// 기존 확장자 붙임
	dest += ext;
	
	Copy(source, dest);
}

void Copy(const path& source, const path& dest)
{
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
		// Source file is small, so read completely and write into target
		// ifstream and ofstream => 서로 공유가 된다
		// 한 쪽이 읽고 다른쪽에서 바로 출력이 가능하다
		// 실행과 동시에 실행여부 확인
		if (!input.read(buffer, fileSize)) {
			throw std::runtime_error("Error occurred during read operation");
		}
		if (!output.write(buffer, fileSize)) {
			throw std::runtime_error("Error occurred during write operation");
		}
	}
	// 파일 크기가 버퍼보다 크다
	else
	{
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
			* 진행도 표시를 위한 부분
			* 전체 진행도에서 현재 진행률을 계산
			* 0 보다 작은 경우를 없애기 위해 10을 곱했다
			* progress == oldProgress -> 별로 진행이 안됐다 = 표시할 필요 없음
			*/
			progress = static_cast<int>((10 * static_cast<float>(i) / chunks));
			if (progress != oldProgress)
				std::cout << ".";
			oldProgress = progress;
		}
		
		// 나머지 부분 복사하기 -> 버퍼보다 작은 사이즈이기 때문에, 버퍼를 초기화해야 한다
		// 그래야 예기치 않은 부분까지 복사가 안된다
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
	std::cout << " Done!" << std::endl;
	input.close();
	output.close();

}



void MoveFiles(const path& source, const path& dest)
{
	directory_iterator beg{ source };
	directory_iterator end{};

	while (beg != end)
	{
		if (!is_directory(*beg))
		{
			path copiedFile{ *beg };
			path copiedFileName{ copiedFile.filename() };

			Copy(*beg, dest / copiedFileName);
		}
		else
		{
			path copiedDir{ *beg };
			path copiedDirName{ copiedDir.filename() };

			//std::cout << "Copied Dir Path is " << (dest / copiedDirName) << std::endl;
			if (!create_directory(dest / copiedDirName))
				throw std::runtime_error("Error occurred during making dest / copiedDirName");

			MoveFiles(copiedDir, dest / copiedDirName);
		}
		++beg;
	}
}

void DirectoryCopy(const path& dir)
{
	path source{ dir };
	path dest{ dir };
	dest += "_Copied";

	if(!create_directory(dest))
		throw std::runtime_error("Error occurred during making copied dir");

	MoveFiles(source, dest);
}



path AcceptFileName()
{
	path fileName{};
	std::cin >> fileName;
	return fileName;
}


void BinaryCopy(const path& fileName)
{
	// 존재하지 않는 파일의 이름 -> 해당 이름으로 디렉토리 생성
	if (!exists(fileName))
	{
		create_directory(fileName);
		return;
	}
	else
	{
		// 존재 & 파일
		if (!is_directory(fileName))
			CopyFileInDirectory(fileName);
		else // 존재 & 디렉토리
		{
			std::cout << "is directory" << std::endl;
			DirectoryCopy(fileName);
		}
	}

	
}


int main()
{
	path fileName = AcceptFileName();

	std::cout << fileName;


	try
	{
		BinaryCopy(fileName);
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}
