#pragma once
#include <utility>
#include <string>

// Primary Template Definition
// ���ø� �Լ� => �����Ϸ��� ���� �Լ��� ��������� �ϹǷ�
// ����� �� �ʿ��� ���ǰ� ��� ���Ͽ� �����ؾ� �Ѵ�


// 1.
template<typename T>
T Add(T x, T y) {
	return x + y;
}

// 2. => Accept array by reference
template<typename T, int arrSize>
T ArraySum(T(&arrRef)[arrSize]) {
	T sum{ 0 };
	for (int i = 0; i < arrSize; i++)
		sum += arrRef[i];

	return sum;
}

// 3. => Accept array by reference
template<typename T, int arrSize>
T Max(T(&arrRef)[arrSize]) {
	T max{ arrRef[0] };
	for (int i = 1; i < arrSize; i++)
		if (arrRef[i] > max) max = arrRef[i];

	return max;
}

// 4. => Accept array by reference
template<typename T, int arrSize>
std::pair<T, T> MinMax(T(&arrRef)[arrSize]) {
	T min{ arrRef[0] };
	T max{ arrRef[0] };

	for (int i = 1; i < arrSize; i++)
	{
		if (arrRef[i] < min) min = arrRef[i];
		if (arrRef[i] > max) max = arrRef[i];
	}

	return std::pair<T, T>{min, max};
}


/*
	Explicit Specialization

	���ø� �Լ��� Ư�� Ÿ���� ���� ��, �������ϴ� ���
	
	�켱 �⺻ ���ø� �Լ� ���Ƿ� ���� ������ = Instantiation
	�����ǵ� �ڵ�� �ٽ� ����� => ������
		Linker �� ���� ������ �ڵ尡 ������

	���� ������Ͽ���, ������ �� ���̶�� ������ �˷��ְ� = Declaration
	������ ������ cpp file ���� �����Ѵ� = Implementation
		�׷��� ��� ���� ���� ���ǰ� 2�� �������� �ʰ� �ȴ�
*/
template<>
std::pair<const char*, const char*> MinMax<const char*>(const char* (&ref)[5]);

template<>
std::pair<std::string, std::string> MinMax<std::string>(std::string(&ref)[5]);