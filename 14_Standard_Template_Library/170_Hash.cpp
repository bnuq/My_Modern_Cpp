#include <iostream>
#include <string>


// User Defined Data Type 을 저장하는 hash table 을 만들어보자
#include <unordered_set>

// 직접 만든 데이터 타입
class Employee {
	std::string m_Name;
	int m_Id;
public:
	Employee(const std::string& n, int id) :m_Name(n), m_Id(id) {

	}
	const std::string& GetName()const {
		return m_Name;
	}
	int GetId()const {
		return m_Id;
	}
};

// hash function for Employ Class
// function object 로 정의한다
struct EmployeeHash {
	size_t operator()(const Employee& emp) const {
		
		// Employee class 각 성분에 대해서 hash 를 구하고
		auto s1 = std::hash<std::string>{}(emp.GetName());
		auto s2 = std::hash<int>{}(emp.GetId());
		
		// xor operation
		return s1 ^ s2;
	}
};


//Custom function object for equality
// unordered container 에 넣기 위해서는 필요
struct EmpEquality {
	bool operator()(const Employee& e1, const Employee e2)const {
		return e1.GetId() == e2.GetId() && e1.GetName() == e2.GetName();
	}
};


int main()
{
	// hash object 를 만든다? => std::string 값을 받아서 index 를 출력하는 hash function
	std::hash<std::string> h;
	//Hash is computed by the function object
	std::cout << "Hash Value for \"Hello\" : " << h("Hello") << std::endl;


	// type, hash function, equality, allocator => unordered container 정의
	// function object 를 만들지는 않고, 그냥 타입만 넘긴다
	std::unordered_set<Employee, EmployeeHash, EmpEquality>coll;

	coll.insert(Employee("Umar", 123));
	coll.insert(Employee("Bob", 678));
	coll.insert(Employee("Joey", 612));

	for (const auto& x : coll) {
		std::cout << x.GetId() << ":" << x.GetName() << std::endl;
	}
}