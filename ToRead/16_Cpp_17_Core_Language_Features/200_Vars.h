#pragma once
/*
	Header File 에서 정의된 변수 => 해당 헤더파일을 포함하는 모든 cpp 파일에서 정의되어 사용
	각 cpp file 에서 만들어진 obj 파일 => int global 의 정의가 여러 개 존재 => 링커 오류

	One Definition Rule 을 어긴다, 헤더파일은 여러 번 사용되는 데, 그 안에 정의가 있으면
	정의가 여러번 쓰이는 것과 같아서

	그래서 변수 정의는 한번만 쓰이는 cpp file, 소스 파일에 적어야 한다
*/
//int global;

// 헤더파일에서 extern 변수를 알려줘서 => 다른 헤더파일에서 자동으로 인식하게 할 수 도 있다
extern int global;


/*
	C++ 17 에서 부터는 inline keyword => extern 사용 없이 글로번 변수를 정의할 수 있다
	그냥 헤더파일에 inline keyword 로 글로벌 변수 정의,
	재정의가 여러번 되어도 정의는 한번만 진행하고
	자동으로 서로 다른 소스파일에서 해당 변수를 사용할 수 있게 된다
	unique throughout the program
*/
inline int global2 = 500;



class Test {
public:
	/*
		static member variable => class 전체에 속하는 변수
		반드시 cpp 에서 따로 정의를 해주어야 한다, 재정의가 여러번 등장하면 안되니까
		violate one definition rule
		int Test::m_Data = 50;

		대신 C++17 에서 부터는 inline keyword 를 통해서
		헤더 파일에서 정의를 하면서, 동시에 재정의 문제를 피할 수 있다
	*/
	inline static int m_Data = 50;

	// const expression member variable 에 대해서는 inline 이 자동으로 포함된다
	constexpr static int PATHSIZE = 255;
	int x = 5;
};