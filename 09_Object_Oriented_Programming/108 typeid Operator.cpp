#include <iostream>	
#include "./99_105_Bank_Project/Account.h"
#include "./99_105_Bank_Project/Checking.h"
#include "./99_105_Bank_Project/Savings.h"
#include "./99_105_Bank_Project/Transaction.h"

// 객체의 타입에 대한 정보를 알기 위해서 필요
#include <typeinfo>


int main() {

	Checking ch("Boo", 2000, 30);
	Account* pAccount = &ch;
	Transact(pAccount);

	Savings sh("Foo", 3000, 0.5);
	pAccount = &sh;
	Transact(pAccount);


	// RTTI = Run Time Type Information
	int i{};
	float f{};

	/*
		typeid operator
		객체의 타입에 대한 정보를 저장한
		type_info 객체를 리턴한다

		polymorphic types => run time 에 리턴
		그외 타입 => compile time 에 결정
	*/
	const std::type_info& ti1 = typeid(i);
	const std::type_info& ti2 = typeid(f);

	// type_info :: name() => 타입 이름을 리턴
	std::cout << ti1.name() << std::endl;
	std::cout << ti2.name() << std::endl;

	const std::type_info& ti3 = typeid(ch);
	const std::type_info& ti4 = typeid(sh);
	std::cout << ti3.name() << std::endl;
	std::cout << ti4.name() << std::endl;


	// base class pointer type
	const std::type_info& ti5 = typeid(pAccount);
	std::cout << ti5.name() << std::endl;

	// 실제 base class pointer 가 가리키는 객체의 타입 정보를 리턴한다
	// 진짜 base class 인지, 아니면 어떤 child class 인지
	const std::type_info& ti6 = typeid(*pAccount);
	std::cout << ti6.name() << std::endl;


	// base class pointer 가 가리키는 객체가 Savings class 라면
	if (ti6 == typeid(Savings))
		std::cout << "Points to Savings class" << std::endl;


	// reference 의 경우에는 어떻게 작동할까?
	// 포인터를 역참조한 것 처럼, 실제 가리키고 있는 객체의 타입 정보가 나온다
	Account& refAccount1 = ch; // child class 를 base class reference 로 가리키기
	std::cout << typeid(refAccount1).name() << std::endl;

	Account& refAccount2 = sh; // child class 를 base class reference 로 가리키기
	std::cout << typeid(refAccount2).name() << std::endl;
}
