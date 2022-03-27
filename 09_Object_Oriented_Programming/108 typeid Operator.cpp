#include <iostream>	
#include "./99_105_Bank_Project/Account.h"
#include "./99_105_Bank_Project/Checking.h"
#include "./99_105_Bank_Project/Savings.h"
#include "./99_105_Bank_Project/Transaction.h"

// ��ü�� Ÿ�Կ� ���� ������ �˱� ���ؼ� �ʿ�
#include <typeinfo>


int main() {

	Checking ch("Boo", 2000, 30);
	Account* pAccount = &ch;
	Transact(pAccount);

	Savings sh("Foo", 3000, 0.5);
	pAccount = &sh;
	Transact(pAccount);


	// RTTI = Run Time Type Information
	int i{};
	float f{};

	/*
		typeid operator
		��ü�� Ÿ�Կ� ���� ������ ������
		type_info ��ü�� �����Ѵ�

		polymorphic types => run time �� ����
		�׿� Ÿ�� => compile time �� ����
	*/
	const std::type_info& ti1 = typeid(i);
	const std::type_info& ti2 = typeid(f);

	// type_info :: name() => Ÿ�� �̸��� ����
	std::cout << ti1.name() << std::endl;
	std::cout << ti2.name() << std::endl;

	const std::type_info& ti3 = typeid(ch);
	const std::type_info& ti4 = typeid(sh);
	std::cout << ti3.name() << std::endl;
	std::cout << ti4.name() << std::endl;


	// base class pointer type
	const std::type_info& ti5 = typeid(pAccount);
	std::cout << ti5.name() << std::endl;

	// ���� base class pointer �� ����Ű�� ��ü�� Ÿ�� ������ �����Ѵ�
	// ��¥ base class ����, �ƴϸ� � child class ����
	const std::type_info& ti6 = typeid(*pAccount);
	std::cout << ti6.name() << std::endl;


	// base class pointer �� ����Ű�� ��ü�� Savings class ���
	if (ti6 == typeid(Savings))
		std::cout << "Points to Savings class" << std::endl;


	// reference �� ��쿡�� ��� �۵��ұ�?
	// �����͸� �������� �� ó��, ���� ����Ű�� �ִ� ��ü�� Ÿ�� ������ ���´�
	Account& refAccount1 = ch; // child class �� base class reference �� ����Ű��
	std::cout << typeid(refAccount1).name() << std::endl;

	Account& refAccount2 = sh; // child class �� base class reference �� ����Ű��
	std::cout << typeid(refAccount2).name() << std::endl;
}
