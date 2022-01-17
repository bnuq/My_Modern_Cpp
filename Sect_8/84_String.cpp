#include <cstring> // for c-style
#include <iostream>
using namespace std;


const char* cStyleCombine(const char* pFirst, const char* pLast) {

	/*
		char fullname[20];  쓰면 안된다
		1. 지역 변수는 함수 종료 후 사라지기에,
		이 변수를 리턴하면 함수 값을 받는 쪽에서는 쓰레기 값을 받게 된다

		2. 고정된 배열 크기, 이름 길이를 알지 못한다

		=> 따라서 동적 메모리 할당으로 해결

		3. 문자열은 마지막에 널문자로 끝나야 하므로, 그것까지 계산해야 한다

		4. 현재 이름 정보는 heap 메모리에 저장했기 때문에, 사용후에는
		직접 해당 메모리를 해제해주어야 한다
	*/
	char* fullname = new char[ strlen(pFirst) + strlen(pLast) + 1];
	strcpy(fullname, pFirst);
	// first name 을 복사하고

	strcat(fullname, pLast);
	// last name 을 이어 붙인다

	return fullname;
}


void cStyleString() {
	// first name, last name 을 입력받고 둘을 합친 string 을 구하자

	char first[10];
	char last[10];
	cin.getline(first, 10);
	cin.getline(last, 10);

	const char* pFullName = cStyleCombine(first, last);
	// Insert into the database

	cout << pFullName << endl;

	delete[] pFullName;
	// 4. 메모리 해제 ~ 함수 호출자 입장에서는 이게 어떤 타입의 주소인지 모르기에
	// 호출한 함수를 확인해서, 그냥 타입인지 배열 타입인지 확인해야 한다
}


/*
	C-Style String
	error prone
	complex
	복잡한 세부사항이 너무 많다
	챙겨야하는 사항이 너무 많다
*/


/*
	C++ => String Class 
	메모리 할당, 해제 자동으로 처리
	여러 함수 제공
*/
#include <string> // string header file

void CppString() {
	// Initialize & assign
	std::string str;			// default constructor => empty
	std::string s = "Hello";	// parameterized constructor => raw string 사용
	s = "World";				// assign raw string

	// Access
	s[0] = 'A';
	char ch = s[0];				// subscript 로 요소 접근

	// overloaded on stream operator
	std::cout << s << std::endl;
	std::cin >> s;				// white space 까지만 입력
	std::getline(std::cin, s);	// 전체 문장 입력

	// Size
	std::cout << s.length() << std::endl;	// caches the length

	// Insert & Concatenate
	std::string s1{ "Hello" }, s2{ "World" }; // uniform initialization
	s = s1 + s2;				// concatenate
	s += s1;

	s.insert(6, "Mine");		// 특정 위치에 string 을 삽입

	// Comparison
	if (s1 != s2) {}

	// Removal
	s.erase();		// 전체 제거
	s.clear();
	s.erase(0, 4);	// 특정 범위 제거

	// Search
	// find method, 찾고자 하는 raw string or string object, 찾는 걸 시작하는 위치
	auto pos = s.find("World", 0);
	// substring 을 찾은 위치 리턴
	// substring 이 없다면, string::npos 라는 상수 리턴

	if (pos != std::string::npos) {
		// Found
	}
}


void CppStringCombine() {
	std::string first;
	std::string last;

	std::getline(std::cin, first);
	std::getline(std::cin, last);

	std::string fullname = first + last;

	std::cout << fullname << std::endl;
}


// c-style 이 필요할 때
void num3() {
	std::string name{ "crazyMan" };

	// standard string 이 아닌 raw string 이 필요한 경우 => c_str method
	printf("%s", name.c_str());
}


void num4() {
	// standard string initialization
	std::string s1 = "Umar";
	std::string s2("Umar");
	std::string s3{ "Umar" }; // prefer

	using namespace std::string_literals;
	auto s4 = "Umar"s; // s = string 을 나타내는 문자 
						//	=> 이런 식으로 쓰이는 문자를 literal 이라 한다
}



// assigment 1
#include <cctype>
std::string ToUpper(const std::string& str) {
	std::string retStr; // empty
	
	// 문자열을 모두 돌아 => ragne-based for loop 사용
	for (auto i : str)
		retStr += toupper(i);
	
	return retStr;
}


std::string ToLower(const std::string& str) {
	std::string retStr; // empty

	// 문자열을 모두 돌아 => ragne-based for loop 사용
	for (auto i : str)
		retStr += tolower(i);

	return retStr;
}


int main() {
	std::string s;
	std::getline(std::cin, s);

	std::cout << ToUpper(s) << std::endl;
	std::cout << ToLower(s) << std::endl;
}