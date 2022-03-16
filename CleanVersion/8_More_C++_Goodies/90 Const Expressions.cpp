#include <iostream>
/*
	Constant expression function rules

	1. Should accept and return literal types only
	 (void, scalar types(int, float, char), references, etc....)
	 + constexpr ctor �� ������ class

	2. Should contain only single line statement that should be a return statement
	�� C++14 �̻� ���� �׸��̾�

	3. constexpr functions are implicitly inline
	������Ͽ� �����ؾ� �Ѵ� => ��Ŀ�� ó���ϱ� ����, �����Ϸ��� �Լ����Ǹ� �˾ƾ� inlining �� �����ϹǷ�
	+ One Definition Rule ������
*/
// literal types ���� �ް�, �����ϴ� �Լ� => ������ �ð��� ��� ���� => constexpr ����
// ������ ��� ���� �����ϴϱ�, constexpr -> ������ �� ����ϵ��� �Ѵ�
constexpr int GetNumber() {
	return 42;
}
constexpr int Add(int x, int y) {
	return x + y;
}
constexpr int Max(int x, int y) {
	//Needs C++14 compiler
	if (x > y)
		return x;
	return y;
	//return x > y ? x : y;
}
int main() {
	//Behaves as a constexpr function
	/*
		constexpr = const expression
		���� i �� �ݵ�� ��� ���� �����ٴ� ���� Ȯ�����´�
		�׻� compile time �� ���ȴ�

		constexpr variable �� constexpr �θ� �ʱ�ȭ�� �����ϴ�
	*/
	constexpr int i = GetNumber();
	int arr[i]; // i �� compile time �� ���Ǳ� ������, �迭 ũ��� ����� �� �ִ�


	//Behaves as a constexpr function
	// const �� ���, ��������� ���� run time �� ���Ǵ� ��쵵 �ִ�
	const int j = GetNumber();
	int arr1[j]; // GetNumber() == constexpr => compile time �� return �ϱ� ������, j �� �迭 ũ��� �� �� �־���

	//Behaves as a normal function => runtime �� �����Ѵ�
	int x = GetNumber();

	//Error x is not constexpr
	//constexpr int sum = Add(x, 5);

	//Behaves as a normal function. 
	int sum2 = Add(3, 5);

	return 0;
}
