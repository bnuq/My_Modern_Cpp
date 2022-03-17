#include "Transaction.h"
#include "Checking.h"

#include <iostream>


/*
	��� child class ���� base class �� �����ϰ� �ֱ� ������
	base class �� ����Ű�� ������, ���۷����� child class �� ����ų �� �ִ�

	����Ű�� �� ��¥ base class �� ���� �ְ�
	child class ���� base class �� ���� �ִ�

	����Ű�� base class �� ����Լ��� ����ϰ��� �� ��,
	�ݵ�� �ش� base class �� ����Լ��� ����ϰ� ���� ��
		=> �׳� base class ���� ����Լ��� ����

	�ƴϸ� base class �� �����ϰ� �ִ� child class �� ����Լ��� ����ϰ� ������
		=> �� ��쿡 base class ���� ����Լ��� ������ �� virtual keyword �� ���δ�
*/
void Transact(Account* pAccount)
{
	std::cout << "Transaction started" << std::endl;
	std::cout << "Initial balance" << pAccount->GetBalance() << std::endl;

	// ����Ű�� base class �� �̿��ؼ�, �װ��� ����Լ��� ȣ��
	// ��¥ base class �� ����Լ��� ����Ǵ� ��,
	// �ƴϸ� base class �� �����ϰ� �ִ� child class �� ���� ������ ����Լ��� ����Ǵ� ����
	// virtual keyword �� ���ؼ� �����ȴ�
	pAccount->Deposit(100);			// non-virtual
	pAccount->AccumulateInterest(); // virtual function

	/*
	�ϴ� ������ pAccount �� ����Ű�� Account class => Checking class ��� ����
	������ �´ٰ� �����ϰ� down cast
	Checking* pChecking = static_cast<Checking*>(pAccount);

	Checking class �� ����Լ� ȣ�� => ��� Checking class �� ����Ų �� �ƴϿ��� �� ���� �߻�
	std::cout << "Checking Class Minimum Balance " << pChecking->GetMinimumBalance() << std::endl;

	typeid ��� => ���� ����Ű�� �ִ� Ÿ���� Checking class Ÿ�������� Ȯ��
	if (typeid(*pAccount) == typeid(Checking)) {
		��¥�� ���� ����, Checking class �� down cast �Ѵ�
		Checking* pChecking = static_cast<Checking*>(pAccount);
		std::cout << "Checking Class Minimum Balance " << pChecking->GetMinimumBalance() << std::endl;
	}	
	*/


	/*
		dynamic_cast
		type cast �� ������ ��, ��� Ȯ���ϰ� �۾����ش�
		
		pAccount �� Checking class ��ü�� ����Ű�� �־��ٸ� ~ type cast �� ���ְ�
		pAccount �� �ٸ� child class ��ü�� ����Ű�� �־��ٸ� ~ return nullptr
	*/
	Checking* pChecking = dynamic_cast<Checking*>(pAccount);
	if (pChecking != nullptr) {
		std::cout << "Checking Class Minimum Balance " << pChecking->GetMinimumBalance() << std::endl;
	}


	pAccount->Withdraw(170);
	std::cout << "Interest rate" << pAccount->GetInterestRate() << std::endl;
	std::cout << "Final balance" << pAccount->GetBalance() << std::endl;

}


// base class �� ���۷����� ����Ű�� ��� ����
void Transact(Account& pAccount)
{
	std::cout << "Transaction started" << std::endl;
	std::cout << "Initial balance" << pAccount.GetBalance() << std::endl;

	pAccount.Deposit(100);
	pAccount.AccumulateInterest();


	/*
		pAccount = base class �� ����Ű�� ���۷���

		pAccount ���۷�����, Checking class �� ����Ű�� ���۷��� ���� �ƴ����� Ȯ���ϴ� ����
		�´ٸ� down cast �� ������ => pAccount �� ����Ű�� ��ü�� Checking class �� �����ϰ�, ���۷����� ����
			Ÿ�Կ� ���۷����� �����ؼ� ǥ���Ѵ�

		���� �ȵȴٸ�, exception �� �����Ѵ�
	*/
	Checking& pChecking = dynamic_cast<Checking&>(pAccount);
	// If cannot, return exception
	std::cout << "Checking Class Minimum Balance " << pChecking.GetMinimumBalance() << std::endl;


	pAccount.Withdraw(170);

	std::cout << "Interest rate" << pAccount.GetInterestRate() << std::endl;
	std::cout << "Final balance" << pAccount.GetBalance() << std::endl;

}

