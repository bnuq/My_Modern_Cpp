#include <iostream>
#include <fstream>

int main()
{
	int x{ 5 };
	auto f = [y = x](int arg)
	{
		return y + arg;
	};

	std::cout << f(9) << std::endl; // 9+5 ���


	// ������ ������ �Ѵ�
	std::ofstream out{ R"(./Sect_13/157_file.txt)" };

	/*
	* ������ ���� �۾��� ���� �Լ��� ���ؼ� �����ϰ� ������
	* �ٸ� �������� �������� ���ϰ� �ϰ� �ʹ�
	* ���� �Լ��� �ܼ��� capturing �ϴ� �Ϳ� ��ġ�� �ʰ�
	* ���� ���ο��� ������ ������ �����ϵ��� �Ѵ� = Generalized Lambda Capture
	* �׷���, �ܺο� ������ �ȴ�
	*/
	// ofstream = non-copyable => move �� ���� �ѱ��
	// ������ ����� ��Ʈ���� ���� ǥ���� ������ ����
	// ���� ���ٿ����� ������ �����ϴ�
	// ������ ���� => ofstream �� ��ȭ�� �ִϱ�, mutable
	auto fileWrite = [out = std::move(out)](int x) mutable
	{
		out << x;
	};
	fileWrite(1000);
	out << 200; // �� �������� out �� ���̻� ���Ͽ� ������� ���� => ���Ͽ� �� �� ����


}