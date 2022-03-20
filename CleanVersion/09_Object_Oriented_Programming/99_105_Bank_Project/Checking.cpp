#include "Checking.h"
#include <iostream>


Checking::Checking(const std::string& name, float balance, float minbalance)
	// 역시나 부모 객체를 직접 생성자를 호출해서 먼저 만들어 준다
	// 만약 부모 생성자를 직접 호출하지 않으면, 자동으로 default ctor 호출 => 원하는 작업이 아니다
	// 애초에 default ctor 이 없어
	: Account{name, balance}, m_MinimumBalance{minbalance}
{
}

Checking::~Checking()
{
}

void Checking::Withdraw(float amount) 
{
	if (m_Balance - amount > m_MinimumBalance) {
		// 부모의 멤버함수를 사용 => 부모 클래스를 밝히고 멤버함수를 사용할 수 있다
		Account::Withdraw(amount);

		// Withdraw(amount);   그냥 쓰면 recursion 발생
	}		
	else
		std::cout << "Should not fall below " << m_MinimumBalance << std::endl;
}

float Checking::GetMinimumBalance() const
{
	return m_MinimumBalance;
}
