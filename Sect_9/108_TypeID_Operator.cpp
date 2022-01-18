#include <iostream>	
#include "Account.h"
#include "Checking.h"
#include "Savings.h"
#include "Transaction.h"

#include <typeinfo>


int main()
{
	Checking ch("Boo", 2000, 30);
	Account* pAccount = &ch;
	Transact(pAccount);

	Savings sh("Foo", 3000, 0.5);
	pAccount = &sh;
	Transact(pAccount);


	// RTTI = Run Time Type Information
	int i{};
	float f{};
	const std::type_info& ti1 = typeid(i);
	const std::type_info& ti2 = typeid(f);
	std::cout << ti1.name() << std::endl;
	std::cout << ti2.name() << std::endl;

	const std::type_info& ti3 = typeid(ch);
	const std::type_info& ti4 = typeid(sh);
	std::cout << ti3.name() << std::endl;
	std::cout << ti4.name() << std::endl;


	const std::type_info& ti5 = typeid(pAccount);
	std::cout << ti5.name() << std::endl;

	const std::type_info& ti6 = typeid(*pAccount);
	std::cout << ti6.name() << std::endl;

	if (ti6 == typeid(Savings))
		std::cout << "Points to Savings class" << std::endl;
}
