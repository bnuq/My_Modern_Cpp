#pragma once
#include <string>
#include <iostream>
#include <map>


enum class Group {Friends, Family, Coworker, Aquaintance};



class Contact
{
public:
	//Contact() = default;
	~Contact() = default;

	Contact(const Contact&) = default;
	Contact& operator=(const Contact&) = default;

	Contact(Contact&&) = default;
	Contact& operator=(Contact&&) = default;


	// 1,2
		std::string firstName;
		std::string lastName;
	// 3,4
		std::string primaryPN;
		std::string secondPN;
	// 5
		std::string company;
	// 6
		Group group;


/*
	�ణ ������ perfect forwarding �Ἥ �����ڸ� ����� ������ �ߴµ� ����
	1. default argument �Ұ���
	2. �׳� ���ڿ��� const char[n] ���� �迭�� �ν�, ���� Ÿ������ �־��ַ��� std::string �̶�� ����� �Ѵ�

	string �� stl �̴ϱ� ������ �׳� �ñ���
	���� string �� ������ ������ �����Ƿ� const reference �� �׳� ����
	�ƴϸ� ������ rvalue �� ���ؼ��� �����ϱ� rvalue �� �޵���

	template<typename T>
	Contact(T&& fn, T&& ln, T&& ppn, T&& spn)
		: firstName{std::forward<std::string>(fn)}, lastName{std::forward<T>(ln)}, primaryPN{std::forward<T>(ppn)}, secondPN{ std::forward<T>(spn) }
	{

	}
*/

	// Default argument ���� ���𿡼� ���־�� �Ѵ� => ���ǿ����� ��� ����
	// ��� arguments have default value => this constructor = default constructor �̴� => �ߺ� ���� ���ϱ�
	//Contact(const std::string& fn = "", const std::string& ln = "", const std::string& ppn = "", const std::string& spn = "");
	Contact(std::string&& fn = "", std::string&& ln = "", std::string&& ppn = "", std::string&& spn = "", std::string&& cp = "", 
		Group gp = Group::Friends);


	friend std::ostream& operator<< (std::ostream&, Contact);
};

