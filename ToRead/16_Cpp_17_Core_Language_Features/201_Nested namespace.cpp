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

	using A::B::C::Foo; // �Լ� �̸��� ����, ������ Foo �� �� ������ Foo �� �����ϰڴ�
	Foo();

	using namespace A::B::C;
	Foo();

	A::B::C::Goo();

	// using �̿��� alias �� type �� ���ؼ��� ����Ѵ�
	// �Լ��� namespace �� ���ؼ��� ��� ���Ѵ�
	using fp = void (*)();
}