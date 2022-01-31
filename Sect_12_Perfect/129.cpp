#include <iostream>

// Old Code
// Overloading
//int Max(int x, int y) {
//	return x > y ? x : y;
//}
//float Max(float x, float y) {
//	return x > y ? x : y;
//}

//Primary Template
//template<class T> 도 가능
template<typename T>
T Max(T x, T y) {
	std::cout << typeid(T).name() << std::endl;
	return x > y ? x : y;
}

int main()
{
	// instantiation
	// 어떤 타입이 함수를 필요로 하면, 컴파일러가 함수를 만든다
	// argument 를 통해서 타입 추론
	auto num = Max(9.0f, 0.3f);
	std::cout << num << std::endl;

	auto num2 = Max(9, 3);
	std::cout << num2 << std::endl;


}