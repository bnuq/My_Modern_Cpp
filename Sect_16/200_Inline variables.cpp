#include "200_Vars.h"
// �ٸ� �ҽ� ���Ͽ��� ���ǵ� ������ ����Ѵٰ� �˸�
// ���⼭�� ����, �˸� => �ʱ�ȭ �Ұ���
//extern int global; == ������Ͽ��� �̸� ������ ���, �ҽ� ���Ͽ����� �ʿ� ����

#include <iostream>

int main() {
	global = 100;
	std::cout << global << std::endl;

	std::cout << global2 << std::endl;

	Test t{};
	std::cout << t.x << std::endl;
	std::cout << Test::m_Data << std::endl;
}