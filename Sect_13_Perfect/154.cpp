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
// �Ϲ����� Uder defined data type �ε�
struct objCompInc {
	// functino call operator �� �����Ѵ�
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

	// Lambda Expression �� Function Object �� �ٷ� ���� �ִ´�
	// �Լ��� �ϴ� ���� �ٷ� �� �� �ִ�
	// ���� ����
	Sort(arr, [](auto x, auto y) {
		return x > y;
		});

	// auto �̿��ؼ� �̸����̱�
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
void ForEach(T(&arr)[size], Callback operation)
{
	for (int i = 0; i < size; i++)
		// �� �迭 ���ҿ� ���ؼ� operation �� �����Ѵ�
		operation(arr[i]);
}

int main()
{
	int arr[]{ 2,5,9,1,4 };
	
	// �ٷ� Lambda Expression �� �־ ����
	ForEach(arr, [](auto x)
		{
			std::cout << x << " , ";
		});
	std::cout << std::endl;

	
	
	int offset = 5;
				 // capture list ���� �ٱ��� offset variable �� capture => ���ٿ��� ��밡���ϰ� �Ѵ�
				 // copy �ؼ� ���ٷ� �����´�
				 // �⺻������ ���� ǥ���� => const function call operator �� ����
				 // capture list => member variable, caputred by value
				 // const function �̴ϱ� ��� ���� �ٲ� �� ����
	ForEach(arr, [offset](auto x)
		{
			x += offset;
			std::cout << x << " , ";

			// ++offset;
		});
	std::cout << std::endl;


	// ��� ���� �ٲٷ���, mutable => constness �� ���ŵȴ�
	// offset �� copy �� ���� �Ѿ ~ ���� offset ���� ��ȭ ����
	ForEach(arr, [offset](auto x) mutable
		{
			x += offset;
			std::cout << x << " , ";

			++offset;
		});
	std::cout << std::endl;

	std::cout << "offset is " << offset << std::endl;
}