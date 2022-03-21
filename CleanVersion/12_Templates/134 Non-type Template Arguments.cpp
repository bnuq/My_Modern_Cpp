#include <iostream>

/*
	Non-type template parameter
	
	Template Arguments list �� ���ԵǴµ�
	typename �� �ƴ� arguments

	arguments �� ���ؼ� deduction �Ǵ� ����� �ƴϴ�
	�ݵ�� ���ø� �Լ��� ȣ���� ��, template argument list �� ���ؼ� ���� �Ѱ� ����

	constant ����Ѵ�
*/
template<int size> // non-type template parameter
void Print() {
	char buffer[size]{}; // constant ó�� ��� ����
	std::cout << size << std::endl;
}

/*
	�̷� ������ non-type template parameter ��
	�Ϲ� argument �� �޴� ���� �Ұ���

	template<int size>
	void Print2(const int size) {
		std::cout << size << std::endl;
	}
*/



/*
	array type �� argument �� �޴� ���
	
	array type reference ���� size ������ �̹� ����ִٴ� �� �̿�
		�迭�� ������ ������ �̹� Ÿ�Կ� ���ԵǾ� �ִ�

	Size is implicitly calculated in non-type template argument
	array type reference �� argument �� ���� ��, Ÿ�� �ȿ� �̹� ����� ����־�
	template argument list �� �ѱ��� �ʾƵ�, ��� ���� �Ѿ�´�
*/
template<typename T, int size>
T Sum(T(&arr)[size]) { // �迭�� reference �� �޴´ٴ� ��
	T sum{};
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum;
}

int main() {

	// non-type template argument �� 3 �� list �� ���� �ѱ��
	Print<3>();
	// Print2<10>(10); �ȵȴ�, �Ұ���

	int i{ 3 };
	// Print<i>();  constant �� �ƴ� ������ non-type template argument �� �ѱ� �� ����

	
	// �迭 �̸� => array type
	int arr[]{ 3,1,9,7 };
	// �迭 �ּ� ���� ������ �־, ���� �����ͷ� �޴´�
	int* pInt = arr;

	
	// ������ �迭 �̸��� ������ �� ���� �ƴϴ�, �迭 �̸� = array type
	int sum = Sum(arr); // array type = �迭 ũ�⿡ ���� ������ ����ִ�
	//std::cout << sum << std::endl;

	// array type reference �� �ڼ��ϰ� ��Ÿ�� ��
	int(&ref)[4] = arr;
	//int (&ref)[5] = arr ; ����Ű�� �迭 ũ�Ⱑ �޶� �Ұ���
	//std::cout << Sum(ref) << std::endl;


	// ���� ���� template argument list �� ����ϴ� ���
	// typename �� �����־�� �ϰ�
	// non-type template argument �� �ڵ����� �ľǵǱ� ������ �ѱ��� �ʾƵ� �ȴ�
	std::cout << Sum<int>(arr) << std::endl;
	std::cout << Sum<int, 4>(arr) << std::endl;
	// std::cout << Sum<int, 5>(arr) << std::endl; array type �� ���� �ʴ� arguments �� �ȵȴ�

	return 0;
}