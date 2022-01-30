#include <iostream>
#include <string>
#include "135_Assign3.h" // Template Definition Headerfile ÀÌ¿כ



int main()
{
	float fArr[]{1.1f, 3.3f, 9.9f, 2.2f, 5.5f};

	// 2.
	std::cout << ArraySum(fArr) << std::endl;

	// 3.
	std::cout << Max(fArr) << std::endl;

	// 4.
	std::pair minmax{ MinMax(fArr) };
	std::cout << minmax.first << " " << minmax.second << std::endl;


	// 4-1.
	const char* oldStrArr[]{ "kim", "dong", "hyeon", "sunday", "maple" };
	std::pair oldStrMinMax{ MinMax(oldStrArr) };
	std::cout << oldStrMinMax.first << " " << oldStrMinMax.second << std::endl;

	// 4-2.
	std::string strArr[]{ "kim", "dong", "hyeon", "sunday", "maple" };
	std::pair strMinMax{ MinMax(strArr) };
	std::cout << strMinMax.first << " " << strMinMax.second << std::endl;

}