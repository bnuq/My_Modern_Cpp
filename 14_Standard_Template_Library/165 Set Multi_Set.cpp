#include <iostream>
#include <set>

//comparator 설정 시 필요
#include <functional>


int main() {

	//set => binary tree 로 구성 => element 를 비교하는 방법이 필요하다
	//type, comparator, allocator
	std::set<int, std::greater<int>> s{ 8,2,0,9,5 };
	//std::set<int> s{ 8,2,0,9,5 };


	//No push_back, only insert as elements are ordered automatically
	s.insert(1);


	//Only multiset allows duplicates
	//일반 set 은 아무리 넣어도 하나만 들어간다 => 무시되는 거지
	s.insert(3);
	s.insert(3);
	s.insert(3);


	auto itr = s.begin();
	//*itr = 3; => 직접 변경 불가능, 이미 노드 위치가 설정됐으니까

	while (itr != s.end()) {
		//왼쪽 -> 오른쪽으로 iterator 가 순회
		std::cout << *itr++ << " ";
	}
	std::cout << std::endl;

	
	//Erase by key or position
	s.erase(0); //by key
	s.erase(++s.begin()); //by iterator, position


	for (auto x : s)
		std::cout << x << " ";
	std::cout << std::endl;
	
	
	//find( key, value ) => 해당 위치, iterator 얻기
	itr = s.find(9);

	// 실패 시 return end()
	if (itr != s.end()) {
		std::cout << "Element found" << std::endl;
	}
	else {
		std::cout << "Not found" << std::endl;
	}


	
	//multiset => binary tree 에 저장은 똑같, 중복 값을 저장할 수 있다
	std::multiset<int, std::less<int>> ms{ 3,2,4,1,2 };
	ms.insert(4);
	ms.insert(4);
	ms.insert(4);
	ms.insert(4);


	/*
		equal_range()
		
		return iterator pair
		multiset 에서 중복되는 값들의 위치를 찾는 함수
	*/
	auto found = ms.equal_range(4); //범위 iterator 를 가지는 pair 리턴
	while (found.first != found.second) {
		std::cout << *found.first++ << " ";
	}
}