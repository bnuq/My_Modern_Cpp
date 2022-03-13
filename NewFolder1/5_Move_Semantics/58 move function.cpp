#include <iostream>

class Integer {
	int data{};
public:
	//Default constructor
	Integer() { std::cout << "Default Ctor" << std::endl; }
	//Parameterized constructor
	Integer(int value) : data{ value } { std::cout << "Parameterized constructor" << std::endl; }

	//Copy constructor
	Integer(const Integer& obj) { std::cout << "Copy constructor" << std::endl; }
	Integer& operator=(const Integer& obj) = default;

	//Move constructor
	Integer(Integer&& obj) noexcept { std::cout << "Move constructor" << std::endl; }
	Integer& operator=(Integer&& obj) = default;

	~Integer() = default;
};


void Print(Integer a) {

}


int main() {
	/*
		std::move function
		l-value 를 이용해서 객체를 만들 때, 
		강제적으로 l-value 에 대해서 move constructor 를 사용하게 하는 것
		== static_cast<Integer&&>(obj)

		사용된 l-value 는 사라질 임시 객체처럼, 더이상 사용하지 못하게 된다
	*/
	Integer i1{ 9 }; // Para Ctor

	Integer i2{ i1 }; // Copy Ctor

	Integer i3{ std::move(i1) }; // Move Ctor
	// 이제 더이상 i1 을 사용할 수 없다, r-value 처럼 사용됐기 때문에 => 사라진 것이나 마찬가지

	Print(std::move(i2)); // Print function 의 인수 Integer a 를 만드는 데, i2 가 r-value 처럼 사용됐다
	// 역시 이제 i2 를 사용할 수 없다
}