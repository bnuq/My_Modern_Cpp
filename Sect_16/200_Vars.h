#pragma once
/*
	Header File ���� ���ǵ� ���� => �ش� ��������� �����ϴ� ��� cpp ���Ͽ��� ���ǵǾ� ���
	�� cpp file ���� ������� obj ���� => int global �� ���ǰ� ���� �� ���� => ��Ŀ ����

	One Definition Rule �� ����, ��������� ���� �� ���Ǵ� ��, �� �ȿ� ���ǰ� ������
	���ǰ� ������ ���̴� �Ͱ� ���Ƽ�

	�׷��� ���� ���Ǵ� �ѹ��� ���̴� cpp file, �ҽ� ���Ͽ� ����� �Ѵ�
*/
//int global;

// ������Ͽ��� extern ������ �˷��༭ => �ٸ� ������Ͽ��� �ڵ����� �ν��ϰ� �� �� �� �ִ�
extern int global;


/*
	C++ 17 ���� ���ʹ� inline keyword => extern ��� ���� �۷ι� ������ ������ �� �ִ�
	�׳� ������Ͽ� inline keyword �� �۷ι� ���� ����,
	�����ǰ� ������ �Ǿ ���Ǵ� �ѹ��� �����ϰ�
	�ڵ����� ���� �ٸ� �ҽ����Ͽ��� �ش� ������ ����� �� �ְ� �ȴ�
	unique throughout the program
*/
inline int global2 = 500;



class Test {
public:
	/*
		static member variable => class ��ü�� ���ϴ� ����
		�ݵ�� cpp ���� ���� ���Ǹ� ���־�� �Ѵ�, �����ǰ� ������ �����ϸ� �ȵǴϱ�
		violate one definition rule
		int Test::m_Data = 50;

		��� C++17 ���� ���ʹ� inline keyword �� ���ؼ�
		��� ���Ͽ��� ���Ǹ� �ϸ鼭, ���ÿ� ������ ������ ���� �� �ִ�
	*/
	inline static int m_Data = 50;

	// const expression member variable �� ���ؼ��� inline �� �ڵ����� ���Եȴ�
	constexpr static int PATHSIZE = 255;
	int x = 5;
};