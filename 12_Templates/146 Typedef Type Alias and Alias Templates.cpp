#include <iostream>
#include <vector>
#include <list>


// ������ function
const char* GetErrorMessage(int errorNo) {
	return "Empty";
}


/*
	typedef

	�̹� �����ϴ� Ÿ�Կ� ������ �̸��� �ο�
	���� ���
*/
typedef unsigned int typedefUInt;
typedef const char *(*typedefPEN)(int); // function pointer �� ���, ��ȣ �ȿ� typedef �̸��� ����
typedef std::vector < std::list<std::string>> typedefNames;



/*
	Type Alias

	���� �����ϴ� Ÿ�Կ� ������ �̸��� �ο�
	using �� ���
	�� ���� ����
*/
using UInt = unsigned int;
using PFN = const char *(*)(int); // function pointer �� ��쿡�� ���� ����
using Names = std::vector<std::list<std::string>>;

// Type Alias �� ������ ��
void ShowError(PFN pfn){
	
}



/*
	Alias Template

	Type Alias + Template
	���ø��� �޴� Ÿ�� �� ���ؼ� ~
	Template Parameter �� �̿��ϴ� Ÿ�Կ� Type Alias �� ������ �� �ִ�
*/
template<typename T>
using NamesT = std::vector<std::list<T>>;




int main() {

	// Type Alias �̿�
	PFN pfn = GetErrorMessage;
	ShowError(pfn);
	Names names;

	
	// Alias Template �̿�
	// �̿��ϰ� ���� Ÿ���� �־ => ���ο� Ÿ���� ���� �� �ִ�
	// �ٵ� ������ �̸��� ����� �� �ִ�
	NamesT<std::string> namest{};
	NamesT<NamesT<int>> namest2{};
	// NamesT namest3{}; typename T �� ������ ���� ����


	return 0;
}
