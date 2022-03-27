/*
	서로 다른 두 객체가 각각 서로를 가리키는 경우
	서로 shared pointer 로 가리키면, reference count 가 각각 1 => 메모리가 정리되지 않는다
	한쪽을 weak pointer 로 사용 => refer count 가 안 오르니까, 리소스는 공유하면서 해제할 때는 방해가 안된다
	근데 그러면 양쪽 다 weak pointer 로 사용하면 되는 거 아닌가?
*/

#include <iostream>

class Employee;
class Project {
public:
	std::shared_ptr<Employee> m_emp{}; // project 에는 employee 가 무조건 존재해야 한다는 의미에서..?
	//std::weak_ptr<Employee> m_emp{};
	Project() { std::cout << "Project()" << std::endl; }
	~Project() { std::cout << "~Project()" << std::endl; }
};

class Employee {
public:
	// 한쪽에서는 weak pointer 로 가리킨다
	std::weak_ptr<Project> m_prj{};
	Employee() { std::cout << "Employee()" << std::endl; }
	~Employee() { std::cout << "~Employee()" << std::endl; }
};


int main() {
	std::shared_ptr<Project> prj{ new Project{} };
	std::shared_ptr<Employee> emp{ new Employee{} };
	
	prj->m_emp = emp;
	
	// weak pointer 는 shared pointer 를 할당받는다
	// shared pointer 의 underlying control block 을 가리킨다
	// underlying control block => reference count 저장
	emp->m_prj = prj;

}