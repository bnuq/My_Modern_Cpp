#include "180_Contacts.h"

#include <algorithm>


Contacts::Contacts(std::vector<Contact>&& conVec) //������ ����� r-value, move ���Ѽ� �ʱ�ȭ����
	: contacts{ conVec } //r-value �ϱ�, vector ���� move operation �ڵ����� ����� ��?
{
}

void Contacts::Two_DisplayFirstNameAndPrimeNum() {
	for (auto x : contacts)
		std::cout << x.firstName << " and " << x.primaryPN << std::endl;
}

void Contacts::Three_DisplaySameCompany(std::string cp) {
	int companyNum{};

	//count_if() => Ư�� ������ �����ϴ� ������ ����
	companyNum = std::count_if(contacts.begin(), contacts.end(), [&cp](const auto& x) {
		return x.company == cp;
		});

	std::cout << companyNum << std::endl;
}

void Contacts::Four_DisplaySameGroup(Group gp) {

	//for_each() => Ư�� ������ ��� ��ҿ� �����Ѵ�
	std::for_each(contacts.begin(), contacts.end(), [&gp](const auto& e) {
		if (e.group == gp) {
			std::cout << e << std::endl;
		}
		});
}

void Contacts::Five_FindByName(std::string name) {

	//find_if() => Ư�� ������ �Ǵ� ��Ҹ� ã�´�
	auto itr = std::find_if(contacts.begin(), contacts.end(), [name](const auto& e) {
		return (e.firstName == name);
		});

	if (itr == contacts.end()) { //�� ã�� ���

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

