#include <iostream>
#include <string>


// User Defined Data Type �� �����ϴ� hash table �� ������
#include <unordered_set>

// ���� ���� ������ Ÿ��
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
// function object �� �����Ѵ�
struct EmployeeHash {
	size_t operator()(const Employee& emp) const {
		
		// Employee class �� ���п� ���ؼ� hash �� ���ϰ�
		auto s1 = std::hash<std::string>{}(emp.GetName());
		auto s2 = std::hash<int>{}(emp.GetId());
		
		// xor operation
		return s1 ^ s2;
	}
};


//Custom function object for equality
// unordered container �� �ֱ� ���ؼ��� �ʿ�
struct EmpEquality {
	bool operator()(const Employee& e1, const Employee e2)const {
		return e1.GetId() == e2.GetId() && e1.GetName() == e2.GetName();
	}
};


int main()
{
	// hash object �� �����? => std::string ���� �޾Ƽ� index �� ����ϴ� hash function
	std::hash<std::string> h;
	//Hash is computed by the function object
	std::cout << "Hash Value for \"Hello\" : " << h("Hello") << std::endl;


	// type, hash function, equality, allocator => unordered container ����
	// function object �� �������� �ʰ�, �׳� Ÿ�Ը� �ѱ��
	std::unordered_set<Employee, EmployeeHash, EmpEquality>coll;

	coll.insert(Employee("Umar", 123));
	coll.insert(Employee("Bob", 678));
	coll.insert(Employee("Joey", 612));

	for (const auto& x : coll) {
		std::cout << x.GetId() << ":" << x.GetName() << std::endl;
	}
}