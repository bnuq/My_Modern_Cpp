#pragma once
#include <vector>
#include <string>

struct Contact
{
	std::string F_name;
	std::string L_name;
	std::string e_mail;
	std::string address;
	std::string company;
	std::string groups;
	std::string Pr_number{};
	std::string Scd_number{};

	std::string getFName() const;
	std::string getLName() const;
	std::string getCompany() const;
	std::string getGroup() const;
	std::string getPrNum() const;

	friend std::ostream& operator<<(std::ostream& out, const Contact& profiles);
};

