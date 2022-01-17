/*
	String Stream
		IOstream 과 비슷
		internally maintain the string buffer
		all operations performed in string buffer

	#include <sstream>
	stringstream
	istringstream		only read
	ostringstream		only write
*/

#include <iostream>
#include <sstream>

void num1() {
	int a{ 5 }, b{ 6 };
	int sum{ a + b };

	std::stringstream ss;

	// string stream => can convert a primitive type to a string object
	// << operator 를 이용해서 string buffer 에 넣는다
	// create formatted string
	ss << "Sum of " << a << " and " << b << " is : " << sum << std::endl;

	// str method => 2가지 사용 방법
	std::string s = ss.str();		// 1. string buffer's string return
	std::cout << s << std::endl;

	ss.str("abcdef");				// 2. string buffer 값 재설정
	std::cout << ss.str() << std::endl;

	ss.str("");						// => string buffer clear
	ss << sum;
	auto ssum = ss.str();
	std::cout << ssum << std::endl; // int => string 으로 변환

	// to_string 함수를 이용하면 모든 primitive type -> string 변환 가능
	auto ssum2 = std::to_string(sum);
	std::cout << ssum2 << std::endl;
}


void num2() {
	/*
		반대로 string stream 에서 string 을 읽는 경우
		parsing 하는데 쓰인다
	*/
	std::string data = "12 89 21";
	int a;
	std::stringstream ss;
	ss.str(data);	// set data string to string stream

	// fail method => fail bit check = set when fail to read any more input
	// 읽는 것을 실패하고 나서, fail bit 값이 바뀌고 그걸 확인
	ss.fail();
	while (ss >> a) { // string buffer 에서 string 을 하나 읽어 냄
					  // space 를 delimiter 로 사용
					  // 실패 시 바로 return false, fail bit 값 변경한다
		// int a => stringstream 에서 읽은 값을 int 로 저장한다
		std::cout << a << std::endl;

		// 결과적으로 string buffer 에 저장되어 있던 string 을 int 로 바꾸었다
	}


	// 그런데 사실 이미 string => primitive type 으로 바꾸는 함수가 존재한다
	// stoi, 그리고 기타 등등
	int x = std::stoi("122");
	std::cout << x << std::endl;
}


int main() {
	num2();
}