/*
	Weak Pointer
	shared pointer �� ����ϰ� �ϳ��� �޸𸮸� ���� ��ü�� �����ϰ� �ִ� ��Ȳ
	�׷���, underlying pointer �� �߰��� �ٸ� ��ü�� ���� ������ �� �� �ִ�
	�̷� ��Ȳ����
	shared pointer => ������ ��ü�� nullptr ���� ������, reference count �� �ϳ� ����
				   => underlying pointer �� �ش� �޸𸮴� �����ǰ�
				   => �ٸ� ��ü���� ������ �� �����ϰ� �ִ�
	weak pointer => underlying pointer, �ش� �޸𸮰� ������ �� �ִ�
				 => �����ϴ� �ٸ� ��ü����, ����ϱ� ���� �ش� �޸𸮰� ��ȿ�� �� �ƴ� ���� �Ǵ��� �� �ִ�
*/
#include <iostream>

class Printer {
	/*
		int �� �����ϴ� weak pointer
		shared pointer �� ���ؼ� => underlying pointer �� �����Ѵ�
		���� shared pointer �� reference count �� Ȯ�� => underlying pointer �� ��ȿ�� �� �ƴ� ���� �� �� �ִ�
	*/
	std::weak_ptr<int> m_pValue{};

public:
				  // shared pointer �� �����鼭, weak pointer ����
	void SetValue(std::weak_ptr<int> p) {
		m_pValue = p; // weak pointer copy
	}
	void Print() {
		// weak pointer ������ use_count method ��� ���� => �����ϰ� �ִ� shared pointer ���� üũ
		std::cout << "Reference Count : " << m_pValue.use_count() << std::endl;
		
		// weak pointer �� �����ϰ� �ִ� shared pointer �� ���ؼ�, �����Ϸ��� �޸��� ��ȿ���� üũ�� �� �ִ�
		// shared pointer �� underlying resource �� �̹� �����ƴٸ�, expired() => true �� ���´�
		if (m_pValue.expired()) {
			std::cout << "Reference Count : " << m_pValue.use_count() << std::endl;
			std::cout << "Resource is no longer available" << std::endl;
			return;
		}
		else {
			// ��ȿ�ϴٸ�, ���� ���ҽ��� ������ �� �ִµ�
			// weak pointer �� �״�� ������� �ʰ�
			// ���ҽ��� �����ϴ� shared pointer �� �ϳ� ���� ���� �����Ѵ� => reference count �� �ϳ� ������
			// lock() method => shared pointer �ϳ��� ����� ����
			auto sp = m_pValue.lock();
			std::cout << "Value is " << *sp << std::endl;
			
			// sp �� Ȯ���ϳ� m_pValue �� Ȯ���ϳ�, �Ѵ� ���� ���ҽ��� �����ϴ�
			// shared pointer �� Ȯ���ϱ� ������, ���� ����� ���´�
			std::cout << "Reference Count : " << sp.use_count() << std::endl;
			std::cout << "Reference Count : " << m_pValue.use_count() << std::endl;
		}
	}
};


int main() {
	Printer prn{};
	
	int num{};
	std::cin >> num;

	std::shared_ptr<int> p{ new int{num} };

	// weak pointer ������ ���ؼ� shared pointer �� �ѱ�
	prn.SetValue(p);

	// ���� num ���ڰ� 10 �� �ѱ�� ���, ���ҽ��� �����ع�����
	if (*p > 10) p = nullptr; // shared pointer �� ���ҽ��� �����Ѵ�

	// �׸��� �����Ϳ��� ��� => �����Ϳ��� ���ҽ��� �����ƴ� �� Ȯ���ϰ�, �������� �ʾ��� ���� ����ϰ� �Ѵ�
	prn.Print();
}