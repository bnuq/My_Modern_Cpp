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


	// member function �������� lambda function �� ����� �� �ִ�
	void AssignFinalPrice() {

		// ����Ǵ� tax array
		float taxes[]{ 12, 5, 5 };
		float basePrice{ price };

		/*
			Capture this
		
			Lambda Expression ����,
			���� member function �� ȣ���� ��ü�� member variable �� �����Ϸ��� �Ѵ�

			�׷��� member function ������ �翬�� member variable �� ����� �� ������
			lambda expression ���忡���� member variable �� ������ �ʴ´�
		
			�̷� �� capture list => [ this ] ���
			�ڵ����� capture by reference => ȣ���� ��ü�� ����� ����
			
			���� member function �� ȣ���� ��ü��
			��� member variable �� capture �Ѵ�

			private ������� ������ �����ϴ�
		*/
		ForEach(taxes, [basePrice, this](float tax) {
			float taxedPrice = basePrice * tax / 100;
			
			//member variable �� price �� ����
			//price �� private ��� �����ε���, ĸó�� �����ϰ� -> �׷��� ����� �����ϴ�
			price += taxedPrice;
		});
	}


	float GetPrice()const {
		return price;
	}
};



int main() {

	/*
		�߰�����
		lambda expression with empty capture list
		�ڵ����� type conversion �� ���� 
		=> ������ function object �� ����Ű�� function pointer �����Ѵ�

		atexit function = c function => ���α׷� ����ÿ�, Ư�� �Լ��� ����
		c function �̱� ������, function object �� ���� �� ����
	 
		������ lambda expression �� capture list �� ����ִٸ�
		C �Լ��� ���ٸ� ���� ����� �� �ִ�
	*/
	atexit([]() { // ���α׷��� ���� �� �ڵ�����, ���� �Լ��� ȣ���ϴ� �Լ�
		std::cout << "Program Finish..." << std::endl; 
	});
	
	
	Product p{ "Watch", 500 };
	p.AssignFinalPrice();
	std::cout << p.GetPrice() << std::endl;



	/*
		Lambda within a lambda
		���� �ȿ��� �� ���ٸ� ����
	*/
	[](int x) {
		x *= 2; //x �� 2 �� �ǰ�

		//���� �ȿ��� ���� �Լ��� �� �����
		[](int y) {
			std::cout << y << std::endl;
		}/*��������� ���� ǥ����*/(x); //x �� ���� ǥ���Ŀ� �Է��Ѵ�
	}/*��������� ���� ǥ����*/(5); //5 �� ���ٿ� �Է�

	return 0;
}