#include <iostream>
#include <vector>

//Primary or base template
template<typename T, int columns>
class PrettyPrinter {
	T *m_pData;

public:
	PrettyPrinter(T *data) :m_pData(data) {
	}

	void Print() {
		std::cout << "Columns:" << columns << std::endl;
		std::cout << "{" << *m_pData << "}" << std::endl;
	}

	T * GetData() {
		return m_pData;
	}
};



/*
	Partial Specialization

	Specialization 인데, Template Arguments 중 일부분만 조건을 충족했을 때
	재정의하는 것

	여기서는 non-type template argument 가 80 일때를 재정의한다
*/
template<typename T> // 특정 조건이 된 template parameter 를 제외하고, 나머지는 리스트에 적는다
class PrettyPrinter<T, 80> { // non-type template argument 가 80 일 때
	T *m_pData;

public:
	PrettyPrinter(T *data) :m_pData(data) {
	}

	void Print() {
		std::cout << "Using 80 Columns"<< std::endl;
		std::cout << "{" << *m_pData << "}" << std::endl;
	}

	T * GetData() {
		return m_pData;
	}
};




// Smart Pointer 구현, RAII
template<typename T>
class SmartPointer {
	T *m_ptr;

public:
	SmartPointer(T *ptr) :m_ptr(ptr) {
	}

	T * operator ->() {
		return m_ptr;
	}

	T & operator *() {
		return *m_ptr;
	}

	~SmartPointer() {
		delete m_ptr;
	}
};



/*
	Partial Specialization for Array Type

	Template Argument 는 기존 정의와 일치하는데
	클래스가 heap 에 array 를 할당한 메모리를 사용하는 경우

	이런 경우에 대해서, 따로 표시를 할 수 있고
	따로 재정의할 수 있다
*/
template<typename T>
class SmartPointer<T[]> { // heap 에 array 를 할당한 리소스를 사용한다고 알림
	T *m_ptr;   

public:
	SmartPointer(T *ptr) :m_ptr(ptr) {

	}
	T & operator[](int index) {
		return m_ptr[index];
	}
	~SmartPointer() {
		delete[] m_ptr;
	}
};



int main() {
	int data = 800;
	PrettyPrinter<int, 10> p1{ &data }; // 일반적인 경우
	p1.Print();

	PrettyPrinter<int, 80> p2{ &data }; // Partial Specialization
	p2.Print();


	SmartPointer<int> s1{ new int{10} }; // 일반적인 사용
	std::cout << *s1 << std::endl;
	
	// heap 에 array 를 할당한 리소스를 사용하는 클래스 라는 걸 알림
	SmartPointer<int[]> s2{ new int[5]{ 1,2,3,4,5 } };
	
	std::cout << s2[0] << std::endl;
	std::cout << s2[2] << std::endl;
	return 0;
}