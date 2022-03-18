#include <iostream>
#include <string>
#include <map>

int main()
{
	
	// key type, value type, comparator, allocator ����
	// key ���� �ڵ����� �����ؼ� �����Ѵ�
	std::map<int, std::string> m{
		
		// key, value �� pair ���·� ����ȴ�
		{1, "Superman"},
		{2, "Batman"},
		{3, "Green Lantern"}
	};


	// insert �� �� pair object �� ���� �ִ´�
	// binary tree �ϱ�, Ư�� ��ġ�� �ִ´� X => �׳� Ʈ���� �߰��ϴ� ����
	m.insert(std::pair<int, std::string>(8, "Aquaman"));
	

	// std::make_pair => Ÿ���� �ڵ����� ��ȯ�ؼ� ������ش� => Ÿ�� ������ ���ŷο��� ����
	m.insert(std::make_pair(6, "Wonder Woman"));
	m.insert(std::make_pair(6, "Powergirl")); // �Ϲ� map => duplicate X, �׳� ���õȴ�


	//Only map support [] operator
	// key �� �ٲ� �� ������, key �̿� => value �� �ٲ� �� �ִ�
	m[0] = "Flash";
	m[0] = "Kid Flash";

	
	// map �ȿ� �ִ� pair ���� ó�� => reference �̿�, ���ʿ��� ���縦 ���´�
	for (const auto &x : m) {
		std::cout << x.first << " : " << x.second << std::endl;
	}

	
	auto itr = m.begin(); // iterator
	
	//Lookup by key
	itr = m.find(1);
	if (itr != m.end()) {
		std::cout << "Found:" << itr->second << std::endl;
	}
	else {
		std::cout << "Not found" << std::endl;
	}


	// Avoid using [] for searching as it will insert an empty element if a key cannot be found
	// �������� �ʴ� key �� [] �� ã�����ϸ�, �׳� ���� map �� �ڵ����� �߰��� �ǹ�����
	std::cout << "Find 3 : " << m[3] << std::endl;	// 3 = �����ϴ� key => value ���
	std::cout << "Find 10 :" << m[10] << std::endl;	// 10 = ���� key => empty value �� �Բ� �ڵ����� �߰��ȴ�
	for (const auto& x : m) {
		std::cout << x.first << " : " << x.second << std::endl;
	}


	// ����� ��� => key �̿� or iterator �̿�
	m.erase(0);
	itr = m.begin();
	m.erase(itr);
	itr = (--m.end());
	m.erase(itr);

	for (const auto& x : m) {
		std::cout << x.first << " : " << x.second << std::endl;
	}




	// multimap �� ��� �ߺ�����, [] ��� �Ұ���
	std::multimap<int, std::string>mm{
		{1, "first"},
		{2, "second"}
	};

	//mm[1] = "FIRST"; �Ұ���


	// multimap, key �ߺ�����
	mm.insert(std::make_pair(3, "third"));
	mm.insert(std::make_pair(3, "THIRD"));
	mm.insert(std::make_pair(3, "SebunJJE"));


	// returns a pair that contains begin & end of the range.
	// ������ key �� ������ ������ ���� iterator pair return
	auto found = mm.equal_range(3);
	while (found.first != found.second) {

		// first, second => iterator => smart pointer ó�� ���
		std::cout << found.first->first << " : " << found.first->second << std::endl;
		found.first++;
	}
	
}