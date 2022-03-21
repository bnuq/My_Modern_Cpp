#include <iostream>

/*
	Class Template

	템플릿을 이용하여 클래스를 만듦
	원하는 타입을 가지는 클래스를 만들 수 있다

	Only Member functions invoked are instantiated
	호출되는 member functions 만 instantiation 된다
*/
template<typename T, int size> // size = non-type template argument => function arguments 로 받을 수 없다
class Stack {
	// non static data member initialization
	T m_Buffer[size]{};
	int m_Top{ -1 };

public:
	// Default Constructor
	Stack() = default;

	//Stack(const Stack<T, size> &obj) {  longhand notation		=> Class 의 Template Parameters 를 항상 명시
	Stack(const Stack& obj) {		   // shorthand notation	=> 해당 클래스 내에서는 Template Parameters 를 명시하지 않아도 된다
		m_Top = obj.m_Top;
		for (int i = 0; i <= m_Top; ++i) {

			// 복사 생성자에서 배열을 할당 안해도
			// non static data member initialization 에 의해서, 메모리가 할당되나봐??
			m_Buffer[i] = obj.m_Buffer[i];
		}
	}


	// array type reference 를 function argument 로 받는 경우
	// argument 만으로 non type template argument 까지 받을 수 있다
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
		= Stack 클래스 정의 안에서는, Stack 만 쓰는 것이 가능하다
	*/
	static Stack Create(); // static member function
};



// 밖에서 정의
template<typename T, int size>
void Stack<T, size>::Pop() { // class  declaration 밖에선 longhand, 하던데로 template parameters 를 모두 적어준다
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
		non-type template arguments 는 list 를 통해서 무조건 넘겨야 한다 + Constant
			아니면 array type reference 를 통해 넘기던지
	*/
	// array type reference 를 받는 경우 => template arguments 를 모두 function arguments 를 통해서 유추할 수 있다
	// 따라서 리스트를 따로 적지 않아도 된다
	int arr[]{ 1,2,3,4,5 };
	Stack ssss{ arr };


	// 일반적인 경우 template arguments 를 유추할 수 없기 때문에
	// 리스트에 적어주어야 한다
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