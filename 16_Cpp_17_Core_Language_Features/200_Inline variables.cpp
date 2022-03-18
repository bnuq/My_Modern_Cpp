#include "200_Vars.h"
// 다른 소스 파일에서 정의된 변수를 사용한다고 알림
// 여기서는 선언, 알림 => 초기화 불가능
//extern int global; == 헤더파일에서 미리 선언한 경우, 소스 파일에서는 필요 없다

#include <iostream>

int main() {
	global = 100;
	std::cout << global << std::endl;

	std::cout << global2 << std::endl;

	Test t{};
	std::cout << t.x << std::endl;
	std::cout << Test::m_Data << std::endl;
}