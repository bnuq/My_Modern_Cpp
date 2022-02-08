#include <iostream>
#include <list>
#include <forward_list>

int main()
{
	
	// list = two way linked list => insert, erase 가 자유롭다, 쉽다
	std::list<int> coll;
	for (int i = 0; i < 5; ++i) {
		coll.push_back(i * 10);
	}
	for (int i = 0; i < 5; ++i) {
		coll.push_front(-i * 10);
	}

	// random access 불가능
	//coll[1] = 10;

	auto itr = coll.begin();
	while (itr != coll.end()) {
		std::cout << *itr++ << " ";
	}
	std::cout << std::endl;


	// iterator => insert, erace 쉽다!
	// two way linked list => iterator 가 양방향으로 다닌다, 원소들이 붙어있지 않다 => 단순 덧셈 뺄셈이 불가능하다
	itr = coll.begin();

	//coll.insert(itr + 1, 800);
	//coll.erase(itr + 4);

	// ++, -- 연산자 가능 => 전치냐 후치냐에 따라서 => iterator 를 먼저 바꾸고 이용하는 지, 이용하고 값을 바꾸는 지
	// -- = 앞쪽, 왼쪽으로 이동
	// ++ = 뒤쪽, 오른쪽으로 이동
	coll.insert(++itr, 7000);
	coll.insert(--itr, 8000);


	itr = coll.begin();
	// std::advance, std::next 이용해서 iterator 이동
	std::advance(itr, 4);
	coll.insert(itr, 9000);

	itr = coll.begin();
	itr = std::next(itr, 5);
	coll.insert(itr, 10000);


	for (auto x : coll)
		std::cout << x << " ";
	std::cout << std::endl;




	itr = coll.begin();
	coll.erase(itr++);
	coll.erase(itr++);


	for (auto x : coll)
		std::cout << x << " ";
	std::cout << std::endl;




	// forward list = one way linked list => 방향이 한 쪽밖에 없다
	std::forward_list<int> forColl;
	for (int i = 0; i < 10; ++i) {
		
		// 앞에서만 넣는 것이 가능하다
		forColl.push_front(i);
		
		// 뒤로는 못 넣는다
		//forColl.push_back(i + 2);
	}

	for (auto x : forColl) {
		std::cout << x << " ";
	}
	std::cout << std::endl;



	// insert, erase 도 iterator 가 가리키는 노드의 ~ 뒤에서 적용한다
	forColl.insert_after(forColl.begin(), 10);
	forColl.erase_after(++forColl.begin());

	for (auto x : forColl) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	auto forItr = forColl.begin();
	forColl.insert_after(++forItr, 100);
	std::advance(forItr, 3);
	forColl.insert_after(forItr, 200);
	forColl.erase_after(++forItr);

	for (auto x : forColl) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}