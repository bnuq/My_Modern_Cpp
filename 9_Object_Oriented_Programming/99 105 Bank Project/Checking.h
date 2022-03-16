#pragma once
#include "Account.h"
class Checking final : public Account 
{
	float m_MinimumBalance;

public:
//	Checking(const std::string& name, float balance);

	Checking(const std::string& name, float balance, float minbalance);
	using Account::Account;

	
	~Checking() override;
	

	void Withdraw(float amount) override;
	
	float GetMinimumBalance() const;
};
