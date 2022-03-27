#include <iostream>
/*
	Old Code => Overloading 이용
	=> 사용하고자 하는 타입별로 함수 overloading 을 직접 구현

	int Max(int x, int y) {
		return x > y ? x : y;
	}
	float Max(float x, float y) {
		return x > y ? x : y;
	}
*/

// Primary Template
// template<class T> 도 가능 => 하지만 보통 typename 을 사용
template<typename T> // 임의의 타입 T 를 받을 때, 함수 정의
T Max(T x, T y) {
	std::cout << typeid(T).name() << std::endl;
	return x > y ? x : y;
}


template<typename T1, typename T2>
void Test(T1 a1, T2 a2) {
	std::cout << typeid(T1).name() << std::endl;
	std::cout << typeid(T2).name() << std::endl;
	return;
}

int main() {

	/*
		template 함수의 arguments 를 compiler 가 분석
		어떤 타입을 넣어서 해당 함수를 만들어야 하는 지를, compile 단계에서 분석한다
		그리고 해당 타입이 들어간 함수를 만든다
		= Instantiation
	*/
	auto num = Max(9.0f, 0.3f); // T = float type
	std::cout << num << std::endl;

	auto num2 = Max(9, 3); // T = int type
	std::cout << num2 << std::endl;


	// template argument list 에 해당 타입을 모두 적어야 하는가?
	// 다 적지 않아도 된다, 부족한 부분을 arguments 에서 알아낼 수 있으면 실행이 잘된다
	Test(1, 2.0f);
	
	// typename T1 만 지정, T2 는 유추
	Test<int>(1, 2.0f);
	Test<float>(1, 2.0f);

	// typename T1, T2 모두 지정
	Test<int, float>(1, 2.0f);
	Test<float, float>(1, 2.0f);
}