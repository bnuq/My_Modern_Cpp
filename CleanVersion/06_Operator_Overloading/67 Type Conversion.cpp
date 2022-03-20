#include <iostream>

int main() {
	int a{ 5 }, b{ 2 };
	float c = a; // implicit conversion
	// float c{ a };  uniform initializaion => implicit conversion �� ���´�
	float d = a / b; // 5/2 = 2 => 2.0
	
	// C-Style Conversion
	float f1 = (float)a / b;
	char* p1 = (char*)(&a); // ��ȿ�� �˻縦 ���� �ʴ´�

	// C++ Style Conversion => compile time �� �۵�
	// static_cast
	float f2 = static_cast<float>(a) / b;
	// char* p2 = static_cast<char*>(&a);  static_cast => ��ȿ�� �˻� ����, �ٲٱ� ���� Ȯ���Ѵ�
	
	// reinterpret_cast => C-style �� ����, ���� �ٸ� Ÿ���̿��� ��ȯ�� �����ش�
	char* p3 = reinterpret_cast<char*>(&a);
	// �ٸ��� = const, voliatile ���� qualifier �� �����Ѵ�, ������ ���Ѵ�
	const int x = 1;
	int* ip1 = (int*)(&x);
	/*
		const int* => �׳� int* �� �ٲٷ��� �õ� => �Ѵ� �Ұ��� 
		int* ip2 = static_cast<int*>(&x);
		int* ip3 = reinterpret_cast<int*>(&x);
	*/

	// const_cast => reinterpret_cast �� ����, const qualifier �� ���� ����� �����Ѵ�
	const int xx = 2;
	int* ip4 = const_cast<int*>(&xx);
	// float ip5 = const_cast<float>(xx);  ��� const ���� �� ����� ���Ѵ�

	// dynamic_cast => run time �� �۵�??
}