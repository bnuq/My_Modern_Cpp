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
	// C++ 11 ���� ��� container can use uniform initialization
	std::vector<int> vint{ 1,2,3,4 };

	std::vector<Integer> VInt;
	VInt.reserve(10);

	// 1. 9=> Integer(9) �� ���� �����
	// 2. �ռ� ���� ���� rvalue=> ���� ���� Integer(&&) �� �����
	VInt.push_back(9);


	// emplace => ���� ���� Integer �� ����鼭, �ٷ� 5 �� �ʱ�ȭ �Ѵ�
	// ��ü�� 1���� �����
	VInt.emplace_back(10);

	// ����� �Լ�, emplace, emplace_front
	// emplace ��� => Copy Assignment Operator �ʿ��ߴ�
	// pos ���� ��ġ��, ���� �ִ� ����
	VInt.emplace(VInt.end(), Integer(100));


	for (const auto& x : VInt)
		std::cout << x << std::endl;



	std::vector<std::pair<int, std::string>>largeVec;

	// ���� push_back => ��ü�� �Ѱܾ� �ϹǷ�, pair �� ���� �־��־�� �Ѵ�
	largeVec.push_back(std::pair<int, std::string>{1, "SuperMan"});
	largeVec.push_back(std::make_pair(2, "BatMan"));


	// emplace_back �� ���� ������ ��ü�� ���� ����� ������, ��ü ������ �ʿ��� argument �� �ѱ�� �ȴ�
	largeVec.emplace_back(3, "SpiderMan");
	largeVec.emplace(largeVec.end(), 4, "Molu");

	for (auto x : largeVec)
		std::cout << x.first << " : " << x.second << std::endl;
}

void codeFrom176()
{
	std::vector<Integer>vec;

	/*
	* vector �� ���� ��� �߰��ϸ�, ������ ũ�Ⱑ �� �ʿ��� => ���Ҵ��� �ϰ� �ȴ�
	* �׷��� ������ ������ ���� ���� �Ҵ��� ���Ϳ� �ְ�, ���ο� ���� �������µ�
	* ������ ���� ��ü => move operation �� �̿��ϸ�, ���ʿ��� ����, ������ ���� �� �ִµ� �۵����� �ʴ´�
	* ��?? => move constructor, move assignment operator �� �־ exception �� �߰��� �߻��ϸ� ���Ҵ��� �Ϸᰡ �ȵż� ������ �����
	* �׷��� noexcept �� ��������� ���� ���� �ʴٸ� move operation �� ���� �ʴ´�
	*
	* move constructor
	* move assignment operator
	* ����, ���ǿ� noexcept �� ����� ���� ���͸� ���Ҵ��� �� move operation �� ����Ѵ�
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
	// capacity = growing ���� ���� �� �ִ� ����
	std::cout << "Capacity : " << vInt.capacity() << std::endl;


	// element �� ������ capacity �� ���� �ʴ´�
	vInt.erase(vInt.begin(), vInt.end() - 10);
	std::cout << "Size : " << vInt.size() << std::endl;
	std::cout << "Capacity : " << vInt.capacity() << std::endl;


	// shrink to fit => capaacity �� size �� �°� ���Ҵ�
	vInt.shrink_to_fit();
	std::cout << "Size : " << vInt.size() << std::endl;
	std::cout << "Capacity : " << vInt.capacity() << std::endl;


}

void codeFrom177_data()
{
	// ������ �а� ���� ��
	std::ifstream input{};
	input.open(R"(./Sect_14/175_Integer.cpp)");

	if (!input)
	{
		std::cout << "Could not open file" << std::endl;
		return;
	}
	
	 // from C++17, filesystem �̿�, ������ ũ�⸦ �� �� �ִ�
	auto fSize = std::filesystem::file_size(R"(./Sect_14/175_Integer.cpp)");

	// ������ char array �̿� => ���� characters �� ���� ����
	// char* buff = new char[size]{};

	// char array �� ���� �����ϸ� �����ϱ�, vector �� string �� �̿��� �� �ִ�
	// chars ������ vector, string �� �±�
	// memory management �� �ñ��
	//std::vector<char> buffer;
	std::string buffer;

	// ���� ũ�⸸ŭ container ũ�� ����
	buffer.resize(fSize);

	// data() => container �� �ּ� ����
	input.read(buffer.data(), fSize);

	
	std::cout << buffer.data() << std::endl;
}

void codeFrom178()
{
	// container ���� ���� ����� ����� �������̿��µ�
	// C++20 ����, sequence contatiner ���� ��� �����ϰ� ���� ���� �� �ְ� �ƴ�
	// std::erase �̿�, ������ ��ġ�� ã�Ƽ� ���� �� �ִ�

	// Any sequence containers
	std::vector<int> vInt{ 1,2,3,4 };
	std::list<int> lst{ 1,2,3,4 };
	std::deque<int> deq{ 4,3,2,1 };


	// ������ ������� value �� ���� �� �ִ�
	std::erase(vInt, 3);
	std::erase(lst, 2);
	std::erase(deq, 1);
	
}

void codeFrom179()
{
	// Associative Containers �� ���ؼ�
	// �ڵ����� ���ĵǱ� ������ ���� �� ��ġ�� ������ �� ����
	// ������, �������� ���� �뷫���� ��ġ�� �˷��ָ鼭 ���� �� �ִ� => ��Ʈ�� �ùٸ��� �� ������ ���� �� �ֵ�
	// + emplace
	std::set<int> s{ 3,2,4,1 };

	s.emplace(0);
	s.emplace_hint(s.end(), 10);


	for (auto x : s)
		std::cout << x << std::endl;




	// Associative Coontainer �ȿ� � ���� �����ϴ� �� �˷��� �� ��
	// 1. ���� ���
	auto itr = s.find(3); // find method => iterator return
	if (itr == s.end()) std::cout << "Not found";

	// 2. From C++20
	auto found = s.contains(3); // contains method => bool return
	if(found) std::cout << "Found";



	std::set<std::string> names{ "Omar", "Ayaan", "Raihaan" };

	// find() => iterator return => const iterator, �̰ɷ� ����Ű�� ���� ������ �� ����
	// set �� �̹� �����Ǿ� �ֱ� ������... �ٲٸ� ȥ���̴�
	auto it = names.find("Omar");
	auto& name1 = *it;
	// name1[0] = 'Z'; �ٲ� �� ����
	
	auto name2 = *it;
	name2[0] = 'Z';

	// value or iterator �� �̿��ؼ� �������
	//names.erase("Omar");
	names.erase(it);
	// �ٲ� ���� �־��־�� �Ѵ� => Copy �̿�
	names.insert(name2);



	// �ƴϸ� from C++17, non-copyable �� ��밡��
	// extract method => ���� ���� move �ع����� ���
	// auto node = names.extract("Omar");
	auto node = names.extract(it);

	node.value()[0] = 'Z';

	names.insert(std::move(node)); // ���� ���� move => ���� ��ü �̿�

}





int main()
{
	codeFrom179();
}