#include <iostream>

// Old Code
// Overloading
//int Max(int x, int y) {
//	return x > y ? x : y;
//}
//float Max(float x, float y) {
//	return x > y ? x : y;
//}

//Primary Template
//template<class T> �� ����
template<typename T>
T Max(T x, T y) {
	std::cout << typeid(T).name() << std::endl;
	return x > y ? x : y;
}

int main()
{
	// instantiation
	// � Ÿ���� �Լ��� �ʿ�� �ϸ�, �����Ϸ��� �Լ��� �����
	// argument �� ���ؼ� Ÿ�� �߷�
	auto num = Max(9.0f, 0.3f);
	std::cout << num << std::endl;

	auto num2 = Max(9, 3);
	std::cout << num2 << std::endl;


}