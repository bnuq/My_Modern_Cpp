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
	}(); // �����ڸ��� �ٷ� ȣ��


	// Compiler automatically creates a function object
	// ���������� function object �� ���� class, struct �� �����
	auto fn = []() {
		std::cout << "Welcome to Lambda expressions" << std::endl ;
	};
	fn();
	// ���������� class type �� ���� �� �� �ִ�
	std::cout << typeid(fn).name() << std::endl;


	// Generic/polymorphic lambda
	// Template ó�� ��� Ÿ�Կ� ���ؼ� �۵��ϵ��� ����� => using auto
	// For <excp specificaion>
	//	noexcept => exception �� ����
	//	noexcept(false) => exception �� �����Ѵ�
	//							  <optional specifiers>
	auto sum = [](auto x, auto y)/*mutable*//*noexcept*//*-> <return type>*/ {
		return x + y;			//	^^^^		^^^^
	};


	// Function Object ���
	Unnamed<float> n;
	std::cout << "Sum is:" << n(5.5f, 2.2f) << std::endl;

	// Lambda Expression ���
	std::cout << "Sum is:" << sum(5.5f, 2.2f) << std::endl;

	return 0;
}