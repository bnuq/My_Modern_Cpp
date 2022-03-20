#include <iostream>

/* Car.h, Declaration */
class Car {
	float fuel{ 0 };
	float speed{ 0 };
	int passengers{ 0 };
	/*
		Static Member Variable
		��ü�� ������ �ʰ� Ŭ���� ��ü�� ���ϴ� ����
		Ŭ���� �ϳ��� ���ϴ� ����, ��� Ŭ���� ��� �Լ����� ������ �� �ִ�
		��� Ŭ������ ��ü���� �����ϴ� ����
		
		�⺻������ Declaration ���� �ʱ�ȭ�� �Ұ����ϴ� => C++17 ���� ���� inline keyword ����ϸ� ����

		static => type ���� ������ �ʴ´ٰ� ���� => �׷��� ���� ������ ���� ���� �ʴ´�
		��� const => type �� ���Ѵ� => ������ ���� �� �־�� �Ѵ�
	*/
public:
	static int totalCount;

public:
	Car();
	void Dashboard();
	~Car() = default;

	/*
		Static Member Function
		Ŭ���� ��ü�� ���ϴ� �Լ�
		this pointer ��� �Ұ���
		non-static member �� ���� �Ұ���
	*/
	static void showCount();
};


/* Car.cpp */
// static class member �� �ۿ��� ���� ������ �־�� �Ѵ�
// ������ ���� static keyword �� �Ⱦ���??
int Car::totalCount; // �⺻������ 0 ���� �ʱ�ȭ �ȴ�

Car::Car() {
	// Member Function ���� static class member �� ������ �� �ִ�
	std::cout << "Making Car" << std::endl;
	//Car::totalCount++; �̷��� �ᵵ �Ǵ� ��, ���� �� �׷��� �ȴ�
	totalCount++;
}
void Car::Dashboard() {
	std::cout << "Fuel level : " << fuel << std::endl;
	std::cout << "Speed : " << speed << std::endl;
	std::cout << "Passengers : " << passengers << std::endl;
	
	// class �� member function ���� static class member �� ������ ��
	// ���� class :: ǥ�ø� ���� �ʾƵ� ���� �����ϳ�?
	std::cout << "TotalCount : " << totalCount << std::endl;
}

// static member function ����, ���� static keyword �� ������� �ʾƵ� �ȴ�
void Car::showCount() {
	//std::cout << "Fuel level : " << fuel << std::endl;	non-static member �� ���� �Ұ���
	//std::cout << "TotalCount : " << this->totalCount << std::endl;	this pointer ��� �Ұ���
	std::cout << "TotalCount : " << totalCount << std::endl;	// static member variable �� ���
}


int main() {
	Car c1{}, c2{};

	c1.Dashboard(); // totalcount �� 2���� �ȴ�

	Car c3{};

	// static class member �� �����ϴ� ���
	// static member variable �� ���
	std::cout << Car::totalCount << std::endl;	// class ��ü�� ���ؼ� �����ϰų�
	std::cout << c2.totalCount << std::endl;	// class �� object �� ���ؼ� �����ϴ� �͵� ����

	// static member function �� ���
	Car::showCount();	// class ��ü�� ���� �����ϰų�  <- �� ��� �� ��ȣ
	c3.showCount();		// ���⼭�� ��ü�� ���� �����ϴ� ���� �����ϴ�
	
}