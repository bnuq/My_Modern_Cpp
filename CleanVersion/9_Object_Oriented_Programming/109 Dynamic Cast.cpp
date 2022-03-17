#include <iostream>	
#include "./99_105_Bank_Project/Account.h"
#include "./99_105_Bank_Project/Checking.h"
#include "./99_105_Bank_Project/Savings.h"
#include "./99_105_Bank_Project/Transaction.h"

#include <typeinfo>


int main()
{
	// base class ref �� child class ��ü�� ����Ų��

	Checking ch("Boo", 2000, 30);
	Account& refCheking = ch;

	Savings sh("Foo", 3000, 0.5);
	Account& refSaving = sh;

	try {
		// try block �� => run time �� exception �� ������ �� �ִ� �ڵ带 �ۼ��Ѵ�
		Transact(refCheking);


		std::cout << std::endl << std::endl;


		Transact(refSaving);
	}
	catch (std::exception& ex) { // get an exception type
		std::cout << "Exception " << ex.what() << std::endl;
	}

	return 0;
}

// typeid �� dynamic_cast ������� �ʴ� ���� ���� ����
// Ÿ���� �˾Ƴ���, Ÿ�Կ� ���� �����ϵ��� ������ �ʴ� ���� ���� ����