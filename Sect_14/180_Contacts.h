#pragma once
#include "180_Contact.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>



class Contacts
{
public:
	Contacts() = default;
	~Contacts() = default;
	
	Contacts(std::vector<Contact>);


	template<typename Callback>
	void One_DisplayAllContacts(const Callback&);

	void Two_DisplayFirstNameAndPrimeNum();

	void Three_DisplaySameCompany(std::string cp);

	void Four_DisplaySameGroup(Group gp);

	void Five_FindByName(std::string name);

private:
	std::vector<Contact> contacts;
};


// 템플릿의 경우, 어떤 타입이 들어왔을 때 => 바로 instantiation 할 수 있어야 하니까 관련 정의가 모두 헤더파일에 있어야 한다?
template<typename Callback>
inline void Contacts::One_DisplayAllContacts(const Callback& operation)
{
	std::sort(contacts.begin(), contacts.end(), operation);

	for (auto x : contacts)
		std::cout << x;
}