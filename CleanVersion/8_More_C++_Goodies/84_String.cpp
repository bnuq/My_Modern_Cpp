#include <cstring> // for c-style
#include <iostream>
using namespace std;


const char* cStyleCombine(const char* pFirst, const char* pLast) {

	/*
		char fullname[20];  ���� �ȵȴ�
		1. ���� ������ �Լ� ���� �� ������⿡,
		�� ������ �����ϸ� �Լ� ���� �޴� �ʿ����� ������ ���� �ް� �ȴ�

		2. ������ �迭 ũ��, �̸� ���̸� ���� ���Ѵ�

		=> ���� ���� �޸� �Ҵ����� �ذ�

		3. ���ڿ��� �������� �ι��ڷ� ������ �ϹǷ�, �װͱ��� ����ؾ� �Ѵ�

		4. ���� �̸� ������ heap �޸𸮿� �����߱� ������, ����Ŀ���
		���� �ش� �޸𸮸� �������־�� �Ѵ�
	*/
	char* fullname = new char[ strlen(pFirst) + strlen(pLast) + 1];
	strcpy(fullname, pFirst);
	// first name �� �����ϰ�

	strcat(fullname, pLast);
	// last name �� �̾� ���δ�

	return fullname;
}


void cStyleString() {
	// first name, last name �� �Է¹ް� ���� ��ģ string �� ������

	char first[10];
	char last[10];
	cin.getline(first, 10);
	cin.getline(last, 10);

	const char* pFullName = cStyleCombine(first, last);
	// Insert into the database

	cout << pFullName << endl;

	delete[] pFullName;
	// 4. �޸� ���� ~ �Լ� ȣ���� ���忡���� �̰� � Ÿ���� �ּ����� �𸣱⿡
	// ȣ���� �Լ��� Ȯ���ؼ�, �׳� Ÿ������ �迭 Ÿ������ Ȯ���ؾ� �Ѵ�
}


/*
	C-Style String
	error prone
	complex
	������ ���λ����� �ʹ� ����
	ì�ܾ��ϴ� ������ �ʹ� ����
*/


/*
	C++ => String Class 
	�޸� �Ҵ�, ���� �ڵ����� ó��
	���� �Լ� ����
*/
#include <string> // string header file

void CppString() {
	// Initialize & assign
	std::string str;			// default constructor => empty
	std::string s = "Hello";	// parameterized constructor => raw string ���
	s = "World";				// assign raw string

	// Access
	s[0] = 'A';
	char ch = s[0];				// subscript �� ��� ����

	// overloaded on stream operator
	std::cout << s << std::endl;
	std::cin >> s;				// white space ������ �Է�
	std::getline(std::cin, s);	// ��ü ���� �Է�

	// Size
	std::cout << s.length() << std::endl;	// caches the length

	// Insert & Concatenate
	std::string s1{ "Hello" }, s2{ "World" }; // uniform initialization
	s = s1 + s2;				// concatenate
	s += s1;

	s.insert(6, "Mine");		// Ư�� ��ġ�� string �� ����

	// Comparison
	if (s1 != s2) {}

	// Removal
	s.erase();		// ��ü ����
	s.clear();
	s.erase(0, 4);	// Ư�� ���� ����

	// Search
	// find method, ã���� �ϴ� raw string or string object, ã�� �� �����ϴ� ��ġ
	auto pos = s.find("World", 0);
	// substring �� ã�� ��ġ ����
	// substring �� ���ٸ�, string::npos ��� ��� ����

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


// c-style �� �ʿ��� ��
void num3() {
	std::string name{ "crazyMan" };

	// standard string �� �ƴ� raw string �� �ʿ��� ��� => c_str method
	printf("%s", name.c_str());
}


void num4() {
	// standard string initialization
	std::string s1 = "Umar";
	std::string s2("Umar");
	std::string s3{ "Umar" }; // prefer

	using namespace std::string_literals;
	auto s4 = "Umar"s; // s = string �� ��Ÿ���� ���� 
						//	=> �̷� ������ ���̴� ���ڸ� literal �̶� �Ѵ�
}



// assigment 1
#include <cctype>
std::string ToUpper(const std::string& str) {
	std::string retStr; // empty
	
	// ���ڿ��� ��� ���� => ragne-based for loop ���
	for (auto i : str)
		retStr += toupper(i);
	
	return retStr;
}


std::string ToLower(const std::string& str) {
	std::string retStr; // empty

	// ���ڿ��� ��� ���� => ragne-based for loop ���
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