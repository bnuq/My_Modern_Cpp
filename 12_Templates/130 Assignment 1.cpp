#include <iostream>


// 1.
template<typename T>
T Add(T x, T y) {
	return x + y;
}

// 2. 2개의 arguments 중 하나만 T 타입, 다른 하나는 무조건 int
template<typename T>
T ArraySum(T* pArr, int arrSize) {
	T sum{ 0 };
	for (int i = 0; i < arrSize; i++)
		sum += pArr[i];

	return sum;
}

// 3.
template<typename T>
T Max(T* pArr, int arrSize) {
	T max{ pArr[0] };
	for (int i = 1; i < arrSize; i++)
		if (pArr[i] > max) max = pArr[i];

	return max;
}

// 4.
template<typename T>
std::pair<T, T> MinMax(T* pArr, int arrSize) {
	T min{ pArr[0] };
	T max{ pArr[0] };

	for (int i = 1; i < arrSize; i++)
	{
		if (pArr[i] < min) min = pArr[i];
		if (pArr[i] > max) max = pArr[i];
	}

	return std::pair<T, T>{min, max};
}


int main() {
	float fArr[]{1.1f, 3.3f, 9.9f, 2.2f, 5.5f};

	std::pair<float, float> minmax{ MinMax(fArr, 5) };
	
	std::cout << minmax.first << " " << minmax.second << std::endl;

}