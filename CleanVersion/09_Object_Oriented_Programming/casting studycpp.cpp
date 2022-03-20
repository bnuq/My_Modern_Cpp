

class Base {
public:
	Base() = default;
	virtual ~Base() = default;
};

class Child : public Base {

};

int main() {
	Base base{};
	Child child{};

	// Object Slicing
	Base anoBase = child; // child attribute �� �� ���ư���, Base �κи� ����

	// Upcast
	// Base pointer, reference �� Base �� �����޴� �ƹ� Ŭ������ �� ����Ű�� ��
	// ������ ����Ű�� ���� ������, Base Class Type �κ��� �����ϰ� �ִٸ� ����ų �� �ִ�
	// Child Class Type ���� Base Class Type �κп��� �����ϴ� ��
	Base* pBase = &child;
	Base& refBase = child;

	// Downcast
	// Base pointer, reference �� ������ ����Ű�� �� ������
	// �װ��� Ư�� �ڽ� Ŭ������ ����Ų�ٰ� �����ϴ� ��
	// �ణ �����ϴ� ����, ���� ����Ű�� �ִ� �� � Child �ϲ���~
	Child* pChild = static_cast<Child*>(pBase);
	Child& refChild = static_cast<Child&>(refBase);


	// Dynamic Cast
	// Down cast �� �����ִ� ����
	// Base pointer, reference �� ����Ű�� �ִ� ��ü, concrete object �� Ÿ���� Ȯ�����ش�
	// �׸��� �� Ÿ���� down cast �Ϸ��� Ÿ�԰� ���� �� ���� Ȯ��~
	// ������ => Down Cast �����ϴ� => �����۵�
	// �ٸ��� => Down Cast �Ұ��� => return nullptr
	// Base Class �� virtual function �� �ݵ�� �ϳ� �����ؾ� �Ѵ�
	Child* ppChild = dynamic_cast<Child*>(pBase);
	Child& refrefChild = dynamic_cast<Child&>(refBase);

	// �����غôµ� up cast ���� dynamic_cast �� ���ʿ��� �� ����... �� Ÿ���� �´� �� Ȯ���ϰ� �̷� �ʿ䰡 �����ϱ�
}