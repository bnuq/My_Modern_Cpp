#include "180_Contacts.h"

#include <algorithm>


Contacts::Contacts(std::vector<Contact>&& conVec) //어차피 사라질 r-value, move 시켜서 초기화하자
	: contacts{ conVec } //r-value 니까, vector 에서 move operation 자동으로 실행될 듯?
{
}

void Contacts::Two_DisplayFirstNameAndPrimeNum() {
	for (auto x : contacts)
		std::cout << x.firstName << " and " << x.primaryPN << std::endl;
}

void Contacts::Three_DisplaySameCompany(std::string cp) {
	int companyNum{};

	//count_if() => 특정 조건을 만족하는 개수를 센다
	companyNum = std::count_if(contacts.begin(), contacts.end(), [&cp](const auto& x) {
		return x.company == cp;
		});

	std::cout << companyNum << std::endl;
}

void Contacts::Four_DisplaySameGroup(Group gp) {

	//for_each() => 특정 연산을 모든 요소에 적용한다
	std::for_each(contacts.begin(), contacts.end(), [&gp](const auto& e) {
		if (e.group == gp) {
			std::cout << e << std::endl;
		}
		});
}

void Contacts::Five_FindByName(std::string name) {

	//find_if() => 특정 조건이 되는 요소를 찾는다
	auto itr = std::find_if(contacts.begin(), contacts.end(), [name](const auto& e) {
		return (e.firstName == name);
		});

	if (itr == contacts.end()) { //못 찾은 경우

		itr = std::find_if(contacts.begin(), contacts.end(), [name](const auto& e) {
			return (e.lastName == name);
			});
	}

	if (itr == contacts.end())
	{
		std::cout << "No name" << std::endl;
		return;
	}
	else
	{
		std::cout << "I found" << std::endl << *itr << std::endl;
		return;
	}
}

