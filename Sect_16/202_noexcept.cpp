// noexcept => ���� throw ���� �ʴ´�, Ȯ��
// function type �� ���Եȴ�
void Foo() noexcept {
}
void Bar() {
}

int main() {
	void (*p)(); // function pointer
	// �Ϲ� �Լ� ������, ����Ű�� �� ������ ����
	p = Foo; p();
	p = Bar; p();


	void (*pp)() noexcept; // noexcept function pointer
	// noexcept function �� ����Ű�� ������ �� �ִ�
	pp = Foo; pp();
	//pp = Bar; pp();
}