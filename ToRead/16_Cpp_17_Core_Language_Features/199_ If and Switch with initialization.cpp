#include <iostream>
#include <fstream>
#include <filesystem>
void Alloc() {
	int* p = (int*)malloc(sizeof(int));
	if (p != nullptr) {
		*p = 50;
		free(p);
	}
	// 위, 아래 같은 내용

	//if (initialization ; condition) {
	// if 문 내 범위에서만 사용하는 변수 초기화하고, 특정 조건일 때만 if 내 진입
	// if, else if, else 모두 접근 가능 => 벗어나면 사용 불가능
	if (int* p = (int*)malloc(sizeof(int)); p != nullptr) {
		*p = 50;
		free(p);
	}
	else {
		//Here p will be nullptr
		// p 에 접근은 가능하다
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
	// if 문 내에서만 사용하는 변수 out, if 문을 벗어나면 접근 불가능
	// 동시에 condition 을 통해서 특정 조건을 지정할 수 있다
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