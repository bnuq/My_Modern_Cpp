#include <iostream>
#include <vector>
#include <list>


// 임의의 function
const char* GetErrorMessage(int errorNo) {
	return "Empty";
}


/*
	typedef

	이미 존재하는 타입에 간단한 이름을 부여
	옛날 방식
*/
typedef unsigned int typedefUInt;
typedef const char *(*typedefPEN)(int); // function pointer 의 경우, 괄호 안에 typedef 이름이 들어간다
typedef std::vector < std::list<std::string>> typedefNames;



/*
	Type Alias

	역시 존재하는 타입에 간단한 이름을 부여
	using 을 사용
	더 보기 쉽다
*/
using UInt = unsigned int;
using PFN = const char *(*)(int); // function pointer 의 경우에도 보기 쉽다
using Names = std::vector<std::list<std::string>>;

// Type Alias 를 적용한 예
void ShowError(PFN pfn){
	
}



/*
	Alias Template

	Type Alias + Template
	템플릿을 받는 타입 에 대해서 ~
	Template Parameter 를 이용하는 타입에 Type Alias 를 적용할 수 있다
*/
template<typename T>
using NamesT = std::vector<std::list<T>>;




int main() {

	// Type Alias 이용
	PFN pfn = GetErrorMessage;
	ShowError(pfn);
	Names names;

	
	// Alias Template 이용
	// 이용하고 싶은 타입을 넣어서 => 새로운 타입을 만들 수 있다
	// 근데 간단한 이름을 사용할 수 있다
	NamesT<std::string> namest{};
	NamesT<NamesT<int>> namest2{};
	// NamesT namest3{}; typename T 를 유추할 수가 없다


	return 0;
}
