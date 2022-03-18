#include <iostream>
using namespace std;

class Test {
public:
	Test() {
		cout << "Test()" << endl;
	}
	~Test() {
		cout << "~Test()" << endl;
	}
};


void func1() {
	// 함수 내에서 로컬 변수를 만들고
	Test t{};

	// 중간에 exception 이 발생한다면
	throw runtime_error{"func error"};

	// Stack Unwinding
	// 호출했던 함수 스택을 자동으로 정리 => 함수 내 로컬 변수를 스스로 정리한다
	// 자동으로 dtor 호출, 그냥 scope 끝나니까 변수들이 사라지는 거지
}


void func2() {
	// 함수 내에서 Heap 메모리를 할당, 리소스를 사용한다면
	Test* pt = new Test{};

	// 중간에 exception 이 발생했을 때
	throw runtime_error{ "func error" };

	// 로컬 변수만 정리하기 때문에, 리소스 정리는 이루어 지지 않는다 => dtor 호출되지 않음
	// Memory Leak
	delete pt;
}


#include <memory>
#include <vector>
void func3() {
	// 그래서 만약 함수 내에서 리소스를 할당하고자 한다면, 스마트 포인터를 써야 한다
	// 만약 중간에 함수가 갑작스럽게 종료가 되더라도, 스마트 포인터의 dtor => 리소스를 해제해준다
	unique_ptr<Test> upt{ new Test{} };


	// 아니면 STL 을 사용 => 자동으로 메모리를 관리해준다
	vector<int> vec{};
	vec.reserve(100); // vector :: reserve() => 일정 크기 메모리를 확보


	/*
		직접 메모리를 관리하는 것을 피하고
		samrt pointer 와 container 를 사용하라
	*/


	throw runtime_error{ "func error" };
}


int main() {
	try {
		//func1();
		//func2();
		func3();
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}
}


