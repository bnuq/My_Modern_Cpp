#include <iostream>
#include <string>
#include "Integer.h"

#include <memory>



// 임의의 T 타입 객체를 만들어서 리턴하는 함수
// Varadic Template
/*
	여러 개의 typename 들, Template parameter pack 을 ... 으로 표현
	=> pack 을 Params 라는 pack name 으로 받는다

	정의하는 부분이므로, 타입과 ... 이 pack-name 앞에 온다
*/
template <typename T, typename ... Params>
/*
	Template Parameter Pack 에 대응되는 function parameter 의 타입 pack
	=> Params ... 로 표현
	해당 타입 pack 을 나타내는 변수 pack => args 로 나타낸다
	args = function parameter pack

	정의하는 부분이므로, 타입을 나타내는 Params 와 ... 이 pack-name 앞에 온다
*/
T* CreateObject(Params&& ... args) {
	
	/*
		return new T{args};
			이렇게 하면 parameter pack 을 확장하지 않았다고 뜬다
			그냥 pack name 만 넘겨서는 사용할 수 없다
	*/
	/*
		return new T{ args ... };
			parameter pack 을 확장하는 방법
			사용할 때는 pack name 뒤에 ... 을 붙여야 한다
	*/
	/*
		perfect forwarding 을 활용하는 방법
		레퍼런스가 가리키는 l-value, r-value 타입을 보존해서 다음 함수에 넘긴다
	*/
	/*
		생성자에 parameter pack 을 넘기는 구조
		parameter pack = 0 개 이상의 arguments 에 불과하다
		따라서 해당 타입의 생성자 중, 그런 arguments 를 받는 생성자가 존재하기만 하면 된다
	*/
	return new T{ std::forward<Params>(args)... };
}





template <typename T, typename ... Params>
std::unique_ptr<T> CreateUniquePointer(Params&& ... args) {
	// perfect forwarding 으로 T 객체를 생성한 다음
	// unique pointer 가 할당한 리소스를 관리하고
	// unique pointer 리턴 => caller 에게 r-value 로 리턴
	return std::unique_ptr<T>{ new T{ std::forward<Params>(args)... } };
}


int main() {
	/*
		원래는 template arguments list 를 전부 다 채울 필요는 없다
		앞쪽에서 부터 채울 수 있는 만큼 채워도, 나머지 부분을 arguments 를 통해서 deduction 해낼 수 있다
		애초에 parameter pack 을 리스트에 지정해서 넣을 수는 없다

		하지만 해당 템플릿 함수 function arguments 로 function arguments pack 만 받는다
		따라서, arguments 에서 typename T 를 유추해 낼 수가 없다
		
		그러므로 template arguments list 에 typename T 는 반드시 명시를 해주어야 한다
		
		인식한 T 타입의 객체를 생성
	*/
	//int* p1 = CreateObject(5);  typename T 를 유추해 낼 방법이 없다
	int* p1 = CreateObject<int>(5);
	std::cout << *p1 << std::endl;
	
	// 다른 객체에 대해서도 다 가능
	std::string* p2 = CreateObject<std::string>();
	Integer* p3 = CreateObject<Integer>(45);


	delete p1;
	delete p2;
	delete p3;


	// unique pointer 는, new int => unique_ptr 로 자동 변환이 안된다
	//std::unique_ptr<int> pp = new int{ 10 };

	// unique pointer 는 copy 는 불가능, 하지만 move operation 은 가능하다
	std::unique_ptr<int> pp = std::unique_ptr<int>{ new int{10} };

	// r-value unique pointer 를 리턴하기 때문에, move ctor 로 unique pointer 생성
	std::unique_ptr<Integer> up4 = CreateUniquePointer<Integer>(50);

	// Copy 는 불가능
	//std::unique_ptr<Integer> up5 = up4;

	std::cout << *up4 << std::endl;
}