#include <iostream>
#include <fstream>


int main() {

	int x{ 5 };

	/*
		Generalized Capture
		Capture List 에서 새로운 변수를 만들 수 있다
		변수는 반드시 바깥에서 Capture 한 변수로 초기화 되어야 한다
		바깥 변수와 같은 이름을 가질 수 있다
		Caputure by Value, Capture by Reference 모두 가능하다
	*/
	auto f = [y = x](int arg) { // Lambda Expression 에서만 사용할 변수 y 를 새로 만들었다
		return y + arg;
	};
	std::cout << f(9) << std::endl; // 9+5 출력


	/*
		Out Filestream
		File <- Stream, 파일에 내용을 쓰고자 한다
	*/
	std::ofstream out{ R"(./Files/157 file.txt)" };

	/*
		파일에 문자열을 쓰는 작업을 람다 함수를 통해서 진행하고 싶은데
		다른 곳에서는 파일 스트림에 접근하지 못하게 하고 싶다
	
		따라서 Generalized Capture 를 사용
		람다 표현식에서 직접 변수를 생성해 사용하면
		람다 표현식이 끝날 때 같이 사라지므로 => 더이상 다른 곳에서 이용하지 못한다
		따라서 외부와 구분 지을 수 있다
	
		ofstream = non-copyable => std::move() 를 통해 넘긴다
		파일이 연결된 스트림이 람다 표현식 변수에 저장 => 람다 표현식 내부로 범위가 바뀌었다
		이제 람다에서만 접근이 가능하다
		파일을 쓴다 => ofstream 에 변화를 준다 => 멤버 변수가 바뀐다 => mutable
	*/
	auto fileWrite = [out = std::move(out)](int x) mutable {
		out << x << std::endl;
	};
	fileWrite(1000);

	/*
		std::move() 했기 때문에, 기존에 람다 밖에 있던 out ofstream 은 nullptr 을 가리키고 있다
		이 out 은 더이상 파일에 연결되지 않음 => 파일에 쓸 수 없다
	*/
	// out << 200;

	// ostream 이 넘어간, lambda expression 에서만 파일에 접근이 가능하다
	fileWrite(200);
}