#include <iostream>
#include <vector>
#include <set>

//여러 알고리즘을 도와주는 헤더파일
#include <algorithm>


//직접 만든 클래스를 Container 에 넣고 Algorithm 을 이용해 조작해보자
//직접 정의한 클래스
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
		Employee 객체끼리 값을 비교하는 Comparator
		
		이것처럼 클래스 내 멤버함수로 정의할 수도 있다
		bool operator <(const Employee &e)const {
			return m_Id < e.m_Id;
		}

		하지만 이것 보다는, 밖에서 Function Object를 이용해서 만드는 것이
		더 유연한 코드를 만들 수 있다
	*/
};


//C++ 를 사용하는 사람 id 를 저장하는 function object
//Callback에 사용되지만, 동시에 객체 자신 내에 데이터를 저장할 수 있다
struct EmpIds {
	std::vector<int> m_Ids;

	void operator()(const Employee& emp) {
		if (emp.GetProgrammingLanguage() == "C++")
			m_Ids.push_back(emp.GetId());
	}
};


void makeVector() {

	//Employee 객체를 저장하는 Vector
	std::vector<Employee> v{
		Employee{ "Umar", 101, "C++" },
		Employee{ "Bob", 202, "Java"},
		Employee{ "Joey", 200, "C++"}
	};


	/*
		Use callback to avoid overloading comparison operators
		직접 정의한 객체를 비교할 때, 클래스 내부에 정의된 멤버 operator 사용 => 너무 제한적이다

		Comparator 를 정의하지 않고, 그때 그때 필요한 것을 지정한다 => 여기서는 Lambda Expression 이용
		+ alogrithm::함수를 사용
	*/
	//boolean return = predicate
	//algorithm::sort() => iterator 로 범위 지정, comparator로 정렬
	//지정 구간을 정렬해준다
	std::sort(v.begin(), v.end(), [](const auto& e1, const auto& e2) { //e1이 왼쪽, e2가 오른쪽에 올때 참을 리턴하도록한다
		
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


	//얼마나 많은 사람들이 C++ 를 사용하는 지 알고 싶다
	int cppCount{};
	
	//1. 직접 루프를 돌면서 확인
	for (const auto &e : v) {
		if (e.GetProgrammingLanguage() == "C++")
			++cppCount;
	}
	cppCount = 0;

	/*
		2. algorithm::count() 사용
		return the count of some specific elements in the container

		그런데 이걸 사용하려면 클래스에 == operator 가 오버로드 되어 있어야 한다
		cppCount = std::count(v.begin(), v.end(), Employee("", 0, "C++"));	
	*/

	
	/*
		3. algorithm::count_if() 사용

		operator overloading이 없어도 사용가능
		count_if => predicate 를 받는다
		그때 그때 원하는 comparatpor를 줄 수 있다 
	*/
	// 람다 표현식으로 predicate 제공
	cppCount = std::count_if(v.begin(), v.end(), [](const auto& e) {
		return e.GetProgrammingLanguage() == "C++";
		});

	std::cout << "Count:" << cppCount << std::endl;


	
	/*
		algorithm::find_if()

		comparator가 참을 리턴하는 요소를 만나면, 그 위치 iterator 를 리턴
	*/
	//Find if any employee knows Java
	auto itr = std::find_if(v.begin(), v.end(), [](const auto& e) {
		return e.GetProgrammingLanguage() == "Java";
		});
	if (itr != v.end()) { //못 찾으면 end() iterator 를 리턴한다
		std::cout << "Found:" << itr->GetName() << " is a Java programmer" << std::endl;
	}


	
	/*
		algorithm::for_each()

		container 의 각 element 에 대해서, 넘겨받은 Callback 을 적용한다
	*/
	std::for_each(v.begin(), v.end(), [](const auto& e) {
		std::cout << e.GetName() << std::endl;
		});



	/*
		for_each()에 function object를 사용하는 경우
			사용한 function object를 리턴한다
		
		Callback으로 function object를 넘기는 경우
		function object 내 멤버변수를 이용할 수 있다
	*/
	//Get ids of all employees that know C++
	//넘긴 Function Object를 리턴한다        			//Function Object 를 만들어서 넘김
	auto foundIds = std::for_each(v.begin(), v.end(), EmpIds{});
	
	for (int id : foundIds.m_Ids) {
		std::cout << "Id:" << id << std::endl;
	}
}



//Custom comparator for associative containers
//Employee 객체들을 비교하는 방법을 직접 지정
//Function Object로 구현한, 비교 연산자
struct EmpCompare {
	bool operator ()(const Employee& e1, const Employee& e2)const {
		return e1.GetId() < e2.GetId();
	}
};



void makeSet() {
	
	/*
		set 에 새로운 만든 타입을 저장하고자 한다
		set/multiset, map/multimap = associative containers
		=> binary tree 이용, 자동으로 정렬한다
		= comparator 가 필요 => function object 를 이용해보자
	*/
	std::set<Employee, EmpCompare> v{
		//				 ^^^^ Using custom comparator, 타입만 넘기네?
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