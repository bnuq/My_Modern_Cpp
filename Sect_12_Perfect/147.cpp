#include <iostream>
#include <type_traits>

template <typename T>
T Divide(T a, T b)
{
	// floating point type 에 대해서만 나눗셈을 진행하게 하고 싶다
	// 그래서 metaprogramming 과 잘 쓰인다~
	if (std::is_floating_point<T>::value == false)
	{
		std::cout << "Use floating point types only" << std::endl;
		return 0;
	}
	else return a / b;
}


template <typename T>
void Check(T&&) // r-value template type => l or r - value reference 로 T 가 받는다
{
	std::cout << std::boolalpha
		<< "Is T l-value reference? " << std::is_reference<T>::value << std::endl;

	std::cout << "After removing reference, "
		<< std::is_reference< typename std::remove_reference<T>::type >::value << std::endl;
}


int main()
{
	std::cout << std::boolalpha // = bool type 에서 0,1 대신에 true, false 출력
		<< "is int integer? : " << std::is_integral<int>::value << std::endl;

	std::cout << Divide(9, 4) << std::endl;
	std::cout << Divide(9.0f, 4.0f) << std::endl;

	Check(5);
	int value{ 5 };
	Check(value);
}