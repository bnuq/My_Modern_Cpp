#include "Transaction.h"
#include "Checking.h"

#include <iostream>


/*
	모든 child class 들은 base class 를 포함하고 있기 때문에
	base class 를 가리키는 포인터, 레퍼런스로 child class 를 가리킬 수 있다

	가리키는 게 진짜 base class 일 수도 있고
	child class 안의 base class 일 수도 있다

	가리키는 base class 의 멤버함수를 사용하고자 할 때,
	반드시 해당 base class 의 멤버함수를 사용하고 싶은 지
		=> 그냥 base class 에서 멤버함수를 정의

	아니면 base class 를 포함하고 있는 child class 의 멤버함수를 사용하고 싶은지
		=> 이 경우에 base class 에서 멤버함수를 정의할 때 virtual keyword 를 붙인다
*/
void Transact(Account* pAccount)
{
	std::cout << "Transaction started" << std::endl;
	std::cout << "Initial balance" << pAccount->GetBalance() << std::endl;

	// 가리키는 base class 를 이용해서, 그것의 멤버함수를 호출
	// 진짜 base class 의 멤버함수가 실행되는 지,
	// 아니면 base class 를 포함하고 있는 child class 의 새로 구현한 멤버함수가 실행되는 지는
	// virtual keyword 에 의해서 결정된다
	pAccount->Deposit(100);			// non-virtual
	pAccount->AccumulateInterest(); // virtual function

	/*
	일단 무조건 pAccount 가 가리키는 Account class => Checking class 라고 생각
	무조건 맞다고 생각하고 down cast
	Checking* pChecking = static_cast<Checking*>(pAccount);

	Checking class 의 멤버함수 호출 => 사실 Checking class 를 가리킨 게 아니였을 때 에러 발생
	std::cout << "Checking Class Minimum Balance " << pChecking->GetMinimumBalance() << std::endl;

	typeid 사용 => 실제 가리키고 있는 타입이 Checking class 타입인지를 확인
	if (typeid(*pAccount) == typeid(Checking)) {
		진짜로 맞을 때만, Checking class 로 down cast 한다
		Checking* pChecking = static_cast<Checking*>(pAccount);
		std::cout << "Checking Class Minimum Balance " << pChecking->GetMinimumBalance() << std::endl;
	}	
	*/


	/*
		dynamic_cast
		type cast 가 가능한 지, 대신 확인하고 작업해준다
		
		pAccount 가 Checking class 객체를 가리키고 있었다면 ~ type cast 를 해주고
		pAccount 가 다른 child class 객체를 가리키고 있었다면 ~ return nullptr
	*/
	Checking* pChecking = dynamic_cast<Checking*>(pAccount);
	if (pChecking != nullptr) {
		std::cout << "Checking Class Minimum Balance " << pChecking->GetMinimumBalance() << std::endl;
	}


	pAccount->Withdraw(170);
	std::cout << "Interest rate" << pAccount->GetInterestRate() << std::endl;
	std::cout << "Final balance" << pAccount->GetBalance() << std::endl;

}


// base class 를 레퍼런스로 가리키는 경우 버전
void Transact(Account& pAccount)
{
	std::cout << "Transaction started" << std::endl;
	std::cout << "Initial balance" << pAccount.GetBalance() << std::endl;

	pAccount.Deposit(100);
	pAccount.AccumulateInterest();


	/*
		pAccount = base class 를 가리키는 레퍼런스

		pAccount 레퍼런스가, Checking class 를 가리키는 레퍼런스 인지 아닌지를 확인하는 과정
		맞다면 down cast 를 진행한 => pAccount 가 가리키는 객체를 Checking class 라 생각하고, 레퍼런스를 지정
			타입에 레퍼런스를 지정해서 표현한다

		만약 안된다면, exception 을 리턴한다
	*/
	Checking& pChecking = dynamic_cast<Checking&>(pAccount);
	// If cannot, return exception
	std::cout << "Checking Class Minimum Balance " << pChecking.GetMinimumBalance() << std::endl;


	pAccount.Withdraw(170);

	std::cout << "Interest rate" << pAccount.GetInterestRate() << std::endl;
	std::cout << "Final balance" << pAccount.GetBalance() << std::endl;

}

