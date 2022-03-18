#include <iostream>

//Primary Template
template<typename T>
T Max(T x, T y) {
	std::cout << typeid(T).name() << std::endl;
	return x > y ? x : y;
}

//Explicit Instantiation
//template 만 쓰고 template argument list 는 쓰지 않는다

// char 타입의 Max 함수를 직접 만들게 지시한다
// 호출하지 않아도 만들어진다
template char Max(char x, char y);

//Explicit Specialization
//template + empty template argument list
// 이 타입에 대해서 재정의
//template<> const char* Max(const char* x, const char* y) { 타입 지시는 옵션
template<> const char* Max<const char*>(const char* x, const char* y) {
	std::cout << "Max<const char*>()" << std::endl;
	return strcmp(x, y) > 0 ? x : y;
}

int main()
{
	// T type 은 하나, 맞춰주기
	Max(static_cast<float>(3), 6.3f);

	// 명시적으로 타입 설정하기 => 자동으로 타입변환
	Max<double>(3, 5.3f);

	// function template address 취급 => instantiation
	// function pointer 이용
	int (*pfn)(int, int) = Max;

	const char* a{ "A" };
	const char* b{ "B" };
	std::cout << Max(a, b) << std::endl;

	return 0;
}
