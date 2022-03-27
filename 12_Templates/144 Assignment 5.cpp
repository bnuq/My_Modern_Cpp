#include <iostream>
#include <vector>


// Primary Class Template
template<typename T>
class PrettyPrinter {
	T* m_pData;
public:
	PrettyPrinter(T* data) :m_pData(data) {

	}
	void Print() {
		std::cout << "{" << *m_pData << "}" << std::endl;
	}

	T* GetData() {
		return m_pData;
	}
};


// Explicit Specialization for std::vector< std::vector<int> >
// Print() member function 하나에 대해서만 진행
template<>
void PrettyPrinter<std::vector< std::vector<int> >>::Print() {

	std::cout << "{" << std::endl;
	for (const auto& vec : *m_pData) {
		for (const auto& x : vec) {
			std::cout << x;
		}
		std::cout << std::endl;
	}
	std::cout << "}" << std::endl;
}



int main() {

	std::vector<std::vector<int>> vec{ {1,2,3}, {4,5,6}, {7,8,9} };
	PrettyPrinter{ &vec }.Print();


	return 0;
}