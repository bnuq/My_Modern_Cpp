/*
	String Stream
		IOstream 과 비슷
		internally maintain the string buffer
		all operations performed in string buffer

	#include <sstream> => 아래 것들이 모두 포함된다
		stringstream
		istringstream		only read
		ostringstream		only write
*/
#include <iostream>
#include <sstream> // String Stream

void num1() {
	int a{ 5 }, b{ 6 };
	int sum{ a + b };

	std::stringstream ss{};

	// string stream => can convert a primitive type to a string object
	// << operator 를 이용해서 string buffer 에 넣음으로서
	// 들어오는 primitive type 을 string 으로 바꿀 수 있다
	// create formatted string => 원하는 형식의 string 을 만드는 데 유용
	ss << "Sum of " << a << " and " << b << " is : " << sum << std::endl;

	// 이제 string stream 안에 들어있는, string 을 빼낼 때 => str() method 사용
	// str() method 의 2가지 사용 방법
	std::string s = ss.str();		// 1. string buffer's string return
	std::cout << s << std::endl;

	ss.str("abcdef");				// 2. string buffer 값 재설정
	std::cout << ss.str() << std::endl;

	ss.str("");						// => string buffer clear
	ss << sum;	// string stream 에 들어가면서, int => string 으로 자동 변환
	auto ssum = ss.str();
	std::cout << ssum << std::endl;

	// 아니면 함수를 이용
	// to_string 함수를 이용하면 모든 primitive type -> string 변환 가능
	auto ssum2 = std::to_string(sum);
	std::cout << ssum2 << std::endl;
}


void num2() {
	/*
		반대로 string stream 에서 string 을 읽을 수 있는데
		주로 parsing 하는데 사용한다
	*/
	std::string data = "12 89 21";
	int a;
	std::stringstream ss;
	ss.str(data);	// set data string to string stream

	// fail method => fail bit check = set when fail to read any more input
	// 읽는 것을 실패하면 fail bit 값이 바뀌는데, 그 값을 확인
	if (ss.fail()) return;

	while (ss >> a) { // string buffer 에서 string 을 하나 읽어 냄
					  // space, 빈공간을 delimiter 로 사용
					  // 실패 시 바로 return false, fail bit 값 변경한다

		// 값을 받는 변수 a 가 int type 이므로 => stringstream 에서 읽은 값을 int 로 저장한다
		std::cout << a << std::endl;
		// 결과적으로 string buffer 에 저장되어 있던 string 을 int 로 바꾸었다
	}

	// 함수 이용하는 방법
	// 그런데 사실 이미 string => primitive type 으로 바꾸는 함수가 존재한다
	// stoi, 그리고 기타 등등
	int x = std::stoi("122");
	std::cout << x << std::endl;
}


#include <typeinfo> // type 확인에 필요
int main() {
	num2();

	std::string data{ "12 345 67" };
	std::stringstream ss{ data }; // string stream 의 버퍼를 string 으로 바로 초기화
	/*
		string stream 에서 값을 읽어올 때
		값을 받는 변수의 타입에 맞춰서, string stream 에서 읽은 데이터를 저장한다

		즉 int type 이 받으면, string -> int 로 바꾸어 저장
		char type 이 받으면, string -> char 로 바꾸어 저장

		12, 345, 67
		1, 2, 3, 4, 5, 6, 7
	*/
	//int c{};
	char c{};
	while (ss >> c) {
		std::cout << typeid(c).name() << " : " // 변수의 타입을 출력
				  << c << std::endl;
	}
}