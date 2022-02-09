#include "180_Contact.h"

#include <iostream>
#include <string>






// 모든 정보를 출력
std::ostream& operator<<(std::ostream& out, Contact c)
{
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
	: firstName{ std::move(fn) }, lastName{ std::move(ln) }, primaryPN{ std::move(ppn) }, secondPN{ std::move(spn) }, company{std::move(cp)}, group{gp}
{
}