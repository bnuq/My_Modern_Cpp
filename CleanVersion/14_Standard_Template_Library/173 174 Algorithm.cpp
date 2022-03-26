#include <iostream>
#include <vector>
#include <set>

//���� �˰����� �����ִ� �������
#include <algorithm>


//���� ���� Ŭ������ Container �� �ְ� Algorithm �� �̿��� �����غ���
//���� ������ Ŭ����
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

	/*
		Employee ��ü���� ���� ���ϴ� Comparator
		
		�̰�ó�� Ŭ���� �� ����Լ��� ������ ���� �ִ�
		bool operator <(const Employee &e)const {
			return m_Id < e.m_Id;
		}

		������ �̰� ���ٴ�, �ۿ��� Function Object�� �̿��ؼ� ����� ����
		�� ������ �ڵ带 ���� �� �ִ�
	*/
};


//C++ �� ����ϴ� ��� id �� �����ϴ� function object
//Callback�� ��������, ���ÿ� ��ü �ڽ� ���� �����͸� ������ �� �ִ�
struct EmpIds {
	std::vector<int> m_Ids;

	void operator()(const Employee& emp) {
		if (emp.GetProgrammingLanguage() == "C++")
			m_Ids.push_back(emp.GetId());
	}
};


void makeVector() {

	//Employee ��ü�� �����ϴ� Vector
	std::vector<Employee> v{
		Employee{ "Umar", 101, "C++" },
		Employee{ "Bob", 202, "Java"},
		Employee{ "Joey", 200, "C++"}
	};


	/*
		Use callback to avoid overloading comparison operators
		���� ������ ��ü�� ���� ��, Ŭ���� ���ο� ���ǵ� ��� operator ��� => �ʹ� �������̴�

		Comparator �� �������� �ʰ�, �׶� �׶� �ʿ��� ���� �����Ѵ� => ���⼭�� Lambda Expression �̿�
		+ alogrithm::�Լ��� ���
	*/
	//boolean return = predicate
	//algorithm::sort() => iterator �� ���� ����, comparator�� ����
	//���� ������ �������ش�
	std::sort(v.begin(), v.end(), [](const auto& e1, const auto& e2) { //e1�� ����, e2�� �����ʿ� �ö� ���� �����ϵ����Ѵ�
		
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


	//�󸶳� ���� ������� C++ �� ����ϴ� �� �˰� �ʹ�
	int cppCount{};
	
	//1. ���� ������ ���鼭 Ȯ��
	for (const auto &e : v) {
		if (e.GetProgrammingLanguage() == "C++")
			++cppCount;
	}
	cppCount = 0;

	/*
		2. algorithm::count() ���
		return the count of some specific elements in the container

		�׷��� �̰� ����Ϸ��� Ŭ������ == operator �� �����ε� �Ǿ� �־�� �Ѵ�
		cppCount = std::count(v.begin(), v.end(), Employee("", 0, "C++"));	
	*/

	
	/*
		3. algorithm::count_if() ���

		operator overloading�� ��� ��밡��
		count_if => predicate �� �޴´�
		�׶� �׶� ���ϴ� comparatpor�� �� �� �ִ� 
	*/
	// ���� ǥ�������� predicate ����
	cppCount = std::count_if(v.begin(), v.end(), [](const auto& e) {
		return e.GetProgrammingLanguage() == "C++";
		});

	std::cout << "Count:" << cppCount << std::endl;


	
	/*
		algorithm::find_if()

		comparator�� ���� �����ϴ� ��Ҹ� ������, �� ��ġ iterator �� ����
	*/
	//Find if any employee knows Java
	auto itr = std::find_if(v.begin(), v.end(), [](const auto& e) {
		return e.GetProgrammingLanguage() == "Java";
		});
	if (itr != v.end()) { //�� ã���� end() iterator �� �����Ѵ�
		std::cout << "Found:" << itr->GetName() << " is a Java programmer" << std::endl;
	}


	
	/*
		algorithm::for_each()

		container �� �� element �� ���ؼ�, �Ѱܹ��� Callback �� �����Ѵ�
	*/
	std::for_each(v.begin(), v.end(), [](const auto& e) {
		std::cout << e.GetName() << std::endl;
		});



	/*
		for_each()�� function object�� ����ϴ� ���
			����� function object�� �����Ѵ�
		
		Callback���� function object�� �ѱ�� ���
		function object �� ��������� �̿��� �� �ִ�
	*/
	//Get ids of all employees that know C++
	//�ѱ� Function Object�� �����Ѵ�        			//Function Object �� ���� �ѱ�
	auto foundIds = std::for_each(v.begin(), v.end(), EmpIds{});
	
	for (int id : foundIds.m_Ids) {
		std::cout << "Id:" << id << std::endl;
	}
}



//Custom comparator for associative containers
//Employee ��ü���� ���ϴ� ����� ���� ����
//Function Object�� ������, �� ������
struct EmpCompare {
	bool operator ()(const Employee& e1, const Employee& e2)const {
		return e1.GetId() < e2.GetId();
	}
};



void makeSet() {
	
	/*
		set �� ���ο� ���� Ÿ���� �����ϰ��� �Ѵ�
		set/multiset, map/multimap = associative containers
		=> binary tree �̿�, �ڵ����� �����Ѵ�
		= comparator �� �ʿ� => function object �� �̿��غ���
	*/
	std::set<Employee, EmpCompare> v{
		//				 ^^^^ Using custom comparator, Ÿ�Ը� �ѱ��?
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
	//makeVector();
	makeSet();
}