#include <iostream>
class Integer {
public:
	int m_Value{ 100 };

	/*
		default keyword
		parameterized constructor 때문에 default ctor 가 자동으로 생기지 않는 경우
		컴파일러가 자동으로 만들어주는 생성자를 사용하겠다 ~ 는 뜻
		non-static member variabele initialization 이 작동한다
	*/
	Integer() = default;
	
	// parameterized constructor
	Integer(int value) {
		m_Value = value;
	}

	/*
		delete keyword
		이런 종류의 함수를 사용하지 않겠다, 자동으로도 만들지 말라고 지시
		copy ctor 의 사용을 아예 막아버렸다
	*/
	Integer(const Integer&) = delete;
	Integer& operator =(const Integer&) = default; // copy ctor 이 없어도, copy operator 는 정의할 수 있다
	
	void SetValue(int value) {
		m_Value = value;
	}
	// SetValue 함수가 float type 을 받는 경우를 => 아예 없애라, 자동으로 float -> int 변환 되는 것을 막아라
	void SetValue(float) = delete;
};

int main() {
	Integer i1{};
	Integer i3{ 500 };
	i1 = i3; // copy operator 사용
	/*
		copy ctor 를 사용하는 경우들
		delete 했기 때문에, 아예 실행 자체가 안된다
		Integer i2{ i1 };
		Integer i3 = i1;	copy operator 처럼 보이지만, 생성하면서 값을 초기화 하는 것이기 때문에 copy ctor 이다
	*/

	std::cout << i1.m_Value << std::endl; // 100 출력

	i1.SetValue(5);		// int 사용은 원래 가능
	//Error as SetValue(float) is deleted
	//i1.SetValue(67.1f); // float -> int 자동 변환을 막음, 그냥 flaot 가 들어오는 상황을 아예 막음
	return 0;
}