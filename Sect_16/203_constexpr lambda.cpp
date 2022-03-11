#include <iostream>
#include <sstream>

template<typename T, int size, typename Callback>
// array reference => array size 까지 받을 수 있다
void ForEach(T(&arr)[size], Callback operation) {
	for (int i = 0; i < size - 1; ++i) {
		operation(arr[i]);
	}
}

class Product {
	std::string name;
	float price;
public:
	Product(const std::string& n, float p) :name(n), price(p) {
	}

	void AssignFinalPrice() {
		float taxes[]{ 12, 5, 5 };
		float basePrice{ price };
		//Capture this => member func 호출한 객체를 가리킴, 호출 객체 주소를 넘겨받음
		ForEach(taxes, [basePrice, this](float tax) {
			float taxedPrice = basePrice * tax / 100;
			price += taxedPrice;
			});
	}

	float GetPrice()const {
		return price;
	}

	// lambda function return
	auto GetDescription() {
		// *this 를 캡처 => 호출한 객체 값 전체를 복사해서 lambda function 에
		// 캡처한다, 호출 객체 값 전체를 복사
		return[*this](const std::string& header) {
			std::ostringstream ost;
			ost << header << std::endl;

			ost << "Name : " << name << std::endl;
			ost << "Price : " << price << std::endl;
			return ost.str();
		};

	}
};
void UsingLambda() {
	Product *p = new Product { "Watch", 500 };
	p->AssignFinalPrice();
	std::cout << p->GetPrice() << std::endl;
	
	// lambda function 을 반환 받는다
	auto desc = p->GetDescription() ;
	delete p ; // 호출 객체를 지워도, *this 로 캡처했기 때문에 람다 함수를 계속 사용할 수 있다
	
	// call lambda function
	std::cout << desc("##############") << std::endl;


	// lambda function 은 constant expression 이 될 수 있다고 판단되면
	// 자동으로 constexpr type 이 된다
	auto f = [](int x, int y) /*constexpr*/ {
		return x + y;
	};
	// constexpr 타입에 담으면 => constexpr type => compile time 에 계산
	constexpr auto sum = f(3, 5);

	// 그냥 담으면, run time 에 계산
	auto sum2 = f(9, 3);

	std::cout << sum << std::endl;
}

int main() {
	UsingLambda();
}