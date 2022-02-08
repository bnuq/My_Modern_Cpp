#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>


#include <vector>
#include <list>
#include <deque>

#include <set>


#include "175_Integer.h"


void codeFrom175()
{
	// C++ 11 부터 모든 container can use uniform initialization
	std::vector<int> vint{ 1,2,3,4 };

	std::vector<Integer> VInt;
	VInt.reserve(10);

	// 1. 9=> Integer(9) 를 먼저 만들고
	// 2. 앞서 만든 값을 rvalue=> 벡터 내에 Integer(&&) 를 만든다
	VInt.push_back(9);


	// emplace => 벡터 내에 Integer 를 만들면서, 바로 5 로 초기화 한다
	// 객체를 1개만 만든다
	VInt.emplace_back(10);

	// 비슷한 함수, emplace, emplace_front
	// emplace 사용 => Copy Assignment Operator 필요했다
	// pos 이전 위치에, 값을 넣는 역할
	VInt.emplace(VInt.end(), Integer(100));


	for (const auto& x : VInt)
		std::cout << x << std::endl;



	std::vector<std::pair<int, std::string>>largeVec;

	// 기존 push_back => 객체를 넘겨야 하므로, pair 를 만들어서 넣어주어야 한다
	largeVec.push_back(std::pair<int, std::string>{1, "SuperMan"});
	largeVec.push_back(std::make_pair(2, "BatMan"));


	// emplace_back 은 벡터 내에서 객체를 직접 만들기 때문에, 객체 생성에 필요한 argument 만 넘기면 된다
	largeVec.emplace_back(3, "SpiderMan");
	largeVec.emplace(largeVec.end(), 4, "Molu");

	for (auto x : largeVec)
		std::cout << x.first << " : " << x.second << std::endl;
}

void codeFrom176()
{
	std::vector<Integer>vec;

	/*
	* vector 에 값을 계속 추가하면, 벡터의 크기가 더 필요해 => 재할당을 하게 된다
	* 그러면 기존에 저장한 값을 새로 할당한 벡터에 넣고, 새로운 값을 가져오는데
	* 기존에 만든 객체 => move operation 을 이용하면, 불필요한 생성, 삭제를 막을 수 있는데 작동하지 않는다
	* 왜?? => move constructor, move assignment operator 가 있어도 exception 이 중간에 발생하면 재할당이 완료가 안돼서 문제가 생긴다
	* 그래서 noexcept 가 명시적으로 씌여 있지 않다면 move operation 을 하지 않는다
	*
	* move constructor
	* move assignment operator
	* 선언, 정의에 noexcept 를 썼더니 이제 벡터를 재할당할 때 move operation 을 사용한다
	*/
	vec.emplace_back(1);
	vec.emplace_back(2);
	vec.emplace_back(3);
}

void codeFrom177_shrink()
{
	std::vector<int> vInt;
	for (size_t i = 0; i < 100; i++)
		vInt.emplace_back(i);

	// size = number of elements
	std::cout << "Size : " << vInt.size() << std::endl;
	// capacity = growing 없이 넣을 수 있는 개수
	std::cout << "Capacity : " << vInt.capacity() << std::endl;


	// element 를 지워도 capacity 는 줄지 않는다
	vInt.erase(vInt.begin(), vInt.end() - 10);
	std::cout << "Size : " << vInt.size() << std::endl;
	std::cout << "Capacity : " << vInt.capacity() << std::endl;


	// shrink to fit => capaacity 를 size 에 맞게 재할당
	vInt.shrink_to_fit();
	std::cout << "Size : " << vInt.size() << std::endl;
	std::cout << "Capacity : " << vInt.capacity() << std::endl;


}

void codeFrom177_data()
{
	// 파일을 읽고 싶을 때
	std::ifstream input{};
	input.open(R"(./Sect_14/175_Integer.cpp)");

	if (!input)
	{
		std::cout << "Could not open file" << std::endl;
		return;
	}
	
	 // from C++17, filesystem 이용, 파일의 크기를 알 수 있다
	auto fSize = std::filesystem::file_size(R"(./Sect_14/175_Integer.cpp)");

	// 원래는 char array 이용 => 파일 characters 를 직접 관리
	// char* buff = new char[size]{};

	// char array 를 직접 관리하면 어려우니까, vector 나 string 을 이용할 수 있다
	// chars 관리를 vector, string 에 맞김
	// memory management 를 맡긴다
	//std::vector<char> buffer;
	std::string buffer;

	// 파일 크기만큼 container 크기 조절
	buffer.resize(fSize);

	// data() => container 의 주소 리턴
	input.read(buffer.data(), fSize);

	
	std::cout << buffer.data() << std::endl;
}

void codeFrom178()
{
	// container 에서 값을 지우는 방법이 제각각이였는데
	// C++20 부터, sequence contatiner 들은 모두 동일하게 값을 지울 수 있게 됐다
	// std::erase 이용, 값으로 위치를 찾아서 지울 수 있다

	// Any sequence containers
	std::vector<int> vInt{ 1,2,3,4 };
	std::list<int> lst{ 1,2,3,4 };
	std::deque<int> deq{ 4,3,2,1 };


	// 동일한 방법으로 value 를 지울 수 있다
	std::erase(vInt, 3);
	std::erase(lst, 2);
	std::erase(deq, 1);
	
}

void codeFrom179()
{
	// Associative Containers 에 대해서
	// 자동으로 정렬되기 때문에 넣을 때 위치를 지정할 수 없다
	// 하지만, 넣으려는 값의 대략적인 위치를 알려주면서 넣을 수 있다 => 힌트가 올바르면 더 빠르게 넣을 수 있따
	// + emplace
	std::set<int> s{ 3,2,4,1 };

	s.emplace(0);
	s.emplace_hint(s.end(), 10);


	for (auto x : s)
		std::cout << x << std::endl;




	// Associative Coontainer 안에 어떤 값이 존재하는 지 알려고 할 때
	// 1. 기존 방법
	auto itr = s.find(3); // find method => iterator return
	if (itr == s.end()) std::cout << "Not found";

	// 2. From C++20
	auto found = s.contains(3); // contains method => bool return
	if(found) std::cout << "Found";



	std::set<std::string> names{ "Omar", "Ayaan", "Raihaan" };

	// find() => iterator return => const iterator, 이걸로 가리키는 값을 변경할 수 없다
	// set 에 이미 정리되어 있기 때문에... 바꾸면 혼돈이다
	auto it = names.find("Omar");
	auto& name1 = *it;
	// name1[0] = 'Z'; 바꿀 수 없다
	
	auto name2 = *it;
	name2[0] = 'Z';

	// value or iterator 를 이용해서 지운다음
	//names.erase("Omar");
	names.erase(it);
	// 바꾼 것을 넣어주어야 한다 => Copy 이용
	names.insert(name2);



	// 아니면 from C++17, non-copyable 에 사용가능
	// extract method => 기존 값을 move 해버리는 방법
	// auto node = names.extract("Omar");
	auto node = names.extract(it);

	node.value()[0] = 'Z';

	names.insert(std::move(node)); // 넣을 때도 move => 기존 객체 이용

}





int main()
{
	codeFrom179();
}