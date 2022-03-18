#include <iostream>
#include <set>
// comparator ���� �� �ʿ�
#include <functional>

int main()
{
	// type, comparator, allocator
	std::set<int, std::greater<int>> s{ 8,2,0,9,5 };


	//No push_back, only insert as elements are ordered automatically
	s.insert(1);

	//Only multiset allows duplicates
	//�Ϲ� set �� �ƹ��� �־ �ϳ��� ����
	s.insert(3);
	s.insert(3);
	s.insert(3);

	auto itr = s.begin();
	//*itr = 3; => ���� ���� �Ұ���
	while (itr != s.end())
	{
		std::cout << *itr++ << " ";
	}
	std::cout << std::endl;

	//Erase by key or position
	s.erase(0); //by key
	s.erase(++s.begin()); //by iterator, position

	for (auto x : s)
		std::cout << x << " ";
	std::cout << std::endl;
	
	
	//find() = key, value �� iterator ���
	itr = s.find(9);
	// ���� �� return end()
	if (itr != s.end()) {
		std::cout << "Element found" << std::endl;
	}
	else {
		std::cout << "Not found" << std::endl;
	}


	

	// multiset �� ���
	std::multiset<int, std::less<int>> ms{ 3,2,4,1,2 };
	ms.insert(4);
	ms.insert(4);
	ms.insert(4);
	ms.insert(4);


	//equal_range = multiset ���� �ߺ��Ǵ� ������ ��ġ�� ã�� �Լ�
	auto found = ms.equal_range(4); // ���� iterator �� ������ pair ����
	while (found.first != found.second) {
		std::cout << *found.first++ << " ";
	}
}