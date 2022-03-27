#include "200_Vars.h"
/*
	해결 방법 중 하나 = extern keyword 사용 
	한번만 쓰이는 소스 파일, cpp file 에 글로벌 변수를 정의
	다른 소스파일에서 사용할 때 extern keyword
	=> 다른 소스 파일에서 정의된 변수라는 것을 명시
*/
int global = 10;

void test() {
	global = 100;

	global2 = 200;
}