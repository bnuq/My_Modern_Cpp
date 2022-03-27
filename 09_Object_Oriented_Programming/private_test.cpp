#include <iostream>
using namespace std;

class A {
private:
	int x{}, y{};

protected:
	int w{};

public:
	int r{};
	void print() {
		cout << x << endl;
	}
};

class B : public A {
private:
	int t{};

public:
	int z{};

	void  func() {
		//a.x = 10;
		A a{};
		//a.w = 100;
		w = 100;
		r = 100;
		
	}
	void func2(A a) {
		w = 1000;
		r = 9;
		//aa.w = 100;
		
	}

};


int main() {
	B b{};

	A& refA{ b };
	refA.print();
}