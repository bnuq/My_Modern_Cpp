#include <iostream>
#include <fstream>

int main()
{
	int x{ 5 };
	auto f = [y = x](int arg)
	{
		return y + arg;
	};

	std::cout << f(9) << std::endl; // 9+5 출력


	// 파일을 쓰고자 한다
	std::ofstream out{ R"(./Sect_13/157_file.txt)" };

	/*
	* 파일을 쓰는 작업을 람다 함수를 통해서 진행하고 싶은데
	* 다른 곳에서는 진행하지 못하게 하고 싶다
	* 람다 함수가 단순히 capturing 하는 것에 그치지 않고
	* 직접 내부에서 변수를 생성해 저장하도록 한다 = Generalized Lambda Capture
	* 그러면, 외부와 구분이 된다
	*/
	// ofstream = non-copyable => move 를 통해 넘긴다
	// 파일이 연결된 스트림이 람다 표현식 변수에 저장
	// 이제 람다에서만 접근이 가능하다
	// 파일을 쓴다 => ofstream 에 변화를 주니까, mutable
	auto fileWrite = [out = std::move(out)](int x) mutable
	{
		out << x;
	};
	fileWrite(1000);
	out << 200; // 이 범위에서 out 은 더이상 파일에 연결되지 않음 => 파일에 쓸 수 없다


}