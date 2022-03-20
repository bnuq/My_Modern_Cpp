#include <iostream>

/* Car.h, Declaration */
class Car {
private:
	/*
		Non Static Data Member Initializers
		Member Variable 의 초기화를 선언에서 진행할 수 있다. C++11 에서부터
		생성자에서 멤버 변수를 초기화 하지 않는 경우, 초기화를 담당한다
		생성자에서 초기화를 하는 경우, 생성자의 것을 따른다
	*/
	float fuel{ 0 };
	float speed{ 0 };
	int passengers{ 0 };
	//auto i{ 10 }; 여기서 auto 는 사용 불가능
	
public:
	Car() = default;
	Car(float amount);
	void Dashboard();
	~Car() = default;
};

/* Car.cpp */
// 생성자에서 멤버 변수에 대한 초기화 코드가 있는 경우 => 생성자의 코드를 따른다
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

	c1.Dashboard(); // => 0,0,0 출력
	c2.Dashboard(); // => 2,100,0 출력
}