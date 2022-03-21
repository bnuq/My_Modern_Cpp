#include "135 funcs.h"
#include <string>

/*
	템플릿 함수를 만드는 데 필요한 모든 정의는 헤더파일에 이미 존재

	여기서는 Explicit Specialization Definition 만 추가로 적는다
		4 번째 함수에 대해서만 specializaion 을 구현하자
		Specilalization 에서는 모든 template argument 의 값을 적어주어야 한다
		그래서 array type 에 대해서도 타입과 사이즈 모두 명시해야 한다
*/
// Specialize for an array of strings (const char *)
template<>
std::pair<const char*, const char*> MinMax<const char*>(const char* (&ref)[5]) {
	const char* min{ ref[0] };
	const char* max{ ref[0] };
	int arrSize = 5;

	for (int i = 0; i < arrSize; i++)
	{
		if (strcmp(min, ref[i]) > 0) min = ref[i];
		if (strcmp(ref[i], max) > 0) max = ref[i];
	}

	return std::pair<const char*, const char*>{min, max};
}

// Specialize for strings
template<>
std::pair<std::string, std::string> MinMax<std::string>(std::string(&ref)[5]) {
	std::string min{ ref[0] };
	std::string max{ ref[0] };
	int arrSize = 5;

	// string 은 operator overloading
	for (int i = 1; i < arrSize; i++)
	{
		if (ref[i] < min) min = ref[i];
		if (ref[i] > max) max = ref[i];
	}

	return std::pair<std::string, std::string>{min, max};
}