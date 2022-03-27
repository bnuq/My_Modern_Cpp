#pragma once
#include "Account.h"

// 통장 클래스를 물려 받아 => 저축 통장 이라는 뜻
class Savings final : public Account {
	// 부모의 멤버가 아닌, 자신만의 멤버
	// non-static member initialization
	float m_Rate{ 0.5f }; // 저축통장의 이자율

public:
	// 물려받아도, 자신만의 ctor, dtor, assignment operator 는 정의해야 한다
	// 아니면 default 를 사용하던지

	// Inheriting Constructor
	using Account::Account;

	Savings(const std::string& name, float balance, float rate);
	
	// override keyword => virtual function reimplementation 확인
	~Savings() override;
	float GetInterestRate() const override;
	void AccumulateInterest() override;
};
