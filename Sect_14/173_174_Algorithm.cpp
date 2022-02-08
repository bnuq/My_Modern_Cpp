// ���� ���� Ŭ������ Container �� �ְ� Algorithm �� �̿��� �����غ���

#include <iostream>

#include <vector>
#include <set>

#include <algorithm>

// ���� ������ Ŭ����
class Employee {
	std::string m_Name;
	int m_Id;
	std::string m_ProgLang;
public:
	Employee(const std::string& n, int id, const std::string& pl) :
		m_Name(n),
		m_Id(id),
		m_ProgLang(pl) {

	}
	const std::string& GetName()const {
		return m_Name;
	}
	int GetId()const {
		return m_Id;
	}
	const std::string& GetProgrammingLanguage()const {
		return m_ProgLang;
	}
	// �� ������ �����ε� => STL ���� �ڵ����� ����Ѵ�
	// �̷��� �ȿ� ���� �������� �ʰ�, �̷� �񱳰� �ʿ��� ������ function object �� �־��ִ� ������� �̿�����
	// => using callbacks => flexibility
	//bool operator <(const Employee &e)const {
	//	return m_Id < e.m_Id;
	//}
};



// C++ �� ����ϴ� ��� id �� �����ϴ� function object
struct EmpIds {
	std::vector<int> m_Ids;
	void operator()(const Employee& emp) {
		if (emp.GetProgrammingLanguage() == "C++")
			m_Ids.push_back(emp.GetId());
	}
};



void makeVector()
{
	std::vector<Employee> v{
		Employee{ "Umar", 101, "C++" },
		Employee{ "Bob", 202, "Java"},
		Employee{ "Joey", 200, "C++"}
	};


	// Use callback to avoid overloading comparison operators
	// Comparator �� �������� �ʰ�, �׶� �׶� �ʿ��� ���� �����Ѵ� => ���⼭�� Lambda Expression �̿�
	// boolean return = predicate
	// sort() => iterator �� ���� ����, comparator
	std::sort(v.begin(), v.end(), [](const auto& e1, const auto& e2) {
		
		// �̸��� ���� �� ���� ���� �Ѵ�
		// return e1.GetName() < e2.GetName();

		// id ū�� ���� ������ �Ѵ�
		return e1.GetId() > e2.GetId();
		});


	for (const auto& e : v) {
		std::cout
			<< "Id:" << e.GetId()
			<< " | Name:" << e.GetName()
			<< " | Language:" << e.GetProgrammingLanguage() << std::endl;
	}



	// �󸶳� ���� ������� C++ �� ����ϴ� �� �˰� �ʹ�
	int cppCount{};
	// ���� ������ ���鼭 Ȯ��
	/*for (const auto &e : v) {
		if (e.GetProgrammingLanguage() == "C++")
			++cppCount;
	}*/

	/*
		count algorithm ���
		return the count of some specific elements in the container
		�׷��� �̰� ����Ϸ��� Ÿ�Կ� == operator �� �����ε� �Ǿ� �־�� �Ѵ�
			overloading ����, �׶� �׋� comparatpor �� �ְ� �ʹ� => count_if => predicate �� �޴´�
	*/
	// cppCount = std::count(v.begin(), v.end(), Employee("", 0, "C++"));
	// ���� ǥ�������� predicate ����
	cppCount = std::count_if(v.begin(), v.end(), [](const auto& e) {
		return e.GetProgrammingLanguage() == "C++";
		});
	std::cout << "Count:" << cppCount << std::endl;


	
	// find_if algorithm
	//Find if any employee knows Java
	auto itr = std::find_if(v.begin(), v.end(), [](const auto& e) {
		return e.GetProgrammingLanguage() == "Java";
		});
	if (itr != v.end()) {
		std::cout << "Found:" << itr->GetName() << " is a Java programmer" << std::endl;
	}


	// for_each algorithm
	// container �� �� element �� ���ؼ� ���� ǥ������ ����
	// Print all employee names
	std::for_each(v.begin(), v.end(), [](const auto& e) {
		std::cout << e.GetName() << std::endl;
		});

	// Get ids of all employees that know C++
	// each element �� function object apply => return �Ѵ�
	// function object ������ ����, function pointer X
	auto foundIds = std::for_each(v.begin(), v.end(), EmpIds());
	for (int id : foundIds.m_Ids) {
		std::cout << "Id:" << id << std::endl;
	}


}



// Custom comparator for associative containers
// Employee ��ü���� ���ϴ� ����� ���� ����
struct EmpCompare {
	bool operator ()(const Employee& e1, const Employee& e2)const {
		return e1.GetId() < e2.GetId();
	}
};

void makeSet() {
	
	// set �� ���ο� ���� Ÿ���� �����ϰ��� �Ѵ�
	// associative containers => �ڵ����� �����Ѵ�
	// = comparator �� �ʿ� => function object �� �̿��غ���
	// Using custom comparator
	std::set<Employee, EmpCompare> v{
		//				 ^^^^
		Employee{ "Umar", 101, "C++" },
		Employee{ "Bob", 202, "Java" },
		Employee{ "Joey", 200, "C++" }
	};

	for (const auto& e : v) {
		std::cout
			<< "Id:" << e.GetId()
			<< " | Name:" << e.GetName()
			<< " | Language:" << e.GetProgrammingLanguage() << std::endl;
	}
}


int main()
{
	makeVector();
	//makeSet();
}