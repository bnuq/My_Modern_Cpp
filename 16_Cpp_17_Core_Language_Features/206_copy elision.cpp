#include <iostream>


#pragma region 206_mandatory_copy_elision

/*
	copy elision = ���ʿ��� �ӽ� ��ü�� ����� ���� ������
	�ӽ� ��ü�� ���� �� �ʰ� �ٷ� �Ű����� �����ڸ� ����ϴ� ������ �۵�
	c++14 => copy, move ctor �� ���� �ʴ��� ���ǰ� �Ǿ� �־�� �Ѵ�
	c++17 => copy elision �� �ʼ�, copy, move ctor �� ������ �����ϴ�
		  => l-value �� r-value �� �ʱ�ȭ �� ��, �׻� �۵�
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
		//return n ; // ���⼭�� ������ ��, l-value �� ���� => �޴� �ʿ��� ������ move ctor �� ����, ����� �����ϱ�
		return Number{ 0 }; // �ӽ� ��ü ������ ���ÿ� ����
	}


	template<typename T, typename...Args>
	T Create(Args&&...args) {
		return T{ args... };
	}


	int main_206() {
		// ��δ� parameterized ctor, �ӽ� ��ü ���� �ٷ� ���� ������ ����Ѵ�
		Number n1 = Number{3} ;
		Foo(Number{3}) ;
		auto n2 = Create() ; // ���� �޴� ���� �ӽ� ��ü�� �������� �ʰ�, �ٷ� ���� ������ ����Ѵ�

		auto n3 = Create<Number>(0);
	}
#pragma endregion



