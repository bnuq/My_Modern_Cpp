#include <iostream>

// Primary Template
template<typename T>
T Max(T x, T y) {
	// typeid :: name() => Ÿ�� �̸��� ����
	std::cout << typeid(T).name() << std::endl;
	return x > y ? x : y;
}


/*
	Explicit Instantiation
	
	���ø�����, Ư�� Ÿ���� �޴� ��쿡 ���ؼ� �̸� Instantiation �ϴ� ��
	�ش� Ÿ���� �޴� ���ø� �Լ��� �����̷��� �̸� ����� ������ �Ѵ�
	template �� ���� template argument list, < > �� ���� �ʴ´�
	������� �ϴ� Ư�� Ÿ���� �־, �Լ� �ñ״�ó�� ����
*/
// char Ÿ���� �޴� Max �Լ��� ���� ����� �����Ѵ�
// �� �Լ��� ȣ������ �ʾƵ�, �����Ϸ��� ���ؼ� ������ ���������
// ���� �� ���� �ݵ�� ������Ͽ� �����ؾ� �Ѵ�
template 
char Max(char x, char y);


/*
	Explicit Specialization

	Ư�� Ÿ���� �޴� ��쿡 ���ؼ���, ���ø� �Լ��� �������Ѵ�
	template + empty template argument list, <>
	�׸��� �ڿ� Ư���� �������ϰ��� �ϴ� Ÿ���� ���´�

	�ϴ� �Ϲ� ���ø� �Լ� ���Ƿ� �ش� Ÿ���� ���� ���� Instantiation �� ������
	Explicit Specialization �� ����
	���� ��������� �ƴ�, cpp file �� ���ǰ� ���� �Ѵ�

	ȣ������ �ʾƵ� �����Ϸ��� �̸� �����, Instantiation �� �ϱ� ������
	������ ������Ͽ� �����ؾ� �Ѵ�

	template<>
	const char* Max(const char* x, const char* y) �� ���� ���
		const char* Ÿ�Կ� ���ؼ� ���ø� �Լ��� ������
*/

template<>
				// �Լ� �̸� �ڿ� < type > �� �߰��ؼ�, ���� Ÿ���� ��Ȯ�ϰ� ����� �� �ִ�
				// �� ��� arguments ���� �߷��� �ʿ� ���� �ٷ� ���� Ÿ���� �� �� �ִ�
const char* Max<const char*>(const char* x, const char* y) {
	std::cout << "Max<const char*>()" << std::endl;
	return strcmp(x, y) > 0 ? x : y; // string compare
}



int main() {
	/*
		Template Argument Deduction
		���ø� �Լ��� Arguments �� ���ؼ�, �ش� ���ø� �Լ��� �ʿ�� �ϴ� Ÿ���� �˾Ƴ��� ����
		�ڵ� Ÿ�� ��ȯ ����, �ݵ�� �����־�� �Ѵ�
	*/
	// T type �� �ϳ�, �����ֱ�
	Max(static_cast<float>(3), 6.3f);


	// �ƴϸ� template argument list �� �̿�
	// ��������� Ÿ�� ���� => �ش� Ÿ���� ���� ���ø� �Լ��� ����� ������
	// �� ��� Ÿ���� Ȯ���ϰ� �����ǹǷ�, arguments ���� �ڵ� Ÿ�� ��ȯ�� �����ϴ�
	Max<double>(3, 5.3f);


	// function pointer �̿� => ���ø� �Լ��� ����Ų�ٸ�
	// �ش� Ÿ���� ������ ���ø� �Լ��� �ݵ�� ����� ���� => Instantiation �߻�
	int (*pfn)(int, int) = Max;


	const char* a{ "A" };
	const char* b{ "B" };

	// Arguments �� ���ؼ� const char* �� �޴� Max �Լ��� �ʿ��ϴٴ� ���� Ȯ����
	// �����Ϸ��� ���� ������� => Instantiation
	std::cout << Max(a, b) << std::endl;

	return 0;
}
