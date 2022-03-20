#include "Checking.h"
#include <iostream>


Checking::Checking(const std::string& name, float balance, float minbalance)
	// ���ó� �θ� ��ü�� ���� �����ڸ� ȣ���ؼ� ���� ����� �ش�
	// ���� �θ� �����ڸ� ���� ȣ������ ������, �ڵ����� default ctor ȣ�� => ���ϴ� �۾��� �ƴϴ�
	// ���ʿ� default ctor �� ����
	: Account{name, balance}, m_MinimumBalance{minbalance}
{
}

Checking::~Checking()
{
}

void Checking::Withdraw(float amount) 
{
	if (m_Balance - amount > m_MinimumBalance) {
		// �θ��� ����Լ��� ��� => �θ� Ŭ������ ������ ����Լ��� ����� �� �ִ�
		Account::Withdraw(amount);

		// Withdraw(amount);   �׳� ���� recursion �߻�
	}		
	else
		std::cout << "Should not fall below " << m_MinimumBalance << std::endl;
}

float Checking::GetMinimumBalance() const
{
	return m_MinimumBalance;
}
