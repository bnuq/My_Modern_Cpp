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
	약간 억지로 perfect forwarding 써서 생성자를 만들어 보려고 했는데 실패
	1. default argument 불가능
	2. 그냥 문자열은 const char[n] 으로 배열로 인식, 같은 타입으로 넣어주려면 std::string 이라고 적어야 한다

	string 은 stl 이니까 관리는 그냥 맡기자
	나는 string 을 변경할 생각이 없으므로 const reference 로 그냥 받자
	아니면 무조건 rvalue 를 통해서만 받으니까 rvalue 로 받든지

	template<typename T>
	Contact(T&& fn, T&& ln, T&& ppn, T&& spn)
		: firstName{std::forward<std::string>(fn)}, lastName{std::forward<T>(ln)}, primaryPN{std::forward<T>(ppn)}, secondPN{ std::forward<T>(spn) }
	{

	}
*/

	// Default argument 값은 선언에서 써주어야 한다 => 정의에서는 없어도 무관
	// 모든 arguments have default value => this constructor = default constructor 이다 => 중복 선언 피하기
	//Contact(const std::string& fn = "", const std::string& ln = "", const std::string& ppn = "", const std::string& spn = "");
	Contact(std::string&& fn = "", std::string&& ln = "", std::string&& ppn = "", std::string&& spn = "", std::string&& cp = "", 
		Group gp = Group::Friends);


	friend std::ostream& operator<< (std::ostream&, Contact);
};

