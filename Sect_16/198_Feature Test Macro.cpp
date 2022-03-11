#include <iostream>

// ifdef = if not defined, 이하의 내용이 정의된적이 없다면
#ifdef __has_include
	// filesystem header file 이 사용 가능하다면, include 시킬 수 있다면
//#	if __has_include(<filesystem>)
#	if __has_include(<windows.h>) // 윈도우 환경인지 확인할 수 있다
#		include <filesystem> // <filesystem> header 를 포함시키도
		namespace fs = std::filesystem; // namespace 도 사용한다
#	else // <filesystem> 이 사용 불가능 하다면,
#		include <experimental/filesystem> // experimental header file 사용
#		namespace fs = std::experimental::filesystem;
#	endif
#endif

int main() {
	fs::path p{ "C:" };

	// 특정 cpp 기능이 사용가능한지 아닌지를 알 수 있다 => 추가된 년도/월 을 값으로 저장
	std::cout << __cpp_inline_variables << std::endl;
	std::cout << __cpp_capture_star_this << std::endl;
}