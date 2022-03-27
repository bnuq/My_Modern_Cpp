#include <iostream>

/* Car.h, Declaration */
class Car {
	float fuel{ 0 };
	float speed{ 0 };
	int passengers{ 0 };
	/*
		Static Member Variable
		객체에 속하지 않고 클래스 전체에 속하는 변수
		클래스 하나에 속하는 변수, 모든 클래스 멤버 함수에서 접근할 수 있다
		모든 클래스의 객체들이 공유하는 변수
		
		기본적으로 Declaration 에서 초기화가 불가능하다 => C++17 에서 부터 inline keyword 사용하면 가능

		static => type 에는 속하지 않는다고 생각 => 그래서 값을 정의할 때는 쓰지 않는다
		대신 const => type 에 속한다 => 정의할 때도 써 주어야 한다
	*/
public:
	static int totalCount;

public:
	Car();
	void Dashboard();
	~Car() = default;

	/*
		Static Member Function
		클래스 전체에 속하는 함수
		this pointer 사용 불가능
		non-static member 에 접근 불가능
	*/
	static void showCount();
};


/* Car.cpp */
// static class member 는 밖에서 따로 정의해 주어야 한다
// 정의할 때는 static keyword 를 안쓰네??
int Car::totalCount; // 기본적으로 0 으로 초기화 된다

Car::Car() {
	// Member Function 에서 static class member 에 접근할 수 있다
	std::cout << "Making Car" << std::endl;
	//Car::totalCount++; 이렇게 써도 되는 데, 굳이 안 그래도 된다
	totalCount++;
}
void Car::Dashboard() {
	std::cout << "Fuel level : " << fuel << std::endl;
	std::cout << "Speed : " << speed << std::endl;
	std::cout << "Passengers : " << passengers << std::endl;
	
	// class 의 member function 에서 static class member 에 접근할 때
	// 따로 class :: 표시를 하지 않아도 접근 가능하네?
	std::cout << "TotalCount : " << totalCount << std::endl;
}

// static member function 정의, 역시 static keyword 를 사용하지 않아도 된다
void Car::showCount() {
	//std::cout << "Fuel level : " << fuel << std::endl;	non-static member 에 접근 불가능
	//std::cout << "TotalCount : " << this->totalCount << std::endl;	this pointer 사용 불가능
	std::cout << "TotalCount : " << totalCount << std::endl;	// static member variable 만 사용
}


int main() {
	Car c1{}, c2{};

	c1.Dashboard(); // totalcount 가 2개가 된다

	Car c3{};

	// static class member 에 접근하는 방법
	// static member variable 의 경우
	std::cout << Car::totalCount << std::endl;	// class 자체를 통해서 접근하거나
	std::cout << c2.totalCount << std::endl;	// class 의 object 를 통해서 접근하는 것도 가능

	// static member function 의 경우
	Car::showCount();	// class 자체를 통해 접근하거나  <- 이 방법 더 선호
	c3.showCount();		// 여기서도 객체를 통해 접근하는 것이 가능하다
	
}