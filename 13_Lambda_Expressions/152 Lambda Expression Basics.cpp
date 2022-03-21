#include <iostream>


// Possible implementation of a lambda expression as a function object
template<typename T>
struct Unnamed {
	T operator()(T x, T y)const {
		return x + y;
	}
};



int main() {

	// Lambda Expression �⺻ ����
	// �׳� ȥ�� �����Ǵ� ���, �����ڸ��� �ٷ� ȣ��ȴ�
	[]() {
		std::cout << "Lambda Expression" << std::endl;
	}();


	// Compiler automatically creates a function object
	// ���������� function object �� ���� class, struct �� �����
	auto fn = []() { // fn == function object => function call operator �� ������ lambda expression �� ����
		std::cout << "Welcome to Lambda expressions" << std::endl ;
	}; // �� ��쿡�� �ٷ� ������� �ʴ´�
	// lambda expression ����
	fn();

	// auto fn �� ���������� class type �� ���� �� �� �ִ�
	std::cout << typeid(fn).name() << std::endl;


	/*
		Generic/Polymorphic Lambda Expression

		Template ó�� ��� Ÿ�Կ� ���ؼ� ������ �� �ֵ��� �����
		auto Ÿ���� ����ؼ�, � Ÿ���̵� ���� �� �ֵ��� �Ѵ�

		�⺻ ���� �ܿ�, �߰����� ������ ��Ÿ�� �� �ִ�
	   						      <optional specifiers> */
	auto sum = [](auto x, auto y)/* mutable ���� */ /* noexcept ���� */ /* -> <return type> ��� */ {
		return x + y;			 //	^^^^		       ^^^^
	};



	// Function Object ���
	Unnamed<float> n{};
	std::cout << "Sum is:" << n(5.5f, 2.2f) << std::endl;

	// Lambda Expression ���
	std::cout << "Sum is:" << sum(5.5f, 2.2f) << std::endl;

	return 0;
}