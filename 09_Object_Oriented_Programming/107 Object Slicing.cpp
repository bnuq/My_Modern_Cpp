#include <iostream>	
#include "./99_105_Bank_Project/Account.h"
#include "./99_105_Bank_Project/Checking.h"
#include "./99_105_Bank_Project/Savings.h"

int main() {

	// child class = base class + own attributtes
	Checking ch{ "Boo", 100 };

	/*
		Upcast
		base class Ÿ���� ����Ű�� ������ child class �� ����Ű�� ��, �����ͳ� ���۷��� �̿�
		child class �� base class �κ��� ����Ŵ
		child class Ÿ���� base class Ÿ������ �÷��� �����Ѵ�~

		base class �� ����Ű�� ������, child class �� ����Լ��� ȣ���� �� �ִ�
	*/
	Account* pAccount = &ch; // �ڵ����� ����

	/*
		Object Slicing
		child class ��ü�� base class ��ü�� �����ϴ� ��
		�׳� child class ���� base class �κи� ����� �����ϰ� �ȴ�
		
		base class �� ���� ���ϴ� �κ���, �׳� �߷� ������ �ȴ�
	*/
	Account acc = ch;


	/*
		Down cast
		�ݴ�� child class Ÿ���� ����Ű�� ������ base class Ÿ���� ����Ű�� ��
		�׳� base class Ÿ�� �����ͳ� ���۷���
			=> �̰� ��¥ base class ����, base class �� �����ϴ� � child class ���� �� ���� ���µ�
		�� base class �� ����Ű�� ����, �׳� Ư�� child class ��� �����ϴ� ��
		base class Ÿ���� child class Ÿ������ ������ �����Ѵ�~
	*/
	// Checking* pChecking = pAccount; �ڵ����δ� �ȵǰ�
	Checking* pChecking = static_cast<Checking*>(pAccount); // ������ ��ȯ�� �ʿ�

	return 0;
}