#include <iostream>
#include <sstream>

template<typename T, int size, typename Callback>
// array reference => array size ���� ���� �� �ִ�
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
		//Capture this => member func ȣ���� ��ü�� ����Ŵ, ȣ�� ��ü �ּҸ� �Ѱܹ���
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
		// *this �� ĸó => ȣ���� ��ü �� ��ü�� �����ؼ� lambda function ��
		// ĸó�Ѵ�, ȣ�� ��ü �� ��ü�� ����
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
	
	// lambda function �� ��ȯ �޴´�
	auto desc = p->GetDescription() ;
	delete p ; // ȣ�� ��ü�� ������, *this �� ĸó�߱� ������ ���� �Լ��� ��� ����� �� �ִ�
	
	// call lambda function
	std::cout << desc("##############") << std::endl;


	// lambda function �� constant expression �� �� �� �ִٰ� �ǴܵǸ�
	// �ڵ����� constexpr type �� �ȴ�
	auto f = [](int x, int y) /*constexpr*/ {
		return x + y;
	};
	// constexpr Ÿ�Կ� ������ => constexpr type => compile time �� ���
	constexpr auto sum = f(3, 5);

	// �׳� ������, run time �� ���
	auto sum2 = f(9, 3);

	std::cout << sum << std::endl;
}

int main() {
	UsingLambda();
}