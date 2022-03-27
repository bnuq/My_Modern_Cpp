#include <iostream>

/*
	Type Trait

	타입에 대해서 조사할 수 있도록 도와줌
	
	템플릿은 항상 임의의 type 을 받을 수 있는데,
	이때 특정 타입에 대해서만 어떤 동작을 만들고 싶다
		타입을 조사할 필요가 있고
		그래서 type trait 을 사용

	그래서 metaprogramming 과 잘 쓰인다~

	compile time 에 타입에 대한 조사를 진행한다?
*/
#include <type_traits>


template <typename T>
T Divide(T a, T b) {
	/*
		floating point type 에 대해서만 나눗셈을 진행하게 하고 싶다	
		그래서 type_trait 함수를 이용 => 임의로 받은 타입이 floating point type 인지 조사한다
	*/
	if (std::is_floating_point<T>::value == false) 	{
		std::cout << "Use floating point types only" << std::endl;
		return 0;
	}
	else return a / b;
}


template <typename T>
void Check(T&& arg) { // r-value reference => l or r - value 모두 각 타입에 맞는 reference 로 받을 수 있다 
	
	std::cout << std::boolalpha          // T 타입이 현재 l-value refer 인지 r-value refer 인지, 함수를 통해서 알 수 있다
		<< "Is T l-value reference? " << std::is_reference<T>::value << std::endl;

	// typeid 를 써도, 그냥 최종 가리키는 타입이 무엇인지만 나온다 => 그냥 int
	std::cout << "Type is " << typeid(std::forward<T>(arg)).name() << std::endl;



	std::cout << "After removing reference, "
		// 타입의 성질을 변경할 수도 있다
		// reference 를 떼어내 버린 후, 타입을 리턴
		// 그 타입이 l-value reference 인지 확인
		<< std::is_reference< typename std::remove_reference<T>::type >::value << std::endl;

}



int main() {

	std::cout << std::boolalpha // = bool type 에서 0,1 대신에 true, false 출력
		<< "is int integer? : " << std::is_integral<int>::value << std::endl;

	std::cout << Divide(9, 4) << std::endl;
	std::cout << Divide(9.0f, 4.0f) << std::endl;

	// r-value
	Check(5);

	// l-value
	int value{ 5 };
	Check(value);
}