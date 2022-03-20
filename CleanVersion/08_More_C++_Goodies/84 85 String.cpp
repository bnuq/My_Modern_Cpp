#include <cstring> // for c-style string = Raw String
#include <iostream>
using namespace std;

// c-style string 2���� ���̷��� �Ѵ�
const char* cStyleCombine(const char* pFirst, const char* pLast) {
	/*
		char fullname[20];  ���� �ȵȴ�
		1. ���� ������ �Լ� ���� �� ������⿡,
		�� ������ �����ϸ� �Լ� ���� �޴� �ʿ����� ������ ���� �ް� �ȴ� => �����Ҵ� �޸� �ּҸ� ����

		2. ������ �迭 ũ��, �̸� ���̸� ���� ���Ѵ� => ���� ���� �޸� �Ҵ����� �ذ�

		3. ���ڿ��� �������� �ι��ڷ� ������ �ϹǷ�, �װͱ��� ����ؾ� �Ѵ� => ũ�� ���

		4. ���� �̸� ������ heap �޸𸮿� �����߱� ������, ����Ŀ��� ���� �ش� �޸𸮸� �������־�� �Ѵ�
	*/
	char* fullname = new char[ strlen(pFirst) + strlen(pLast) + 1]; // �����Ҵ�
	strcpy(fullname, pFirst); // first name �� �����ϰ�  , strcpy function
	strcat(fullname, pLast); // last name �� �̾� ���δ� , strcat function

	return fullname;	// �����Ҵ��� �޸� �ּҸ� ����
}

void cStyleString() {
	// first name, last name �� �Է¹ް� ���� ��ģ string �� ������
	char first[10];
	char last[10];

	// c-style string ������ �׳� cin �� ���� �Է¹��� �� �ִ� => withe space ����
	char test[10];
	std::cin >> test;
	std::cout << test << std::endl;

	// c-style string ���� ������� �Է¹��� ���� cin.getline()
	cin.getline(first, 10);
	cin.getline(last, 10);

	const char* pFullName = cStyleCombine(first, last);
	// Insert into the database
	cout << pFullName << endl;

	delete[] pFullName;
	// 4. �޸� ���� ~ �Լ� ȣ���� ���忡���� �̰� �׳� �����Ҵ� �޸����� �����Ҵ� �迭���� �� �� ����
	// ���� ���� ȣ���� �Լ��� ����, �׳� Ÿ������ �迭 Ÿ������ Ȯ���ؾ� �Ѵ�
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
#include <string> // string header file for C++ String

void CppString() {
	// Initialize & assign
	std::string str;			// default constructor => empty

	/*
		"��¼�� ��¼��" <= �� ��ü�� Raw String = C-Style String
		const char[size] Ÿ���̴� + �ι��ڱ��� �ڵ����� �����Ѵ�
	*/
	std::string s = "Hello";	// parameterized constructor => raw string ���
	s = "World";				// assign raw string �� ����

	// Access
	s[0] = 'A';
	char ch = s[0];				// subscript �� ��� ����

	// overloaded on stream operator
	std::cout << s << std::endl;

	// C++ String ������ cin �� ���� �Է� ���� => white space ������ �Է��� ��
	std::cin >> s;
	getchar(); // ���ۿ� ����� ���๮�� ������

	// C++ Style String ���� ������� �Է¹��� ���� std::getline() �̿�
	// ���� ������ ���� => �˾Ƽ� �ٽ� �޸� �Ҵ��� ���ִϱ�
	std::getline(std::cin, s);	// ��ü ���� �Է�

	// Size
	std::cout << s.length() << std::endl;	// caches the length
	std::cout << s.size() << std::endl;		// length() == size()

	// Insert & Concatenate
	std::string s1{ "Hello" }, s2{ "World" }; // uniform initialization �̿�
	s = s1 + s2;				// concatenate => �ܼ� ������ ��밡��
	s += s1;

	//s.insert(s.begin(), "test"); iterator �� �̿��� insert �� �Ұ���
	s.insert(6, "Mine");		// Ư�� ��ġ �ε����� string �� ����

	// Comparison
	if (s1 != s2) {}

	// Removal
	s.erase(0, 4);	// Ư�� ���� ����

	s.erase();		// ��ü ����
	s.clear();
	

	// Search
	// ** find method ** ã���� �ϴ� raw string or string object, ã�� �� �����ϴ� ��ġ
	auto pos = s.find("World", 0);	// 0 �ε������� ���� ~ "World" �� ã�ƶ�

	// substring �� ã�� ��ġ ����
	// substring �� ���ٸ�, string::npos ��� ��� ����
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


// c-style �� �ʿ��� ��
void num3() {
	std::string name{ "crazyMan" };

	// standard string �� �ƴ� raw string �� �ʿ��� ��� => c_str() method
	printf("%s", name.c_str());
}


void num4() {
	// standard string initialization
	std::string s1 = "Umar";
	std::string s2("Umar");
	std::string s3{ "Umar" }; // prefer

	using namespace std::string_literals;
	auto s4 = "Umar"s; // s = string �� ��Ÿ���� ����
	// s �� �Ἥ => "Umar" �� std::string type �̶�� ���� �˸� => auto �� �װ� �����鼭, �ڵ����� string Ÿ���� �ȴ�
	// => �̷� ������ ���̴� ���ڸ� literal �̶� �Ѵ�

	std::string test{ "111" };
	// "111" = const char[4] Ÿ���� ������
	auto test2{ "111" };  // const char* type
	auto test3{ "111"s }; // std::string type

	//test2.length();
	test3.length();
}



// assigment 1
#include <cctype> // toupper(), tolower() ����� ����
std::string ToUpper(const std::string& str) {
	std::string retStr; // empty
	
	// ���ڿ��� ��� ���� => range-based for loop ���
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
	/*std::string s;
	std::getline(std::cin, s);

	std::cout << ToUpper(s) << std::endl;
	std::cout << ToLower(s) << std::endl;*/

	num4();
}