#pragma once
#include <iostream>
class Integer {
	int *m_pInt;
public:
	//Default constructor
	Integer();
	//Parameterized constructor
	Integer(int value);
	//Copy constructor
	Integer(const Integer &obj);
	//Move constructor
	Integer(Integer &&obj);
	int GetValue()const;
	void SetValue(int value);
	~Integer();


	/*
		원래는 헤더파일에 정의가 들어오면 안된다
		헤더파일을 포함하는 cpp file 마다 정의를 하게 되고
		나중에 링커에 의해 obj 파일이 합쳐질 때 => 정의가 여러 개 발생하니까 문제
		
		근데 되는 이유?
		컴파일러가 자동으로 inline 처리 하는 듯?
		inline => 함수 본체가 소스코드에 그냥 들어간다
	*/
	void test() {
		std::cout << "Has a definition" << std::endl;
		return;
	}


	friend std::ostream & operator <<(std::ostream & out, const Integer &obj);
};
