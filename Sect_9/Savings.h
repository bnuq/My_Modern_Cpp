#pragma once
#include "Account.h"

class Savings final : public Account
{
	float m_Rate;

public:
	Savings(const std::string& name, float balance, float rate);
	~Savings() override;

	float GetInterestRate() const override;
	void AccumulateInterest() override;
};
