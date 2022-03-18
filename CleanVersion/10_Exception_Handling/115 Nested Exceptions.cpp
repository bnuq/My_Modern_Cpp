/*
	Nested Exceptions Handling
	try - catch block 을 2중으로 사용할 수 있다
	함수 내에서 try catch block 을 사용해서, 함수 내에서 exception 을 처리할 수 있고
	거기서 발생한 excetpion 을, 다시 함수를 호출한 곳으로 반환할 수 있다
*/

#include <iostream>
using namespace std;


void func() {
	// 함수 내에서도 try - catch 를 사용할 수 있다
	// 함순 내 작업에서 exception 을 활용할 수 있다
	
	for (int i = 1; i < 10; i++) {
		// try-catch 를 반복해서 사용한다
		try {
			cout << "Processing " << i;
			if (i & 1) { // Bit Manipulation
				throw runtime_error("It is Odd");
			}
			cout << endl;
		}
		// 반복문 내에서, 예외 발생 시 처리 담당
		catch (exception& ex) {
			cout << " : " << ex.what() << endl;

			// catch block 내에서, 받은 exception 을 다시 바깥으로 던질 수 있다
			// 함수 내에서 처리 못하는 예외의 경우, 그 예외를 그대로 함수 바깥으로 전달
			if (i > 6) throw; // 그냥 throw 만 쓰면 된다

			// 받은 예외가 아닌, 다른 예외로 바꾸어서 리턴할 수 도 있다
			if (i == 3) {
				cout << typeid(ex).name() << endl;

				// ex 는 runtime error 에 대한 레퍼런스
				// 따라서 bad_alloc 을 runtime_error 에 대입하는 꼴인데..
				// 이게 되네??
				ex = bad_alloc{};

				cout << typeid(ex).name() << endl;
				//ex = runtime_error("Erro Made by func");
				throw;
			}
		}
	}
}


int main() {
	int x{ 10 };
	int& ref = x;
	int y{ 100 };
	ref = y; // x = y
	cout << x << endl;
	
	try {
		func();
	}
	catch (exception& ex) {
		cout << typeid(ex).name() << endl;
		cout << ex.what() << endl;
	}
}