#pragma once
#include "Account.h"

// ���� Ŭ������ ���� �޾� => ���� ���� �̶�� ��
class Savings final : public Account {
	// �θ��� ����� �ƴ�, �ڽŸ��� ���
	// non-static member initialization
	float m_Rate{ 0.5f }; // ���������� ������

public:
	// �����޾Ƶ�, �ڽŸ��� ctor, dtor, assignment operator �� �����ؾ� �Ѵ�
	// �ƴϸ� default �� ����ϴ���

	// Inheriting Constructor
	using Account::Account;

	Savings(const std::string& name, float balance, float rate);
	
	// override keyword => virtual function reimplementation Ȯ��
	~Savings() override;
	float GetInterestRate() const override;
	void AccumulateInterest() override;
};
