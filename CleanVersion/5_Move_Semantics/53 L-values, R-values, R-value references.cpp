#include <iostream>

//Returns r-value
int Add(int x, int y) {
	return x + y;
}
//Return l-value
int& Transform(int& x) {
	x *= x;
	return x;
}

// l-value 전용
void Print(int& x) {
	std::cout << "Print(int&)" << std::endl;
}
// r-value 전용
void Print(int&& x) {
	std::cout << "Print(int &&)" << std::endl;
}

/*
	다른 reference 를 받는 함수가 없는 경우,
	l-value, r-value  모두 받을 수 있다
*/
void Print(const int& x) {
	std::cout << "Print(const int&)" << std::endl;
}



int main() {
	//x is lvalue
	int x = 10;

	//ref is l-value reference
	int& ref = x;
	//l-value return 을 l-value reference 로 받는다
	int& ref2 = Transform(x);
	//Binds to function that accepts l-value reference
	Print(x);


	//rv is r-value reference
	int&& rv = 8;
	rv = 10; // r-value 에 대입하는 게 되네??

	//Add returns a temporary (r-value)
	int&& rv2 = Add(3, 5);
	//Binds to function that accepts a temporary, i.e. r-value reference
	Print(3);
	return 0;
}

