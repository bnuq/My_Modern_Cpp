#include <iostream>
#include <vector>
#include <list>

const char * GetErrorMessage(int errorNo) {
	return "Empty";
}

// 1.
//typedef const char *(*PFN)(int);

// 2.
using PFN = const char *(*)(int);

void ShowError(PFN pfn){
	
}


// 1.
//typedef std::vector < std::list<std::string>> Names;


// 2. Alias Template
template<typename T>
using NamesT = std::vector<std::list<T>>;


// 3. ±×³É Type Alias
using Names = std::vector<std::list<std::string>>;

int main() {

	NamesT<std::string> namest;
	NamesT<NamesT<int>> namest2;

	Names names;
	Names nnames;

	PFN pfn = GetErrorMessage;
	ShowError(pfn);
	return 0;
}
