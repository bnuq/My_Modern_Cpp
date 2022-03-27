#include <iostream>
#include <type_traits>


template <typename T>
T Divide(T a, T b) {
	/*
		type traits -> compile time �� Ÿ���� ���� �ľ�
		 
		static assert -> compile time �� expression �� ���� �򰡸� ������
	
		���� ���� ���� �̿��ϸ� ���� �ʴ� Ÿ�Կ� ���� �������� ���� �� �ִ�
	*/
	// �� expression == false �� ���, �� message �� �Բ� fail �� ����
	static_assert(std::is_floating_point<T>::value, "Use floating point types only");
		
	return a / b;
}


int main() {

	// �ƿ� �����ϱ� ���� ���� ǥ�ö߰ų�
	// static_assert(sizeof(void*) == 4, "It is not 32-bit Mode");
	
	// sizeof �������� ���
	// runtime, �� ���α׷��� ����ǰ� ���� ��,������ �����ȴ�
	if (sizeof(void*) != 4)
		std::cout << "It is not 32-bit Mode" << std::endl;


	// Divide(9, 3); ������ �ܰ迡�� ������ �߻���Ŵ
	std::cout << Divide(9.0f, 3.0f) << std::endl;
}