#include "Savings.h"
Savings::Savings(const std::string& name, float balance, float rate)
	// member variable initializer list �� ���ؼ�
	// �����޴� �θ� ��ü��, �ڽ��� ���� ȣ�����־�� �Ѵ�
	// ���� ȣ������ ������, �����Ϸ��� default ctor �� �ڵ����� ȣ��
	// �ٵ� ���� base class ���� default ctor �� �����ϱ� => ����
	: Account{name, balance}, m_Rate{rate}
{
}

Savings::~Savings()
{
}

float Savings::GetInterestRate() const
{
	return m_Rate;
}

void Savings::AccumulateInterest()
{
	m_Balance += (m_Balance * m_Rate);
}
