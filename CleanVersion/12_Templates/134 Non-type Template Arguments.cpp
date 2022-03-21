#include <iostream>

/*
	Non-type template parameter
	
	Template Arguments list 에 포함되는데
	typename 은 아닌 arguments

	arguments 를 통해서 deduction 되는 대상이 아니다
	반드시 템플릿 함수를 호출할 때, template argument list 를 통해서 값을 넘겨 받음

	constant 취급한다
*/
template<int size> // non-type template parameter
void Print() {
	char buffer[size]{}; // constant 처럼 사용 가능
	std::cout << size << std::endl;
}

/*
	이런 식으로 non-type template parameter 를
	일반 argument 로 받는 것은 불가능

	template<int size>
	void Print2(const int size) {
		std::cout << size << std::endl;
	}
*/



/*
	array type 을 argument 로 받는 경우
	
	array type reference 에는 size 정보가 이미 들어있다는 걸 이용
		배열의 사이즈 정보가 이미 타입에 포함되어 있다

	Size is implicitly calculated in non-type template argument
	array type reference 를 argument 로 받을 때, 타입 안에 이미 상수가 들어있어
	template argument list 에 넘기지 않아도, 상수 값이 넘어온다
*/
template<typename T, int size>
T Sum(T(&arr)[size]) { // 배열의 reference 를 받는다는 뜻
	T sum{};
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum;
}

int main() {

	// non-type template argument 인 3 을 list 를 통해 넘긴다
	Print<3>();
	// Print2<10>(10); 안된다, 불가능

	int i{ 3 };
	// Print<i>();  constant 가 아닌 변수를 non-type template argument 로 넘길 수 없다

	
	// 배열 이름 => array type
	int arr[]{ 3,1,9,7 };
	// 배열 주소 값을 가지고 있어서, 보통 포인터로 받는다
	int* pInt = arr;

	
	// 하지만 배열 이름이 포인터 인 것은 아니다, 배열 이름 = array type
	int sum = Sum(arr); // array type = 배열 크기에 대한 정보가 들어있다
	//std::cout << sum << std::endl;

	// array type reference 를 자세하게 나타낸 것
	int(&ref)[4] = arr;
	//int (&ref)[5] = arr ; 가리키는 배열 크기가 달라서 불가능
	//std::cout << Sum(ref) << std::endl;


	// 굳이 굳이 template argument list 를 사용하는 경우
	// typename 은 밝혀주어야 하고
	// non-type template argument 는 자동으로 파악되기 때문에 넘기지 않아도 된다
	std::cout << Sum<int>(arr) << std::endl;
	std::cout << Sum<int, 4>(arr) << std::endl;
	// std::cout << Sum<int, 5>(arr) << std::endl; array type 과 맞지 않는 arguments 는 안된다

	return 0;
}