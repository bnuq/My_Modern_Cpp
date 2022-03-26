#include "180_Contact.h"
#include "180_Contacts.h"

#include <iostream>
#include <string>

int main() {

	//enum class 정보는 contact headerfile 에서 가져올 수 있다
	std::vector<Contact> vecCon{
		//r-value 로 초기화

		Contact{std::string{"AAA"}, std::string{"BB"}, std::string{"CC"}, std::string{"DD"}, "gehenna", Group::Aquaintance},
		
		Contact{"Jana", "Lee", "12", "99", "millenium", Group::Aquaintance},
		
		Contact{"Donghyeon", "Park", "56", "78", "gehenna", Group::Family},
		
		Contact{"Study", "Kim", "90", "01", "Molu", Group::Friends},

		Contact{"Aminen", "Shady", "23", "33", "gehenna", Group::Aquaintance}
	};

	Contacts contactsBook{ std::move(vecCon) }; //l-value 가 넘어가는 거였네

	//
	//// 1-1. first name 으로 정렬
	//contactsBook.One_DisplayAllContacts([](const auto& e1, const auto& e2) {
	//	return e1.firstName < e2.firstName;
	//	});

	//std::cout << std::endl << std::endl;

	//// 1-2. last name 으로 정렬
	//contactsBook.One_DisplayAllContacts([](const auto& e1, const auto& e2) {
	//	return e1.lastName < e2.lastName;
	//	});

	//std::cout << std::endl << std::endl;



	//// 2. first name, primary number 만 출력
	//contactsBook.Two_DisplayFirstNameAndPrimeNum();
	//


	//// 3.
	//contactsBook.Three_DisplaySameCompany("gehenna");



	// 4.
	//contactsBook.Four_DisplaySameGroup(Group::Aquaintance);



	// 5.
	contactsBook.Five_FindByName("Lee");
	contactsBook.Five_FindByName("Donghyeon");
	contactsBook.Five_FindByName("Guzzi");
	
	return 0;
}