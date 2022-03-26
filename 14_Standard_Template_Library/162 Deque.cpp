#include <iostream>
#include <deque>


int main() {

	//deque => 양 끝단에서 오고 나갈 수 있다
	std::deque<int> coll{ 7,8,9 };

	/*
		push_back()
		puch_fornt()

		앞, 뒤 양쪽에서 넣는 것이 가능하다
	*/
	for (int i = 0; i < 5; ++i) {
		coll.push_back(i * 10);
	}
	for (int i = 0; i < 5; ++i) {
		coll.push_front(- i * 10);
	}


	// random access
	coll[0] = 100;

	
	//iterator 사용
	auto itr = coll.begin();
	while (itr != coll.end()) {
		std::cout << *itr++ << " ";
	}
	std::cout << std::endl;


	/*
		insert()
		erase()

		iterartor 를 이용해서, 해당 위치에 값을 넣거나 빼기
	*/
	coll.insert(coll.begin()+2, -1000);
	coll.erase(coll.end() - 5);


	/*
		pop_back()
		pop_front()
	
		지우는 것도 앞 뒤 모두에서 가능하다
	*/
	coll.pop_back();
	coll.pop_front();


	for (int i = 0; i< coll.size(); ++i) {
		std::cout << coll[i] << " ";
	}
	std::cout << std::endl;
}