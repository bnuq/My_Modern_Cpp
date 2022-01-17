#pragma once
#include "Account.h"
class Checking final : public Account 
{
public:
//	Checking(const std::string& name, float balance);
	using Account::Account;
	~Checking() override;
	

	void Withdraw(float amount) override;
};
