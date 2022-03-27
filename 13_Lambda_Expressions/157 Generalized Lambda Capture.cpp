#include <iostream>
#include <fstream>


int main() {

	int x{ 5 };

	/*
		Generalized Capture
		Capture List ���� ���ο� ������ ���� �� �ִ�
		������ �ݵ�� �ٱ����� Capture �� ������ �ʱ�ȭ �Ǿ�� �Ѵ�
		�ٱ� ������ ���� �̸��� ���� �� �ִ�
		Caputure by Value, Capture by Reference ��� �����ϴ�
	*/
	auto f = [y = x](int arg) { // Lambda Expression ������ ����� ���� y �� ���� �������
		return y + arg;
	};
	std::cout << f(9) << std::endl; // 9+5 ���


	/*
		Out Filestream
		File <- Stream, ���Ͽ� ������ ������ �Ѵ�
	*/
	std::ofstream out{ R"(./Files/157 file.txt)" };

	/*
		���Ͽ� ���ڿ��� ���� �۾��� ���� �Լ��� ���ؼ� �����ϰ� ������
		�ٸ� �������� ���� ��Ʈ���� �������� ���ϰ� �ϰ� �ʹ�
	
		���� Generalized Capture �� ���
		���� ǥ���Ŀ��� ���� ������ ������ ����ϸ�
		���� ǥ������ ���� �� ���� ������Ƿ� => ���̻� �ٸ� ������ �̿����� ���Ѵ�
		���� �ܺο� ���� ���� �� �ִ�
	
		ofstream = non-copyable => std::move() �� ���� �ѱ��
		������ ����� ��Ʈ���� ���� ǥ���� ������ ���� => ���� ǥ���� ���η� ������ �ٲ����
		���� ���ٿ����� ������ �����ϴ�
		������ ���� => ofstream �� ��ȭ�� �ش� => ��� ������ �ٲ�� => mutable
	*/
	auto fileWrite = [out = std::move(out)](int x) mutable {
		out << x << std::endl;
	};
	fileWrite(1000);

	/*
		std::move() �߱� ������, ������ ���� �ۿ� �ִ� out ofstream �� nullptr �� ����Ű�� �ִ�
		�� out �� ���̻� ���Ͽ� ������� ���� => ���Ͽ� �� �� ����
	*/
	// out << 200;

	// ostream �� �Ѿ, lambda expression ������ ���Ͽ� ������ �����ϴ�
	fileWrite(200);
}