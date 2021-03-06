#include <cstring> // for c-style string = Raw String
#include <iostream>
using namespace std;

// c-style string 2개를 붙이려고 한다
const char* cStyleCombine(const char* pFirst, const char* pLast) {
	/*
		char fullname[20];  쓰면 안된다
		1. 지역 변수는 함수 종료 후 사라지기에,
		이 변수를 리턴하면 함수 값을 받는 쪽에서는 쓰레기 값을 받게 된다 => 동적할당 메모리 주소를 리턴

		2. 고정된 배열 크기, 이름 길이를 알지 못한다 => 따라서 동적 메모리 할당으로 해결

		3. 문자열은 마지막에 널문자로 끝나야 하므로, 그것까지 계산해야 한다 => 크기 계산

		4. 현재 이름 정보는 heap 메모리에 저장했기 때문에, 사용후에는 직접 해당 메모리를 해제해주어야 한다
	*/
	char* fullname = new char[ strlen(pFirst) + strlen(pLast) + 1]; // 동적할당
	strcpy(fullname, pFirst); // first name 을 복사하고  , strcpy function
	strcat(fullname, pLast); // last name 을 이어 붙인다 , strcat function

	return fullname;	// 동적할당한 메모리 주소를 리턴
}

void cStyleString() {
	// first name, last name 을 입력받고 둘을 합친 string 을 구하자
	char first[10];
	char last[10];

	// c-style string 에서도 그냥 cin 을 통해 입력받을 수 있다 => withe space 제외
	char test[10];
	std::cin >> test;
	std::cout << test << std::endl;

	// c-style string 에서 공백까지 입력받을 때는 cin.getline()
	cin.getline(first, 10);
	cin.getline(last, 10);

	const char* pFullName = cStyleCombine(first, last);
	// Insert into the database
	cout << pFullName << endl;

	delete[] pFullName;
	// 4. 메모리 해제 ~ 함수 호출자 입장에서는 이게 그냥 동적할당 메모리인지 동적할당 배열인지 알 수 없다
	// 따라서 직접 호출한 함수를 통해, 그냥 타입인지 배열 타입인지 확인해야 한다
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
#include <string> // string header file for C++ String

void CppString() {
	// Initialize & assign
	std::string str;			// default constructor => empty

	/*
		"어쩌고 저쩌고" <= 이 자체가 Raw String = C-Style String
		const char[size] 타입이다 + 널문자까지 자동으로 포함한다
	*/
	std::string s = "Hello";	// parameterized constructor => raw string 사용
	s = "World";				// assign raw string 도 가능

	// Access
	s[0] = 'A';
	char ch = s[0];				// subscript 로 요소 접근

	// overloaded on stream operator
	std::cout << s << std::endl;

	// C++ String 에서도 cin 을 통한 입력 가능 => white space 까지만 입력할 때
	std::cin >> s;
	getchar(); // 버퍼에 저장된 개행문자 뺴내기

	// C++ Style String 에서 공백까지 입력받을 때는 std::getline() 이용
	// 길이 제한이 없다 => 알아서 다시 메모리 할당을 해주니까
	std::getline(std::cin, s);	// 전체 문장 입력

	// Size
	std::cout << s.length() << std::endl;	// caches the length
	std::cout << s.size() << std::endl;		// length() == size()

	// Insert & Concatenate
	std::string s1{ "Hello" }, s2{ "World" }; // uniform initialization 이용
	s = s1 + s2;				// concatenate => 단순 연산자 사용가능
	s += s1;

	//s.insert(s.begin(), "test"); iterator 를 이용한 insert 는 불가능
	s.insert(6, "Mine");		// 특정 위치 인덱스에 string 을 삽입

	// Comparison
	if (s1 != s2) {}

	// Removal
	s.erase(0, 4);	// 특정 범위 제거

	s.erase();		// 전체 제거
	s.clear();
	

	// Search
	// ** find method ** 찾고자 하는 raw string or string object, 찾는 걸 시작하는 위치
	auto pos = s.find("World", 0);	// 0 인덱스에서 부터 ~ "World" 를 찾아라

	// substring 을 찾은 위치 리턴
	// substring 이 없다면, string::npos 라는 상수 리턴
	if (pos != std::string::npos) {
		// Found
		std::cout << pos << std::endl;
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

	// standard string 이 아닌 raw string 이 필요한 경우 => c_str() method
	printf("%s", name.c_str());
}


void num4() {
	// standard string initialization
	std::string s1 = "Umar";
	std::string s2("Umar");
	std::string s3{ "Umar" }; // prefer

	using namespace std::string_literals;
	auto s4 = "Umar"s; // s = string 을 나타내는 문자
	// s 를 써서 => "Umar" 가 std::string type 이라는 것을 알림 => auto 가 그걸 받으면서, 자동으로 string 타입이 된다
	// => 이런 식으로 쓰이는 문자를 literal 이라 한다

	std::string test{ "111" };
	// "111" = const char[4] 타입을 가진다
	auto test2{ "111" };  // const char* type
	auto test3{ "111"s }; // std::string type

	//test2.length();
	test3.length();
}



// assigment 1
#include <cctype> // toupper(), tolower() 사용을 위해
std::string ToUpper(const std::string& str) {
	std::string retStr; // empty
	
	// 문자열을 모두 돌아 => range-based for loop 사용
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
	/*std::string s;
	std::getline(std::cin, s);

	std::cout << ToUpper(s) << std::endl;
	std::cout << ToLower(s) << std::endl;*/

	num4();
}