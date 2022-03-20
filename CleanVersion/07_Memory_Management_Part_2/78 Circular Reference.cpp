/*
	���� �ٸ� �� ��ü�� ���� ���θ� ����Ű�� ���
	���� shared pointer �� ����Ű��, reference count �� ���� 1 => �޸𸮰� �������� �ʴ´�
	������ weak pointer �� ��� => refer count �� �� �����ϱ�, ���ҽ��� �����ϸ鼭 ������ ���� ���ذ� �ȵȴ�
	�ٵ� �׷��� ���� �� weak pointer �� ����ϸ� �Ǵ� �� �ƴѰ�?
*/

#include <iostream>

class Employee;
class Project {
public:
	std::shared_ptr<Employee> m_emp{}; // project ���� employee �� ������ �����ؾ� �Ѵٴ� �ǹ̿���..?
	//std::weak_ptr<Employee> m_emp{};
	Project() { std::cout << "Project()" << std::endl; }
	~Project() { std::cout << "~Project()" << std::endl; }
};

class Employee {
public:
	// ���ʿ����� weak pointer �� ����Ų��
	std::weak_ptr<Project> m_prj{};
	Employee() { std::cout << "Employee()" << std::endl; }
	~Employee() { std::cout << "~Employee()" << std::endl; }
};


int main() {
	std::shared_ptr<Project> prj{ new Project{} };
	std::shared_ptr<Employee> emp{ new Employee{} };
	
	prj->m_emp = emp;
	
	// weak pointer �� shared pointer �� �Ҵ�޴´�
	// shared pointer �� underlying control block �� ����Ų��
	// underlying control block => reference count ����
	emp->m_prj = prj;

}