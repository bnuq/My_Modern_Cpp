#include <iostream>

class Test {
public:
	int data{ 100 };
	/*
		constant member function
		포인터를 생각해봐, const 가 이름 뒤에 붙으니까
		이 멤버 함수 자체가 constant => 멤버 함수를 호출하는 객체 자체를 constant 취급
		this pointer 를 통해서 멤버 변수를 바꿀 수 없다
	*/
	void constMemberFunc() const;

	void func() {
		std::cout << "func" << std::endl;
	}
};

void Test::constMemberFunc() const { // const 자체가 타입에 속하기 때문에 => 정의를 쓸 때 같이 써주어야 한다
	// data++;	멤버 변수를 바꾸는 것이 불가능
	std::cout << "Constant Member Function Called" << std::endl;
}


int main() {
	Test t{};
	t.constMemberFunc();
	t.func();

	const Test tt{};
	tt.constMemberFunc();
	// tt.func();	const 객체는 const member function 만 호출 가능
}