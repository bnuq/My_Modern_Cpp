#include <iostream>
#include <initializer_list>
#include "Integer.h"

/*
	템플릿 함수 argument 가 std::initializer_list 를 받는 경우
	= Works only for homogenous data types
	initializer_list 의 경우, 갯수에는 제한이 없지만 모든 요소들의 타입이 같아야 한다
*/
template<typename T>
void Print(std::initializer_list<T> args) {
	for (const auto &x : args) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}




// Base Case Function
// Zero argument
// Stop the recursion
void Print(){
	std::cout << " | Base Case" << std::endl;
}


// A template with atleast one parameter pack = Variadic Template
// 가변 길이 템플릿
/*
	다음 템플릿 함수의 template parameter 에서
	typename... Params 와 같은 template parameter
	= Template Parameter Pack 이라고 한다
	= Accepts zero or more template arguments

	typaname... 이 한 세트 + 그것들을 가리키는 이름 = Params
		... = ellipses
		여러개의 type 들이 템플릿에 쓰이게 되고, 그 typename 들을 한꺼번에 Params 로 가리킨다
		Params = pack-name 이라고 한다
		pack 전체에 대한 이름
		정의하는 부분이니까 ... 이 pack-name 앞에 온다
 
	Params 가 가리키는 각각의 요소에 직접 접근하는 것은 불가능
	=> recursion 이용
*/
template<typename T, typename... Params>
/*
	템플릿 함수의 function parameter 에서
	Param... args 와 같은 function parameter
	= Function Parameter Pack
	= Accepts zero or more function arguments

	Params... + args
		여러 typenames 인 typename pack 인 Params 에 대해서
		그 타입을 가지는 변수들 pack 을 args 로 가리킨다
		정의하는 부분이니까 ... 이 pack-name 앞에 온다

	여기서는 l-value, r-vlaue 모두 각 타입에 맞는 reference 로 가리키기 위해
	r-value reference 를 사용했다
*/
void Print(T &&a, Params&&... args) {

	// 첫번째를 제외한, 나머지 parameter pack 에 들어있는 요소들의 개수를
	// 구하는 방법 => sizeof... 연산자를 사용 => pack 에 들어있는 개수를 리턴
	/*
		std::cout << sizeof...(args) << std::endl;
		std::cout << sizeof...(Params) << std::endl;
	*/
	std::cout << a;

	if (sizeof...(args) != 0) {
		std::cout << ",";
	}

	//We can forward a function parameter pack
	// Perfect Forwarding, 각 타입에 맞게 Copy, Move 를 사용하도록 한다
	// 여기서는 ... 순서가 반대
	// parameter pack 을 다시 다른 함수 argument 로 넘길 때는
	// ... 이 pack-name 뒤에 온다, 호출할 때니까?
	Print(std::forward<Params>(args)...);

	// Recursion, 재귀 호출
	// parameter pack 에 들어있는 것들을 앞에서부터, 하나씩 처리한다
}



int main() {
	
	// std::initializer_list<T> 를 argument 로 넘겨서 템플릿 함수를 이용하는 경우
	// Print{ 1, 2, 3, 4 };  이렇게 쓰면 Print 객체 생성자를 호출하는 Uniform Initialization 모양
	Print({ 1, 2, 3, 4 }); // 괄호 안에 { } 중괄호를 적어서 전달한다
	// Print({ 1, 2.5, 3, 4 });  중간에 타입이 다른 값이 하나만 들어가도 인수 형식을 { ... } 타입으로 인식한다
	
	
	// 함수 호출에 필요한 arguments 를 그냥 아무 타입들을
	// 개수 제한 없이 넣는다 => 이거 자체가 parameter pack
	Print(1, 2.5, 3, "4");


	Integer val{ 1 };
	// int, l-value, r-value
	// User Defined Type 을 넣을 수도 있다
	Print(0, val, Integer{ 2 });


	return 0;
}

/*
* Recursively 하게 처리
* 가장 앞에 있는 arguments 부터 하나씩 처리
1. Print(1, 2.5, 3, "4") ;
2. Print(2.5, 3, "4") ;
3. Print(3, "4") ;
4. Print("4") ;
5. Print() ;
*/
