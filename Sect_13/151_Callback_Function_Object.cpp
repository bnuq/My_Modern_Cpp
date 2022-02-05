/*
* Function Object as a Callback
* function object
* = object override function call operator
* 
* 장점
* 1. 정의된 객체에 function call operator 적용 => 무엇이 호출되는 지를 안다? compile time 에 optimization 가능
* 2. invocation 사이에서 state 를 저장할 수 있다 => 객체 내 정보 저장
* 
* function pointer 보다는 function object 사용 권장
* 
* function pointer 는 compiler 가 어떤 함수를 호출하는 건지 알수가 없다 => 주소만 가지고 있어 => 나중에 주소를 통해 호출, inlining 이 불가능하다?
*	specified by runtime
*/
#include <iostream>
//using Comparator = bool(*)(int, int);
// Compatator 를 template type arguement 로 받어서 => function pointer, function object 둘 다 받을 수 있다
template<typename T, int size, typename Comparator>
//void Sort(T(&arr)[size], Comparator&& comp) {
void Sort(T(&arr)[size], Comparator comp) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - 1; ++j) {
			// function pointer 를 받아도
			// function object 를 받아도 
			// 호출 방식이 동일하다
			if (comp(arr[j], arr[j + 1])) {
				T temp = std::move(arr[j]);
				arr[j] = std::move(arr[j + 1]);
				arr[j + 1] = std::move(temp);
			}
		}
	}
}
//Function pointers as comparators
bool funcCompInc(int x, int y) {
	return x > y;
}
bool funcCompDec(int x, int y) {
	return x < y;
}


//Function Object as comparator
// 일반적인 Uder defined data type 인데
struct objCompInc {
	// functino call operator 를 정의한다
	bool operator()(int x, int y) {
		return x > y;
	}
};
int main() {

	// function call
	funcCompInc(3, 5);

	// Make an object
	objCompInc comp;

	// function object 에 연산자를 사용
	comp(3, 5);//comp.operator()(3,5) ;


	int arr[]{ 1,6,8,4,0 };
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	// callback by function object 
	//Sort(arr, comp);
	Sort(arr, funcCompDec);

	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	return 0;
}