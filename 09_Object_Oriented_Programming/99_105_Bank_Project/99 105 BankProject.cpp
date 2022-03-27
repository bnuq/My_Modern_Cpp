#include <iostream>
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"

int main()
{
//	Savings sav{ "for_save", 100, 0.5 };
//	Checking che{ "for_check", 1000 };
//
//	using namespace std;
//	cout << che.GetBalance() << endl;
//
//	che.Deposit(200);
//	che.AccumulateInterest();
//	che.Withdraw(980);
//
//	cout << che.GetBalance() << endl;
//
//	return 0;

	Checking checking{ "for_check", 1000 };
	Savings savings{ "for_save", 1000, 0.8};

	

	Transact(&checking);
	Transact(&savings);

	return 0;
}