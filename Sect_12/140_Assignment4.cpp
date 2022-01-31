#include <iostream>
#include <string>
#include "138_Integer.h"

//template <typename T>
//T* CreateObject<T>()
//{
//	return
//}


template <typename T, typename ... Params>
// function template ���ǿ��� <> �� Ÿ���� ����Ϸ���
// ����ϴ� ��� template argument �� ����ؾ� �Ѵ�
T* CreateObject(Params&& ... args)
{
	//return new T{args}; => �̷��� �ϸ� parameter pack �� Ȯ������ �ʾҴٰ� ���
	//return new T{ args ... }; => parameter pack �� Ȯ���ϴ� ���
	return new T{ std::forward<Params>(args)... }; // perfect forwarding �� Ȱ���ϴ� ���
	// parameter pack ���� ���� �ʱ�ȭ�� �����ϴ�! => �̰� �˷������
	// parameter pack �� ����־ ����
}


int main()
{
	// ���������� �����ϴ� Ÿ����, ������� ���� ����
	// �� �ܴ� �ڵ����� �ν�
	// �׷��� ���ϴ� ��ŭ�� Ÿ�Ը� ���� ��ȣ�� ���� �� �ִ�
	int* p1 = CreateObject<int>(5);
	std::cout << *p1 << std::endl;
	

	std::string* p2 = CreateObject<std::string>();
	Integer* p3 = CreateObject<Integer>(45);


	delete p1;
	delete p2;
	delete p3;
}