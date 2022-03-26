#include <iostream>
#include <string>

// User Defined Data Type 을 저장하는 hash table 을 만들어보자
#include <unordered_set>


//저장하고자 하는, 직접 만든 데이터 타입
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



//hash function for Employ Class
//function object 로 정의한다
struct EmployeeHash {
	size_t operator()(const Employee& emp) const {
		
		/*
			std::hash<type>{} => 해당 타입을 받는 hash function return
			출력된 hash function 에 타입을 넣으면 => hash function 결과가 나온다
		
			Employee class 각 성분에 대해서 hash 를 구하고
		*/
		auto s1 = std::hash<std::string>{}(emp.GetName());
		auto s2 = std::hash<int>{}(emp.GetId());
		
		//xor operation
		//hash 결과는 xor 연산한다?
		return s1 ^ s2;
	}
};


//Custom function object for equality
//unordered set 에 넣기 위해서는 비교 comparator 가 필요하다
struct EmpEquality {
	bool operator()(const Employee& e1, const Employee e2)const {
		return e1.GetId() == e2.GetId() && e1.GetName() == e2.GetName();
	}
};


int main() {
	// hash object 를 만든다 => std::string 값을 받아서 index 를 출력하는 hash function
	std::hash<std::string> h;

	//Hash is computed by the function object
	std::cout << "Hash Value for \"Hello\" : " << h("Hello") << std::endl;


	//type, hash function, equality, allocator => unordered container 정의
	/*
		User Defined Type을 저장하기 때문에 Default를 사용할 수 없다
		User Defined Type을 받는 Hash 와 Equality를 정의해주어야 한다
		
		function object 객체를 넘기지 않고, 그냥 타입만 넘긴다
	*/
	std::unordered_set<Employee, EmployeeHash, EmpEquality>coll;

	coll.insert(Employee("Umar", 123));
	coll.insert(Employee("Bob", 678));
	coll.insert(Employee("Joey", 612));

	for (const auto& x : coll) {
		std::cout << x.GetId() << ":" << x.GetName() << std::endl;
	}
}