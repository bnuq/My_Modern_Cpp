#include <iostream>
#include <vector>

// Primary Class Template
template<typename T>
class PrettyPrinter {
	T *m_pData;
public:
	PrettyPrinter(T *data) :m_pData(data) {

	}
	void Print() {
		std::cout << "{" << *m_pData << "}" << std::endl;
	}

	T * GetData() {
		return m_pData;
	}
};

// Explicit Specialization for const char* type
// template argument 를 비워둔다 + 타입을 완전히 지정
template<>
class PrettyPrinter<const char*> {
	const char *m_pData; // 특별히 이 경우에만 T 를 저장하게 해
public:
	PrettyPrinter(const char *data) :m_pData(data) {

	}
	void Print() {
		std::cout << "{" << m_pData << "}" << std::endl;
	}
	const char * GetData() {
		return m_pData;
	}
};


// vector type 에 대해서, 전체 specialization 한 경우
//template<>
//class PrettyPrinter<std::vector<int>> {
//	std::vector<int> *m_pData;
//public:
//	PrettyPrinter(std::vector<int> *data) :m_pData(data) {
//
//	}
//	void Print() {
//		std::cout << "{";
//		for (const auto &x : *m_pData) {
//			std::cout << x;
//		}
//		std::cout << "}" << std::endl;
//	}
//	std::vector<int> * GetData() {
//		return m_pData;
//	}
//};

// Member function 하나에 대해서만 specialization
//Explicit specialization of a member function should appear outside the class
template<>
void PrettyPrinter<std::vector<int>>::Print() {
	std::cout << "{";
	for (const auto& x : *m_pData) {
		std::cout << x;
	}
	std::cout << "}" << std::endl;
}

int main() {
	
	//int data = 5;
	//float f = 8.2f;
	//PrettyPrinter<int> p1(&data);
	//p1.Print();
	//PrettyPrinter<float> p2(&f);
	//p2.Print();
	

	const char* p{ "Hello World" };	// p 에 저장된 건 string 's 첫번째 문자 address
	std::cout << p << std::endl;	// 주소 출력 아니고, 문자열 출력
	std::cout << *p << std::endl;	// 문자열 첫번째 문자 출력

	//Specialization 전
	//PrettyPrinter<const char*> p3{ &p };	// 문자열 주소를 저장한 p 를 가리키는 p3
	//p3.Print();
	//const char** pData = p3.GetData();	// p3 가 가리키는 곳을 똑같이 가리키는 pData
	//std::cout << *pData << std::endl;

	// Specialization 후
	PrettyPrinter<const char*> p3{ p };
	p3.Print();
	const char* pData = p3.GetData();


	std::vector<int> v{ 1,2,3,4,5 };
	PrettyPrinter<std::vector<int>> pv(&v);
	pv.Print();


	return 0;
}