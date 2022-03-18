#include <iostream>
namespace A {
	namespace B {
		namespace C {
			void Goo() {

			}
		}
	}
}
namespace A::B::C {
	void Foo() {
	}
}

int main() {
	A::B::C::Foo();

	using A::B::C::Foo; // 함수 이름만 지정, 앞으로 Foo 는 이 범위의 Foo 만 생각하겠다
	Foo();

	using namespace A::B::C;
	Foo();

	A::B::C::Goo();

	// using 이용한 alias 는 type 에 대해서만 사용한다
	// 함수나 namespace 에 대해서는 사용 안한다
	using fp = void (*)();
}