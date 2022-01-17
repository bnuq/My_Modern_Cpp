#include <iostream>
using namespace std;


/*
	Enumerated Type
	정수 값에 이름을 붙여서 사용
	매크로나 상수 선언 없이 한번에 사용할 수 있다
	정해진 범위의 값만 가진다

	use 'enum' keyword
	restricted range of values
	called symobolic constants, enumerator
		internally represented as undefined integral types
		enumerator -> integer, but not the other way
			Color c = Red; 일 때
			c = 1; -> 불가능
			c = static_cast<Color>(1);
			int x = Red; -> 가능
	Defalut value = 0, but users can assign any value
	옆으로 갈때마다 1 씩 증가
	Enumerator visible in which defined
*/


// enum 정의 -> { } 중괄호로 초기화 = uniform initialization
// enum type 과 enumulator 의 범위는 같다 -> enumulator 이름이 같으면 중복이다
enum Color { RED, GREEN, BLUE };

// enumulator 이름 중복 에러
// 그래서 unscoped enum 은 더이상 사용하지 않는다
// enum Traffic { RED, GREEN, BLUE };


// 앞서 정의한 enum = enumulated type = 타입처럼 사용한다 -> 내부적으로는 정수 취급
// enumerator 의 범위가 타입을 벗어나니까, 경고 알람이 들어왔다
void FillColor(Color color)
{
	if (color == RED) {
		cout << "RED" << endl;
	}
	if (color == GREEN) {
		cout << "GREEN" << endl;
	}
	if (color == BLUE) {
		cout << "BLUE" << endl;
	}
}


void num_1() {
	// Enumulator 정의
	
	Color c = RED;
	
	// 정의된 enum type 만 넘길 수 있다
	FillColor(c);
	FillColor(GREEN);

	// integer -> enum 은 금지되어 있어서, 정수값을 넘길 수 없다
	// FillColor(1);

	// 아니면 static_cast 를 통해 명시적으로 타입변환을 지시
	FillColor(static_cast<Color>(2));

}



/*
	scoped enum
	enumerator 의 범위가 enumerated type 내부로 한정되는 것
	바깥에서 enumerator 를 볼 수 없게 된다
	반드시 enum type 을 통해서 enumerator 접근

	enum class

	선호
*/
enum class Color2 {RED, GREEN, BLUE}; // 이제 enumerator 가 겹쳐도 괜찮다
enum class Traffic { RED, GREEN, BLUE };


void FillColor2(Color2 color)
{
	// scoped enum's enumerator 사용을 위해서는 어느 타입에 속하는 지를 알려야 한다
	if (color == Color2::RED) {
		cout << "RED" << endl;
	}
	if (color == Color2::GREEN) {
		cout << "GREEN" << endl;
	}
	if (color == Color2::BLUE) {
		cout << "BLUE" << endl;
	}
}


void num_2() {
	// scoped enum => enumerator, doesn't implicitly convert to integer
	// int x = Color2::RED; compile error

	// 명시적 타입 변환만 허용
	int x = static_cast<int>(Color2::RED);
	Color2 c = static_cast<Color2>(2);
}



// enumerator 가 저장되는 타입을 int 가 아닌, 다른 타입으로도 설정할 수 있다
// 그래도 일단 정수형 타입이여야 겠지
// : => enum type 이 저장되는 타입 지정
// assignment => enumerator 의 값을 지정할 수 있다, 이후 옆으로 갈수록 1 씩 증가
enum class Color3 : long {RED = 100, GREEN, BLUE = 105};
// 진짜 문자 저장이 아니고, 아스키 코드 값으로 저장
enum class Color4 : char { RED = 'e', GREEN = 'g', BLUE };



int main()
{
	num_1();
	num_2();
}