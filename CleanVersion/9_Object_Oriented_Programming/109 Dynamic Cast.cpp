#include <iostream>	
#include "./99_105_Bank_Project/Account.h"
#include "./99_105_Bank_Project/Checking.h"
#include "./99_105_Bank_Project/Savings.h"
#include "./99_105_Bank_Project/Transaction.h"

#include <typeinfo>


int main()
{
	// base class ref 로 child class 객체를 가리킨다

	Checking ch("Boo", 2000, 30);
	Account& refCheking = ch;

	Savings sh("Foo", 3000, 0.5);
	Account& refSaving = sh;

	try {
		// try block 내 => run time 에 exception 을 리턴할 수 있는 코드를 작성한다
		Transact(refCheking);


		std::cout << std::endl << std::endl;


		Transact(refSaving);
	}
	catch (std::exception& ex) { // get an exception type
		std::cout << "Exception " << ex.what() << std::endl;
	}

	return 0;
}

// typeid 나 dynamic_cast 사용하지 않는 것이 가장 좋다
// 타입을 알아내고, 타입에 따라서 동작하도록 만들지 않는 것이 가장 좋다