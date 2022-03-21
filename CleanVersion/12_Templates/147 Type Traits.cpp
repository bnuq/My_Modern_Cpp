#include <iostream>

/*
	Type Trait

	Ÿ�Կ� ���ؼ� ������ �� �ֵ��� ������
	
	���ø��� �׻� ������ type �� ���� �� �ִµ�,
	�̶� Ư�� Ÿ�Կ� ���ؼ��� � ������ ����� �ʹ�
		Ÿ���� ������ �ʿ䰡 �ְ�
		�׷��� type trait �� ���

	�׷��� metaprogramming �� �� ���δ�~

	compile time �� Ÿ�Կ� ���� ���縦 �����Ѵ�?
*/
#include <type_traits>


template <typename T>
T Divide(T a, T b) {
	/*
		floating point type �� ���ؼ��� �������� �����ϰ� �ϰ� �ʹ�	
		�׷��� type_trait �Լ��� �̿� => ���Ƿ� ���� Ÿ���� floating point type ���� �����Ѵ�
	*/
	if (std::is_floating_point<T>::value == false) 	{
		std::cout << "Use floating point types only" << std::endl;
		return 0;
	}
	else return a / b;
}


template <typename T>
void Check(T&& arg) { // r-value reference => l or r - value ��� �� Ÿ�Կ� �´� reference �� ���� �� �ִ� 
	
	std::cout << std::boolalpha          // T Ÿ���� ���� l-value refer ���� r-value refer ����, �Լ��� ���ؼ� �� �� �ִ�
		<< "Is T l-value reference? " << std::is_reference<T>::value << std::endl;

	// typeid �� �ᵵ, �׳� ���� ����Ű�� Ÿ���� ���������� ���´� => �׳� int
	std::cout << "Type is " << typeid(std::forward<T>(arg)).name() << std::endl;



	std::cout << "After removing reference, "
		// Ÿ���� ������ ������ ���� �ִ�
		// reference �� ��� ���� ��, Ÿ���� ����
		// �� Ÿ���� l-value reference ���� Ȯ��
		<< std::is_reference< typename std::remove_reference<T>::type >::value << std::endl;

}



int main() {

	std::cout << std::boolalpha // = bool type ���� 0,1 ��ſ� true, false ���
		<< "is int integer? : " << std::is_integral<int>::value << std::endl;

	std::cout << Divide(9, 4) << std::endl;
	std::cout << Divide(9.0f, 4.0f) << std::endl;

	// r-value
	Check(5);

	// l-value
	int value{ 5 };
	Check(value);
}