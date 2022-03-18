#include "136_Integer.h"
#include <iostream>
#include <string>
class Employee {
	std::string m_Name;
	Integer m_Id;

public:
	/*
	* const reference => r-value 도 가리킬 수 있다
	* 그래서 임시 객체를 받을 수 있기 때문에
	* argument 가 임시 객체임에도 Copy Constructor 를 사용하게 된다
	* l-value 가 있어도, r-value argument 에 대해서는, Move Constructor 를 사용하고 싶다
	* 
	Employee(const std::string& name, const Integer& id) :
		m_Name{ name },
		m_Id{ id }
	{
		std::cout << "Employee(const std::string &name, const Integer &id)" << std::endl; 
	}
	*/
	
	// member template
	template<typename T1, typename T2>
	Employee(T1 &&name,  T2 &&id) :
	/* 
	* template argument 를 r-value reference 로 설정해주면
	* l-value => l-value reference 로 받고
	* r-value => r-value reference 로 자동으로 받는다
	* 즉, 2가지 경우에 대해서 모두 대응이 가능하다
	*/
		/*
		* 타입을 자동으로 바꿔서 받았지만, 이름 있는 변수 name, id 로 받았기에
		* 무조건 l-value 취급된다
		* function call 을 할 때, r-value 라는 것을 알리기 위해서
		* 타입을 보존한 채로 생성자에 넘길 필요가 있다
		* std::forward<T> => T type 을 보존한 채로, function 에 forward
		* = Perfect Forwarding
		*/
		m_Name{ std::forward<T1>(name) },
		m_Id{ std::forward<T2>(id) } {
		std::cout << "Employee(std::string &&name,  Integer &&id)" << std::endl;

	}
};

// template argument = r-value reference => 자동으로 l,r-value 받기
template<typename T1, typename T2>
Employee *Create(T1 && a, T2 &&b) {
	// std::forward => type information preserve
	return new Employee(std::forward<T1>(a), std::forward<T2>(b));
}

int main() {
	
	std::cout << "Case 1" << std::endl;
	std::string name = "Umar";
	Employee emp2{ name, 100 };

	std::cout << "Case 2" << std::endl;
	Integer val{ 100 };
	Employee emp3{ std::string{"Umar"}, val };

	std::cout << "Case 3" << std::endl;
	auto emp = Create("Umar", Integer{ 100 });
	return 0;
}