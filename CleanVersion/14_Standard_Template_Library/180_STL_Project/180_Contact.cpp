#include "180_Contact.h"

#include <iostream>
#include <string>


// 모든 정보를 출력
std::ostream& operator<<(std::ostream& out, Contact c) {

	out << "*****" << std::endl;
	out << c.firstName << " , " << c.lastName << std::endl;
	out << c.primaryPN << " , " << c.secondPN << std::endl;
	out << c.company << std::endl;
	return out;
}

//Contact::Contact(const std::string& fn, const std::string& ln, const std::string& ppn, const std::string& spn)
//	: firstName{fn}, lastName{ln}, primaryPN{ppn}, secondPN{spn}
//{
//}


Contact::Contact(std::string&& fn, std::string&& ln, std::string&& ppn, std::string&& spn, std::string&& cp, Group gp)
	//r-value reference 니까, std::move() 안써도 move operation 이 일어날 듯?
	//이때는, 그래도 확실하게 하고 싶어서 쓴 것 같다
	: firstName{ std::move(fn) }, lastName{ std::move(ln) }, primaryPN{ std::move(ppn) }, secondPN{ std::move(spn) }, company{std::move(cp)}, group{gp}
{
}