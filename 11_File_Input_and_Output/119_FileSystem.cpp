#include <iostream>
// experimental �� ���� deprecated => �׳� filesystem ���
#include <filesystem>

int main()
{
	using namespace std::filesystem;
	
	// path �� ���� ������ ����, ������ �̷� ������ �����ϴ� ���� �˻����� �ʴ´�
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