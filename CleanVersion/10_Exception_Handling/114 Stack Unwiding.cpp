#include <iostream>
using namespace std;

class Test {
public:
	Test() {
		cout << "Test()" << endl;
	}
	~Test() {
		cout << "~Test()" << endl;
	}
};


void func1() {
	// �Լ� ������ ���� ������ �����
	Test t{};

	// �߰��� exception �� �߻��Ѵٸ�
	throw runtime_error{"func error"};

	// Stack Unwinding
	// ȣ���ߴ� �Լ� ������ �ڵ����� ���� => �Լ� �� ���� ������ ������ �����Ѵ�
	// �ڵ����� dtor ȣ��, �׳� scope �����ϱ� �������� ������� ����
}


void func2() {
	// �Լ� ������ Heap �޸𸮸� �Ҵ�, ���ҽ��� ����Ѵٸ�
	Test* pt = new Test{};

	// �߰��� exception �� �߻����� ��
	throw runtime_error{ "func error" };

	// ���� ������ �����ϱ� ������, ���ҽ� ������ �̷�� ���� �ʴ´� => dtor ȣ����� ����
	// Memory Leak
	delete pt;
}


#include <memory>
#include <vector>
void func3() {
	// �׷��� ���� �Լ� ������ ���ҽ��� �Ҵ��ϰ��� �Ѵٸ�, ����Ʈ �����͸� ��� �Ѵ�
	// ���� �߰��� �Լ��� ���۽����� ���ᰡ �Ǵ���, ����Ʈ �������� dtor => ���ҽ��� �������ش�
	unique_ptr<Test> upt{ new Test{} };


	// �ƴϸ� STL �� ��� => �ڵ����� �޸𸮸� �������ش�
	vector<int> vec{};
	vec.reserve(100); // vector :: reserve() => ���� ũ�� �޸𸮸� Ȯ��


	/*
		���� �޸𸮸� �����ϴ� ���� ���ϰ�
		samrt pointer �� container �� ����϶�
	*/


	throw runtime_error{ "func error" };
}


int main() {
	try {
		//func1();
		//func2();
		func3();
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}
}


