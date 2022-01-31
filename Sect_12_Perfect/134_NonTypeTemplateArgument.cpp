#include <iostream>

//Non-type template parameter
// constant ���
template<int size>
void Print() {
	char buffer[size]; // constant ó�� ��� ����
	std::cout << size << std::endl;
}

//Size is implicitly calculated in non-type template argument
// array �� ����Ű�� reference ���� size ������ �̹� ����ִٴ� �� �̿�
// size = Template argument �ε� type �� �ƴϴ� - = non-type
template<typename T, int size>
T Sum(T(&arr)[size]) { // �迭�� reference �� �޴´ٴ� ��
	T sum{};
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum;
}

int main()
{
	Print<3>();
	int i{ 3 };
	// Print<i>();

	int arr[]{ 3,1,9,7 };
	int sum = Sum(arr); // �迭 �̸� = reference = �迭 ũ�⿡ ���� ������ ����ִ�
	std::cout << sum << std::endl;

	int(&ref)[4] = arr; // �迭�� ����Ű�� reference
	//int (&ref)[5] = arr ; ����Ű�� �迭 ũ�Ⱑ �޶� �Ұ���
	std::cout << Sum(ref) << std::endl;

	return 0;
}