#include "Integer.h"
#include <iostream>
#include <string>


class Employee {
	std::string m_Name{};
	Integer m_Id{};

public:
	/*
		const reference => const type& 형태
		l-value, r-value 모두 가리킬 수 있다

		따라서 constructor 를 통해서 Empolyee 객체를 만들 때
		2 개의 arguments 중 둘다 l-value 이거나, 둘다 r-value 이면 좋겠지만
		둘 중 하나가 다른 경우가 반드시 존재한다

		이때 하나가 임시객체, r-value 인 경우엔
		무조건 l-value, r-value 둘다 처리할 수 있는 copy constructor 가 호출된다
	
		Employee(const std::string& name, const Integer& id) :
			m_Name{ name },
			m_Id{ id } {
			std::cout << "Employee(const std::string &name, const Integer &id)" << std::endl; 
		}

		이 경우 r-value 로 넘어간 argument 의 경우, 무조건 copy constructor 를 호출하게 된다

		목적 =
		arguments 에 l-value 와, r-value 가 섞여 있어도
		r-value 에 대해서는 Move Constructor 를 사용하게 하고 싶다
	*/ 
	
	
	// Member Template
	template<typename T1, typename T2>
	Employee(T1 &&name,  T2 &&id) :
		/* 
			템플릿 함수의 argument 를 r-value reference 로 설정해주면
			l-value => l-value reference 로 받고
			r-value => r-value reference 로 자동으로 받는다
			즉, 2가지 경우에 대해서 모두 대응이 가능하다
		
			하지만, 어쨌든 이름 있는 변수 name, id 로 받았기 때문에
			무조건 l-value 취급된다

			따라서 각 멤버들을 초기화 하기 위해서, 각 멤버의 constructor 를 호출할 때
			r-value 에 대해서는 r-value 라는 것을 알려야 한다
		
			따라서 레퍼런스가 가리키는 객체의 타입을 보존한 채로 생성자에 넘길 필요가 있다
			
			std::forward<T> => T type 을 보존한 채로, 함수 호출에 인자를 넘길 수 있다
		
			l-value 인지 r-value 인지 타입을 보존하는 것 = Perfect Forwarding
		*/
		// 이름 있는 변수에 저장되어 있지만
		// 각 레퍼런스가 가리키는 객체의 타입을 살려서 생성자에 전달하면
		// 상황에 맞게 Copy or Move Ctor 이 호출될 것이다
		m_Name{ std::forward<T1>(name) },
		m_Id{ std::forward<T2>(id) } {
		std::cout << "Employee(std::string &&name,  Integer &&id)" << std::endl;
	}
};


// 템플릿 함수의 argument = r-value reference => 자동으로 l,r-value reference 로 arguments 를 받음
template<typename T1, typename T2>
Employee *Create(T1 && a, T2 &&b) {
	// std::forward => type information preserve
	// 각 레퍼런스가 가리키는 객체의 타입을 보존한다, 알려준다
	return new Employee(std::forward<T1>(a), std::forward<T2>(b));
}


int main() {
	
	std::cout << "Case 1" << std::endl;
	std::string name = "Umar";
	Employee emp2{ name, 100 };

	std::cout << "Case 2" << std::endl;
	Integer val{ 100 };
	Employee emp3{ std::string{"Umar"}, val };


	//std::cout << "Case 3" << std::endl;
	// 이런식으로 template argument list 에 직접 값을 채우는 것은 불가능
	//Employee emp3 = Employee<std::string, Integer>( std::string{"Kim"}, 90);


	std::cout << "Case 3" << std::endl;
	auto emp = Create("Umar", Integer{ 100 });

	val.test();


	return 0;
}