#include <iostream>
#include <map>

struct Person {
	std::string m_Name;
	int m_Age;
	Person() = default;
	Person(const std::string& name, int age) :m_Name{ name }, m_Age{ age }{}
};

struct S1 {
	int arr1[8]{};
	char ch1[256]{};
};

int main() {
	Person p{ "Ayaan", 14 };
	/*
		�������� �� memebr variable �� ���ε��� �����ؾ� �ߴµ�
		auto name = p.m_Name ;
		auto age = p.m_Age ;
	*/
	// Structure Binding �� ����ϸ�, �� ��� ������ ���ÿ� ������ �� �ִ�
	// const, volatile, reference ��� ����
	const auto& [name, age] = p;
	std::cout << p.m_Age << std::endl;


	// STL ���� ���� ����� �� �ִ�
	std::pair<int, int> p1{ 3,5 };
	auto [key, value] = p;

	// map => ���������� pair �� ����
	std::map<int, std::string> errorInfo{ {1, "Not available"}, {2, "Port is in use"} };

	//for (auto err : errorInfo) {
	//	// ������� => first, second �� pair �� ���п� ����
	//	std::cout << err.first << ":" << err.second << std::endl;
	//}

	// ���ʿ� �� pair �� ���� �� structure binding ���� �޾� => �� ���п� �̸��� ���δ�
	for (const auto& [key, value] : errorInfo) {
		std::cout << key << ":" << value << std::endl;
	}

	// array ���� ��� ����
	int arr[] = { 1,2,3 };
	auto [a, b, c] = arr;

	auto arr2 = arr; // �׳� array �̸��� ����, pointer type
	
	S1 s{};
	/*
	* structure binding ���� array type �� ������
	* �޴� �ʵ� array type ���� �޴´�
	*/
	auto [s1, s2] = s;
}