#include <iostream>


// �迭�� �� ���ҿ�, operation �� �����ϴ� ���ø� �Լ�
template<typename T, int size, typename Callback>
void ForEach(T(&arr)[size], Callback operation) {
	for (int i = 0; i < size - 1; ++i) {
		operation(arr[i]);
	}
}


int main() {
	
	int arr[]{ 1,6,8,4,0 };	

	/*
		Capture List Modes
		
		Capture List ���� ������ ĸó�� ��, �������� ������ �� �� �ִ�
	*/

	/*
		Caputure variable by reference
			�ٱ��� ������ ���۷����� �����´�
			���� �����ϸ� �ٱ��� ������ ����
			��� ������ ���ϴ� ���� �ƴϱ� ������, mutable �� ��� ���� �����ϴ�
	*/
	int sum{ 0 };
	ForEach(arr, [&sum](auto& x) {
		sum += x;
		});
	std::cout << "Sum is " << sum << std::endl;


	/*
		Capture all variables by reference
			�տ� �����ϴ� ��� ������ capture by reference
			���� ������ ������ �ʿ� ����
	*/
	sum = 0;
	ForEach(arr, [&](auto& x) {
		sum += x;
		});
	std::cout << "Sum is " << sum << std::endl;


	/*
		Capture all variables by value
			�տ� �����ϴ� ��� ������ capture by value
			Function Object �ȿ� ��������� ����� => mutable ���� ������ ���� �Ұ���
			�ٱ��� ���� ������ ������� �ʴ´�
	*/
	sum = 0;
	ForEach(arr, [=](auto& x) mutable {
		sum += x;
		});
	std::cout << "Sum is " << sum << std::endl;



	/*
		Ư�� ������ �ٸ��� �ް�, ������ �������� �� �ٸ��� �ޱ�
		[=, &sum]
			�� value �� �޴µ�, sum �� reference
		[&, sum]
			�� reference �� �޴µ�, sum �� value
	*/
	int sum1 = 0;
	int sum2 = 0;
	ForEach(arr, [&, sum1](auto &x) mutable { // sum1 �� value �� ����
		sum1 += x;
		sum2 += x;
	});
	std::cout << "Sum1 is " << sum1 << std::endl;
	std::cout << "Sum2 is " << sum2 << std::endl;



	return 0;
}

