#pragma once
#include "180_Contact.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>



class Contacts {
private:
	std::vector<Contact> contacts;

public:
	Contacts() = default;
	Contacts(std::vector<Contact>&&);

	
	//���ø��� ����ϴ� ��� �Լ� => Callback �� ���ø� ���ڷ� �޴´�
	//��� ������ Function Object, Function Pointer �� �׳� ���� �� �ִ�
	template<typename Callback>
	void One_DisplayAllContacts(const Callback&);


	void Two_DisplayFirstNameAndPrimeNum();
	void Three_DisplaySameCompany(std::string cp);
	void Four_DisplaySameGroup(Group gp);
	void Five_FindByName(std::string name);
};



//���ø��� ���, � Ÿ���� ������ ��
//�����Ϸ��� ���� => �ٷ� instantiation �� �� �־�� �Ѵ�
//���� ���� ���ǰ� ��� ������Ͽ� �־�� �Ѵ�
template<typename Callback>
void Contacts::One_DisplayAllContacts(const Callback& operation) {
	
	//�־��� opearation �� �������� ������ �Ѵ�
	std::sort(contacts.begin(), contacts.end(), operation);

	for (auto x : contacts)
		std::cout << x;
}