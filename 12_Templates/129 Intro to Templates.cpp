#include <iostream>
/*
	Old Code => Overloading �̿�
	=> ����ϰ��� �ϴ� Ÿ�Ժ��� �Լ� overloading �� ���� ����

	int Max(int x, int y) {
		return x > y ? x : y;
	}
	float Max(float x, float y) {
		return x > y ? x : y;
	}
*/

// Primary Template
// template<class T> �� ���� => ������ ���� typename �� ���
template<typename T> // ������ Ÿ�� T �� ���� ��, �Լ� ����
T Max(T x, T y) {
	std::cout << typeid(T).name() << std::endl;
	return x > y ? x : y;
}


template<typename T1, typename T2>
void Test(T1 a1, T2 a2) {
	std::cout << typeid(T1).name() << std::endl;
	std::cout << typeid(T2).name() << std::endl;
	return;
}

int main() {

	/*
		template �Լ��� arguments �� compiler �� �м�
		� Ÿ���� �־ �ش� �Լ��� ������ �ϴ� ����, compile �ܰ迡�� �м��Ѵ�
		�׸��� �ش� Ÿ���� �� �Լ��� �����
		= Instantiation
	*/
	auto num = Max(9.0f, 0.3f); // T = float type
	std::cout << num << std::endl;

	auto num2 = Max(9, 3); // T = int type
	std::cout << num2 << std::endl;


	// template argument list �� �ش� Ÿ���� ��� ����� �ϴ°�?
	// �� ���� �ʾƵ� �ȴ�, ������ �κ��� arguments ���� �˾Ƴ� �� ������ ������ �ߵȴ�
	Test(1, 2.0f);
	
	// typename T1 �� ����, T2 �� ����
	Test<int>(1, 2.0f);
	Test<float>(1, 2.0f);

	// typename T1, T2 ��� ����
	Test<int, float>(1, 2.0f);
	Test<float, float>(1, 2.0f);
}