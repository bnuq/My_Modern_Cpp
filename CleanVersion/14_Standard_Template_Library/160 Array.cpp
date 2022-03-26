#include <iostream>
#include <array>


int main() {

	// std::array
	// 저장 타입과 갯수 지정
	// uniform initialization
	std::array<int, 5> arr{ 3,1,8,5,9 };
	

	// create iterator
	auto itr = arr.begin();
	auto itr2 = arr.end();


	// range-based for loop
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	
	
	// static array 주소 리턴
	// underlying array 주소를 리턴
	int* pInt = arr.data();


	std::array<float, 10> testArr{ 1.1f, 2.2f };
	auto testItr = testArr.begin();

	// arr.size() => element 개수
	for (int i = 0; i < testArr.size(); ++i) {
		std::cout << *testItr << std::endl;
		++testItr;
	}

	return 0;
}