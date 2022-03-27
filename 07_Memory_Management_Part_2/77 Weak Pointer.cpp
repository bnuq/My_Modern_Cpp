/*
	Weak Pointer
	shared pointer 와 비슷하게 하나의 메모리를 여러 객체가 참조하고 있는 상황
	그런데, underlying pointer 가 중간에 다른 객체에 의해 해제가 될 수 있다
	이런 상황에서
	shared pointer => 해제한 객체만 nullptr 값을 가지고, reference count 만 하나 감소
				   => underlying pointer 와 해당 메모리는 유지되고
				   => 다른 객체들은 여전히 잘 공유하고 있다
	weak pointer => underlying pointer, 해당 메모리가 해제될 수 있다
				 => 공유하던 다른 객체들은, 사용하기 전에 해당 메모리가 유효한 지 아닌 지를 판단할 수 있다
*/
#include <iostream>

class Printer {
	/*
		int 를 관리하는 weak pointer
		shared pointer 를 통해서 => underlying pointer 에 접근한다
		받은 shared pointer 의 reference count 를 확인 => underlying pointer 가 유효한 지 아닌 지를 알 수 있다
	*/
	std::weak_ptr<int> m_pValue{};

public:
				  // shared pointer 를 받으면서, weak pointer 생성
	void SetValue(std::weak_ptr<int> p) {
		m_pValue = p; // weak pointer copy
	}
	void Print() {
		// weak pointer 에서도 use_count method 사용 가능 => 공유하고 있는 shared pointer 갯수 체크
		std::cout << "Reference Count : " << m_pValue.use_count() << std::endl;
		
		// weak pointer 가 저장하고 있는 shared pointer 를 통해서, 접근하려는 메모리의 유효성을 체크할 수 있다
		// shared pointer 의 underlying resource 가 이미 해제됐다면, expired() => true 가 나온다
		if (m_pValue.expired()) {
			std::cout << "Reference Count : " << m_pValue.use_count() << std::endl;
			std::cout << "Resource is no longer available" << std::endl;
			return;
		}
		else {
			// 유효하다면, 이제 리소스에 접근할 수 있는데
			// weak pointer 를 그대로 사용하지 않고
			// 리소스를 공유하는 shared pointer 를 하나 새로 만들어서 접근한다 => reference count 는 하나 증가함
			// lock() method => shared pointer 하나를 만들어 낸다
			auto sp = m_pValue.lock();
			std::cout << "Value is " << *sp << std::endl;
			
			// sp 로 확인하나 m_pValue 로 확인하나, 둘다 같은 리소스를 공유하는
			// shared pointer 로 확인하기 때문에, 같은 결과가 나온다
			std::cout << "Reference Count : " << sp.use_count() << std::endl;
			std::cout << "Reference Count : " << m_pValue.use_count() << std::endl;
		}
	}
};


int main() {
	Printer prn{};
	
	int num{};
	std::cin >> num;

	std::shared_ptr<int> p{ new int{num} };

	// weak pointer 생성을 위해서 shared pointer 를 넘김
	prn.SetValue(p);

	// 받은 num 숫자가 10 을 넘기는 경우, 리소스를 해제해버린다
	if (*p > 10) p = nullptr; // shared pointer 가 리소스를 정리한다

	// 그리고 프린터에서 출력 => 프린터에서 리소스가 해제됐는 지 확인하고, 해제되지 않았을 때만 출력하게 한다
	prn.Print();
}