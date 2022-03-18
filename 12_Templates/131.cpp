#include <iostream>

//Primary Template
template<typename T>
T Max(T x, T y) {
	std::cout << typeid(T).name() << std::endl;
	return x > y ? x : y;
}

//Explicit Instantiation
//template �� ���� template argument list �� ���� �ʴ´�

// char Ÿ���� Max �Լ��� ���� ����� �����Ѵ�
// ȣ������ �ʾƵ� ���������
template char Max(char x, char y);

//Explicit Specialization
//template + empty template argument list
// �� Ÿ�Կ� ���ؼ� ������
//template<> const char* Max(const char* x, const char* y) { Ÿ�� ���ô� �ɼ�
template<> const char* Max<const char*>(const char* x, const char* y) {
	std::cout << "Max<const char*>()" << std::endl;
	return strcmp(x, y) > 0 ? x : y;
}

int main()
{
	// T type �� �ϳ�, �����ֱ�
	Max(static_cast<float>(3), 6.3f);

	// ��������� Ÿ�� �����ϱ� => �ڵ����� Ÿ�Ժ�ȯ
	Max<double>(3, 5.3f);

	// function template address ��� => instantiation
	// function pointer �̿�
	int (*pfn)(int, int) = Max;

	const char* a{ "A" };
	const char* b{ "B" };
	std::cout << Max(a, b) << std::endl;

	return 0;
}
