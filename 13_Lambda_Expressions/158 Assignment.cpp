#include <iostream>
#include <vector>
#include <list>

// Function Object

// 1. Max
template <typename T>
struct MaxFuncObj {
	T operator()(T x, T y) const { // 기본적으로 function call operator 는 const member function
		return (x > y) ? x : y;
	}
};


// 2.
template <typename T>
struct GreaterFO {
	bool operator()(T x, T y) {
		return (x > y) ? true : false;
	}
};


// 3.
template <typename T>
struct LessFO {
	bool operator()(T x, T y) {
		return (x < y) ? true : false;
	}
};


// 4. QnA 에 있는 코드 참고했다
template <typename T>
struct MinMaxFO { // iterator 로 지정된 범위 내에서, 최소값과 최대값을 리턴

	/*
		내가 맨 처음 만든 버전

		어떤 STL 의 iterator 를 받을 지 모르므로, auto 를 이용해 받는다
		std::pair<T, T> operator()(auto itrBegin, auto itrEnd) {

		auto 로 받았지만 무조건 어떤 STL 의 iterator 가 왔다고 생각
		포인터 처럼 사용한다
		auto min{ *itrBegin };
		auto max{ *itrBegin };

		iterator 는 부등호 연산자를 지원하지 않는다
		for (auto it = itrBegin; it != itrEnd; ++it) {
			if (*it < min) min = *it;
			if (*it > max) max = *it;
		}

		return std::make_pair<T, T>(min, max);
	}
	*/


	// 참고한 코드
	// 템플릿 안에서 또 템플릿 사용 => 어떤 iterator 가 들어올 지 모르므로, template 의 typename 으로 받는다
	template<typename Iterator> // 뭐가 들어올 지 모르지만, STL 의 iterator type 이 들어올 것이라 생각
								// typename 의 이름을 Iterator 로 받는다
	std::pair<T, T> operator()(Iterator itrBegin, Iterator itrEnd) { // operator function argument 를 통해서 template argument 를 추론할 수 있다

		/*
			모든 STL 의 iterator 들에는 value_type 이라는 멤버 변수가 존재
			value_type => iterator 가 가리키는 요소의 데이터 타입을 리턴
			리턴한 타입을 typename 으로 받아 => 타입이라는 것을 먼저 알린다
			이후 해당 타입의 이름, min, max 를 이용해서 변수 정의

			무조건 STL 의 iterator 타입이 전달될 것임을 알았기 때문에 가능한 코드
		*/
		typename Iterator::value_type min{ *itrBegin };
		typename Iterator::value_type max{ *itrBegin };

		
		// iterator 값은 부등호 연산자를 지원하지 않는다
		for (auto it = itrBegin; it != itrEnd; ++it) {
			if (*it < min) min = *it;
			if (*it > max) max = *it;
		}

		return std::make_pair(min, max);
	}
};




int main() {

	// STL 의 iterator 타입에서 value_type 을 쓴 예
	typename std::vector<int>::iterator::value_type p{};

	
	
	// Lambda Expression 과 그에 대응하는 Function Object 들을 써보자

	// 1. Max
	auto Max = [](auto x, auto y) {
		return (x > y) ? x : y;
	};
	//Class Template 에서 생성자가 있다면, argument 에서 template argument 를 추론할 수 있었겠지만
	//그냥 쓰는 경우엔 추론할 수 없으므로 list 에 반드시 template argument 를 적어야 한다
	MaxFuncObj<float> maxFO;
	std::cout << Max(3.4f, 7.6f) << std::endl;
	std::cout << maxFO(3.4f, 7.6f) << std::endl;



	// 2.
	auto Greater = [](auto x, auto y) -> bool	{ // lambda expression 의 return type 을 명시
		return (x > y) ? true : false;
	};
	GreaterFO<float> greaterFO;
	std::cout << Greater(1.2f, 2.3f) << std::endl;
	std::cout << greaterFO(1.2f, 2.3f) << std::endl;



	// 3.
	auto Less = [](auto x, auto y) -> bool {
		return (x < y) ? true : false;
	};
	LessFO<float> lessFO;
	std::cout << Less(1.2f, 2.3f) << std::endl;
	std::cout << lessFO(1.2f, 2.3f) << std::endl;



	// 4. => iterator 를 일단 auto 로 그냥 받을 수 있다
	auto MinMax = [](auto itrBegin, auto itrEnd) {

		// iterator => 포인터 처럼 사용
		auto min{ *itrBegin };
		auto max{ *itrBegin };
		
		// iterator 값은 부등호 연산자를 지원하지 않는다
		for (auto it = itrBegin; it != itrEnd; ++it) {
			if (*it < min) min = *it;
			if (*it > max) max = *it;
		}

		return std::make_pair(min, max);
	};
	MinMaxFO<double> minmaxFO;

	std::vector<int> vec{ 30, 20, 50, 40, 10 };
	std::list<double> lst{ 55.5, 11.1, 22.2, 33.3, 44.4 };



	// STL :: Vector :: iterator 에 대해서 작동
	auto [vecMin, vecMax] = MinMax(vec.begin(), vec.end());		// std::pair 에 대해서 Structured Binding 사용
	std::cout << vecMin << " , " << vecMax << std::endl;

	vecMin = 0; vecMax = 0;

	std::tie(vecMin, vecMax) = minmaxFO(vec.begin(), vec.end()); // std::tie 를 통해서 Structured Binding 으로 만든 변수들을
	std::cout << vecMin << " , " << vecMax << std::endl;		 // 다시 Structured Binding 에 사용할 수 있다
	


	// STL :: List :: iterator 에 대해서 작동
	auto [lstMin, lstMax] = MinMax(lst.begin(), lst.end());
	std::cout << lstMin << " , " << lstMax << std::endl;

	lstMin = 0; lstMax = 0;

	std::tie(lstMin, lstMax) = minmaxFO(lst.begin(), lst.end());
	std::cout << lstMin << " , " << lstMax << std::endl;




	// function object, function call operator 타입 명시적으로 나타내면서 사용하는 방법
	// operator () 를 나누어서 적어준다
		// typename T = double, 이라는 건 function object 만들 때 이미 명시
									// typename Iterator = list<double>::iterator => lst.begin(), lst.end() 인 function arguments 를 통해서 알 수 있다
	auto [mmin, mmax] = minmaxFO.operator() < std::list<double>::iterator > (lst.begin(), lst.end());
	std::cout << mmin << " , " << mmax << std::endl;
}