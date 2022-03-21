#include <iostream>
#include <vector>


// Primary Class Template
template<typename T>
class PrettyPrinter {
	T* m_pData;

public:
	// Parapmeterized Constructor
	// Function Parameter Type = T*
	// Template Parameter Type = T -> ���� �ٸ���, ���� �س� �� ����
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
	 
	Ư�� Ÿ�Կ� ���ؼ���, Ŭ���� ���ø��� ������
	������ ������ cpp file �� �ۼ�

	for const char* type
 */
template<> // template Parameter �� ������ �����Ƿ� => template argument �� ����д� + Ÿ���� ������ ����
class PrettyPrinter<const char*> {
	const char *m_pData; // Ư���� �� ��쿡�� T �� �����ϰ� ��

public:
	/*
		typename T = const char* �� ��쿡��
		Template Parameter = Function Parameter = const char* �̴�
	*/
	PrettyPrinter(const char* data) :m_pData(data) {

	}
	void Print() {
		// const char* type �� ���ؼ��� ������ �ٸ���
		std::cout << "{" << m_pData << "}" << std::endl;
	}
	// ���� �� Ÿ���� ����, GetData() ���� Ÿ���� typename �� ����
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
	��ü Ŭ���� ���ø��� ���ؼ��� �ƴ�
	Member function �ϳ��� ���ؼ��� explicit specialization �� �����ϴ�
	
	Explicit specialization of a member function should appear outside the class
	cpp file �� �ۼ�
*/
template<>
void PrettyPrinter<std::vector<int>>::Print() { // Ư�� Ÿ���� ��� �Լ����� ����
	std::cout << "{";

	for (const auto& x : *m_pData) {
		std::cout << x;
	}

	std::cout << "}" << std::endl;
}




int main() {
	
	// Primitive Type ���
	int data = 5;
	float f = 8.2f;
	PrettyPrinter<int> p1(&data);
	p1.Print();
	PrettyPrinter<float> p2(&f);
	p2.Print();
	

	// For const char* type
	const char* p{ "Hello World" };	// p �� ����� �� string 's ù��° ���� address
	std::cout << p << std::endl;	// �ּ� ��� �ƴϰ�, ���ڿ� ���
	std::cout << *p << std::endl;	// ���ڿ� ù��° ���� ���

	/*
		Specialization ������ const char* Ÿ�Կ����� �Ȱ��� ����Ѵ�
	
		const char** Ÿ���� function arguments �� �ѱ�� ���
		PrettyPrinter<const char*> p3{ &p };
		p3.Print();

		GetData() ���� Ÿ���� const char**
		const char** pData = p3.GetData();
		std::cout << *pData << std::endl;

	*/


	// Explicit Specialization for const char* �Ŀ���, ����� �޶�����
	// ������ �����ϱ�
	//PrettyPrinter<const char*> p3{ p };
	PrettyPrinter p3{ p }; // template argument type = function argument type => ���� ���� => ����Ʈ ��� �ȴ�
	p3.Print();
	const char* pData = p3.GetData();
	std::cout << pData << std::endl;


	std::vector<int> v{ 1,2,3,4,5 };
	PrettyPrinter<std::vector<int>> pv(&v);
	
	// vector<int> type �� ���ؼ���, Print() member function �� ������ �ƴ�
	pv.Print();


	return 0;
}