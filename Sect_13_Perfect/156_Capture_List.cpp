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
	// member function ������ lambda function ���
	void AssignFinalPrice() {
		// ����Ǵ� tax array
		float taxes[]{ 12, 5, 5 };
		float basePrice{ price };
		// Capture this
		// ���� ��ü�� ����� �����ϰ� �ʹ� => this ���
		// �ڵ����� by reference �ε�?
		ForEach(taxes, [basePrice, this](float tax) {
			float taxedPrice = basePrice * tax / 100;
			
			// member variable �� price �� ����
			price += taxedPrice;
		});
	}
	float GetPrice()const {
		return price;
	}
};
int main() {


	// atexit function = c function => ���α׷� ����ÿ�, Ư�� �Լ��� ����
	// function object �� ���� �� ����
	// lambda expression with empty capture list
	// type conversion => ������ function object �� ����Ű�� function pointer ����
	// C �Լ��� ���ٸ� ���� ����� �� �ִ�
	atexit([]() {
		std::cout << "Program is exitting..." << std::endl; 
	});
	
	
	Product p{ "Watch", 500 };
	p.AssignFinalPrice();
	std::cout << p.GetPrice() << std::endl;



	//Lambda within a lambda
	[](int x) {
		x *= 2; // 10 �ǰ�

		// ���� �ȿ��� ���� �Լ��� ����� ȣ��
		[](int x) {
			std::cout << x << std::endl; 
		}(x); // 10 ����

	}(5); // 5 ��
	

	return 0;
}