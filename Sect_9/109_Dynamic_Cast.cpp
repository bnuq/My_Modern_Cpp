#include <iostream>	
#include "Account.h"
#include "Checking.h"
#include "Savings.h"
#include "Transaction.h"

#include <typeinfo>


int main()
{

	Checking ch("Boo", 2000, 30);
	Checking& refCheking = ch;


	Savings sh("Foo", 3000, 0.5);
	Savings& refSaving = sh;

	try {
		Transact(refCheking);


		std::cout << std::endl << std::endl;


		Transact(refSaving);
	}
	catch (std::exception& ex) {
		std::cout << "Exception " << ex.what() << std::endl;
	}

	return 0;
}
