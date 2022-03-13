#include <iostream>
/* Test.h */
class Test {
	int data{ 10 };
	int value{ 100 };

public:
	Test();
	Test(int d);
	Test(int d, int v);
};

/* Test.cpp */
/*
	Delegating Constructor
	다른 생성자를 이용해서, 내 생성자 역할을 하는 것
	생성자 관련 코드를 한 곳에만 써놓을 수 있다

	Delegating ctor 를 먼저 실행하고 => 이후에 내 생성자를 실행한다
*/
Test::Test() : Test(20) { // Test(ind d) ctor 를 이용
	std::cout << "Test()" << std::endl;
}
Test::Test(int d) : Test(d, 200) { // Test(ind d, int v) 이용
	std::cout << "Test(int d)" << std::endl;
}
Test::Test(int d, int v) : data{ d }, value{ v } {
	std::cout << "Test(int d, int v)" << std::endl;
}


int main() {
	Test t{ 30, 300 };

	Test tt{ 40 };

	Test ttt{};
}