#pragma once
#include <string>

// ���࿡�� ���Ǵ� �⺻ ����, ������ ����� ����
class Account
{
	std::string m_Name;
	int m_AccNo;

	// static member => ������� Account ������ �ľ��ϴ� �� ���δ�
	static int s_ANGenerator;

protected: // child ������ ������ �� �ִ�
	float m_Balance;

public:
	// parameterized constructor
	Account(const std::string& name, float balance);
	
	/*
		�����ͳ� ���۷����� base class �� ����Լ��� ������ ��~
		�ݵ�� base class ������ ����Լ��� �����Ű����
			=> �׳� ����

		base class �� �����ϰ� �ִ� child class �� ������ �����Ű����
			=> virtual Ű���� �ۼ�
			���� child class ���� ������ ������ �����Ѵٸ�, �� ������ ����Լ��� �����Ų��

		virtual �� Ÿ�Կ� ������ �ʴ´� => declaration ������ �ۼ�
	*/
	// destructor �� ���, �����ͳ� ���۷����� ����Ű�� Ÿ���� �ݵ�� �����ؾ� �ϹǷ�
	// �ݵ�� virtual keyword �� ��� �Ѵ�
	virtual	~Account();

	const std::string GetName() const;
	float GetBalance() const;
	int GetAccountNo() const;
	virtual	float GetInterestRate() const;

	virtual	void AccumulateInterest();
	virtual void Withdraw(float amount);
	void Deposit(float amount);
	
};

