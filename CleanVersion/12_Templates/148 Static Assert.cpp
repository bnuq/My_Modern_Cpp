#include <iostream>
#include <type_traits>


template <typename T>
T Divide(T a, T b) {
	/*
		type traits -> compile time 에 타입의 성질 파악
		 
		static assert -> compile time 에 expression 에 대한 평가를 끝낸다
	
		따라서 둘을 같이 이용하면 맞지 않는 타입에 대한 컴파일을 피할 수 있다
	*/
	// 앞 expression == false 인 경우, 뒤 message 와 함께 fail 을 리턴
	static_assert(std::is_floating_point<T>::value, "Use floating point types only");
		
	return a / b;
}


int main() {

	// 아예 빌드하기 전에 에러 표시뜨거나
	// static_assert(sizeof(void*) == 4, "It is not 32-bit Mode");
	
	// sizeof 연산자의 경우
	// runtime, 즉 프로그램이 실행되고 나서 참,거짓이 결정된다
	if (sizeof(void*) != 4)
		std::cout << "It is not 32-bit Mode" << std::endl;


	// Divide(9, 3); 컴파일 단계에서 에러를 발생시킴
	std::cout << Divide(9.0f, 3.0f) << std::endl;
}