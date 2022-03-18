// �����쿡���� ���͸��� �齽������ �����Ѵ�

#include <iostream>
// experimental �� ���� deprecated => �׳� filesystem ���
#include <filesystem>


int main() {

	// <filesystem> �� ���ϴ� ��ҵ��� filesystem namespace �� ����
	// namespace ���� ���� �������־�� �Ѵ�
	using namespace std::filesystem;
	

	/*
		path
		���� ��� ���ڿ��� ���� => Raw String Literal �� �̿��ؼ� �ʱ�ȭ
		���ڿ� ���ͷ� ������ ����, ������ �̷� ������ �����ϴ� ���� �˻����� �ʴ´�
	*/
	path p{ R"(c:/Windows)" }; // directory path
		
	// path :: has_filename() => path �� filename �� �����ϴ� ��, �ƴ����� �����Ѵ�
	if (p.has_filename())
		// path :: filename() => path �� ������ ��� ���ڿ�����, ���� �������� �ش��ϴ� ���� �Ǵ� ���丮
		// ��� ���ڿ� ���� ������ ��Ҹ� path �� �����Ѵ�
		std::cout << p.filename() << std::endl;

	
	path e{ R"(e:/temp/temp2/test.txt)" }; // file path

	if (e.has_filename())
		std::cout << e.filename() << std::endl;



	/*
		Range based for loop + path
		path �� �����ϴ� �� ���ϵ��� �ϳ��� ����ų �� �ִ�
		
		�ٵ� ù��° / �� �� �ν��ϴ� ����? ù��° �͸� �ν��Ѵ�
	*/
	for (const auto& x : e)
		std::cout << x << std::endl;


	/*
		directory_iterator
		path �� directory path �� ���� ��ȿ => file path �� exception �߻�
		�ش� path directory �ȿ� �����ϴ� ���빰, ���ϵ��� ����Ű�� iterator
	*/
	directory_iterator beg{ p }; // ù ��° ����
	directory_iterator end{};
	while (beg != end)
	{
		// * �� ������ => �ش� ������ path �� ����
		std::cout << *beg << std::endl;
		++beg; // ���ϵ��� �ϳ��ϳ��� ����Ų��
	}
}