#include <iostream>

/* Car.h, Declaration */
class Car {
private:
	/*
		Non Static Data Member Initializers
		Member Variable �� �ʱ�ȭ�� ���𿡼� ������ �� �ִ�. C++11 ��������
		�����ڿ��� ��� ������ �ʱ�ȭ ���� �ʴ� ���, �ʱ�ȭ�� ����Ѵ�
		�����ڿ��� �ʱ�ȭ�� �ϴ� ���, �������� ���� ������
	*/
	float fuel{ 0 };
	float speed{ 0 };
	int passengers{ 0 };
	//auto i{ 10 }; ���⼭ auto �� ��� �Ұ���
	
public:
	Car() = default;
	Car(float amount);
	void Dashboard();
	~Car() = default;
};

/* Car.cpp */
// �����ڿ��� ��� ������ ���� �ʱ�ȭ �ڵ尡 �ִ� ��� => �������� �ڵ带 ������
Car::Car(float amount) : fuel{ amount }, speed{ 100 } {
}
void Car::Dashboard() {
	std::cout << "Fuel level : " << fuel << std::endl;
	std::cout << "Speed : " << speed << std::endl;
	std::cout << "Passengers : " << passengers << std::endl;
}


int main() {
	Car c1{};		// Default Constructor
	Car c2{ 2 };	// Parameterized Constructor

	c1.Dashboard(); // => 0,0,0 ���
	c2.Dashboard(); // => 2,100,0 ���
}