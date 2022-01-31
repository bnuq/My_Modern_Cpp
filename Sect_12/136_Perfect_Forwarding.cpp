#include "136_Integer.h"
#include <iostream>
#include <string>
class Employee {
	std::string m_Name;
	Integer m_Id;

public:
	/*
	* const reference => r-value �� ����ų �� �ִ�
	* �׷��� �ӽ� ��ü�� ���� �� �ֱ� ������
	* argument �� �ӽ� ��ü�ӿ��� Copy Constructor �� ����ϰ� �ȴ�
	* l-value �� �־, r-value argument �� ���ؼ���, Move Constructor �� ����ϰ� �ʹ�
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
	* template argument �� r-value reference �� �������ָ�
	* l-value => l-value reference �� �ް�
	* r-value => r-value reference �� �ڵ����� �޴´�
	* ��, 2���� ��쿡 ���ؼ� ��� ������ �����ϴ�
	*/
		/*
		* Ÿ���� �ڵ����� �ٲ㼭 �޾�����, �̸� �ִ� ���� name, id �� �޾ұ⿡
		* ������ l-value ��޵ȴ�
		* function call �� �� ��, r-value ��� ���� �˸��� ���ؼ�
		* Ÿ���� ������ ä�� �����ڿ� �ѱ� �ʿ䰡 �ִ�
		* std::forward<T> => T type �� ������ ä��, function �� forward
		* = Perfect Forwarding
		*/
		m_Name{ std::forward<T1>(name) },
		m_Id{ std::forward<T2>(id) } {
		std::cout << "Employee(std::string &&name,  Integer &&id)" << std::endl;

	}
};

// template argument = r-value reference => �ڵ����� l,r-value �ޱ�
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