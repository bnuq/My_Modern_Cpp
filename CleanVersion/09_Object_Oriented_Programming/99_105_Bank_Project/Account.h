#pragma once
#include <string>

// 은행에서 사용되는 기본 계좌, 통장의 기능을 구현
class Account
{
	std::string m_Name;
	int m_AccNo;

	// static member => 만들어진 Account 개수를 파악하는 데 쓰인다
	static int s_ANGenerator;

protected: // child 에서만 접근할 수 있다
	float m_Balance;

public:
	// parameterized constructor
	Account(const std::string& name, float balance);
	
	/*
		포인터나 레퍼런스로 base class 의 멤버함수를 실행할 때~
		반드시 base class 버전의 멤버함수를 실행시키려면
			=> 그냥 정의

		base class 를 포함하고 있는 child class 의 버전을 실행시키려면
			=> virtual 키워드 작성
			만약 child class 에서 정의한 버전이 존재한다면, 그 버전의 멤버함수를 실행시킨다

		virtual 은 타입에 속하지 않는다 => declaration 에서만 작성
	*/
	// destructor 의 경우, 포인터나 레퍼런스가 가리키는 타입을 반드시 제거해야 하므로
	// 반드시 virtual keyword 를 써야 한다
	virtual	~Account();

	const std::string GetName() const;
	float GetBalance() const;
	int GetAccountNo() const;
	virtual	float GetInterestRate() const;

	virtual	void AccumulateInterest();
	virtual void Withdraw(float amount);
	void Deposit(float amount);
	
};

