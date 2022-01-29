#include <iostream>
#include <string>

int main()
{
	// escape sequence
	std::string oldfilename{ "C\\temp\\newfile.txt" };
	std::cout << oldfilename << std::endl;

	// raw string literal
	std::string filename{ R"(C\temp\newfile.txt)"};
	std::cout << filename << std::endl;

	// with delimiter
	std::string message{ R"msgg(C++ indroduced filesystem API"(In C++17)")msgg" };
	std::cout << message << std::endl;


	return 0;
}