#include <iostream>	
#include "Account.h"
#include "Checking.h"
#include "Savings.h"

int main()
{
	Checking ch{ "Boo", 100 };
	Account* pAccount = &ch;

	Account acc = ch;

	// Checking* pChecking = pAccount;
	Checking* pChecking = static_cast<Checking*>(pAccount);

	return 0;
}