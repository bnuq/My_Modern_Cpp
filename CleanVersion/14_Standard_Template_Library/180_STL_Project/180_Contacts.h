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

	
	//템플릿을 사용하는 멤버 함수 => Callback 을 템플릿 인자로 받는다
	//모든 종류의 Function Object, Function Pointer 를 그냥 받을 수 있다
	template<typename Callback>
	void One_DisplayAllContacts(const Callback&);


	void Two_DisplayFirstNameAndPrimeNum();
	void Three_DisplaySameCompany(std::string cp);
	void Four_DisplaySameGroup(Group gp);
	void Five_FindByName(std::string name);
};



//템플릿의 경우, 어떤 타입이 들어왔을 때
//컴파일러에 의해 => 바로 instantiation 할 수 있어야 한다
//따라서 관련 정의가 모두 헤더파일에 있어야 한다
template<typename Callback>
void Contacts::One_DisplayAllContacts(const Callback& operation) {
	
	//주어진 opearation 을 기준으로 정렬을 한다
	std::sort(contacts.begin(), contacts.end(), operation);

	for (auto x : contacts)
		std::cout << x;
}