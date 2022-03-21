#include <iostream>

template<typename T, int size, typename Comparator>
void Sort(T(&arr)[size], Comparator comp) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - 1; ++j) {
			if (comp(arr[j], arr[j + 1])) {
				T temp = std::move(arr[j]);
				arr[j] = std::move(arr[j + 1]);
				arr[j + 1] = std::move(temp);
			}
		}
	}
}

//Function pointers as comparators
bool funcCompInc(int x, int y) {
	return x > y;
}
bool funcCompDec(int x, int y) {
	return x < y;
}

//Function Object as comparator
struct objCompInc {
	bool operator()(int x, int y) {
		return x > y;
	}
};



void Code_One() {

	int arr[]{ 1,6,8,4,0 };
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	// Lambda Expression 을 Function Object 가 들어갈 자리에 바로 넣을 수 있다
	// 함수가 하는 일을 바로 알 수 있다 + 범위 한정
	Sort(arr, [](auto x, auto y) {
		return x > y;
		});

	// auto 이용해서 lambda expression 저장
	auto lambdaComp = [](auto x, auto y) {
						return x < y;
						};
	Sort(arr, lambdaComp);

	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}



// 배열의 각 원소에 대해서, 특정 연산을 진행하는 템플릿 함수
template<typename T, int size, typename Callback>
void ForEach(T(&arr)[size], Callback operation) {
	for (int i = 0; i < size; i++)
		// 각 배열 원소에 대해서 operation 을 적용한다
		operation(arr[i]);
}


int main()
{
	int arr[]{ 2,5,9,1,4 };
	// Lambda Expression 을 직접 넣어서 실행
	ForEach(arr, [](auto x)
		{
			std::cout << x << " , ";
		});
	std::cout << std::endl;
	

	
	int offset = 5;
	/*
		capture list = [ ], 대괄호
		바깥의 variable 을 capture => 람다에서 사용할 수 있게 한다
		copy 해서 람다로 가져온다

		기본적으로 람다 표현식 => const member function 으로 구현되며
		capture list 에 들어온 변수 => member variable, copied by value 로 구현된다
		
		따라서 const function 이므로, 기본적으로 캡쳐한 값을 바꿀 수 없다
	*/
	ForEach(arr, [offset](auto x) {
			x += offset;
			std::cout << x << " , ";

			// ++offset; 캡처한 값을 바꿀 수는 없다
		});
	std::cout << std::endl;


	/*
		캡처한 값을 바꾸기 위해서는, mutable 하다는 것을 알려야 한다
		=> constness 가 제거된다
	*/
	ForEach(arr, [offset](auto x) mutable { // 캡처한 값 바꿀 수 있다는 걸 알림
			x += offset;
			std::cout << x << " , ";

			++offset;
		});
	std::cout << std::endl;

	// Capture List 에 넘길 때, copy by value ~ 기존 offset 값은 변화 없음
	std::cout << "offset is " << offset << std::endl;
}