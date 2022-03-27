#include <iostream>

// Primary Template
template<typename T>
T Max(T x, T y) {
	// typeid :: name() => 타입 이름을 리턴
	std::cout << typeid(T).name() << std::endl;
	return x > y ? x : y;
}


/*
	Explicit Instantiation
	
	템플릿에서, 특정 타입을 받는 경우에 대해서 미리 Instantiation 하는 것
	해당 타입을 받는 템플릿 함수를 컴파이러가 미리 만들어 놓도록 한다
	template 만 쓰고 template argument list, < > 는 쓰지 않는다
	만들고자 하는 특정 타입을 넣어서, 함수 시그니처를 선언
*/
// char 타입을 받는 Max 함수를 직접 만들게 지시한다
// 이 함수를 호출하지 않아도, 컴파일러에 의해서 무조건 만들어진다
// 따라서 이 선언도 반드시 헤더파일에 존재해야 한다
template 
char Max(char x, char y);


/*
	Explicit Specialization

	특정 타입을 받는 경우에 한해서만, 템플릿 함수를 재정의한다
	template + empty template argument list, <>
	그리고 뒤에 특별히 재정의하고자 하는 타입을 적는다

	일단 일반 템플릿 함수 정의로 해당 타입이 들어가는 것을 Instantiation 한 다음에
	Explicit Specialization 을 실행
	따라서 헤더파일이 아닌, cpp file 에 정의가 들어가야 한다

	호출하지 않아도 컴파일러가 미리 만드는, Instantiation 을 하기 때문에
	선언은 헤더파일에 존재해야 한다

	template<>
	const char* Max(const char* x, const char* y) 와 같이 사용
		const char* 타입에 대해서 템플릿 함수를 재정의
*/

template<>
				// 함수 이름 뒤에 < type > 을 추가해서, 들어가는 타입을 정확하게 명시할 수 있다
				// 이 경우 arguments 에서 추론할 필요 없이 바로 들어가는 타입을 알 수 있다
const char* Max<const char*>(const char* x, const char* y) {
	std::cout << "Max<const char*>()" << std::endl;
	return strcmp(x, y) > 0 ? x : y; // string compare
}



int main() {
	/*
		Template Argument Deduction
		템플릿 함수의 Arguments 를 통해서, 해당 템플릿 함수가 필요로 하는 타입을 알아내는 과정
		자동 타입 변환 없고, 반드시 맞춰주어야 한다
	*/
	// T type 은 하나, 맞춰주기
	Max(static_cast<float>(3), 6.3f);


	// 아니면 template argument list 를 이용
	// 명시적으로 타입 설정 => 해당 타입이 들어가는 템플릿 함수를 만들어 버린다
	// 이 경우 타입이 확실하게 결정되므로, arguments 에서 자동 타입 변환이 가능하다
	Max<double>(3, 5.3f);


	// function pointer 이용 => 템플릿 함수를 가리킨다면
	// 해당 타입을 가지는 템플릿 함수는 반드시 만들어 진다 => Instantiation 발생
	int (*pfn)(int, int) = Max;


	const char* a{ "A" };
	const char* b{ "B" };

	// Arguments 를 통해서 const char* 를 받는 Max 함수가 필요하다는 것이 확실함
	// 컴파일러에 의해 만들어짐 => Instantiation
	std::cout << Max(a, b) << std::endl;

	return 0;
}
