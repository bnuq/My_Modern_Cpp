#include <iostream>
#include <array>

int main()
{
	// std::array ���� ��, Ÿ�԰� ���� ����
	// uniform initialization
	std::array<int, 5> arr{ 3,1,8,5,9 };
	

	// create iterator
	auto itr = arr.begin();


	// range-based for loop
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	
	
	// static array �ּ� ����
	int* pInt = arr.data();



	std::array<float, 10> testArr{ 1.1f, 2.2f };
	auto testItr = testArr.begin();

	// arr.size() => element ����
	for (int i = 0; i < testArr.size(); ++i) {
		std::cout << *testItr << std::endl;
		++testItr;
	}

	return 0;
}