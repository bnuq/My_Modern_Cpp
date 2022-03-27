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

	Specialization �ε�, Template Arguments �� �Ϻκи� ������ �������� ��
	�������ϴ� ��

	���⼭�� non-type template argument �� 80 �϶��� �������Ѵ�
*/
template<typename T> // Ư�� ������ �� template parameter �� �����ϰ�, �������� ����Ʈ�� ���´�
class PrettyPrinter<T, 80> { // non-type template argument �� 80 �� ��
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




// Smart Pointer ����, RAII
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

	Template Argument �� ���� ���ǿ� ��ġ�ϴµ�
	Ŭ������ heap �� array �� �Ҵ��� �޸𸮸� ����ϴ� ���

	�̷� ��쿡 ���ؼ�, ���� ǥ�ø� �� �� �ְ�
	���� �������� �� �ִ�
*/
template<typename T>
class SmartPointer<T[]> { // heap �� array �� �Ҵ��� ���ҽ��� ����Ѵٰ� �˸�
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
	PrettyPrinter<int, 10> p1{ &data }; // �Ϲ����� ���
	p1.Print();

	PrettyPrinter<int, 80> p2{ &data }; // Partial Specialization
	p2.Print();


	SmartPointer<int> s1{ new int{10} }; // �Ϲ����� ���
	std::cout << *s1 << std::endl;
	
	// heap �� array �� �Ҵ��� ���ҽ��� ����ϴ� Ŭ���� ��� �� �˸�
	SmartPointer<int[]> s2{ new int[5]{ 1,2,3,4,5 } };
	
	std::cout << s2[0] << std::endl;
	std::cout << s2[2] << std::endl;
	return 0;
}