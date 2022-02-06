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
// 일반적인 Uder defined data type 인데
struct objCompInc {
	// functino call operator 를 정의한다
	bool operator()(int x, int y) {
		return x > y;
	}
};


void Code_One() {

	// function call
	funcCompInc(3, 5);


	int arr[]{ 1,6,8,4,0 };
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	// Lambda Expression 을 Function Object 에 바로 집어 넣는다
	// 함수가 하는 일을 바로 알 수 있다
	// 범위 한정
	Sort(arr, [](auto x, auto y) {
		return x > y;
		});

	// auto 이용해서 이름붙이기
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
void ForEach(T(&arr)[size], Callback operation)
{
	for (int i = 0; i < size; i++)
		// 각 배열 원소에 대해서 operation 을 적용한다
		operation(arr[i]);
}

int main()
{
	int arr[]{ 2,5,9,1,4 };
	
	// 바로 Lambda Expression 을 넣어서 실행
	ForEach(arr, [](auto x)
		{
			std::cout << x << " , ";
		});
	std::cout << std::endl;

	
	
	int offset = 5;
				 // capture list 에서 바깥의 offset variable 을 capture => 람다에서 사용가능하게 한다
				 // copy 해서 람다로 가져온다
				 // 기본적으로 람다 표현식 => const function call operator 로 구현
				 // capture list => member variable, caputred by value
				 // const function 이니까 멤버 값을 바꿀 수 없다
	ForEach(arr, [offset](auto x)
		{
			x += offset;
			std::cout << x << " , ";

			// ++offset;
		});
	std::cout << std::endl;


	// 멤버 값을 바꾸려면, mutable => constness 가 제거된다
	// offset 은 copy 로 값이 넘어가 ~ 기존 offset 값은 변화 없음
	ForEach(arr, [offset](auto x) mutable
		{
			x += offset;
			std::cout << x << " , ";

			++offset;
		});
	std::cout << std::endl;

	std::cout << "offset is " << offset << std::endl;
}