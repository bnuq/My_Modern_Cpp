#include "Transaction.h"
#include "Checking.h"

#include <iostream>

void Transact(Account* pAccount)
{
	std::cout << "Transaction started" << std::endl;
	std::cout << "Initial balance" << pAccount->GetBalance() << std::endl;

	pAccount->Deposit(100);
	pAccount->AccumulateInterest();

	
//	Checking* pChecking = static_cast<Checking*>(pAccount);
//	std::cout << "Checking Class Minimum Balance " << pChecking->GetMinimumBalance() << std::endl;

//	if (typeid(*pAccount) == typeid(Checking))
//	{
//		Checking* pChecking = static_cast<Checking*>(pAccount);
//		std::cout << "Checking Class Minimum Balance " << pChecking->GetMinimumBalance() << std::endl;
//	}
//	


	Checking* pChecking = dynamic_cast<Checking*>(pAccount);
	if(pChecking != nullptr)
		std::cout << "Checking Class Minimum Balance " << pChecking->GetMinimumBalance() << std::endl;


	pAccount->Withdraw(170);

	std::cout << "Interest rate" << pAccount->GetInterestRate() << std::endl;
	std::cout << "Final balance" << pAccount->GetBalance() << std::endl;

}

void Transact(Account& pAccount)
{
	std::cout << "Transaction started" << std::endl;
	std::cout << "Initial balance" << pAccount.GetBalance() << std::endl;

	pAccount.Deposit(100);
	pAccount.AccumulateInterest();

	
//	Checking* pChecking = static_cast<Checking*>(pAccount);
//	std::cout << "Checking Class Minimum Balance " << pChecking->GetMinimumBalance() << std::endl;

//	if (typeid(*pAccount) == typeid(Checking))
//	{
//		Checking* pChecking = static_cast<Checking*>(pAccount);
//		std::cout << "Checking Class Minimum Balance " << pChecking->GetMinimumBalance() << std::endl;
//	}
//	


	Checking& pChecking = dynamic_cast<Checking&>(pAccount);
		// If cannot, return exception
		std::cout << "Checking Class Minimum Balance " << pChecking.GetMinimumBalance() << std::endl;


	pAccount.Withdraw(170);

	std::cout << "Interest rate" << pAccount.GetInterestRate() << std::endl;
	std::cout << "Final balance" << pAccount.GetBalance() << std::endl;

}

