#include <iostream>

/*
	Class Template

	���ø��� �̿��Ͽ� Ŭ������ ����
	���ϴ� Ÿ���� ������ Ŭ������ ���� �� �ִ�

	Only Member functions invoked are instantiated
	ȣ��Ǵ� member functions �� instantiation �ȴ�
*/
template<typename T, int size> // size = non-type template argument => function arguments �� ���� �� ����
class Stack {
	// non static data member initialization
	T m_Buffer[size]{};
	int m_Top{ -1 };

public:
	// Default Constructor
	Stack() = default;

	//Stack(const Stack<T, size> &obj) {  longhand notation		=> Class �� Template Parameters �� �׻� ���
	Stack(const Stack& obj) {		   // shorthand notation	=> �ش� Ŭ���� �������� Template Parameters �� ������� �ʾƵ� �ȴ�
		m_Top = obj.m_Top;
		for (int i = 0; i <= m_Top; ++i) {

			// ���� �����ڿ��� �迭�� �Ҵ� ���ص�
			// non static data member initialization �� ���ؼ�, �޸𸮰� �Ҵ�ǳ���??
			m_Buffer[i] = obj.m_Buffer[i];
		}
	}


	// array type reference �� function argument �� �޴� ���
	// argument ������ non type template argument ���� ���� �� �ִ�
	Stack(T(&arr)[size]) {
		m_Top = 0;
		for (int i = 0; i < size; ++i) {
			m_Buffer[i] = -1;
		}
	}


	void Push(const T& elem) {
		m_Buffer[++m_Top] = elem;
	}

	void Pop();

	const T& Top()const {
		return m_Buffer[m_Top];
	}

	bool IsEmpty() {
		return m_Top == -1;
	}

	/*
		Shorthand notation for class name as return type,
		because it appears inside the class
		= Stack Ŭ���� ���� �ȿ�����, Stack �� ���� ���� �����ϴ�
	*/
	static Stack Create(); // static member function
};



// �ۿ��� ����
template<typename T, int size>
void Stack<T, size>::Pop() { // class  declaration �ۿ��� longhand, �ϴ����� template parameters �� ��� �����ش�
	--m_Top;
}

template<typename T, int size>
/*
	Longhand notation for class name as return type,
	because it appears outside the class
*/
Stack<T, size> Stack<T, size>::Create() {
	return Stack<T, size>{};
}




int main() {

	
	/*
		The template parameter list is part of the type of class.
		The following code will not work.

		Stack<float, 9> s = Stack<float, 10>::Create();
					 ^
		non-type template arguments �� list �� ���ؼ� ������ �Ѱܾ� �Ѵ� + Constant
			�ƴϸ� array type reference �� ���� �ѱ����
	*/
	// array type reference �� �޴� ��� => template arguments �� ��� function arguments �� ���ؼ� ������ �� �ִ�
	// ���� ����Ʈ�� ���� ���� �ʾƵ� �ȴ�
	int arr[]{ 1,2,3,4,5 };
	Stack ssss{ arr };


	// �Ϲ����� ��� template arguments �� ������ �� ���� ������
	// ����Ʈ�� �����־�� �Ѵ�
	Stack<float, 10> s = Stack<float, 10>::Create();
	s.Push(3);
	s.Push(1);
	s.Push(6);
	s.Push(9);

	// Copy Ctor
	auto s2{ s };
	while (!s2.IsEmpty()) {
		std::cout << s2.Top() << " ";
		s2.Pop();
	}


	Stack<const char*, 5> ss;
	ss.Push("Hello");
	auto ss2(ss);
	return 0;

}