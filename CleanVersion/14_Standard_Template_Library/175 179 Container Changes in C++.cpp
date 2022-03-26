#include <iostream>
#include <string>

//File �̿�
#include <fstream>
#include <filesystem>

//STL
#include <vector>
#include <list>
#include <deque>
#include <set>

#include "Integer.h"


void codeFrom175() {
	
	//C++ 11 ���� ��� container can use uniform initialization
	std::vector<int> vint{ 1,2,3,4 };

	std::vector<Integer> VInt;
	VInt.reserve(10); //vector::reserve() => �޸� �̸� Ȯ��

	//1. 9=> Integer(9) �� ���� �����
	//2. �ռ� ���� ���� rvalue=> ���� ���� Integer(&&) �� �����
	VInt.push_back(9);


	//vector::emplace_back() => ���� ���� Integer �� ����鼭, �ٷ� 5 �� �ʱ�ȭ �Ѵ�
	//��ü�� 1���� �����
	VInt.emplace_back(10);

	//����� �Լ�, emplace, emplace_front
	//emplace ��� => Contianer�� ���� �� �ٷ� ��ü�� ����� �ʱ�ȭ �� �� �ִ�
	//pos ���� ��ġ��, ���� �ִ� ����
	//VInt.emplace(VInt.end(), Integer(100)); Move Assignmnet �� ����ϴ� ���
	VInt.emplace(VInt.end(), 100);


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

void codeFrom176() {

	std::vector<Integer>vec{};

	/*
		vector �� ���� ��� �߰��ϸ�, ������ ũ�Ⱑ �� �ʿ��� => ���Ҵ��� �ϰ� �ȴ�
		�׷��� ������ ������ ���� ���� �Ҵ��� ���Ϳ� �ְ�, ���ο� ���� �������µ�
		������ ���� ��ü => move operation �� �̿��ϸ�, ���ʿ��� ����, ������ ���� �� �ִµ�
						=> �غ��ϱ� move operation�� ���� �ʴ���

		��?? => move constructor, move assignment operator �� �־ 
				exception �� �߰��� �߻��ϸ� ���Ҵ��� �Ϸᰡ �ȵż� ������ �����
		
		�׷��� move operation�� noexcept �� ��������� ���� ���� �ʴٸ�
		STL Container�� move operation �� ������� �ʴ´�
	
		move constructor
		move assignment operator ����, ���ǿ� noexcept �� ���� => type�� ���Եȴ�
		���� ���͸� ���Ҵ��� �� move operation �� ����Ѵ�
	*/
	vec.emplace_back(1);
	vec.emplace_back(2);
	vec.emplace_back(3);
}

void codeFrom177_shrink() {

	std::vector<int> vInt;
	for (size_t i = 0; i < 100; i++)
		vInt.emplace_back(i);

	//size = number of elements, ���� ����ϴ� ��� ����
	std::cout << "Size : " << vInt.size() << std::endl;

	//capacity = growing ���� ���� �� �ִ� ����, ���������� �Ҵ�� �޸�
	std::cout << "Capacity : " << vInt.capacity() << std::endl;

	//element �� ������ capacity �� ���� �ʴ´�
	vInt.erase(vInt.begin(), vInt.end() - 10);
	std::cout << "Size : " << vInt.size() << std::endl;
	std::cout << "Capacity : " << vInt.capacity() << std::endl;

	
	/*
		vector :: shrink_to_fit()
		=> capacity �� size �� �°� ���Ҵ��Ѵ�
	*/
	vInt.shrink_to_fit();
	std::cout << "Size : " << vInt.size() << std::endl;
	std::cout << "Capacity : " << vInt.capacity() << std::endl;
}

void codeFrom177_data() {

	// ������ �а� ���� ��
	std::ifstream input{}; //file -> stream, input stream
	input.open(R"(./Files/177 Integer.cpp)");

	if (!input) {
		std::cout << "Could not open file" << std::endl;
		return;
	}
	
	
	/*
		std::filesystem::file_size( path )

		From C++17, filesystem �̿�, path�� �ش��ϴ� ������ ũ�⸦ �� �� �ִ�
	*/
	auto fSize = std::filesystem::file_size(R"(./Files/177 Integer.cpp)");
	

	/*
		������ char array, ���ڿ� => ���� characters �� ���� ����
		getline() => ���ڿ� �� �پ� �ִ� ����̿���
		char* buff = new char[size]{};

		char array �� ���� �����ϸ� �����ϱ�, vector �� string �� �̿��� �� �ִ�
		chars ������ vector, string �� �±�
		+ memory management �� �ñ��
		std::vector<char> buffer;
	*/
	std::string buffer{}; //C-style string �� �ƴ� std::string �� ����Ѵ�


	//string::resize() => ���� ũ�⸸ŭ container ũ�� ����
	buffer.resize(fSize); //���� ������� ������ ������� ���ڿ� �޸� �Ҵ�


	//data() => container �� underlying array �ּ� ����
	//Binary Mode���� �д� ��� ���
	//ifstream::read() => ���� �ּ�, ���� ũ�� => ���ۿ� �Է��Ѵ�
	input.read(buffer.data(), fSize);
		
	std::cout << buffer.data() << std::endl;
}

void codeFrom178() {

	//container ���� ���� ����� ����� �������̿��µ�
	//C++20 ����, sequence contatiner ���� ��� �����ϰ� ���� ���� �� �ְ� �ƴ�
	//std::erase() �̿�, ������ ��ġ�� ã�Ƽ� ���� �� �ִ�

	//Any sequence containers
	std::vector<int> vInt{ 1,2,3,4 };
	std::list<int> lst{ 1,2,3,4 };
	std::deque<int> deq{ 4,3,2,1 };


	// ������ ������� value �� ���� �� �ִ�
	std::erase(vInt, 3);
	std::erase(lst, 2);
	std::erase(deq, 1);
}

void codeFrom179() {

	// Associative Containers �� ���ؼ�
	// �ڵ����� ���ĵǱ� ������ ���� �� ��ġ�� ������ �� ����
	// ������, �������� ���� �뷫���� ��ġ�� �˷��ָ鼭 ���� �� �ִ� 
	// => ��Ʈ�� �ùٸ��� �� ������ ���� �� �ֵ�
	// + emplace �������� �ֱ�
	std::set<int> s{ 3,2,4,1 };

	s.emplace(0);
	s.emplace_hint(s.end(), 10); //10�� ���� �ǵ�, �Ƹ� s.end() ��ġ ������ �� ���̴�~


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
	name2[0] = 'Z'; //�̰Ŵ� name2 �� string �� �����ؿ� �� => �ٸ� ��ü


	//value or iterator �� �̿��ؼ� �������
	//names.erase("Omar");	value�� �̿��� ���� �ְ�
	names.erase(it);		//iterator�� �̿��� ���� �ִ�


	// �ٲ� ���� �־��־�� �Ѵ� => Copy �̿�
	names.insert(name2);


	/*
		extract() method

		C++17 �������� ���, non-copyable �� ��ü���� ���� �����ѵ�
		value or iterator �� � ��带 ã�� ����
		�ش� ��带 move -> �ٱ����� �Űܹ�����

		���� �ٱ����� ���� ��, �ٽ� �ִ� ������� �̿��� �� �ִ�
	*/
	//ã�� ��带 �ٱ��� node �� move ��Ų��
	//Ÿ���� type::node ��
	
	it = names.find("Raihaan");
	//auto node = names.extract("Raihaan");	//value �� �̿��ϰų�
	auto node = names.extract(it);			//iterator �̿�

	//���� �ٱ����� ó��
	//type::node::value() => ��� ���� ���� ����
	node.value()[0] = 'Z';

	names.insert(std::move(node)); // ���� ���� move => ���� ��ü�� �̿�
}





int main() {
	//codeFrom175();
	//codeFrom176();
	//codeFrom177_shrink();
	//codeFrom177_data();
	codeFrom179();
}