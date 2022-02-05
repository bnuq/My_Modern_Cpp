/*
* Function Object as a Callback
* function object
* = object override function call operator
* 
* ����
* 1. ���ǵ� ��ü�� function call operator ���� => ������ ȣ��Ǵ� ���� �ȴ�? compile time �� optimization ����
* 2. invocation ���̿��� state �� ������ �� �ִ� => ��ü �� ���� ����
* 
* function pointer ���ٴ� function object ��� ����
* 
* function pointer �� compiler �� � �Լ��� ȣ���ϴ� ���� �˼��� ���� => �ּҸ� ������ �־� => ���߿� �ּҸ� ���� ȣ��, inlining �� �Ұ����ϴ�?
*	specified by runtime
*/
#include <iostream>
//using Comparator = bool(*)(int, int);
// Compatator �� template type arguement �� �޾ => function pointer, function object �� �� ���� �� �ִ�
template<typename T, int size, typename Comparator>
//void Sort(T(&arr)[size], Comparator&& comp) {
void Sort(T(&arr)[size], Comparator comp) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - 1; ++j) {
			// function pointer �� �޾Ƶ�
			// function object �� �޾Ƶ� 
			// ȣ�� ����� �����ϴ�
			if (comp(arr[j], arr[j + 1])) {
				T temp = std::move(arr[j]);
				arr[j] = std::move(arr[j + 1]);
				arr[j + 1] = std::move(temp);
			}
		}
	}
}
//Function pointers as comparators
bool funcCompInc(int x, int y) {
	return x > y;
}
bool funcCompDec(int x, int y) {
	return x < y;
}


//Function Object as comparator
// �Ϲ����� Uder defined data type �ε�
struct objCompInc {
	// functino call operator �� �����Ѵ�
	bool operator()(int x, int y) {
		return x > y;
	}
};
int main() {

	// function call
	funcCompInc(3, 5);

	// Make an object
	objCompInc comp;

	// function object �� �����ڸ� ���
	comp(3, 5);//comp.operator()(3,5) ;


	int arr[]{ 1,6,8,4,0 };
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	// callback by function object 
	//Sort(arr, comp);
	Sort(arr, funcCompDec);

	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	return 0;
}