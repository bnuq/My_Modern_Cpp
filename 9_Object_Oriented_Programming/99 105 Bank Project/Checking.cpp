#include "Checking.h"
#include <iostream>

//Checking::Checking(const std::string& name, float balance)
//	: Account{ name, balance }
//{
//	
//}

Checking::Checking(const std::string& name, float balance, float minbalance)
	: Account{name, balance	}, m_MinimumBalance{minbalance}
{
}

Checking::~Checking()
{
}

void Checking::Withdraw(float amount) 
{
	if (m_Balance - amount > m_MinimumBalance)
		Account::Withdraw(amount);
	else
		std::cout << "Should not fall below " << m_MinimumBalance << std::endl;
}

float Checking::GetMinimumBalance() const
{
	return m_MinimumBalance;
}
