#include <iostream>

//Non-type template parameter
// constant 취급
template<int size>
void Print() {
	char buffer[size]; // constant 처럼 사용 가능
	std::cout << size << std::endl;
}

//Size is implicitly calculated in non-type template argument
// array 를 가리키는 reference 에는 size 정보가 이미 들어있다는 걸 이용
// size = Template argument 인데 type 이 아니다 - = non-type
template<typename T, int size>
T Sum(T(&arr)[size]) { // 배열의 reference 를 받는다는 뜻
	T sum{};
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum;
}

int main()
{
	Print<3>();
	int i{ 3 };
	// Print<i>();

	int arr[]{ 3,1,9,7 };
	int sum = Sum(arr); // 배열 이름 = reference = 배열 크기에 대한 정보가 들어있다
	std::cout << sum << std::endl;

	int(&ref)[4] = arr; // 배열을 가리키는 reference
	//int (&ref)[5] = arr ; 가리키는 배열 크기가 달라서 불가능
	std::cout << Sum(ref) << std::endl;

	return 0;
}