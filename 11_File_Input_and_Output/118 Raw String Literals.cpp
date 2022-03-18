#include <iostream>
#include <string>

int main() {

	/*
		기존 string literal 사용 => const char[] 타입
		\ 와 같은 특정문자는 사용불가 => escape sequence 를 써주어야 한다
	*/
	std::string oldfilename{ "C:\\temp\\newfile.txt" };
	std::cout << oldfilename << std::endl;

	/*
		Raw String Literal
		R"( -- )" 와 같이 사용
		기존 "" 의 앞에 R 을 적어주고
		() 안에 원하는 문자열을 적는다 
		escape 문자를 걱정하지 않아도 된다
	*/
	std::string filename{ R"(C:\temp\newfile.txt)"};
	std::cout << filename << std::endl;

	/*
		Raw String Literal with Delimiter
		따옴표와 괄호 사이에 특정 문자, delimiter 를 지시할 수 있다
		그래서 문자열 리터럴 중간에 따옴표나 괄호가 들어가도, 문제 없이 쓸 수 있다
			delimiter 덕분에 경계가 명확하게 표현되니까
	*/
	std::string message{ R"msgg(C++ indroduced filesystem API"(In C++17)")msgg" };
	std::cout << message << std::endl;


	return 0;
}