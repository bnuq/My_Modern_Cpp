#include "200_Vars.h"
/*
	�ذ� ��� �� �ϳ� = extern keyword ��� 
	�ѹ��� ���̴� �ҽ� ����, cpp file �� �۷ι� ������ ����
	�ٸ� �ҽ����Ͽ��� ����� �� extern keyword
	=> �ٸ� �ҽ� ���Ͽ��� ���ǵ� ������� ���� ���
*/
int global = 10;

void test() {
	global = 100;

	global2 = 200;
}