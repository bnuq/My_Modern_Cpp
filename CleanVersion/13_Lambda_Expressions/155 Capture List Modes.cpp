#include <iostream>


// 배열의 각 원소에, operation 을 적용하는 템플릿 함수
template<typename T, int size, typename Callback>
void ForEach(T(&arr)[size], Callback operation) {
	for (int i = 0; i < size - 1; ++i) {
		operation(arr[i]);
	}
}


int main() {
	
	int arr[]{ 1,6,8,4,0 };	

	/*
		Capture List Modes
		
		Capture List 에서 변수를 캡처할 때, 여러가지 설정을 할 수 있다
	*/

	/*
		Caputure variable by reference
			바깥의 변수의 레퍼런스를 가져온다
			값을 변경하면 바깥의 변수가 변함
			멤버 변수가 변하는 것이 아니기 때문에, mutable 이 없어도 변경 가능하다
	*/
	int sum{ 0 };
	ForEach(arr, [&sum](auto& x) {
		sum += x;
		});
	std::cout << "Sum is " << sum << std::endl;


	/*
		Capture all variables by reference
			앞에 존재하는 모든 변수를 capture by reference
			따로 변수를 지정할 필요 없다
	*/
	sum = 0;
	ForEach(arr, [&](auto& x) {
		sum += x;
		});
	std::cout << "Sum is " << sum << std::endl;


	/*
		Capture all variables by value
			앞에 존재하는 모든 변수를 capture by value
			Function Object 안에 멤버변수로 만든다 => mutable 하지 않으면 수정 불가능
			바깥의 기존 변수는 영향받지 않는다
	*/
	sum = 0;
	ForEach(arr, [=](auto& x) mutable {
		sum += x;
		});
	std::cout << "Sum is " << sum << std::endl;



	/*
		특정 변수만 다르게 받고, 나머지 변수들은 또 다르게 받기
		[=, &sum]
			다 value 로 받는데, sum 만 reference
		[&, sum]
			다 reference 로 받는데, sum 만 value
	*/
	int sum1 = 0;
	int sum2 = 0;
	ForEach(arr, [&, sum1](auto &x) mutable { // sum1 만 value 로 받음
		sum1 += x;
		sum2 += x;
	});
	std::cout << "Sum1 is " << sum1 << std::endl;
	std::cout << "Sum2 is " << sum2 << std::endl;



	return 0;
}

