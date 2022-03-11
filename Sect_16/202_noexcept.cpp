// noexcept => 절대 throw 하지 않는다, 확신
// function type 에 포함된다
void Foo() noexcept {
}
void Bar() {
}

int main() {
	void (*p)(); // function pointer
	// 일반 함수 포인터, 가리키는 데 제약이 없다
	p = Foo; p();
	p = Bar; p();


	void (*pp)() noexcept; // noexcept function pointer
	// noexcept function 만 가리키고 실행할 수 있다
	pp = Foo; pp();
	//pp = Bar; pp();
}