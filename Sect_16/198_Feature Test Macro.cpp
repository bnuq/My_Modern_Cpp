#include <iostream>

// ifdef = if not defined, ������ ������ ���ǵ����� ���ٸ�
#ifdef __has_include
	// filesystem header file �� ��� �����ϴٸ�, include ��ų �� �ִٸ�
//#	if __has_include(<filesystem>)
#	if __has_include(<windows.h>) // ������ ȯ������ Ȯ���� �� �ִ�
#		include <filesystem> // <filesystem> header �� ���Խ�Ű��
		namespace fs = std::filesystem; // namespace �� ����Ѵ�
#	else // <filesystem> �� ��� �Ұ��� �ϴٸ�,
#		include <experimental/filesystem> // experimental header file ���
#		namespace fs = std::experimental::filesystem;
#	endif
#endif

int main() {
	fs::path p{ "C:" };

	// Ư�� cpp ����� ��밡������ �ƴ����� �� �� �ִ� => �߰��� �⵵/�� �� ������ ����
	std::cout << __cpp_inline_variables << std::endl;
	std::cout << __cpp_capture_star_this << std::endl;
}