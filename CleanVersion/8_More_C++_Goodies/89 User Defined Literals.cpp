#include <iostream>

// � �Ÿ� �� ��Ÿ���� Ŭ����
class Distance {
	// ų�ι��� ������ �Ÿ��� �����Ѵ�
	long double m_kilometer{};
	
public:
	Distance(long double km) : m_kilometer{ km } {

	}

	long double getKm() const {
		return m_kilometer;
	}

	void setKm(long double val) {
		m_kilometer = val;
	}
};


/*
	User Defined Literals
	operator"" �� ����
	global function �� ����
	_ �� �����ϴ� ���ͷ��� ���� �� �ִ�
	_ �� �������� �ʾƵ� ���� ���� �ִµ�, ��� �߻��Ѵ�
*/
Distance operator"" _mi(long double val) { // val �� ���� ���� ���̶�� �濡�� _mi �� ����
	// ���� ���� ���� ų�ι��� ������ �ٲ㼭 ������ Distance �� �����Ѵ�
	// ���ͷ� �̶�� ��, ��� ���� �ǰ� ������ ��ȯ�۾��̴�
	return Distance{ val * 1.6 };
}
long double operator"" _mi_to_km(long double val) { // �׳� �ܼ��� ���� ���� ų�ι��� ������ �ٲٴ� ���ͷ�
	return val * 1.6;
}


int main() {
	Distance d1{ 10 };
	/*
		20.0 �� ���� ���̴�
		�׷��� _mi �� �ٿ��� ���� ���̶�� �� �˸���
		���ÿ� ų�ι��ͷ� ���� �ٲ� ��, ������ Distance �� ������ ������
	*/
	Distance d2{ 20.0_mi }; // copy constructor
	Distance d3{ 30.0_mi_to_km }; // para ctor

	std::cout << d2.getKm() << " : " << d3.getKm() << std::endl;
}