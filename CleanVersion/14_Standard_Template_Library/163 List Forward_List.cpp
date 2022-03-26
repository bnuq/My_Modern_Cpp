#include <iostream>
#include <list>
#include <forward_list>

int main()
{
	
	//list = two way linked list => insert, erase �� �����Ӵ�, ����
	std::list<int> coll;

	/*
		push_back()
		push_front()
	*/
	for (int i = 0; i < 5; ++i) {
		coll.push_back(i * 10);
	}
	for (int i = 0; i < 5; ++i) {
		coll.push_front(-i * 10);
	}

	//random access �Ұ��� => �� ��°�� ��ġ�ϴ� �� �ѹ��� �� �� ����
	//coll[1] = 10;

	auto itr = coll.begin();
	while (itr != coll.end()) {
		std::cout << *itr++ << " ";
	}
	std::cout << std::endl;


	//iterator => insert, erace ����!
	//two way linked list => iterator �� ��������� �ٴѴ�
	itr = coll.begin();

	//������ �پ����� �ʴ� => iterator�� �ܼ� ���� ������ �Ұ����ϴ�
	//coll.insert(itr + 1, 800);
	//coll.erase(itr + 4);

	//++, -- ������ ���� => ��ġ�� ��ġ�Ŀ� ����
	//=> iterator �� ���� �ٲٰ� �̿��ϴ� ��, �̿��ϰ� ���� �ٲٴ� ��
	//-- = ����, �������� �̵�
	//++ = ����, ���������� �̵�
	coll.insert(++itr, 7000);
	coll.insert(--itr, 8000);


	itr = coll.begin();
	
	/*
		std::advance()
		std::next()
		
		iterator�� n ��ŭ ���������� �̵� => �����ϴ� ����
	*/
	std::advance(itr, 4);
	coll.insert(itr, 9000);

	itr = coll.begin();
	itr = std::next(itr, 5);
	coll.insert(itr, 10000);


	for (auto x : coll)
		std::cout << x << " ";
	std::cout << std::endl;


	itr = coll.begin();
	coll.erase(itr++); //iterator��°�� ó���ϰ�, 1ĭ ����
	coll.erase(itr++);


	for (auto x : coll)
		std::cout << x << " ";
	std::cout << std::endl;




	//forward list = one way linked list => ������ �� �ʹۿ� ����
	std::forward_list<int> forColl;
	for (int i = 0; i < 10; ++i) {
		
		/*
			push_front()
		
			����, �տ����� �ִ� ���� �����ϴ�
		*/
		forColl.push_front(i);
		
		// �ڷδ� �� �ִ´�
		//forColl.push_back(i + 2);
	}

	for (auto x : forColl) {
		std::cout << x << " ";
	}
	std::cout << std::endl;


	/*
		insert_after()
		erase_after()

		insert, erase �� iterator �� ����Ű�� ����� ~ �ڿ� �����Ѵ�
	*/
	forColl.insert_after(forColl.begin(), 10);
	forColl.erase_after(++forColl.begin());

	for (auto x : forColl) {
		std::cout << x << " ";
	}
	std::cout << std::endl;



	auto forItr = forColl.begin();
	forColl.insert_after(++forItr, 100);
	

	/*
		std::advance()
		std::next()

		forward_list' iterator ������ ��밡���ϴ�
	*/
	std::advance(forItr, 3);
	forColl.insert_after(forItr, 200);
	forColl.erase_after(++forItr);

	for (auto x : forColl) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}