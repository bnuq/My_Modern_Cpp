/*
* Function Pointer Callback 단점
* 1. 주소를 통해서 호출 => compiler 에 의해 최적화가 안된다, inline 으로 처리할 수 없다?
* 2. state 를 저장할 수 없다 => function 은 global ragne 에 있다, 각 함수 호출 내 변수를 저장할 수 없다?
*/

#include <iostream>

// Function Pointer 를 Type Alias 로 표현
using Comparator = bool(*)(int, int);

// Bubble Sort 흐름
// size-1 까지만 돌아야 한다 => j+1 까지 조사를 하니까
// 대소비교하는 함수를, 포인터로 받는다
// callback 을 function pointer 로 구현
template<typename T, int size>
void Sort(T(&arr)[size], Comparator comp)
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size-1; j++)
		{
			// arr[j] > arr[j+1] 일 때 참을 리턴
			if (comp(arr[j], arr[j + 1]))
			{
				/*
				* User Defined Data Type 에 대해서
				* 불필요한 복사를 막기 위해,
				* std::move 를 사용한다
				*/
				T temp = std::move(arr[j]);
				arr[j] = std::move(arr[j + 1]);
				arr[j + 1] = std::move(temp);
			}
		}
			
	}
		
}

// int type 비교를 하는 함수
// bool type 을 출력하는 함수 = Predicate 라 한다
bool intIncComp(int x, int y)
{
	return x > y;
}

bool intDecComp(int x, int y)
{
	return x < y;
}


int main()
{
	int arr[]{ 2,3,5,9,7,1 };

	for (auto x : arr)
		std::cout << x << " ";
	std::cout << std::endl;

	
	// 함수 이름 => function pointer 로 받을 수 있음
	//Sort(arr, intIncComp);
	Sort(arr, intDecComp);

	for (auto x : arr)
		std::cout << x << " ";
	std::cout << std::endl;
}