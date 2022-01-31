#include <iostream>
#include "138_Integer.h"

//std::initializer_list 사용
//= Works only for homogenous data types
//template<typename T>
//void Print(std::initializer_list<T> args) {
//	for (const auto &x : args) {
//		std::cout << x << " ";
//	}
//}


// Base Case Function
// Zero argument
// Stop the recursion
void Print(){
	std::cout << " | Base Case" << std::endl;
}

//Template parameter pack
// ... = ellipses
// ...Params arguments 각각에 접근하는 것은 불가능 => recursion 이용
template<typename T, typename...Params>
//Function parameter pack
// r-value reference argument => Reference collapsing rule 이용
void Print(T &&a, Params&&... args) {

	// 첫번째를 제외한, 나머지 template parameter pack 의 개수를 구하는 방법, 동일한 결과
	//std::cout << sizeof...(args) << std::endl;
	//std::cout << sizeof...(Params) << std::endl;
	std::cout << a;

	if (sizeof...(args) != 0) {
		std::cout << ",";
	}

	//We can forward a function parameter pack
	// Perfect Forwarding, 불필요한 복사를 막는다
	// 여기서는 ... 순서가 반대
	Print(std::forward<Params>(args)...);
}


int main() {

	/*
	* Used std::initializer_list<T>
	Print({ 1,2.5,3,4 });
	*/
	Print(1, 2.5, 3, "4");
	
	Integer val{ 1 };
	// int, l-value, r-value
	Print(0, val, Integer{ 2 });


	return 0;
}

/*
* Recursively 하게 처리
1. Print(1, 2.5, 3, "4") ;
2. Print(2.5, 3, "4") ;
3. Print(3, "4") ;
4. Print("4") ;
5. Print() ;
*/
