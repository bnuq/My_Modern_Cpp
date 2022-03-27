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


	// member function 내에서도 lambda function 을 사용할 수 있다
	void AssignFinalPrice() {

		// 적용되는 tax array
		float taxes[]{ 12, 5, 5 };
		float basePrice{ price };

		/*
			Capture this
		
			Lambda Expression 에서,
			현재 member function 을 호출한 객체의 member variable 에 접근하려고 한다

			그런데 member function 에서는 당연히 member variable 을 사용할 수 있지만
			lambda expression 입장에서는 member variable 이 보이지 않는다
		
			이럴 때 capture list => [ this ] 사용
			자동으로 capture by reference => 호출한 객체의 멤버를 참조
			
			현재 member function 을 호출한 객체의
			모든 member variable 을 capture 한다

			private 멤버여도 접근이 가능하다
		*/
		ForEach(taxes, [basePrice, this](float tax) {
			float taxedPrice = basePrice * tax / 100;
			
			//member variable 인 price 에 접근
			//price 는 private 멤버 변수인데도, 캡처가 가능하고 -> 그래서 사용이 가능하다
			price += taxedPrice;
		});
	}


	float GetPrice()const {
		return price;
	}
};



int main() {

	/*
		추가사항
		lambda expression with empty capture list
		자동으로 type conversion 을 지원 
		=> 구현된 function object 를 가리키는 function pointer 리턴한다

		atexit function = c function => 프로그램 종료시에, 특정 함수를 실행
		c function 이기 때문에, function object 를 받을 수 없다
	 
		하지만 lambda expression 의 capture list 가 비어있다면
		C 함수와 람다를 같이 사용할 수 있다
	*/
	atexit([]() { // 프로그램이 끝날 때 자동으로, 받은 함수를 호출하는 함수
		std::cout << "Program Finish..." << std::endl; 
	});
	
	
	Product p{ "Watch", 500 };
	p.AssignFinalPrice();
	std::cout << p.GetPrice() << std::endl;



	/*
		Lambda within a lambda
		람다 안에서 또 람다를 정의
	*/
	[](int x) {
		x *= 2; //x 가 2 배 되고

		//람다 안에서 람다 함수를 또 만들어
		[](int y) {
			std::cout << y << std::endl;
		}/*여기까지가 람다 표현식*/(x); //x 를 람다 표현식에 입력한다
	}/*여기까지가 람다 표현식*/(5); //5 를 람다에 입력

	return 0;
}