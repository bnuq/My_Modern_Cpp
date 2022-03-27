#include <iostream>
#include <vector>


// Primary Class Template
template<typename T>
class PrettyPrinter {
	T* m_pData;

public:
	// Parapmeterized Constructor
	// Function Parameter Type = T*
	// Template Parameter Type = T -> 서로 다르다, 유추 해낼 수 없다
	PrettyPrinter(T* data) :m_pData(data) {

	}

	void Print() {
		std::cout << "{" << *m_pData << "}" << std::endl;
	}

	T* GetData() {
		return m_pData;
	}
};


/*
	Explicit Specialization in Class Template
	 
	특정 타입에 대해서만, 클래스 템플릿을 재정의
	재정의 내용은 cpp file 에 작성

	for const char* type
 */
template<> // template Parameter 가 정해져 있으므로 => template argument 를 비워둔다 + 타입을 완전히 지정
class PrettyPrinter<const char*> {
	const char *m_pData; // 특별히 이 경우에만 T 를 저장하게 해

public:
	/*
		typename T = const char* 인 경우에는
		Template Parameter = Function Parameter = const char* 이다
	*/
	PrettyPrinter(const char* data) :m_pData(data) {

	}
	void Print() {
		// const char* type 에 대해서는 적용이 다르다
		std::cout << "{" << m_pData << "}" << std::endl;
	}
	// 역시 이 타입일 때만, GetData() 리턴 타입이 typename 과 같다
	const char* GetData() {
		return m_pData;
	}
};


/*
	Class Template Explicit Specialization
	for Vector<int> Type
*/
//template<>
//class PrettyPrinter<std::vector<int>> {
//	std::vector<int> *m_pData;
// 
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



/*
	전체 클래스 템플릿에 대해서가 아닌
	Member function 하나에 대해서만 explicit specialization 이 가능하다
	
	Explicit specialization of a member function should appear outside the class
	cpp file 에 작성
*/
template<>
void PrettyPrinter<std::vector<int>>::Print() { // 특정 타입의 멤버 함수에만 접근
	std::cout << "{";

	for (const auto& x : *m_pData) {
		std::cout << x;
	}

	std::cout << "}" << std::endl;
}




int main() {
	
	// Primitive Type 사용
	int data = 5;
	float f = 8.2f;
	PrettyPrinter<int> p1(&data);
	p1.Print();
	PrettyPrinter<float> p2(&f);
	p2.Print();
	

	// For const char* type
	const char* p{ "Hello World" };	// p 에 저장된 건 string 's 첫번째 문자 address
	std::cout << p << std::endl;	// 주소 출력 아니고, 문자열 출력
	std::cout << *p << std::endl;	// 문자열 첫번째 문자 출력

	/*
		Specialization 전에는 const char* 타입에서도 똑같이 사용한다
	
		const char** 타입을 function arguments 로 넘기고 사용
		PrettyPrinter<const char*> p3{ &p };
		p3.Print();

		GetData() 리턴 타입은 const char**
		const char** pData = p3.GetData();
		std::cout << *pData << std::endl;

	*/


	// Explicit Specialization for const char* 후에는, 용법이 달라진다
	// 재정의 했으니까
	//PrettyPrinter<const char*> p3{ p };
	PrettyPrinter p3{ p }; // template argument type = function argument type => 유추 가능 => 리스트 없어도 된다
	p3.Print();
	const char* pData = p3.GetData();
	std::cout << pData << std::endl;


	std::vector<int> v{ 1,2,3,4,5 };
	PrettyPrinter<std::vector<int>> pv(&v);
	
	// vector<int> type 에 대해서는, Print() member function 만 재정이 됐다
	pv.Print();


	return 0;
}