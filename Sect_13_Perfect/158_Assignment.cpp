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


// 4. QnA �� �ִ� �ڵ� �����ߴ�
template <typename T>
struct MinMaxFO
{

	// ���⼭ �׳� auto ����ص� �ȴ�
	//std::pair<T, T> operator()(auto itrBegin, auto itrEnd)
	//{
	//	// iterator => ������ ó�� ���
	//	auto min{ *itrBegin };
	//	auto max{ *itrBegin };


	//	// iterator ���� �ε�ȣ �����ڸ� �������� �ʴ´�
	//	for (auto it = itrBegin; it != itrEnd; ++it)
	//	{
	//		if (*it < min) min = *it;
	//		if (*it > max) max = *it;
	//	}

	//	return std::make_pair<T, T>(min, max);
	//}


	// ���ø� �ȿ� ���ø� ��밡�� => �߷��� �Ǵϱ�, ���� ����� ǥ���� ���ص� �ȴ�?
	template<typename Iterator>
	std::pair<T, T> operator()(Iterator itrBegin, Iterator itrEnd)
	{
		// stl iterator �� ����Ű�� ������ Ÿ�� = value_type �� ���� �� �� �ִ�
		typename Iterator::value_type min{ *itrBegin };
		typename Iterator::value_type max{ *itrBegin };

		
		// iterator ���� �ε�ȣ �����ڸ� �������� �ʴ´�
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
	// Function object with template => Ÿ�� �߷��� �� �� �ְ� Ÿ���� �����־�� �Ѵ�
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


	// 4. => iterator �� �ϴ� auto �� �׳� ���� �� �ִ�
	auto MinMax = [](auto itrBegin, auto itrEnd)
	{

		// iterator => ������ ó�� ���
		auto min{ *itrBegin };
		auto max{ *itrBegin };

		
		// iterator ���� �ε�ȣ �����ڸ� �������� �ʴ´�
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


	// function object, function call operator Ÿ�� ��������� ��Ÿ���鼭 ����ϴ� ���
	// operator () �� ����� �����ش�
	auto res = minmaxFO.operator() < std::list<double>::iterator > (lst.begin(), lst.end());
	std::cout << res.first << " , " << res.second << std::endl;

}