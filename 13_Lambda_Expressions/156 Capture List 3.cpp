#include <iostream>

template<typename T, int size, typename Callback>
void ForEach(T(&arr)[size], Callback operation) {
	for (int i = 0; i < size - 1; ++i) {
		operation(arr[i]);
	}
}

// User Define Type
class Product {
	std::string name;
	float price;
public:
	Product(const std::string &n, float p) :name(n), price(p) {

	}
	// member function 내에서 lambda function 사용
	void AssignFinalPrice() {
		// 적용되는 tax array
		float taxes[]{ 12, 5, 5 };
		float basePrice{ price };
		// Capture this
		// 현재 객체의 멤버에 접근하고 싶다 => this 사용
		// 자동으로 by reference 인듯?
		ForEach(taxes, [basePrice, this](float tax) {
			float taxedPrice = basePrice * tax / 100;
			
			// member variable 인 price 에 접근
			price += taxedPrice;
		});
	}
	float GetPrice()const {
		return price;
	}
};
int main() {


	// atexit function = c function => 프로그램 종료시에, 특정 함수를 실행
	// function object 를 받을 수 없다
	// lambda expression with empty capture list
	// type conversion => 구현된 function object 를 가리키는 function pointer 리턴
	// C 함수와 람다를 같이 사용할 수 있다
	atexit([]() {
		std::cout << "Program is exitting..." << std::endl; 
	});
	
	
	Product p{ "Watch", 500 };
	p.AssignFinalPrice();
	std::cout << p.GetPrice() << std::endl;



	//Lambda within a lambda
	[](int x) {
		x *= 2; // 10 되고

		// 람다 안에서 람다 함수를 만들고 호출
		[](int x) {
			std::cout << x << std::endl; 
		}(x); // 10 들어간다

	}(5); // 5 들어가
	

	return 0;
}