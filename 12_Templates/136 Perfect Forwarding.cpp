#include "Integer.h"
#include <iostream>
#include <string>


class Employee {
	std::string m_Name{};
	Integer m_Id{};

public:
	/*
		const reference => const type& ����
		l-value, r-value ��� ����ų �� �ִ�

		���� constructor �� ���ؼ� Empolyee ��ü�� ���� ��
		2 ���� arguments �� �Ѵ� l-value �̰ų�, �Ѵ� r-value �̸� ��������
		�� �� �ϳ��� �ٸ� ��찡 �ݵ�� �����Ѵ�

		�̶� �ϳ��� �ӽð�ü, r-value �� ��쿣
		������ l-value, r-value �Ѵ� ó���� �� �ִ� copy constructor �� ȣ��ȴ�
	
		Employee(const std::string& name, const Integer& id) :
			m_Name{ name },
			m_Id{ id } {
			std::cout << "Employee(const std::string &name, const Integer &id)" << std::endl; 
		}

		�� ��� r-value �� �Ѿ argument �� ���, ������ copy constructor �� ȣ���ϰ� �ȴ�

		���� =
		arguments �� l-value ��, r-value �� ���� �־
		r-value �� ���ؼ��� Move Constructor �� ����ϰ� �ϰ� �ʹ�
	*/ 
	
	
	// Member Template
	template<typename T1, typename T2>
	Employee(T1 &&name,  T2 &&id) :
		/* 
			���ø� �Լ��� argument �� r-value reference �� �������ָ�
			l-value => l-value reference �� �ް�
			r-value => r-value reference �� �ڵ����� �޴´�
			��, 2���� ��쿡 ���ؼ� ��� ������ �����ϴ�
		
			������, ��·�� �̸� �ִ� ���� name, id �� �޾ұ� ������
			������ l-value ��޵ȴ�

			���� �� ������� �ʱ�ȭ �ϱ� ���ؼ�, �� ����� constructor �� ȣ���� ��
			r-value �� ���ؼ��� r-value ��� ���� �˷��� �Ѵ�
		
			���� ���۷����� ����Ű�� ��ü�� Ÿ���� ������ ä�� �����ڿ� �ѱ� �ʿ䰡 �ִ�
			
			std::forward<T> => T type �� ������ ä��, �Լ� ȣ�⿡ ���ڸ� �ѱ� �� �ִ�
		
			l-value ���� r-value ���� Ÿ���� �����ϴ� �� = Perfect Forwarding
		*/
		// �̸� �ִ� ������ ����Ǿ� ������
		// �� ���۷����� ����Ű�� ��ü�� Ÿ���� ����� �����ڿ� �����ϸ�
		// ��Ȳ�� �°� Copy or Move Ctor �� ȣ��� ���̴�
		m_Name{ std::forward<T1>(name) },
		m_Id{ std::forward<T2>(id) } {
		std::cout << "Employee(std::string &&name,  Integer &&id)" << std::endl;
	}
};


// ���ø� �Լ��� argument = r-value reference => �ڵ����� l,r-value reference �� arguments �� ����
template<typename T1, typename T2>
Employee *Create(T1 && a, T2 &&b) {
	// std::forward => type information preserve
	// �� ���۷����� ����Ű�� ��ü�� Ÿ���� �����Ѵ�, �˷��ش�
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
	// �̷������� template argument list �� ���� ���� ä��� ���� �Ұ���
	//Employee emp3 = Employee<std::string, Integer>( std::string{"Kim"}, 90);


	std::cout << "Case 3" << std::endl;
	auto emp = Create("Umar", Integer{ 100 });

	val.test();


	return 0;
}