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
		기존에는 각 memebr variable 에 따로따로 접근해야 했는데
		auto name = p.m_Name ;
		auto age = p.m_Age ;
	*/
	// Structure Binding 을 사용하면, 각 멤버 변수에 동시에 접근할 수 있다
	// const, volatile, reference 모두 가능
	const auto& [name, age] = p;
	std::cout << p.m_Age << std::endl;


	// STL 과도 같이 사용할 수 있다
	std::pair<int, int> p1{ 3,5 };
	auto [key, value] = p;

	// map => 내부적으로 pair 를 저장
	std::map<int, std::string> errorInfo{ {1, "Not available"}, {2, "Port is in use"} };

	//for (auto err : errorInfo) {
	//	// 기존방식 => first, second 로 pair 의 성분에 접근
	//	std::cout << err.first << ":" << err.second << std::endl;
	//}

	// 애초에 각 pair 를 받을 때 structure binding 으로 받아 => 각 성분에 이름을 붙인다
	for (const auto& [key, value] : errorInfo) {
		std::cout << key << ":" << value << std::endl;
	}

	// array 에도 사용 가능
	int arr[] = { 1,2,3 };
	auto [a, b, c] = arr;

	auto arr2 = arr; // 그냥 array 이름만 쓰면, pointer type
	
	S1 s{};
	/*
	* structure binding 으로 array type 을 받으면
	* 받는 쪽도 array type 으로 받는다
	*/
	auto [s1, s2] = s;
}