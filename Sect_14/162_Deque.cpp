#include <iostream>
#include <deque>

int main()
{
	std::deque<int> coll{ 7,8,9 };


	// 앞, 뒤 양쪽에서 넣는 것이 가능하다
	for (int i = 0; i < 5; ++i) {
		coll.push_back(i * 10);
	}
	for (int i = 0; i < 5; ++i) {
		coll.push_front(- i * 10);
	}


	// random access
	coll[0] = 100;


	
	auto itr = coll.begin();
	while (itr != coll.end()) {
		std::cout << *itr++ << " ";
	}
	std::cout << std::endl;


	// insert, erase functions
	coll.insert(coll.begin()+2, -1000);
	coll.erase(coll.end() - 5);


	// 지우는 것도 앞 뒤 모두에서 가능하다
	coll.pop_back();
	coll.pop_front();


	for (int i = 0; i< coll.size(); ++i) {
		std::cout << coll[i] << " ";
	}
	std::cout << std::endl;
}