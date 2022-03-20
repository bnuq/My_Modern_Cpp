#include <iostream>
/*
	Constant expression function rules

	1. Should accept and return literal types only
	 (void, scalar types(int, float, char), references, etc....)
	 + constexpr ctor 를 가지는 class

	2. Should contain only single line statement that should be a return statement
	응 C++14 이상 쓰면 그만이야

	3. constexpr functions are implicitly inline
	헤더파일에 정의해야 한다 => 링커가 처리하기 전에, 컴파일러가 함수정의를 알아야 inlining 이 가능하므로
	+ One Definition Rule 때문에
*/
// literal types 만을 받고, 리턴하는 함수 => 컴파일 시간에 계산 가능 => constexpr 가능
// 어차피 상수 값을 리턴하니까, constexpr -> 컴파일 때 계산하도록 한다
constexpr int GetNumber() {
	return 42;
}
constexpr int Add(int x, int y) {
	return x + y;
}
constexpr int Max(int x, int y) {
	//Needs C++14 compiler
	if (x > y)
		return x;
	return y;
	//return x > y ? x : y;
}
int main() {
	//Behaves as a constexpr function
	/*
		constexpr = const expression
		변수 i 가 반드시 상수 값을 가진다는 것을 확정짓는다
		항상 compile time 에 계산된다

		constexpr variable 은 constexpr 로만 초기화가 가능하다
	*/
	constexpr int i = GetNumber();
	int arr[i]; // i 가 compile time 에 계산되기 때문에, 배열 크기로 사용할 수 있다


	//Behaves as a constexpr function
	// const 의 경우, 비슷하지만 종종 run time 에 계산되는 경우도 있다
	const int j = GetNumber();
	int arr1[j]; // GetNumber() == constexpr => compile time 에 return 하기 때문에, j 를 배열 크기로 쓸 수 있었다

	//Behaves as a normal function => runtime 에 실행한다
	int x = GetNumber();

	//Error x is not constexpr
	//constexpr int sum = Add(x, 5);

	//Behaves as a normal function. 
	int sum2 = Add(3, 5);

	return 0;
}
