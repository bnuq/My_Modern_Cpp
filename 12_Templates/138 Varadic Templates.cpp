#include <iostream>
#include <initializer_list>
#include "Integer.h"

/*
	���ø� �Լ� argument �� std::initializer_list �� �޴� ���
	= Works only for homogenous data types
	initializer_list �� ���, �������� ������ ������ ��� ��ҵ��� Ÿ���� ���ƾ� �Ѵ�
*/
template<typename T>
void Print(std::initializer_list<T> args) {
	for (const auto &x : args) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}




// Base Case Function
// Zero argument
// Stop the recursion
void Print(){
	std::cout << " | Base Case" << std::endl;
}


// A template with atleast one parameter pack = Variadic Template
// ���� ���� ���ø�
/*
	���� ���ø� �Լ��� template parameter ����
	typename... Params �� ���� template parameter
	= Template Parameter Pack �̶�� �Ѵ�
	= Accepts zero or more template arguments

	typaname... �� �� ��Ʈ + �װ͵��� ����Ű�� �̸� = Params
		... = ellipses
		�������� type ���� ���ø��� ���̰� �ǰ�, �� typename ���� �Ѳ����� Params �� ����Ų��
		Params = pack-name �̶�� �Ѵ�
		pack ��ü�� ���� �̸�
		�����ϴ� �κ��̴ϱ� ... �� pack-name �տ� �´�
 
	Params �� ����Ű�� ������ ��ҿ� ���� �����ϴ� ���� �Ұ���
	=> recursion �̿�
*/
template<typename T, typename... Params>
/*
	���ø� �Լ��� function parameter ����
	Param... args �� ���� function parameter
	= Function Parameter Pack
	= Accepts zero or more function arguments

	Params... + args
		���� typenames �� typename pack �� Params �� ���ؼ�
		�� Ÿ���� ������ ������ pack �� args �� ����Ų��
		�����ϴ� �κ��̴ϱ� ... �� pack-name �տ� �´�

	���⼭�� l-value, r-vlaue ��� �� Ÿ�Կ� �´� reference �� ����Ű�� ����
	r-value reference �� ����ߴ�
*/
void Print(T &&a, Params&&... args) {

	// ù��°�� ������, ������ parameter pack �� ����ִ� ��ҵ��� ������
	// ���ϴ� ��� => sizeof... �����ڸ� ��� => pack �� ����ִ� ������ ����
	/*
		std::cout << sizeof...(args) << std::endl;
		std::cout << sizeof...(Params) << std::endl;
	*/
	std::cout << a;

	if (sizeof...(args) != 0) {
		std::cout << ",";
	}

	//We can forward a function parameter pack
	// Perfect Forwarding, �� Ÿ�Կ� �°� Copy, Move �� ����ϵ��� �Ѵ�
	// ���⼭�� ... ������ �ݴ�
	// parameter pack �� �ٽ� �ٸ� �Լ� argument �� �ѱ� ����
	// ... �� pack-name �ڿ� �´�, ȣ���� ���ϱ�?
	Print(std::forward<Params>(args)...);

	// Recursion, ��� ȣ��
	// parameter pack �� ����ִ� �͵��� �տ�������, �ϳ��� ó���Ѵ�
}



int main() {
	
	// std::initializer_list<T> �� argument �� �Ѱܼ� ���ø� �Լ��� �̿��ϴ� ���
	// Print{ 1, 2, 3, 4 };  �̷��� ���� Print ��ü �����ڸ� ȣ���ϴ� Uniform Initialization ���
	Print({ 1, 2, 3, 4 }); // ��ȣ �ȿ� { } �߰�ȣ�� ��� �����Ѵ�
	// Print({ 1, 2.5, 3, 4 });  �߰��� Ÿ���� �ٸ� ���� �ϳ��� ���� �μ� ������ { ... } Ÿ������ �ν��Ѵ�
	
	
	// �Լ� ȣ�⿡ �ʿ��� arguments �� �׳� �ƹ� Ÿ�Ե���
	// ���� ���� ���� �ִ´� => �̰� ��ü�� parameter pack
	Print(1, 2.5, 3, "4");


	Integer val{ 1 };
	// int, l-value, r-value
	// User Defined Type �� ���� ���� �ִ�
	Print(0, val, Integer{ 2 });


	return 0;
}

/*
* Recursively �ϰ� ó��
* ���� �տ� �ִ� arguments ���� �ϳ��� ó��
1. Print(1, 2.5, 3, "4") ;
2. Print(2.5, 3, "4") ;
3. Print(3, "4") ;
4. Print("4") ;
5. Print() ;
*/
