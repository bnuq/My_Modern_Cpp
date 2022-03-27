#include "Integer.h"
#include <iostream>
#include <memory> // For Smart Pointer


Integer* GetPointer(int value) {
	return new Integer{ value };
}

void Display(Integer* p) {
	if (!p) return;
	else std::cout << p->GetValue() << std::endl;
}

void Store1(std::unique_ptr<Integer> p) {
	std::cout << "Copy by Value" << std::endl;
}
void Store2(std::unique_ptr<Integer>& p) {
	std::cout << "Copy by Reference" << std::endl;
}


void Operate(int value) {
	// smart pointer 를 통해서, 관리하고자 하는 객체를 명시해야 한다
	// Integer 를 Heap 에 할당하고자 한다
	// unique pointer has an explicit constructor
	// std::unique_ptr<Integer> p = GetPointer(value); 컴파일러가 Integer* 를 unique pointer 로 자동으로 바꿔주지 않는다
	std::unique_ptr<Integer> p{ GetPointer(value) };

	// smart pointer 에 nullptr 이 할당될 수도 있다
	// 이때 스마트 포인터를 그대로 비교에 사용할 수 있다
	if (p == nullptr) {
		// smart pointer 에 그냥 assignment 는 불가능
		// reset method => 기존에 할당한 메모리를 정리하고, 새로운 메모리를 할당
		p.reset(new Integer{ value });
	}

	// smart pointer 는 객체지만, 포인터 처럼 사용할 수 있다
	p->SetValue(1000);

	// get metohd => return underlying pointer
	Display(p.get());

	// p = new Integer{}; smart pointer 에 다른 주소를 할당하는 건 불가능
	p = nullptr; // 하지만 nullptr 를 할당하는 건 가능 => 기존 메모리를 정리하고 nullptr 할당

	p.reset(new Integer{});
	*p = __LINE__; // 현재 줄 값을 리턴하는 C Macro
	Display(p.get());


	// Unique pointer 는 copy 가 불가능하다
	// Store1(p);
	Store1(std::move(p)); // move 만 가능
	// move 후에는 access 불가능, 다시 메모리를 할당해주어야 한다
	p.reset(new Integer{});

	// 가장 간단한 방법은 reference 를 이용하는 것
	Store2(p);
	p->GetValue(); // reference 를 이용하면, unique pointer 를 계속 사용할 수 있다
}


int main() {
	Operate(7);
}