#include <iostream>
// Possible implementation of a lambda expression as a function object
template<typename T>
struct Unnamed {
	T operator()(T x, T y)const {
		return x + y;
	}
};



int main()
{
	// Lambda Expression
	[]() {
		std::cout << "Lambda Expression" << std::endl;
	}(); // 만들자마자 바로 호출


	// Compiler automatically creates a function object
	// 내부적으로 function object 를 위한 class, struct 를 만든다
	auto fn = []() {
		std::cout << "Welcome to Lambda expressions" << std::endl ;
	};
	fn();
	// 내부적으로 class type 인 것을 알 수 있다
	std::cout << typeid(fn).name() << std::endl;


	// Generic/polymorphic lambda
	// Template 처럼 모든 타입에 대해서 작동하도록 만든다 => using auto
	// For <excp specificaion>
	//	noexcept => exception 이 없다
	//	noexcept(false) => exception 이 존재한다
	//							  <optional specifiers>
	auto sum = [](auto x, auto y)/*mutable*//*noexcept*//*-> <return type>*/ {
		return x + y;			//	^^^^		^^^^
	};


	// Function Object 사용
	Unnamed<float> n;
	std::cout << "Sum is:" << n(5.5f, 2.2f) << std::endl;

	// Lambda Expression 사용
	std::cout << "Sum is:" << sum(5.5f, 2.2f) << std::endl;

	return 0;
}