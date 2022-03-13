#include <iostream>
#include <memory>


void SmartPointerWithLegacy()
{
	// malloc ���� �Ҵ��� �޸𸮸� ����Ʈ �����ͷ� ������ �� �ִ�
	// ������ new �� �޸� �Ҵ�
	std::unique_ptr<int> p{ (int*)malloc(4) };
	*p = 100;
	std::cout << *p << '\n';
	// smart pointer -> scope �� �����鼭 �ڵ����� �޸� ����
	// free(p);
	// ������ ����Ʈ �����ʹ� delete �� �޸� ���� => malloc �� ���� �ʴ�
}


/*
	smart pointer, scope �� ���� ����
	destructor -> invoke 'deleter'
	deleter = a callback that releases the resources
	unique_ptr, shared_ptr -> 'default deleter' = delete ���

	deleter �� ������� ������ �� �ִ� by any kind of callable
		global function
		function object
			= state �� ������ function
			= create by overloading the function call operator
		lambda expression
*/


// 1. Function Object
struct Free { // == �� structure�� deleter
	// Overload function call operator
	// underlying pointer, ���� �ϰ��� �ϴ� �����͸� argument �� �޴´�
	void operator()(int* up) {
		// malloc memory ~ free �� �����Ѵ�
		free(up);
		std::cout << "free memory by function object" << std::endl;
	}
};


// 2. Global Function
void MallocFree(int* up) { // = �Լ��� deleter
	// �����Ϸ��� �޸� �ּҸ� argument �� �޴´�
	free(up);
	std::cout << "free memory by global function" << std::endl;
}


// unique_ptr ���� deleter �����ϴ� ���
void UniquePtrDeleters()
{
	// unique_ptr -> "type"

	/* 1 */
	// �̰� ���� ���� ��õ
	// smart pointer �� deleter type, deleter object �� ��� => specify deleter
	std::unique_ptr<int, Free> p1{ (int*)malloc(sizeof(int)), Free{} };
	*p1 = 10;
	std::cout << "unique_ptr " << "Function Object = deleter " << *p1 << std::endl;


	/* 2 */
	// smart pointer �� function pointer �� function address �� ���
	// function type �� �˸��� ��
	// function pointer = return type ( * �̸� ) (arguments)
	// function pointer �� ���鼭, smart pointer �� ũ�Ⱑ �����Ѵ�?
	std::unique_ptr<int, void (*) (int*)> p2{ (int*)malloc(sizeof(int)), MallocFree };
	*p2 = 20;
	std::cout << "unique_ptr " << "Global Function = deleter " << *p2 << std::endl;
}


// shared_ptr ���� deleter �����ϴ� ���
void SharedPtrDeleters()
{
	/* 1 */
	// �̰� ���� ���� ��õ
	// smart pointer �� deleter object �� ��� => specify deleter
	std::shared_ptr<int> p1{ (int*)malloc(sizeof(int)), Free{} };
	*p1 = 10;
	std::cout << "shared_ptr " << "Function Object = deleter " << *p1 << std::endl;


	/* 2 */
	// smart pointer �� function address �� ���
	std::shared_ptr<int> p2{ (int*)malloc(sizeof(int)), MallocFree };
	*p2 = 20;
	std::cout << "shared_ptr " << "Global Function = deleter " << *p2 << std::endl;
}



int main()
{
	UniquePtrDeleters();
	SharedPtrDeleters();
}