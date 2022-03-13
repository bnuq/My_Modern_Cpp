#include <iostream>


#pragma region 206_mandatory_copy_elision

/*
	copy elision = 불필요한 임시 객체를 만드는 것을 막아줌
	임시 객체를 만들 지 않고 바로 매개변수 생성자를 사용하는 식으로 작동
	c++14 => copy, move ctor 를 쓰지 않더라도 정의가 되어 있어야 한다
	c++17 => copy elision 이 필수, copy, move ctor 이 없더라도 가능하다
		  => l-value 를 r-value 로 초기화 할 때, 항상 작동
*/
	#define DELETE_COPY_MOVE
	class Number {
	public:
		Number(int value) {
			std::cout << "Parameterized ctor\n";
		}
	#ifdef DELETE_COPY_MOVE
		Number(const Number&) = delete;
		Number(Number&&) = delete;
	#else
		Number(const Number&) {
			std::cout << "Copy ctor\n";
		}
		Number(Number&&) noexcept {
			std::cout << "Move ctor\n";
		}
	#endif
	};
	void Foo(Number n) {

	}
	Number Create() {
		//Number n{0} ;
		//return n ; // 여기서는 생성된 것, l-value 을 리턴 => 받는 쪽에서 무조건 move ctor 를 쓴다, 사라질 변수니까
		return Number{ 0 }; // 임시 객체 생성과 동시에 리턴
	}


	template<typename T, typename...Args>
	T Create(Args&&...args) {
		return T{ args... };
	}


	int main_206() {
		// 모두다 parameterized ctor, 임시 객체 없이 바로 본인 생성에 사용한다
		Number n1 = Number{3} ;
		Foo(Number{3}) ;
		auto n2 = Create() ; // 리턴 받는 것을 임시 객체에 저장하지 않고, 바로 본인 생성에 사용한다

		auto n3 = Create<Number>(0);
	}
#pragma endregion



