#include <iostream>
#include <string>
#include <map>


int main()
{
	/*
		Map => Set 처럼 binary tree 를 이용하지만, {key, value} pair 를 저장한다

		key 값을 이용, 자동으로 정렬해서 저장한다
		
		key type, value type, comparator, allocator 지정
			역시나 값들을 비교해서 tree 에 넣어야 하기 때문에 comparator 필요
			default comparator = std::less<key>, 작은 게 앞에 온다, 오름차순
	*/
	std::map<int, std::string> m{		
		//key, value 는 pair 형태로 저장된다
		{1, "Superman"},	//{ } 는 자동으로 pair 만듦
		{2, "Batman"},
		{3, "Green Lantern"}
	};


	//insert 할 때 pair object 를 만들어서 넣는다
	//binary tree 니까, 특정 위치에 넣는다 X => 그냥 트리에 추가하는 거지
	m.insert(std::pair<int, std::string>(8, "Aquaman"));
	

	//std::make_pair => 타입을 자동으로 변환해서 만들어준다 => 타입 지정의 번거로움이 없다
	m.insert(std::make_pair(6, "Wonder Woman"));
	m.insert({7, "KimchiMan"}); //중괄호를 사용해도 pair 만들 수 있다

	m.insert(std::make_pair(6, "Powergirl")); // 일반 map => duplicate X, 그냥 무시된다


	//Only map support [] operator
	//key 는 바꿀 수 없지만, key 이용 => value 를 바꿀 수 있다
	m[0] = "Flash";
	m[0] = "Kid Flash";

	
	// map 안에 있는 pair 들을 처리 => reference 이용, 불필요한 복사를 막는다
	for (const auto &x : m) { //x = map에 들어있는 pair
		std::cout << x.first << " : " << x.second << std::endl;
	}

	
	auto itr = m.begin(); // iterator
	
	
	/*
		find()

		Lookup by key
	*/
	itr = m.find(1);

	if (itr != m.end()) {
		std::cout << "Found:" << itr->second << std::endl;
	}
	else {
		std::cout << "Not found" << std::endl;
	}


	//Avoid using [] for searching
	//as it will insert an empty element if a key cannot be found
	//존재하지 않는 key 를 [] 로 찾으려하면, 그냥 만들어서 map 에 자동으로 추가가 되버린다
	std::cout << "Find 3 : " << m[3] << std::endl;	// 3 = 존재하는 key => value 출력
	std::cout << "Find 10 :" << m[10] << std::endl;	// 10 = 없는 key => empty value 와 함께 자동으로 추가된다
	for (const auto& x : m) {
		std::cout << x.first << " : " << x.second << std::endl;
	}


	// 지우는 방법 => key 이용 or iterator 이용
	m.erase(0);
	
	itr = m.begin();
	m.erase(itr);

	itr = (--m.end());
	m.erase(itr);

	for (const auto& x : m) {
		std::cout << x.first << " : " << x.second << std::endl;
	}




	// multimap 의 경우 중복가능, [] 사용 불가능
	std::multimap<int, std::string>mm{
		{1, "first"},
		{2, "second"}
	};

	
	//multimap 에서는 random access 불가능
	//mm[1] = "FIRST";


	// multimap, key 중복가능
	mm.insert(std::make_pair(3, "third"));
	mm.insert(std::make_pair(3, "THIRD"));
	mm.insert(std::make_pair(3, "SebunJJE"));


	
	/*
		equal_range()

		returns a pair that contains begin & end of the range.
		동일한 key 를 가지는 노드들의 범위 iterator pair return
	*/
	auto found = mm.equal_range(3);
	while (found.first != found.second) {
		// first, second => iterator => smart pointer 처럼 사용
		std::cout << found.first->first << " : " << found.first->second << std::endl;
		found.first++;
	}
	
}