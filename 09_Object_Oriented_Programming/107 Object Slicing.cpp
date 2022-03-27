#include <iostream>	
#include "./99_105_Bank_Project/Account.h"
#include "./99_105_Bank_Project/Checking.h"
#include "./99_105_Bank_Project/Savings.h"

int main() {

	// child class = base class + own attributtes
	Checking ch{ "Boo", 100 };

	/*
		Upcast
		base class 타입을 가리키는 것으로 child class 를 가리키는 것, 포인터나 레퍼런스 이용
		child class 내 base class 부분을 가리킴
		child class 타입을 base class 타입으로 올려서 생각한다~

		base class 를 가리키는 것으로, child class 의 멤버함수를 호출할 수 있다
	*/
	Account* pAccount = &ch; // 자동으로 가능

	/*
		Object Slicing
		child class 객체를 base class 객체에 저장하는 것
		그냥 child class 에서 base class 부분만 떼어내서 저장하게 된다
		
		base class 가 담지 못하는 부분은, 그냥 잘려 나가게 된다
	*/
	Account acc = ch;


	/*
		Down cast
		반대로 child class 타입을 가리키는 것으로 base class 타입을 가리키는 것
		그냥 base class 타입 포인터나 레퍼런스
			=> 이게 진짜 base class 인지, base class 를 포함하는 어떤 child class 인지 알 수가 없는데
		그 base class 를 가리키는 것을, 그냥 특정 child class 라고 생각하는 것
		base class 타입을 child class 타입으로 내려서 생각한다~
	*/
	// Checking* pChecking = pAccount; 자동으로는 안되고
	Checking* pChecking = static_cast<Checking*>(pAccount); // 강제적 변환이 필요

	return 0;
}