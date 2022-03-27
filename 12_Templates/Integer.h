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
		������ ������Ͽ� ���ǰ� ������ �ȵȴ�
		��������� �����ϴ� cpp file ���� ���Ǹ� �ϰ� �ǰ�
		���߿� ��Ŀ�� ���� obj ������ ������ �� => ���ǰ� ���� �� �߻��ϴϱ� ����
		
		�ٵ� �Ǵ� ����?
		�����Ϸ��� �ڵ����� inline ó�� �ϴ� ��?
		inline => �Լ� ��ü�� �ҽ��ڵ忡 �׳� ����
	*/
	void test() {
		std::cout << "Has a definition" << std::endl;
		return;
	}


	friend std::ostream & operator <<(std::ostream & out, const Integer &obj);
};
