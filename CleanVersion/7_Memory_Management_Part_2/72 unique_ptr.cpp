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
	// smart pointer �� ���ؼ�, �����ϰ��� �ϴ� ��ü�� ����ؾ� �Ѵ�
	// Integer �� Heap �� �Ҵ��ϰ��� �Ѵ�
	// unique pointer has an explicit constructor
	// std::unique_ptr<Integer> p = GetPointer(value); �����Ϸ��� Integer* �� unique pointer �� �ڵ����� �ٲ����� �ʴ´�
	std::unique_ptr<Integer> p{ GetPointer(value) };

	// smart pointer �� nullptr �� �Ҵ�� ���� �ִ�
	// �̶� ����Ʈ �����͸� �״�� �񱳿� ����� �� �ִ�
	if (p == nullptr) {
		// smart pointer �� �׳� assignment �� �Ұ���
		// reset method => ������ �Ҵ��� �޸𸮸� �����ϰ�, ���ο� �޸𸮸� �Ҵ�
		p.reset(new Integer{ value });
	}

	// smart pointer �� ��ü����, ������ ó�� ����� �� �ִ�
	p->SetValue(1000);

	// get metohd => return underlying pointer
	Display(p.get());

	// p = new Integer{}; smart pointer �� �ٸ� �ּҸ� �Ҵ��ϴ� �� �Ұ���
	p = nullptr; // ������ nullptr �� �Ҵ��ϴ� �� ���� => ���� �޸𸮸� �����ϰ� nullptr �Ҵ�

	p.reset(new Integer{});
	*p = __LINE__; // ���� �� ���� �����ϴ� C Macro
	Display(p.get());


	// Unique pointer �� copy �� �Ұ����ϴ�
	// Store1(p);
	Store1(std::move(p)); // move �� ����
	// move �Ŀ��� access �Ұ���, �ٽ� �޸𸮸� �Ҵ����־�� �Ѵ�
	p.reset(new Integer{});

	// ���� ������ ����� reference �� �̿��ϴ� ��
	Store2(p);
	p->GetValue(); // reference �� �̿��ϸ�, unique pointer �� ��� ����� �� �ִ�
}


int main() {
	Operate(7);
}