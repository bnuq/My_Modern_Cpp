// 직접 만든 클래스를 Container 에 넣고 Algorithm 을 이용해 조작해보자

#include <iostream>

#include <vector>
#include <set>

#include <algorithm>

// 직접 정의한 클래스
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
	// 비교 연산자 오버로드 => STL 에서 자동으로 사용한다
	// 이럽게 안에 직접 정의하지 않고, 이런 비교가 필요할 때마다 function object 를 넣어주는 방식으로 이용하자
	// => using callbacks => flexibility
	//bool operator <(const Employee &e)const {
	//	return m_Id < e.m_Id;
	//}
};



// C++ 를 사용하는 사람 id 를 저장하는 function object
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
	// Comparator 를 정의하지 않고, 그때 그때 필요한 것을 지정한다 => 여기서는 Lambda Expression 이용
	// boolean return = predicate
	// sort() => iterator 로 범위 지정, comparator
	std::sort(v.begin(), v.end(), [](const auto& e1, const auto& e2) {
		
		// 이름이 작은 게 먼저 오게 한다
		// return e1.GetName() < e2.GetName();

		// id 큰게 먼저 오도록 한다
		return e1.GetId() > e2.GetId();
		});


	for (const auto& e : v) {
		std::cout
			<< "Id:" << e.GetId()
			<< " | Name:" << e.GetName()
			<< " | Language:" << e.GetProgrammingLanguage() << std::endl;
	}



	// 얼마나 많은 사람들이 C++ 를 사용하는 지 알고 싶다
	int cppCount{};
	// 직접 루프를 돌면서 확인
	/*for (const auto &e : v) {
		if (e.GetProgrammingLanguage() == "C++")
			++cppCount;
	}*/

	/*
		count algorithm 사용
		return the count of some specific elements in the container
		그런데 이걸 사용하려면 타입에 == operator 가 오버로드 되어 있어야 한다
			overloading 말고, 그때 그떄 comparatpor 를 주고 싶다 => count_if => predicate 를 받는다
	*/
	// cppCount = std::count(v.begin(), v.end(), Employee("", 0, "C++"));
	// 람다 표현식으로 predicate 제공
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
	// container 의 각 element 에 대해서 람다 표현식을 적용
	// Print all employee names
	std::for_each(v.begin(), v.end(), [](const auto& e) {
		std::cout << e.GetName() << std::endl;
		});

	// Get ids of all employees that know C++
	// each element 에 function object apply => return 한다
	// function object 에서만 가능, function pointer X
	auto foundIds = std::for_each(v.begin(), v.end(), EmpIds());
	for (int id : foundIds.m_Ids) {
		std::cout << "Id:" << id << std::endl;
	}


}



// Custom comparator for associative containers
// Employee 객체들을 비교하는 방법을 직접 지정
struct EmpCompare {
	bool operator ()(const Employee& e1, const Employee& e2)const {
		return e1.GetId() < e2.GetId();
	}
};

void makeSet() {
	
	// set 에 새로운 만든 타입을 저장하고자 한다
	// associative containers => 자동으로 정렬한다
	// = comparator 가 필요 => function object 를 이용해보자
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