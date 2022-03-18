#include <iostream>
#include <type_traits>

template <typename T>
T Divide(T a, T b)
{
	// floating point type �� ���ؼ��� �������� �����ϰ� �ϰ� �ʹ�
	// �׷��� metaprogramming �� �� ���δ�~
	if (std::is_floating_point<T>::value == false)
	{
		std::cout << "Use floating point types only" << std::endl;
		return 0;
	}
	else return a / b;
}


template <typename T>
void Check(T&&) // r-value template type => l or r - value reference �� T �� �޴´�
{
	std::cout << std::boolalpha
		<< "Is T l-value reference? " << std::is_reference<T>::value << std::endl;

	std::cout << "After removing reference, "
		<< std::is_reference< typename std::remove_reference<T>::type >::value << std::endl;
}


int main()
{
	std::cout << std::boolalpha // = bool type ���� 0,1 ��ſ� true, false ���
		<< "is int integer? : " << std::is_integral<int>::value << std::endl;

	std::cout << Divide(9, 4) << std::endl;
	std::cout << Divide(9.0f, 4.0f) << std::endl;

	Check(5);
	int value{ 5 };
	Check(value);
}