#include <iostream>

int main() {
	int a{ 5 }, b{ 2 };
	float c = a; // implicit conversion
	// float c{ a };  uniform initializaion => implicit conversion 을 막는다
	float d = a / b; // 5/2 = 2 => 2.0
	
	// C-Style Conversion
	float f1 = (float)a / b;
	char* p1 = (char*)(&a); // 유효성 검사를 하지 않는다

	// C++ Style Conversion => compile time 에 작동
	// static_cast
	float f2 = static_cast<float>(a) / b;
	// char* p2 = static_cast<char*>(&a);  static_cast => 유효성 검사 진행, 바꾸기 전에 확인한다
	
	// reinterpret_cast => C-style 과 유사, 전혀 다른 타입이여도 변환을 시켜준다
	char* p3 = reinterpret_cast<char*>(&a);
	// 다른점 = const, voliatile 같은 qualifier 를 유지한다, 버리지 못한다
	const int x = 1;
	int* ip1 = (int*)(&x);
	/*
		const int* => 그냥 int* 로 바꾸려는 시도 => 둘다 불가능 
		int* ip2 = static_cast<int*>(&x);
		int* ip3 = reinterpret_cast<int*>(&x);
	*/

	// const_cast => reinterpret_cast 가 못한, const qualifier 를 떼는 기능을 수행한다
	const int xx = 2;
	int* ip4 = const_cast<int*>(&xx);
	// float ip5 = const_cast<float>(xx);  대신 const 떼는 거 말고는 못한다

	// dynamic_cast => run time 에 작동??
}