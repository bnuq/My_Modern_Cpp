#include "Checking.h"
#include <iostream>

//Checking::Checking(const std::string& name, float balance)
//	: Account{ name, balance }
//{
//	
//}

Checking::~Checking()
{
}

void Checking::Withdraw(float amount) 
{
	if (m_Balance - amount > 50)
		Account::Withdraw(amount);
	else
		std::cout << "Should not fall below 50" << std::endl;
}
