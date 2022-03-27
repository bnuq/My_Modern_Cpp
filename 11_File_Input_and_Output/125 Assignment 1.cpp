/*
	Copying binary a binary file
	���� �̹��� ������ ����ߴ�
*/
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <exception>

using namespace std::filesystem;


// soucre path �� �ִ� file �� => dest path �� �����Ѵ�
void Copy(const path& source, const path& dest);

void BinaryFileCopy() {
	// �����ϰ��� �ϴ� ���� ���, ���� ��θ� ��� ������ ����
	path source{ R"(./Files/125 image.jpg)" };
	path dest{ R"(./Files/125 image Copied.jpg)" };

	// binary file copy
	Copy(source, dest);
}


void Copy(const path& source, const path& dest) {

	// input file �� ifstream ����
	std::ifstream input{ source, std::ios::binary | std::ios::in };
	if (!input)	throw std::runtime_error("Could not open the source file");

	// output file �� ofstream ����
	// ofstream �� ������ ������, �ڵ����� �ϳ� �����
	std::ofstream output{ dest, std::ios::binary | std::ios::out };
	if(!output)	throw std::runtime_error("Could not open the destination file");


	// std::filesystem :: file_size( path ) => path �� ������ ũ�⸦ ����
	auto fileSize = file_size(source);


	// binary data�� �ű� ���۸� �����
	const unsigned int BUFFER_SIZE = 512;
	char buffer[BUFFER_SIZE]{}; // byte ������ �ű�
	
	std::cout << "Copying " << source;

	// ���� ����� ���ۺ��� �۴�
	if (fileSize < BUFFER_SIZE) {
		// Source file is small, so read completely and write into target
		// �ռ� ������ ���۸� �̿� => ifstream and ofstream, �� stream ���� �����͸� �����Ѵ�
		// �� ���� �а� �ٸ��ʿ��� �ٷ� ����� �����ϴ�
		// ����� ���ÿ� ���࿩�� Ȯ��
		// read(), write() => ���н� null return
		if (!input.read(buffer, fileSize)) {
			throw std::runtime_error("Error occurred during read operation");
		}
		if (!output.write(buffer, fileSize)) {
			throw std::runtime_error("Error occurred during write operation");
		}
	}
	// ���� ũ�Ⱑ ���ۺ��� ũ��
	else {
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
				���൵ ǥ�ø� ���� �κ�
				��ü ���൵���� ���� ������� ���
				0~1 ���� => 0~10 �������� �ٲٱ� ����, 10�� ���ϰ� int �� type conversion
				progress == oldProgress -> ���� ������ �ȵƴ� = ǥ���� �ʿ� ����
			*/
			progress = static_cast<int>((10 * static_cast<float>(i) / chunks));

			if (progress != oldProgress) // ������� ������ �ƴٰ� �Ǵ�
				std::cout << ".";
			oldProgress = progress; // ����
		}
		
		// ������ �κ� �����ϱ� -> ���ۺ��� ���� �������̱� ������, ���۸� �ʱ�ȭ�ؾ� �Ѵ�
		// �׷��� ����ġ ���� �κб��� ���簡 �ȵȴ�
		memset(buffer, '\0', BUFFER_SIZE); // ��ü ���۸� \0 ������ �ʱ�ȭ

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


int main() {
	try	{
		BinaryFileCopy();
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}
