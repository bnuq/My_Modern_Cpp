#pragma once
#include "Account.h"

/*
	constructor
	destuctor
	assignment operator
	�� 3������ �������� �ʴ´�, �� Ŭ�������� ������ ���־�� �Ѵ�
	�ƴϸ� �׳� default version �� ����ϰų�
*/
// ���� Ŭ������ �����޴� �Ǵٸ� Ŭ���� => �׳� üũ���ϴ� ����
class Checking final : public Account {
	// Non-Static member initialization
	float m_MinimumBalance { 20 }; // Ȥ�� Checking �� ctor �� ȣ����� �ʴ� ���, �ڵ����� �ʱ�ȭ �ǰ� �Ѵ�

public:
	/*
		Inherit Constructor
		
		�ڽ� Ŭ���� �����ڿ��� �߰������� �� �۾��� ���� ���
		child class �� �����ڸ� ���� �ۼ����� �ʰ�,
		�׳� base class �� constructor �� �����޾Ƽ� �װ͸� ����� �� �ִ�

		child class �� �����ڴ� �ƿ� �ۼ����� �ʰ�, �׳� base class �� �����ڷ� ��ü

		������ �μ��� ���� ���� �ľ� -> base class ���� ������ �����ڸ� ã�� ȣ���Ѵ�
	 */
	// base class �� ctor ������
	// string, float �� �μ��� �޴� �����ڰ� �����Ƿ� �װ��� ����Ѵ�
	using Account::Account; 
	
	// �ٸ� ������
	Checking(const std::string& name, float balance, float minbalance);

	// base class �� virtual function �� �������ϴ� ���, Ȯ���ϰ� �������Ѵٴ� �ǹ̿���
	// override keyword ��� => virtual ���� + �Լ� �ñ״�ó �� Ȯ���Ѵ�
	~Checking() override;
	void Withdraw(float amount) override;

	// �ڽ� Ŭ�������� �߰��ϴ� ��� �Լ�
	float GetMinimumBalance() const;
};
