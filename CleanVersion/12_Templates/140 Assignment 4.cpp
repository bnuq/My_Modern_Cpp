#include <iostream>
#include <string>
#include "Integer.h"

#include <memory>



// ������ T Ÿ�� ��ü�� ���� �����ϴ� �Լ�
// Varadic Template
/*
	���� ���� typename ��, Template parameter pack �� ... ���� ǥ��
	=> pack �� Params ��� pack name ���� �޴´�

	�����ϴ� �κ��̹Ƿ�, Ÿ�԰� ... �� pack-name �տ� �´�
*/
template <typename T, typename ... Params>
/*
	Template Parameter Pack �� �����Ǵ� function parameter �� Ÿ�� pack
	=> Params ... �� ǥ��
	�ش� Ÿ�� pack �� ��Ÿ���� ���� pack => args �� ��Ÿ����
	args = function parameter pack

	�����ϴ� �κ��̹Ƿ�, Ÿ���� ��Ÿ���� Params �� ... �� pack-name �տ� �´�
*/
T* CreateObject(Params&& ... args) {
	
	/*
		return new T{args};
			�̷��� �ϸ� parameter pack �� Ȯ������ �ʾҴٰ� ���
			�׳� pack name �� �Ѱܼ��� ����� �� ����
	*/
	/*
		return new T{ args ... };
			parameter pack �� Ȯ���ϴ� ���
			����� ���� pack name �ڿ� ... �� �ٿ��� �Ѵ�
	*/
	/*
		perfect forwarding �� Ȱ���ϴ� ���
		���۷����� ����Ű�� l-value, r-value Ÿ���� �����ؼ� ���� �Լ��� �ѱ��
	*/
	/*
		�����ڿ� parameter pack �� �ѱ�� ����
		parameter pack = 0 �� �̻��� arguments �� �Ұ��ϴ�
		���� �ش� Ÿ���� ������ ��, �׷� arguments �� �޴� �����ڰ� �����ϱ⸸ �ϸ� �ȴ�
	*/
	return new T{ std::forward<Params>(args)... };
}





template <typename T, typename ... Params>
std::unique_ptr<T> CreateUniquePointer(Params&& ... args) {
	// perfect forwarding ���� T ��ü�� ������ ����
	// unique pointer �� �Ҵ��� ���ҽ��� �����ϰ�
	// unique pointer ���� => caller ���� r-value �� ����
	return std::unique_ptr<T>{ new T{ std::forward<Params>(args)... } };
}


int main() {
	/*
		������ template arguments list �� ���� �� ä�� �ʿ�� ����
		���ʿ��� ���� ä�� �� �ִ� ��ŭ ä����, ������ �κ��� arguments �� ���ؼ� deduction �س� �� �ִ�
		���ʿ� parameter pack �� ����Ʈ�� �����ؼ� ���� ���� ����

		������ �ش� ���ø� �Լ� function arguments �� function arguments pack �� �޴´�
		����, arguments ���� typename T �� ������ �� ���� ����
		
		�׷��Ƿ� template arguments list �� typename T �� �ݵ�� ��ø� ���־�� �Ѵ�
		
		�ν��� T Ÿ���� ��ü�� ����
	*/
	//int* p1 = CreateObject(5);  typename T �� ������ �� ����� ����
	int* p1 = CreateObject<int>(5);
	std::cout << *p1 << std::endl;
	
	// �ٸ� ��ü�� ���ؼ��� �� ����
	std::string* p2 = CreateObject<std::string>();
	Integer* p3 = CreateObject<Integer>(45);


	delete p1;
	delete p2;
	delete p3;


	// unique pointer ��, new int => unique_ptr �� �ڵ� ��ȯ�� �ȵȴ�
	//std::unique_ptr<int> pp = new int{ 10 };

	// unique pointer �� copy �� �Ұ���, ������ move operation �� �����ϴ�
	std::unique_ptr<int> pp = std::unique_ptr<int>{ new int{10} };

	// r-value unique pointer �� �����ϱ� ������, move ctor �� unique pointer ����
	std::unique_ptr<Integer> up4 = CreateUniquePointer<Integer>(50);

	// Copy �� �Ұ���
	//std::unique_ptr<Integer> up5 = up4;

	std::cout << *up4 << std::endl;
}