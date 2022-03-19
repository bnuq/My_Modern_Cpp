#pragma once
#include <utility>
#include <string>

// Primary Template Definition
// 템플릿 함수 => 컴파일러에 의해 함수가 만들어져야 하므로
// 만드는 데 필요한 정의가 헤더 파일에 존재해야 한다


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

	템플릿 함수가 특정 타입을 받을 때, 재정의하는 경우
	
	우선 기본 템플릿 함수 정의로 만든 다음에 = Instantiation
	재정의된 코드로 다시 만든다 => 재조립
		Linker 에 의해 재정의 코드가 합쳐짐

	따라서 헤더파일에는, 재정의 될 것이라는 정보만 알려주고 = Declaration
	재정의 내용은 cpp file 에서 정의한다 = Implementation
		그래야 헤더 파일 내에 정의가 2개 존재하지 않게 된다
*/
template<>
std::pair<const char*, const char*> MinMax<const char*>(const char* (&ref)[5]);

template<>
std::pair<std::string, std::string> MinMax<std::string>(std::string(&ref)[5]);