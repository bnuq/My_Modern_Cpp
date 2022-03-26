#include <iostream>
#include <vector>


int main() {

	// vector => type, allocator �� ��� => ���⼭�� Ÿ�Ը�
	std::vector<int> coll{ 1,2,3,4 };

	for (int i = 0; i < 5; ++i) {
		
		// ���� ���� �߰�
		coll.push_back(i * 10);

		// size() method => ���� ���� ����
		std::cout << coll.size() << std::endl;
	}

	// random access ����
	coll[0] = 100;

	// ���� ���� ���
	//for (int i = 0; i< coll.size(); ++i) {
	//	std::cout << coll[i] << " ";
	//} ���ٴ�
	// iterator �� ����ϴ� ���� ����
	auto itr = coll.begin();
	while (itr != coll.end()) {
		// * �� ������ �����ϰ�, ���� ++
		std::cout << *itr++ << " ";
	}
	std::cout << std::endl;


	// insert() => iterator ��ġ�� ���� �߰�
	//���� ��ġ�� �ִ� �� ~ �ڿ� �ִ� �͵� => �ٵ� ��ĭ�� �з�����
	coll.insert(coll.begin()+1, 700);

	// erase() => iterator ��ġ�� ���� ����
	//�ڿ� �ִ� �͵��� ��ĭ�� ������ �̵�
	coll.erase(coll.end() - 5);

	// pop_back() => �� ���� ����
	coll.pop_back();


	for (auto x : coll)
		std::cout << x << " , ";
	std::cout << std::endl;
}