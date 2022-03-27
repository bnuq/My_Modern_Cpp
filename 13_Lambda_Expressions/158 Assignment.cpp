#include <iostream>
#include <vector>
#include <list>

// Function Object

// 1. Max
template <typename T>
struct MaxFuncObj {
	T operator()(T x, T y) const { // �⺻������ function call operator �� const member function
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


// 4. QnA �� �ִ� �ڵ� �����ߴ�
template <typename T>
struct MinMaxFO { // iterator �� ������ ���� ������, �ּҰ��� �ִ밪�� ����

	/*
		���� �� ó�� ���� ����

		� STL �� iterator �� ���� �� �𸣹Ƿ�, auto �� �̿��� �޴´�
		std::pair<T, T> operator()(auto itrBegin, auto itrEnd) {

		auto �� �޾����� ������ � STL �� iterator �� �Դٰ� ����
		������ ó�� ����Ѵ�
		auto min{ *itrBegin };
		auto max{ *itrBegin };

		iterator �� �ε�ȣ �����ڸ� �������� �ʴ´�
		for (auto it = itrBegin; it != itrEnd; ++it) {
			if (*it < min) min = *it;
			if (*it > max) max = *it;
		}

		return std::make_pair<T, T>(min, max);
	}
	*/


	// ������ �ڵ�
	// ���ø� �ȿ��� �� ���ø� ��� => � iterator �� ���� �� �𸣹Ƿ�, template �� typename ���� �޴´�
	template<typename Iterator> // ���� ���� �� ������, STL �� iterator type �� ���� ���̶� ����
								// typename �� �̸��� Iterator �� �޴´�
	std::pair<T, T> operator()(Iterator itrBegin, Iterator itrEnd) { // operator function argument �� ���ؼ� template argument �� �߷��� �� �ִ�

		/*
			��� STL �� iterator �鿡�� value_type �̶�� ��� ������ ����
			value_type => iterator �� ����Ű�� ����� ������ Ÿ���� ����
			������ Ÿ���� typename ���� �޾� => Ÿ���̶�� ���� ���� �˸���
			���� �ش� Ÿ���� �̸�, min, max �� �̿��ؼ� ���� ����

			������ STL �� iterator Ÿ���� ���޵� ������ �˾ұ� ������ ������ �ڵ�
		*/
		typename Iterator::value_type min{ *itrBegin };
		typename Iterator::value_type max{ *itrBegin };

		
		// iterator ���� �ε�ȣ �����ڸ� �������� �ʴ´�
		for (auto it = itrBegin; it != itrEnd; ++it) {
			if (*it < min) min = *it;
			if (*it > max) max = *it;
		}

		return std::make_pair(min, max);
	}
};




int main() {

	// STL �� iterator Ÿ�Կ��� value_type �� �� ��
	typename std::vector<int>::iterator::value_type p{};

	
	
	// Lambda Expression �� �׿� �����ϴ� Function Object ���� �Ẹ��

	// 1. Max
	auto Max = [](auto x, auto y) {
		return (x > y) ? x : y;
	};
	//Class Template ���� �����ڰ� �ִٸ�, argument ���� template argument �� �߷��� �� �־�������
	//�׳� ���� ��쿣 �߷��� �� �����Ƿ� list �� �ݵ�� template argument �� ����� �Ѵ�
	MaxFuncObj<float> maxFO;
	std::cout << Max(3.4f, 7.6f) << std::endl;
	std::cout << maxFO(3.4f, 7.6f) << std::endl;



	// 2.
	auto Greater = [](auto x, auto y) -> bool	{ // lambda expression �� return type �� ���
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



	// 4. => iterator �� �ϴ� auto �� �׳� ���� �� �ִ�
	auto MinMax = [](auto itrBegin, auto itrEnd) {

		// iterator => ������ ó�� ���
		auto min{ *itrBegin };
		auto max{ *itrBegin };
		
		// iterator ���� �ε�ȣ �����ڸ� �������� �ʴ´�
		for (auto it = itrBegin; it != itrEnd; ++it) {
			if (*it < min) min = *it;
			if (*it > max) max = *it;
		}

		return std::make_pair(min, max);
	};
	MinMaxFO<double> minmaxFO;

	std::vector<int> vec{ 30, 20, 50, 40, 10 };
	std::list<double> lst{ 55.5, 11.1, 22.2, 33.3, 44.4 };



	// STL :: Vector :: iterator �� ���ؼ� �۵�
	auto [vecMin, vecMax] = MinMax(vec.begin(), vec.end());		// std::pair �� ���ؼ� Structured Binding ���
	std::cout << vecMin << " , " << vecMax << std::endl;

	vecMin = 0; vecMax = 0;

	std::tie(vecMin, vecMax) = minmaxFO(vec.begin(), vec.end()); // std::tie �� ���ؼ� Structured Binding ���� ���� ��������
	std::cout << vecMin << " , " << vecMax << std::endl;		 // �ٽ� Structured Binding �� ����� �� �ִ�
	


	// STL :: List :: iterator �� ���ؼ� �۵�
	auto [lstMin, lstMax] = MinMax(lst.begin(), lst.end());
	std::cout << lstMin << " , " << lstMax << std::endl;

	lstMin = 0; lstMax = 0;

	std::tie(lstMin, lstMax) = minmaxFO(lst.begin(), lst.end());
	std::cout << lstMin << " , " << lstMax << std::endl;




	// function object, function call operator Ÿ�� ��������� ��Ÿ���鼭 ����ϴ� ���
	// operator () �� ����� �����ش�
		// typename T = double, �̶�� �� function object ���� �� �̹� ���
									// typename Iterator = list<double>::iterator => lst.begin(), lst.end() �� function arguments �� ���ؼ� �� �� �ִ�
	auto [mmin, mmax] = minmaxFO.operator() < std::list<double>::iterator > (lst.begin(), lst.end());
	std::cout << mmin << " , " << mmax << std::endl;
}