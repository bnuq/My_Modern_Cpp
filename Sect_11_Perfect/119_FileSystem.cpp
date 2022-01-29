#include <iostream>
// experimental 은 이제 deprecated => 그냥 filesystem 사용
#include <filesystem>

int main()
{
	using namespace std::filesystem;
	
	// path 에 대한 정보만 저장, 실제로 이런 파일이 존재하는 지는 검사하지 않는다
	// directory path
	path p{ R"(c:/Windows)" };
	if (p.has_filename())
		std::cout << p.filename() << std::endl;

	// file path
	path e{ R"(e:/temp/test.txt)" };
	if (e.has_filename())
		std::cout << e.filename() << std::endl;

	for (const auto& x : e)
		std::cout << x << std::endl;

	directory_iterator beg{ p };
	directory_iterator end{};
	while (beg != end)
	{
		std::cout << *beg << std::endl;
		++beg;
	}
}