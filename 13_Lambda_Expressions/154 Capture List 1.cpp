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

	// Lambda Expression �� Function Object �� �� �ڸ��� �ٷ� ���� �� �ִ�
	// �Լ��� �ϴ� ���� �ٷ� �� �� �ִ� + ���� ����
	Sort(arr, [](auto x, auto y) {
		return x > y;
		});

	// auto �̿��ؼ� lambda expression ����
	auto lambdaComp = [](auto x, auto y) {
						return x < y;
						};
	Sort(arr, lambdaComp);

	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}



// �迭�� �� ���ҿ� ���ؼ�, Ư�� ������ �����ϴ� ���ø� �Լ�
template<typename T, int size, typename Callback>
void ForEach(T(&arr)[size], Callback operation) {
	for (int i = 0; i < size; i++)
		// �� �迭 ���ҿ� ���ؼ� operation �� �����Ѵ�
		operation(arr[i]);
}


int main()
{
	int arr[]{ 2,5,9,1,4 };
	// Lambda Expression �� ���� �־ ����
	ForEach(arr, [](auto x)
		{
			std::cout << x << " , ";
		});
	std::cout << std::endl;
	

	
	int offset = 5;
	/*
		capture list = [ ], ���ȣ
		�ٱ��� variable �� capture => ���ٿ��� ����� �� �ְ� �Ѵ�
		copy �ؼ� ���ٷ� �����´�

		�⺻������ ���� ǥ���� => const member function ���� �����Ǹ�
		capture list �� ���� ���� => member variable, copied by value �� �����ȴ�
		
		���� const function �̹Ƿ�, �⺻������ ĸ���� ���� �ٲ� �� ����
	*/
	ForEach(arr, [offset](auto x) {
			x += offset;
			std::cout << x << " , ";

			// ++offset; ĸó�� ���� �ٲ� ���� ����
		});
	std::cout << std::endl;


	/*
		ĸó�� ���� �ٲٱ� ���ؼ���, mutable �ϴٴ� ���� �˷��� �Ѵ�
		=> constness �� ���ŵȴ�
	*/
	ForEach(arr, [offset](auto x) mutable { // ĸó�� �� �ٲ� �� �ִٴ� �� �˸�
			x += offset;
			std::cout << x << " , ";

			++offset;
		});
	std::cout << std::endl;

	// Capture List �� �ѱ� ��, copy by value ~ ���� offset ���� ��ȭ ����
	std::cout << "offset is " << offset << std::endl;
}