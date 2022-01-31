#include "135_Assign3.h"
#include <string>

// Explicit Specialization Definition

// 4 case 에 대해서만 specializaion 을 구현하자
// Specialize for an array of strings (const char *)
// Specilalization 에서는 모든 template argument 의 값을 적어주어야 한다
// 그래서 T, arrSize 모두 직접 적어주어야 한다 => 그래서 iterator 를 쓴다?
template<>
std::pair<const char*, const char*> MinMax<const char*>(const char* (&ref)[5])
{
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
std::pair<std::string, std::string> MinMax<std::string>(std::string(&ref)[5])
{
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