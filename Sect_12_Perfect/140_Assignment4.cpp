#include <iostream>
#include <string>
#include "138_Integer.h"

//template <typename T>
//T* CreateObject<T>()
//{
//	return
//}


template <typename T, typename ... Params>
// function template 정의에서 <> 에 타입을 명시하려면
// 사용하는 모든 template argument 를 명시해야 한다
T* CreateObject(Params&& ... args)
{
	//return new T{args}; => 이렇게 하면 parameter pack 을 확장하지 않았다고 뜬다
	//return new T{ args ... }; => parameter pack 을 확장하는 방법
	return new T{ std::forward<Params>(args)... }; // perfect forwarding 을 활용하는 방법
	// parameter pack 으로 직접 초기화가 가능하다! => 이걸 알려줘야지
	// parameter pack 이 비어있어도 가능
}


int main()
{
	// 강제적으로 지정하는 타입이, 순서대로 들어가는 구나
	// 그 외는 자동으로 인식
	// 그래서 원하는 만큼의 타입만 꺽쇠 괄호에 넣을 수 있다
	int* p1 = CreateObject<int>(5);
	std::cout << *p1 << std::endl;
	

	std::string* p2 = CreateObject<std::string>();
	Integer* p3 = CreateObject<Integer>(45);


	delete p1;
	delete p2;
	delete p3;
}