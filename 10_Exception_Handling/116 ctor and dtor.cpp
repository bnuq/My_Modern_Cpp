#include <iostream>
#include <memory>
#include <vector>


class A {
public:
	A() {
		std::cout << "A()" << std::endl;
	}
	~A() {
		std::cout << "~A()" << std::endl;
	}
};
class B {
public:
	B() {
		std::cout << "B()" << std::endl;
	}
	~B() {
		std::cout << "~B()" << std::endl;
	}
};




class Test {
	std::unique_ptr<A> pA{};
	B b{};
	std::unique_ptr<int> pInt{};
	std::string pStr{};
	std::vector<int> pArr{};
public:
	/*
		������ ������, exception �� �߻��ϴ� ���
		������ �Լ��� ���ؼ��� stack unwinding
		�Ҹ��ڴ� ȣ������ �ʴ´� => ���� ��� ������ ���ҽ��� �Ҵ��Ѵٸ� ������ ���� �ʴ´�
		
		���� ��� �������� smart pointer �� container �� ��� => ���ҽ��� ����Ѵ�
		RAII concept ���
	*/
	Test() {
		std::cout << "Test():Acquire resources" << std::endl;
		pA.reset(new A);

		/*
		* ���� �޸𸮸� �Ҵ��ϴ� ������ �� => ���� �߻� �� memory leak
			pA = new A;
			pInt = new int;
			pStr = new char[1000];
			pArr = new int[50000];
		*/
	}
	/*
		�Ҹ��� ������ exception �� �߻��ϴ� ��� => �׷� ��찡 �־�� �ȵȴ�
		�Ҹ��ڿ����� exception �� �߻��ؼ��� �ȵȴ�

		�ֳ��ϸ� stack unwinding �� �Ҹ��ڰ� ���� => �׷��� �� exception �߻�
		=> stack unwinding => �Ҹ��� ȣ�� ...
	*/
	~Test() {
		std::cout << "~Test():Release resources" << std::endl;
		
		// ���� �Ҹ��� ������ ���ܰ� �߻��ϴ���, �Ҹ��� ������ ó���� �ݵ�� �ؾ��Ѵ�
		try {
			throw std::runtime_error("Failed to initialize");
		}
		catch (std::exception& ex) {
			std::cout << "Processing an exception : " << ex.what() << std::endl;
		}
				
		/*
			delete pA;
			delete pInt;
			delete[]pStr;
			delete[] pArr;
		*/
	}
};

int main() {
	try {
		Test t;

		// exception �߻� => stack unwinding => Test t ��ü�� �����Ѵ�
		throw std::runtime_error{ "Exception" };
	}
	catch (std::runtime_error& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}