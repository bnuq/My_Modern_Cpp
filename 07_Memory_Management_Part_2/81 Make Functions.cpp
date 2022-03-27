#include <iostream>

void num_1() {
	/*
		Modern C++ discourages manual memory management
		= Avoid using new and delete operators directly

		smart pointer �� ���� ��, heap memory �� ���� �����ؼ� ~ �޸� �ּҸ� �����;� �ϴµ�
		
		���� �������� �ʰ� �޸� �ּҸ� �Ҵ����ִ� ������ �ϴ� global function �� �ִ�
		= Make Function
		= provied for unique_ptr and shared_ptr
	*/

	// Heap �� ���� �����ϴ� ���
	std::unique_ptr<int> p1{ new int }; // new operator �� �޸𸮸� ���� �Ҵ��Ѵ�

	// Make Function ���
	// Factory Function ó�� �����Ѵ� = ��ü�� ��ȯ�ϴ� �Լ�, create an instance of a class
	/*
		make_unique = unique_ptr �� ���� ����
		<> = heap �� �Ҵ��ϰ��� �ϴ� Ÿ��, ���ҽ��� ������ �����ϰ��� �ϴ� Ÿ���� ���
		() = �ش� Ÿ�� constructor �� �ʿ��� arguments
		
		heap �� �޸𸮸� �Ҵ��ϰ�, �� �޸𸮸� ����Ű�� �����͸� �����ϴ�
		����Ʈ �����͸� ���� ����, ����Ʈ ������ ��ü�� �����Ѵ�
	*/
	auto p2 = std::make_unique<int>(9);
}


class Point {
public:
	Point(int x, int y) {
		std::cout << "Point Constructor needs two arguments" << std::endl;
	}
};


void num_2() {
	// Point Ÿ���� ����Ű�� unique_ptr �� ������
	// put arguments passed to constructor
	// Any constructor of the type can be invoked
	auto p = std::make_unique<Point>(10, 100);


	// For dynamic array with unique pointer
	// arguments �� size ����
	// �ʱ�ȭ arguments �� �� �ִ´�, cannot initialze
	auto pArr = std::make_unique<int[]>(5);
	pArr[0] = 10;
}


void num_3() {
	// shared pointer ������ �Ȱ��� ������ �� �ִ�
	auto p = std::make_shared<Point>(10, 100);


	// For dynamic array with shared pointer
	// arguments �� size ����
	// �ʱ�ȭ arguments �� �� �ִ´�, cannot initialze
	// std::make_shared for arrays was added in C++20 standard
	auto pArr = std::make_shared<int[]>(5);
	pArr[0] = 10;


	/*
		shared pointer is implemented differently than a unique pointer
		= store extra information related to the underlying pointer
		= the control block �� �߰������� ����
		
		make_shared �� ����ϸ�, underlying pointer �� ���� �޸𸮿�
		control block �� ���� �޸𸮸� ���ÿ� �Ҵ�
		= new �� �ѹ��� ����Ѵ�
		= delete �� �ѹ��� ����Ѵ�
		=> ȣ�� Ƚ���� �����Ѵ�
	*/
}


/*
	Make Function �� ����
	
	deleter �� custom �� �� ����
*/