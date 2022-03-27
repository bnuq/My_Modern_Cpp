#pragma once
#include <string>
#include <iostream>
#include <map>


//enum class 로 관계 구분
//enumulator 에 범위 적용 => 밖에서 그냥 접근하지 못하게 한다
enum class Group {Friends, Family, Coworker, Aquaintance};


class Contact {

public:
	//parameterized constructor 때문에 default ctor 은 자동으로 생기지 않는다
	//근데 어차피 안쓸거니까 뭐, 없어도 된다
	//Contact() = default;
	/*
		Destructor, Copy Operation, Move Operation
		5개 중 직접 정의하는 것이 하나도 없으므로, 5개 모두 자동으로 생성된다
		따라서, default version 을 사용한다

		~Contact() = default;

		Contact(const Contact&) = default;
		Contact& operator=(const Contact&) = default;

		Contact(Contact&&) = default;
		Contact& operator=(Contact&&) = default;
	*/


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
		2. 그냥 문자열은 const char[n] 으로 배열로 인식
		   string 타입으로 넣어주려면 std::string 이라고 적어야 한다

		string 은 stl 이니까 관리는 그냥 맡기자
		나는 string 을 변경할 생각이 없으므로 const reference 로 그냥 받자
		아니면 무조건 rvalue 를 통해서만 받으니까 rvalue 로 받든지


		template<typename T>
		Contact(T&& fn, T&& ln, T&& ppn, T&& spn)
			: firstName{std::forward<std::string>(fn)}, lastName{std::forward<T>(ln)},
			  primaryPN{std::forward<T>(ppn)}, secondPN{ std::forward<T>(spn) }
		{

		}
	*/

	//Default argument 값은 선언에서 써주어야 한다 => 정의에서는 없어도 무관
	//모든 arguments have default value => this constructor = default constructor 이다 => 중복 선언 피하기
	
	//모든 arguments 를 const l-value reference 로 받는 버전
	//Contact(const std::string& fn = "", const std::string& ln = "", const std::string& ppn = "", const std::string& spn = "");
	
	//나는 Contact 객체를 만들 때, 무조건 r-value 로 넘길 것이므로 r-value reference 를 썼다	
	Contact(std::string&& fn = "", std::string&& ln = "", std::string&& ppn = "", std::string&& spn = "", std::string&& cp = "", 
	Group gp = Group::Friends);



	//바깥의 operator<< 함수는 friend
	//Contact 객체의 모든 멤버에 접근할 수 있다
	//근데 어차피 다 public 으로 선언해놔서...
	friend std::ostream& operator<< (std::ostream&, Contact);
};

