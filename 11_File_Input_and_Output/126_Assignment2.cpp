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
	// dest += "_Copied"; Ȯ���� �ڿ� ���ڿ��� �ٴ´�
	
	// path.extension() => file Ȯ���ڸ� ����, ex)".txt
	path ext{ source.extension() };
	// path ���� extension �� ����
	dest.replace_extension("");
	// ���� �̸� �����ϰ�
	dest += "_Copied";
	// ���� Ȯ���� ����
	dest += ext;
	
	Copy(source, dest);
}

void Copy(const path& source, const path& dest)
{
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
		// Source file is small, so read completely and write into target
		// ifstream and ofstream => ���� ������ �ȴ�
		// �� ���� �а� �ٸ��ʿ��� �ٷ� ����� �����ϴ�
		// ����� ���ÿ� ���࿩�� Ȯ��
		if (!input.read(buffer, fileSize)) {
			throw std::runtime_error("Error occurred during read operation");
		}
		if (!output.write(buffer, fileSize)) {
			throw std::runtime_error("Error occurred during write operation");
		}
	}
	// ���� ũ�Ⱑ ���ۺ��� ũ��
	else
	{
		//Split the file into chunks
		// ��� ������ ��� ���Ѵ�
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
			/*
			* ���൵ ǥ�ø� ���� �κ�
			* ��ü ���൵���� ���� ������� ���
			* 0 ���� ���� ��츦 ���ֱ� ���� 10�� ���ߴ�
			* progress == oldProgress -> ���� ������ �ȵƴ� = ǥ���� �ʿ� ����
			*/
			progress = static_cast<int>((10 * static_cast<float>(i) / chunks));
			if (progress != oldProgress)
				std::cout << ".";
			oldProgress = progress;
		}
		
		// ������ �κ� �����ϱ� -> ���ۺ��� ���� �������̱� ������, ���۸� �ʱ�ȭ�ؾ� �Ѵ�
		// �׷��� ����ġ ���� �κб��� ���簡 �ȵȴ�
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
	// �������� �ʴ� ������ �̸� -> �ش� �̸����� ���丮 ����
	if (!exists(fileName))
	{
		create_directory(fileName);
		return;
	}
	else
	{
		// ���� & ����
		if (!is_directory(fileName))
			CopyFileInDirectory(fileName);
		else // ���� & ���丮
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
