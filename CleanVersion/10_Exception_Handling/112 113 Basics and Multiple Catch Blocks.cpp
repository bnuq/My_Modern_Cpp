#include <iostream>

int ProcessRecords(int count) {
	//int* pArray = (int*)malloc(count * sizeof(int));
	int* pArray{ nullptr };

	// ���ǿ� ���� ���� ������ exception �� �߻��� �� �ִ�
	if (count < 10) throw std::out_of_range("Count should be greater than 10");
	if (count < 0) throw std::bad_alloc{};

	// malloc �� �޸� �Ҵ翡 �������� ���
	if (pArray == nullptr) {
		// exception �� throw �ϰ� �Ѵ�
		// ���α׷��� ���� ������ �� ����
		throw std::runtime_error("Failed to allocat memory");
	}
	else {
		free(pArray);
		return 0;
	}
}


int main() {
	// exception �� �߻��� �� �ִ� �ڵ�� try block ���� ó���Ѵ�
	try {
		// int ���� ���� �� ���� ū ���� �̿�
		//ProcessRecords(std::numeric_limits<int>::max());
		ProcessRecords(2);
	}
	// exception �� �߻��� ��� catch block ���� ��´�
	/*
		Multiple Catch Blocks
		� ������ exception �� �߻��� �� �𸣴�, �߻��� �� �ִ� ��� exception �� ���ؼ�
		�޴� catch block �� ��� ���� ���� �ִ�
	
	catch (std::runtime_error& ex) {
		// exception :: what() �޼ҵ� => exception �� �̸��� ����
		std::cout << ex.what() << std::endl;
	}
	catch (std::out_of_range& ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (std::bad_alloc& ex) {
		std::cout << ex.what() << std::endl;
	}

	*/
	/*
		�ٵ� ��� exception ���� std::exception class �� child class ��
		���� std::exception class �� ������, ���۷����� �̿��ϸ� ��� exception �� 
		����ų �� �ִ� => �̰� �ϳ��� ��� ��� exception �� ���� �� �ִ�
	*/
	catch (std::exception& ex) {
		// exception :: what() �޼ҵ� => exception �� �̸��� ����
		std::cout << ex.what() << std::endl;
	}
	// ������ ���, ellipsis ��� => ������ �޴� ���� ������, �޴� �� �����ϴ�
	// ���ϴ� ���� ����
	catch (...) {
		std::cout << "Exception" << std::endl;
	}
}