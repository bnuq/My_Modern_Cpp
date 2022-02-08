#include <iostream>
//using Comparator = bool(*)(int, int);
template<typename T, int size, typename Comparator>
void Sort(T(&arr)[size], Comparator comp) {
	for (int i = 0; i < size-1; ++i) {
		for (int j = 0; j < size - 1; ++j) {
			if (comp(arr[j], arr[j + 1])) {
				T temp = std::move(arr[j]);
				arr[j] = std::move(arr[j + 1]);
				arr[j + 1] = std::move(temp);
			}
		}
	}
}
bool Comp(int x, int y) {
	return x > y;
}
bool Comp1(int x, int y) {
	return x < y;
}
struct Comp2 {
	bool operator()(int x, int y) {
		return x > y;
	}
};

template<typename T, int size, typename Callback>
void ForEach(T(&arr)[size], Callback operation) {
	for (int i = 0; i < size - 1; ++i) {
		operation(arr[i]);
	}
}

// Lambda Expression 이 내부적으로 구현될 Function Object 모습
template<typename T>
struct __Unnamed {
	int offset;
	__Unnamed(int off) :offset(off) {

	}
	void operator()(T &x) /*const*/ {
		x += offset;
		++offset;
	}
};



class Product {
	std::string name;
	float price;
public:
	Product(const std::string &n, float p) :name(n), price(p) {

	}
	void AssignFinalPrice() {
		float taxes[]{ 12, 5, 5 };
		float basePrice{ price };
		//Capture this
		ForEach(taxes, [basePrice, this](float tax) {
			float taxedPrice = basePrice * tax / 100;
			price += taxedPrice;
		});
	}
	float GetPrice()const {
		return price;
	}
};



int main() {

	// Function Object 이용
	__Unnamed<int> n(3);
	int x = 5;
	n(x);


	
	// Lambda Expression 이용
	int arr[]{ 1,6,8,4,0 };
	// 그대로 출력
	ForEach(arr, [](auto x) {
		std::cout << x << " ";
	});
	std::cout << std::endl;

	int offset = 0;
	ForEach(arr, [offset](auto &x) {
		x += offset;
	});
	ForEach(arr, [offset](auto &x)mutable {
		x += offset;
		++offset;
	});

	
	
	// Caputure List => 출력하는 방법
	// reference 이용, caputure by reference
	int sum{};
	ForEach(arr, [&sum](auto& x) {
		sum += x;
		});
	std::cout << "Sum is " << sum << std::endl;


	// 변수를 모두 capture by reference
	// sum 이 내부 멤버 변수가 아니니까, 변경 가능
	ForEach(arr, [&](auto& x) {
		sum += x;
		});
	std::cout << "Sum is " << sum << std::endl;


	// 모두 capture by value
	ForEach(arr, [=](auto& x) mutable {
		sum += x;
		});
	std::cout << "Sum is " << sum << std::endl;



	// caputure 방식을 각각 지시
	sum = 0;
	ForEach(arr, [&, offset](auto &x) {
		sum += x;
	});
	std::cout << "Sum:" << sum << std::endl;



	return 0;
}

