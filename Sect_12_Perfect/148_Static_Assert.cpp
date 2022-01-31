#include <iostream>

template <typename T>
T Divide(T a, T b)
{
	// type traits �� compile time �� �����ǰ� static assert �� ������ Ÿ�� �� ��, ���� ������
	// ���� ���� ���� �̿��ϸ� ���� �ʴ� Ÿ�Կ� ���ؼ��� �������� ���� �� �ִ�
	static_assert(std::is_floating_point<T>::value, "Use floating point types only");

	// floating point type �� ���ؼ��� �������� �����ϰ� �ϰ� �ʹ�
	// �׷��� metaprogramming �� �� ���δ�~
	//if (std::is_floating_point<T>::value == false)
	//{
	//	std::cout << "Use floating point types only" << std::endl;
	//	return 0;
	//}
	//else
	
	return a / b;
}


int main()
{
	// static assertion, compile time �� �����ȴ�
	// = ���α׷� �����ϱ� ���� ��, ���� ���θ� �� �� �ִ�
	// message �� �Բ� ����, false �� ��� �����ϵ��� ������ message ���
	// �ƿ� �����ϱ� ���� ���� ǥ�ö��
	static_assert(sizeof(void*) == 4, "It is not 32-bit Mode");
	
	// runtime, �� ���α׷��� ����ǰ� ���� ��,������ �����ȴ�
	if (sizeof(void*) != 4)
		std::cout << "It is not 32-bit Mode" << std::endl;


	//Divide(9, 3);
	std::cout << Divide(9.0f, 3.0f) << std::endl;
}