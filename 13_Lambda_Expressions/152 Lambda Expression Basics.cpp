#include <iostream>


// Possible implementation of a lambda expression as a function object
template<typename T>
struct Unnamed {
	T operator()(T x, T y)const {
		return x + y;
	}
};



int main() {

	// Lambda Expression 기본 구조
	// 그냥 혼자 생성되는 경우, 만들자마자 바로 호출된다
	[]() {
		std::cout << "Lambda Expression" << std::endl;
	}();


	// Compiler automatically creates a function object
	// 내부적으로 function object 를 위한 class, struct 를 만든다
	auto fn = []() { // fn == function object => function call operator 가 붙으면 lambda expression 을 실행
		std::cout << "Welcome to Lambda expressions" << std::endl ;
	}; // 이 경우에는 바로 실행되지 않는다
	// lambda expression 실행
	fn();

	// auto fn 이 내부적으로 class type 인 것을 알 수 있다
	std::cout << typeid(fn).name() << std::endl;


	/*
		Generic/Polymorphic Lambda Expression

		Template 처럼 모든 타입에 대해서 동작할 수 있도록 만든다
		auto 타입을 사용해서, 어떤 타입이든 받을 수 있도록 한다

		기본 구조 외에, 추가적인 정보를 나타낼 수 있다
	   						      <optional specifiers> */
	auto sum = [](auto x, auto y)/* mutable 여부 */ /* noexcept 여부 */ /* -> <return type> 명시 */ {
		return x + y;			 //	^^^^		       ^^^^
	};



	// Function Object 사용
	Unnamed<float> n{};
	std::cout << "Sum is:" << n(5.5f, 2.2f) << std::endl;

	// Lambda Expression 사용
	std::cout << "Sum is:" << sum(5.5f, 2.2f) << std::endl;

	return 0;
}