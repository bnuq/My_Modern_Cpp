#include <iostream>
#include <memory>


void num_1()
{
	/*
		dynamic array �� smart pointer �� �����ϴ� ���
		������ ������� �� �� ����
			delete[] �� ȣ���ؾ� �ϴµ� delete ȣ��
			subscript, [] ������ ��� �Ұ���
	*/
	// ���� ��� ��� -> delete[] �� ȣ���ϴ� deleter �� �߰��ؾ� �Ѵ�
	std::unique_ptr<int> p1{ new int[5]{1,2,3,4,5} };
	// p1[0] = 10; [] compile error
	// �̷� ������ �����ϸ� �ǳ�, �����ϴ�
	p1.get()[0] = 10;
}

void num_2()
{
	using namespace std;
	/*
		�׷��� partial specialization �� �̿�?
		empty subscript, [] �� Ÿ�Կ� �߰�
			-> cause the compiler to choose another class of smart pointer
			that provides the subscript operator
			=> can access the array elements
	*/
	// unique_ptr �� Ÿ���� int[] �� ����
	// �̷��� ���⸸ �ص�, delete[] ȣ���ϴ� deleter �� �ڵ� �����ȴ�
	std::unique_ptr<int[]> p1{new int[5]{1,2,3,4,5}};
	// [] �� ���ؼ� ��ҿ� ���� ����
	p1[0] = 10;
	cout << p1[0] << endl;
	
	// shared_ptr version �� C++17 ���� �߰�
	std::shared_ptr<int[]> p2{ new int[5]{1,2,3,4,5} };
	p2[0] = 20;
	cout << p2[0] << endl;
}

/*
	�׷��� ��� dynamic array �� ���� ���� ���� �ʴ�
	grow at runtime -> STL �� �ִ� container �� �������
						= �ڵ����� �޸� ������ �ȴ�

*/