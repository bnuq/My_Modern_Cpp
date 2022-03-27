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
		shared_ptr 의 필요성
		어떤 메모리가, 여러 사람들에 의해 공유되고 있다. 그런데 몇 명이나 그 메모리를 공유하고 있는 지를 모른다
		이런 상황에서, 해당 메모리를 누가 정리할 것인가?
		누가 자신이 그 메모리를 쓰는 가장 마지막 사람이라는 걸, 어떻게 알 것인가?
		알 수가 없다

		그래서 shared_ptr 을 이용해서 어떤 메모리를 같이 공유
		shared_ptr 은 몇 명이 메모리를 공유하는 지 안다
		그래서, 누가 가장 마지막으로 사용하는 지를 알수 있고,
		메모리 정리를 도와줄 수 있다

		shared_ptr => copy 가능
	*/
	/*
		shared_ptr
		메모리에 할당하고자 하는 타입을 명시
		해당 메모리를 하나의 스마트 포인터로만 관리하려면 => unique pointer
		해당 메모리를 여러 스마트 포인터들이 공유한다면, 접근하는 스마트 포인터들이 많다면 => shared pointer

		이 경우엔, 여러 Employee 들이 하나의 Project 를 공유하는 상황
		따라서 메모리에 할당한 Project 객체를 여러 Employee 객체들이 공유하는 상황
		그러므로 shared pointer 를 통해서 메모리에 접근해야 한다

		대부분의 메서드는 unique pointer 와 동일하다
	*/
	std::shared_ptr<Project> m_project{};

public:
	void SetProject(const std::shared_ptr<Project>& prj) {
		// Copy
		// shared pointer 를 복사해서, shared pointer 값을 채울 수 있다
		m_project = prj;
	}
	// const 가 아닌데, const 를 붙여서 리턴 => 받는 쪽에서는 const 가 붙은 걸 받는다
	const std::shared_ptr<Project>& GetProject() const {
		return m_project;
	}
};


void ShowInfoEmployee(const std::unique_ptr<Employee>& emp) {
	std::cout << "Employee Details and Project Details : ";
	
	// 스마트 포인터 => 객체지만, 포인터처럼 사용
	emp->GetProject()->ShowDetails();
}


int main() {
	// 관리하고자 하는 Project 를 Heap 에 할당
	// 그런데 이 Proejct 객체를 다른 객체와도 공유할 것이기 때문에,
	// 다른 객체에서도 접근하게 하고 싶기 때문에
	// shared pointer 를 이용한다
	std::shared_ptr<Project> prj{ new Project{} }; // Heap 에 Project 를 할당
	prj->SetName("Video Decoder");


	// 각각의 Employee 객체들도 Heap 에 할당해서 사용
	// 근데 각 Employee 는 다른 객체에서 접근할 일이 없으니까
	// unique pointer 를 사용하자
	std::unique_ptr<Employee> e1{ new Employee{} };
	e1->SetProject(prj); // project 를 가리키는 shared pointer 를 이용해서, employee 의 shared pointer 를 할당

	std::unique_ptr<Employee> e2{ new Employee{} };
	e2->SetProject(prj);

	std::unique_ptr<Employee> e3{ new Employee{} };
	e3->SetProject(prj);

	// shared pointer => reference count 를 유지 => 몇 개의 스마트 포인터가 같은 메모리를 공유하고 있는지를 체크한다
	std::cout << "Reference Count : " << prj.use_count() << std::endl;

	ShowInfoEmployee(e1);

	prj->ShowDetails();
	prj.get();
	prj.reset(new Project{});
	prj = nullptr;

	// delete 를 할 필요가 없다
}