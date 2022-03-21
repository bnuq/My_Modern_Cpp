/*
	Function Pointer Callback ����
		1. �ּҸ� ���ؼ� ȣ�� => compiler �� ���� ����ȭ�� �ȵȴ�, inline ���� ó���� �� ����
			compile time �� �̸� ����� ������

		2. state �� ������ �� ���� => function �� global range �� �ִ�, �� �Լ� ȣ�� �� ������ ������ �� ����
*/

#include <iostream>

// Function Pointer �� Type Alias �� ǥ��
// bool type �� ����ϴ� �Լ� = Predicate �� �Ѵ�
using Comparator = bool(*)(int, int);


// Bubble Sort �帧
// size-1 ������ ���ƾ� �Ѵ� => j+1 ���� ���縦 �ϴϱ�
// ��Һ��ϴ� �Լ���, �����ͷ� �޴´�
// callback �� function pointer �� ����
template<typename T, int size>
void Sort(T(&arr)[size], Comparator comp) {
	for (int i = 0; i < size-1; i++) {
		for (int j = 0; j < size-1; j++) {

			// Comparator �� ���ؼ� ���� ������ ��� = ������ �ʴ� ����
			// ������ �ٲ������
			if (comp(arr[j], arr[j + 1])) {
				/*
					swap ����
					User Defined Data Type �� ���ؼ�
					���ʿ��� ���縦 ���� ����, std::move() �� ����Ѵ�
				*/
				T temp = std::move(arr[j]);
				arr[j] = std::move(arr[j + 1]);
				arr[j + 1] = std::move(temp);
			}
		}
			
	}
		
}


// int type �񱳸� �ϴ� �Լ�
bool intIncComp(int x, int y) { // ��������
	return x > y;
}
bool intDecComp(int x, int y) { // ��������
	return x < y;
}


int main() {
	int arr[]{ 2,3,5,9,7,1 };

	for (auto x : arr)
		std::cout << x << " ";
	std::cout << std::endl;

	
	// �Լ� �̸� => function pointer �� ���� �� ����
	Sort(arr, intIncComp);
	// Sort(arr, intDecComp);

	for (auto x : arr)
		std::cout << x << " ";
	std::cout << std::endl;
}