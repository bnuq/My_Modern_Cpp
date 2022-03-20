#include <iostream>
class Integer {
public:
	int m_Value{ 100 };

	/*
		default keyword
		parameterized constructor ������ default ctor �� �ڵ����� ������ �ʴ� ���
		�����Ϸ��� �ڵ����� ������ִ� �����ڸ� ����ϰڴ� ~ �� ��
		non-static member variabele initialization �� �۵��Ѵ�
	*/
	Integer() = default;
	
	// parameterized constructor
	Integer(int value) {
		m_Value = value;
	}

	/*
		delete keyword
		�̷� ������ �Լ��� ������� �ʰڴ�, �ڵ����ε� ������ ����� ����
		copy ctor �� ����� �ƿ� ���ƹ��ȴ�
	*/
	Integer(const Integer&) = delete;
	Integer& operator =(const Integer&) = default; // copy ctor �� ���, copy operator �� ������ �� �ִ�
	
	void SetValue(int value) {
		m_Value = value;
	}
	// SetValue �Լ��� float type �� �޴� ��츦 => �ƿ� ���ֶ�, �ڵ����� float -> int ��ȯ �Ǵ� ���� ���ƶ�
	void SetValue(float) = delete;
};

int main() {
	Integer i1{};
	Integer i3{ 500 };
	i1 = i3; // copy operator ���
	/*
		copy ctor �� ����ϴ� ����
		delete �߱� ������, �ƿ� ���� ��ü�� �ȵȴ�
		Integer i2{ i1 };
		Integer i3 = i1;	copy operator ó�� ��������, �����ϸ鼭 ���� �ʱ�ȭ �ϴ� ���̱� ������ copy ctor �̴�
	*/

	std::cout << i1.m_Value << std::endl; // 100 ���

	i1.SetValue(5);		// int ����� ���� ����
	//Error as SetValue(float) is deleted
	//i1.SetValue(67.1f); // float -> int �ڵ� ��ȯ�� ����, �׳� flaot �� ������ ��Ȳ�� �ƿ� ����
	return 0;
}