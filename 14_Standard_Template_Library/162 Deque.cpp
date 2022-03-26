#include <iostream>
#include <deque>


int main() {

	//deque => �� ���ܿ��� ���� ���� �� �ִ�
	std::deque<int> coll{ 7,8,9 };

	/*
		push_back()
		puch_fornt()

		��, �� ���ʿ��� �ִ� ���� �����ϴ�
	*/
	for (int i = 0; i < 5; ++i) {
		coll.push_back(i * 10);
	}
	for (int i = 0; i < 5; ++i) {
		coll.push_front(- i * 10);
	}


	// random access
	coll[0] = 100;

	
	//iterator ���
	auto itr = coll.begin();
	while (itr != coll.end()) {
		std::cout << *itr++ << " ";
	}
	std::cout << std::endl;


	/*
		insert()
		erase()

		iterartor �� �̿��ؼ�, �ش� ��ġ�� ���� �ְų� ����
	*/
	coll.insert(coll.begin()+2, -1000);
	coll.erase(coll.end() - 5);


	/*
		pop_back()
		pop_front()
	
		����� �͵� �� �� ��ο��� �����ϴ�
	*/
	coll.pop_back();
	coll.pop_front();


	for (int i = 0; i< coll.size(); ++i) {
		std::cout << coll[i] << " ";
	}
	std::cout << std::endl;
}