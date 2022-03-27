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


// path = file path, binary file �� ���� ���� ���� �غ�
void CopyFileInDirectory(const path& fileName) {
	path source{ fileName };
	path dest{ fileName };
	
	
	// path.extension() => file Ȯ���ڸ� ����, ex)".txt
	path ext{ source.extension() };

	// path ���� extension �� ����
	dest.replace_extension("");

	// ���� ���丮 ���� �����ϹǷ�, /= �� ���� �ʴ´�
	// dest += " Copied"; Ȯ���� �ڿ� ���ڿ��� �ٴ´�
	// ���� �̸� �����ϰ�
	dest += " Copied";

	// ���� Ȯ���� ����
	// path �� �ᱹ ���ڿ� ���·� ����Ǳ� ������, ���ڿ�ó�� ���갡���ϴ�
	dest += ext;
	
	Copy(source, dest);
}


// Binary File ����
void Copy(const path& source, const path& dest) {
	std::ifstream input{ source, std::ios::binary | std::ios::in };
	if (!input)
		throw std::runtime_error("Could not open the source file");

	// ofstream �� ������ ������, �ڵ����� �ϳ� �����
	std::ofstream output{ dest, std::ios::binary | std::ios::out };
	if(!output)
		throw std::runtime_error("Could not open the destination file");

	// file_size �Լ� => binary file size return
	auto fileSize = file_size(source);

	// �����͸� �ű� ����, ���۸� �����
	const unsigned int BUFFER_SIZE = 512;
	char buffer[BUFFER_SIZE]{};
	
	std::cout << "Copying " << source;

	// ���� ����� ���ۺ��� �۴�
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

		// ���� �� �ش��ϴ� �κ� ����
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
		if (remaining > 0) { // remaining �� �����ϴ� ��쿡
			if (!input.read(buffer, remaining)) {
				throw std::runtime_error("Error occurred during read operation");
			}
			if (!output.write(buffer, remaining)) {
				throw std::runtime_error("Error occurred during write operation");
			}
			std::cout << ".";
		}
	}


	// ���� �Ϸ�
	//std::cout << " Done!" << std::endl;
	input.close();
	output.close();

}



// directory path �ȿ� �ִ� ��� ���ϵ��� ����
void MoveFiles(const path& source, const path& dest) {
	
	// dir path �� ��� ���ϵ��� ����Ű�� iterator
	directory_iterator beg{ source };
	directory_iterator end{};

	
	while (beg != end) { // ���丮 �� ��ü ���Ͽ� ���ؼ�
		
		// ���丮 �� �Ϲ� ����
		if (!is_directory(*beg)) {
			path copiedFile{ *beg };
			// path :: filename() => path �� ��� �� ������, ���� �̸� ����
			path copiedFileName{ copiedFile.filename() };

			// ���� ���丮 �� ������, �����Ϸ��� ���丮 �ȿ�, �Ȱ��� �̸����� ����
			Copy(*beg, dest / copiedFileName);
		}
		// ���丮 �� ���丮
		else {
			path copiedDir{ *beg };
			path copiedDirName{ copiedDir.filename() };

			//std::cout << "Copied Dir Path is " << (dest / copiedDirName) << std::endl;
			
			// �����Ϸ��� ���丮 �ȿ�, �Ȱ��� �̸��� ���丮�� �����
			if (!create_directory(dest / copiedDirName))
				throw std::runtime_error("Error occurred during making dest / copiedDirName");

			// Recursion, ���丮�� �����Ѵ�
			MoveFiles(copiedDir, dest / copiedDirName);
		}

		++beg;
	}
}


// dir = directory path
// ���丮 ��ü�� �����ϴ� �Լ�
void DirectoryCopy(const path& dir) {
	path source{ dir };
	path dest{ dir };
	dest += " Copied"; // �����ϰ��� �ϴ� ���丮�� ���� ����

	if(!create_directory(dest))
		throw std::runtime_error("Error occurred during making copied dir");

	// directory path �ȿ� �ִ� ���ϵ��� ��� ����
	MoveFiles(source, dest);
}



path AcceptFileName() {
	// path �� �ᱹ string �� ��� ������ �����Ѵ�
	path fileName{};

	// cin �� ���� �ٷ� path �� �Է¹��� �� �ִ�
	// �̷��� �ϸ� path �� �ٷ� �Է¹��� �� �ֱ� �ѵ�, �������� �Ұ���
	// std::cin >> fileName;

	// string, ���� �����Ϸ��� => getline(), ��� path �� �ٷ� ����� ���Ѵ�
	std::string p{};
	std::getline(std::cin, p);
	fileName = p;

	return fileName;
}


void BinaryCopy(const path& fileName) {

	// �������� �ʴ� ������ �̸� -> �ش� �̸����� ���丮 ����
	if (!exists(fileName)) {
		// std::filesystem :: create_directory() => ���丮�� �����
		create_directory(fileName);
		return;
	}
	else {
		// std::filesystem :: is_directory() => �ش� path �� directory path ���� Ȯ��
		// ���� && ���� ���
		if (!is_directory(fileName))
			CopyFileInDirectory(fileName); // binary file �� �����Ѵ�
		// ���� && ���丮
		else {
			std::cout << "is directory" << std::endl;
			DirectoryCopy(fileName);	// directory �� �����Ѵ�
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
