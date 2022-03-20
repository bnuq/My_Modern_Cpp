#include "Savings.h"
Savings::Savings(const std::string& name, float balance, float rate)
	// member variable initializer list 를 통해서
	// 물려받는 부모 객체를, 자식이 직접 호출해주어야 한다
	// 직접 호출하지 않으면, 컴파일러는 default ctor 를 자동으로 호출
	// 근데 지금 base class 에는 default ctor 이 없으니까 => 에러
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
