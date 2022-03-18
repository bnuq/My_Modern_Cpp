#include <iostream>

template <typename T>
T Divide(T a, T b)
{
	// type traits 도 compile time 에 결정되고 static assert 도 컴파일 타임 때 참, 거짓 따진다
	// 따라서 둘을 같이 이용하면 맞지 않는 타입에 대해서는 컴파일을 피할 수 있다
	static_assert(std::is_floating_point<T>::value, "Use floating point types only");

	// floating point type 에 대해서만 나눗셈을 진행하게 하고 싶다
	// 그래서 metaprogramming 과 잘 쓰인다~
	//if (std::is_floating_point<T>::value == false)
	//{
	//	std::cout << "Use floating point types only" << std::endl;
	//	return 0;
	//}
	//else
	
	return a / b;
}


int main()
{
	// static assertion, compile time 에 결정된다
	// = 프로그램 실행하기 전에 참, 거짓 여부를 알 수 있다
	// message 와 함께 쓴다, false 인 경우 컴파일되지 않으며 message 출력
	// 아예 빌드하기 전에 에러 표시뜬다
	static_assert(sizeof(void*) == 4, "It is not 32-bit Mode");
	
	// runtime, 즉 프로그램이 실행되고 나서 참,거짓이 결정된다
	if (sizeof(void*) != 4)
		std::cout << "It is not 32-bit Mode" << std::endl;


	//Divide(9, 3);
	std::cout << Divide(9.0f, 3.0f) << std::endl;
}