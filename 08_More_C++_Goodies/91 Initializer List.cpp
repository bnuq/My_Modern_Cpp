#include <iostream>
#include <initializer_list>
#include <cassert>

// container class 에서 많이 도움이 된다
class Bag {
	int arr[10]{};
	int m_Size{};
public:
	// 임의의 배열처럼, 개수를 알 수 없는 어떤 배열로 객체를 만들고 싶다 + Uniform Initialization 을 하고 싶다
	// 임의의 배열 => initializer list 로 표현
	// Provides uniform initialization support for braced list of elements as arguments
	Bag(std::initializer_list<int> values) { // initializer list 를 받는 생성자
		assert(values.size() < 10);
		auto it = values.begin(); // initializer list iterator
		while (it != values.end()) {
			Add(*it);
			++it;
		}
	}
	void Add(int value) {
		assert(m_Size < 10);
		arr[m_Size++] = value;
	}
	void Remove() {
		--m_Size;
	}
	int operator [](int index) {
		return arr[index];
	}
	int GetSize()const {
		return m_Size;
	}
};

// 크기를 알 수 없는 배열을 넘겨받는 것과 같다
void Print(std::initializer_list<int> values) {
	//auto it = values.begin();
	//while (it != values.end()) {
	//	std::cout << *it++ << " ";
	//}
	for (auto x : values) {
		std::cout << x << " ";
	}
}




int main() {
	// Uniform Initialization
	int x{ 0 };
	float y{ 3.1f };
	int arr[5]{ 3,1,3,8,2 };
	std::string s{ "Hello C++" };


	// Initializer_List => 배열처럼 여러 값들을 저장한다
	std::initializer_list<int> data = { 1,2,3,4 };
	// Uniform Initialization 이 아닌 데서, 갑자기 쓰이는 중괄호 => initializer list
	//Braced list of elements automatically creates an initializer_list object
	auto values = { 1,2,3,4 };

	
	// Uniform Initialization 을 작성 => 맞는 arguments 를 받는 생성자가 없다
	// 그런데 initializer_list 를 받는 생성자가 있으면 => Uniform Initialization 을 initializer_list 가 받아 해결한다
	Bag b{ 3,1,8 };
	//b.Add(3);
	//b.Add(1);
	//b.Add(8);
	for (int i = 0; i < b.GetSize(); ++i) {
		std::cout << b[i] << " "; 
	}

	// Print({ 8,2,6,7 });
	for (auto x : { 8,2,6,7 }) {
		std::cout << x << " ";
	}


	return 0;
}