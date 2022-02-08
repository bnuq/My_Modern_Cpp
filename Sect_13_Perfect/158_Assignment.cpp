#include <iostream>
#include <vector>
#include <list>

// Function Object
// 
// 1. Max
template <typename T>
struct MaxFuncObj
{
	T operator()(T x, T y) const
	{
		return (x > y) ? x : y;
	}
};


// 2.
template <typename T>
struct GreaterFO
{
	bool operator()(T x, T y)
	{
		return (x > y) ? true : false;
	}
};


// 3.
template <typename T>
struct LessFO
{
	bool operator()(T x, T y)
	{
		return (x < y) ? true : false;
	}
};


// 4. QnA 에 있는 코드 참고했다
template <typename T>
struct MinMaxFO
{

	// 여기서 그냥 auto 사용해도 된다
	//std::pair<T, T> operator()(auto itrBegin, auto itrEnd)
	//{
	//	// iterator => 포인터 처럼 사용
	//	auto min{ *itrBegin };
	//	auto max{ *itrBegin };


	//	// iterator 값은 부등호 연산자를 지원하지 않는다
	//	for (auto it = itrBegin; it != itrEnd; ++it)
	//	{
	//		if (*it < min) min = *it;
	//		if (*it > max) max = *it;
	//	}

	//	return std::make_pair<T, T>(min, max);
	//}


	// 템플릿 안에 템플릿 사용가능 => 추론이 되니까, 굳이 명시적 표현을 안해도 된다?
	template<typename Iterator>
	std::pair<T, T> operator()(Iterator itrBegin, Iterator itrEnd)
	{
		// stl iterator 가 가리키는 데이터 타입 = value_type 을 통해 알 수 있다
		typename Iterator::value_type min{ *itrBegin };
		typename Iterator::value_type max{ *itrBegin };

		
		// iterator 값은 부등호 연산자를 지원하지 않는다
		for (auto it = itrBegin; it != itrEnd; ++it)
		{
			if (*it < min) min = *it;
			if (*it > max) max = *it;
		}

		return std::make_pair(min, max);
	}
};




int main()
{
	// Lambda Expression
	// 
	// 1. Max
	auto Max = [](auto x, auto y)
	{
		return (x > y) ? x : y;
	};
	// Function object with template => 타입 추론을 할 수 있게 타입을 적어주어야 한다
	MaxFuncObj<float> maxFO;


	std::cout << Max(3.4f, 7.6f) << std::endl;
	std::cout << maxFO(3.4f, 7.6f) << std::endl;


	// 2.
	auto Greater = [](auto x, auto y)->bool
	{
		return (x > y) ? true : false;
	};
	GreaterFO<float> greaterFO;


	std::cout << Greater(1.2f, 2.3f) << std::endl;
	std::cout << greaterFO(1.2f, 2.3f) << std::endl;


	// 3.
	auto Less = [](auto x, auto y)->bool
	{
		return (x < y) ? true : false;
	};
	LessFO<float> lessFO;


	std::cout << Less(1.2f, 2.3f) << std::endl;
	std::cout << lessFO(1.2f, 2.3f) << std::endl;


	// 4. => iterator 를 일단 auto 로 그냥 받을 수 있다
	auto MinMax = [](auto itrBegin, auto itrEnd)
	{

		// iterator => 포인터 처럼 사용
		auto min{ *itrBegin };
		auto max{ *itrBegin };

		
		// iterator 값은 부등호 연산자를 지원하지 않는다
		for (auto it = itrBegin; it != itrEnd; ++it)
		{
			if (*it < min) min = *it;
			if (*it > max) max = *it;
		}

		return std::make_pair(min, max);
	};
	MinMaxFO<double> minmaxFO;



	std::vector<int> vec{ 30, 20, 50, 40, 10 };
	std::list<double> lst{ 55.5, 11.1, 22.2, 33.3, 44.4 };

	std::cout << MinMax(vec.begin(), vec.end()).first << " , "
		<< MinMax(vec.begin(), vec.end()) .second << std::endl;

	std::cout << MinMax(lst.begin(), lst.end()).first << " , "
		<< MinMax(lst.begin(), lst.end()).second << std::endl;


	std::cout << minmaxFO(lst.begin(), lst.end()).first << " , "
		<< minmaxFO(lst.begin(), lst.end()).second << std::endl;


	// function object, function call operator 타입 명시적으로 나타내면서 사용하는 방법
	// operator () 를 나누어서 적어준다
	auto res = minmaxFO.operator() < std::list<double>::iterator > (lst.begin(), lst.end());
	std::cout << res.first << " , " << res.second << std::endl;

}