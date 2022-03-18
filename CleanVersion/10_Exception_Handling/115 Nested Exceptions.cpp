/*
	Nested Exceptions Handling
	try - catch block �� 2������ ����� �� �ִ�
	�Լ� ������ try catch block �� ����ؼ�, �Լ� ������ exception �� ó���� �� �ְ�
	�ű⼭ �߻��� excetpion ��, �ٽ� �Լ��� ȣ���� ������ ��ȯ�� �� �ִ�
*/

#include <iostream>
using namespace std;


void func() {
	// �Լ� �������� try - catch �� ����� �� �ִ�
	// �Լ� �� �۾����� exception �� Ȱ���� �� �ִ�
	
	for (int i = 1; i < 10; i++) {
		// try-catch �� �ݺ��ؼ� ����Ѵ�
		try {
			cout << "Processing " << i;
			if (i & 1) { // Bit Manipulation
				throw runtime_error("It is Odd");
			}
			cout << endl;
		}
		// �ݺ��� ������, ���� �߻� �� ó�� ���
		catch (exception& ex) {
			cout << " : " << ex.what() << endl;

			// catch block ������, ���� exception �� �ٽ� �ٱ����� ���� �� �ִ�
			// �Լ� ������ ó�� ���ϴ� ������ ���, �� ���ܸ� �״�� �Լ� �ٱ����� ����
			if (i > 6) throw; // �׳� throw �� ���� �ȴ�

			// ���� ���ܰ� �ƴ�, �ٸ� ���ܷ� �ٲپ ������ �� �� �ִ�
			if (i == 3) {
				cout << typeid(ex).name() << endl;

				// ex �� runtime error �� ���� ���۷���
				// ���� bad_alloc �� runtime_error �� �����ϴ� ���ε�..
				// �̰� �ǳ�??
				ex = bad_alloc{};

				cout << typeid(ex).name() << endl;
				//ex = runtime_error("Erro Made by func");
				throw;
			}
		}
	}
}


int main() {
	int x{ 10 };
	int& ref = x;
	int y{ 100 };
	ref = y; // x = y
	cout << x << endl;
	
	try {
		func();
	}
	catch (exception& ex) {
		cout << typeid(ex).name() << endl;
		cout << ex.what() << endl;
	}
}