#include <iostream>
#include <fstream>
#include <filesystem>
void Alloc() {
	int* p = (int*)malloc(sizeof(int));
	if (p != nullptr) {
		*p = 50;
		free(p);
	}
	// ��, �Ʒ� ���� ����

	//if (initialization ; condition) {
	// if �� �� ���������� ����ϴ� ���� �ʱ�ȭ�ϰ�, Ư�� ������ ���� if �� ����
	// if, else if, else ��� ���� ���� => ����� ��� �Ұ���
	if (int* p = (int*)malloc(sizeof(int)); p != nullptr) {
		*p = 50;
		free(p);
	}
	else {
		//Here p will be nullptr
		// p �� ������ �����ϴ�
	}
}


void Write(const std::string& data) {
	std::ofstream out{ "file.txt" };
	if (out) {
		if (data.empty()) {
			std::cout << data;
		}
		else {
			std::cout << "No data to write ";
		}
	}


	// if with initialization
	// if �� �������� ����ϴ� ���� out, if ���� ����� ���� �Ұ���
	// ���ÿ� condition �� ���ؼ� Ư�� ������ ������ �� �ִ�
	if (std::ofstream out{ "file.txt" }; out and !data.empty()) {
		std::cout << data;
	}
	else {
		std::cout << "no data to write \n";
	}
}


void UsingSwitch(int errorCode) {
	// switch with initialization
	switch (std::ofstream out{ "file.txt" }; errorCode) {
	case 0:
		out << "Invalid parameter";
		break;
	case 1:
		out << "Could not read from file";
		break;
	}
}
int main() {
	UsingSwitch(1);
}