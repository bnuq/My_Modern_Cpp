#include <iostream>
#include <string>

class Project {
	std::string m_name{};

public:
	void SetName(const std::string& name) { 
		m_name = name;
	}
	void ShowDetails() const {
		std::cout << "[Project Name] : " << m_name << std::endl;
	}
};

class Employee {
	/*
		shared_ptr �� �ʿ伺
		� �޸𸮰�, ���� ����鿡 ���� �����ǰ� �ִ�. �׷��� �� ���̳� �� �޸𸮸� �����ϰ� �ִ� ���� �𸥴�
		�̷� ��Ȳ����, �ش� �޸𸮸� ���� ������ ���ΰ�?
		���� �ڽ��� �� �޸𸮸� ���� ���� ������ ����̶�� ��, ��� �� ���ΰ�?
		�� ���� ����

		�׷��� shared_ptr �� �̿��ؼ� � �޸𸮸� ���� ����
		shared_ptr �� �� ���� �޸𸮸� �����ϴ� �� �ȴ�
		�׷���, ���� ���� ���������� ����ϴ� ���� �˼� �ְ�,
		�޸� ������ ������ �� �ִ�

		shared_ptr => copy ����
	*/
	/*
		shared_ptr
		�޸𸮿� �Ҵ��ϰ��� �ϴ� Ÿ���� ���
		�ش� �޸𸮸� �ϳ��� ����Ʈ �����ͷθ� �����Ϸ��� => unique pointer
		�ش� �޸𸮸� ���� ����Ʈ �����͵��� �����Ѵٸ�, �����ϴ� ����Ʈ �����͵��� ���ٸ� => shared pointer

		�� ��쿣, ���� Employee ���� �ϳ��� Project �� �����ϴ� ��Ȳ
		���� �޸𸮿� �Ҵ��� Project ��ü�� ���� Employee ��ü���� �����ϴ� ��Ȳ
		�׷��Ƿ� shared pointer �� ���ؼ� �޸𸮿� �����ؾ� �Ѵ�

		��κ��� �޼���� unique pointer �� �����ϴ�
	*/
	std::shared_ptr<Project> m_project{};

public:
	void SetProject(const std::shared_ptr<Project>& prj) {
		// Copy
		// shared pointer �� �����ؼ�, shared pointer ���� ä�� �� �ִ�
		m_project = prj;
	}
	// const �� �ƴѵ�, const �� �ٿ��� ���� => �޴� �ʿ����� const �� ���� �� �޴´�
	const std::shared_ptr<Project>& GetProject() const {
		return m_project;
	}
};


void ShowInfoEmployee(const std::unique_ptr<Employee>& emp) {
	std::cout << "Employee Details and Project Details : ";
	
	// ����Ʈ ������ => ��ü����, ������ó�� ���
	emp->GetProject()->ShowDetails();
}


int main() {
	// �����ϰ��� �ϴ� Project �� Heap �� �Ҵ�
	// �׷��� �� Proejct ��ü�� �ٸ� ��ü�͵� ������ ���̱� ������,
	// �ٸ� ��ü������ �����ϰ� �ϰ� �ͱ� ������
	// shared pointer �� �̿��Ѵ�
	std::shared_ptr<Project> prj{ new Project{} }; // Heap �� Project �� �Ҵ�
	prj->SetName("Video Decoder");


	// ������ Employee ��ü�鵵 Heap �� �Ҵ��ؼ� ���
	// �ٵ� �� Employee �� �ٸ� ��ü���� ������ ���� �����ϱ�
	// unique pointer �� �������
	std::unique_ptr<Employee> e1{ new Employee{} };
	e1->SetProject(prj); // project �� ����Ű�� shared pointer �� �̿��ؼ�, employee �� shared pointer �� �Ҵ�

	std::unique_ptr<Employee> e2{ new Employee{} };
	e2->SetProject(prj);

	std::unique_ptr<Employee> e3{ new Employee{} };
	e3->SetProject(prj);

	// shared pointer => reference count �� ���� => �� ���� ����Ʈ �����Ͱ� ���� �޸𸮸� �����ϰ� �ִ����� üũ�Ѵ�
	std::cout << "Reference Count : " << prj.use_count() << std::endl;

	ShowInfoEmployee(e1);

	prj->ShowDetails();
	prj.get();
	prj.reset(new Project{});
	prj = nullptr;

	// delete �� �� �ʿ䰡 ����
}