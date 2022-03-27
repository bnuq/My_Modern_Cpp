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
	//Copy Assignment Operator
	Integer& operator=(const Integer& obj);


//Move Operation => noexcept 를 지정해준다
	//Move constructor
	Integer(Integer &&obj) noexcept;
	//Move Assignment Operator
	Integer& operator=(Integer&& obj) noexcept;




	int GetValue()const;
	void SetValue(int value);
	~Integer();

	friend std::ostream & operator <<(std::ostream & out, const Integer &obj);
};
