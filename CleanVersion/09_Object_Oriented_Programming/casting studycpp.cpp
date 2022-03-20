

class Base {
public:
	Base() = default;
	virtual ~Base() = default;
};

class Child : public Base {

};

int main() {
	Base base{};
	Child child{};

	// Object Slicing
	Base anoBase = child; // child attribute 가 다 날아가고, Base 부분만 남김

	// Upcast
	// Base pointer, reference 로 Base 를 물려받는 아무 클래스나 다 가리키는 것
	// 무엇을 가리키는 지는 모르지만, Base Class Type 부분을 포함하고 있다면 가리킬 수 있다
	// Child Class Type 에서 Base Class Type 부분에만 집중하는 것
	Base* pBase = &child;
	Base& refBase = child;

	// Downcast
	// Base pointer, reference 가 무엇을 가리키는 지 모르지만
	// 그것이 특정 자식 클래스를 가리킨다고 생각하는 것
	// 약간 예지하는 느낌, 지금 가리키고 있는 건 어떤 Child 일꺼야~
	Child* pChild = static_cast<Child*>(pBase);
	Child& refChild = static_cast<Child&>(refBase);


	// Dynamic Cast
	// Down cast 를 도와주는 역할
	// Base pointer, reference 가 가리키고 있는 객체, concrete object 의 타입을 확인해준다
	// 그리고 그 타입이 down cast 하려는 타입과 같은 지 먼저 확인~
	// 같으면 => Down Cast 가능하다 => 정상작동
	// 다르다 => Down Cast 불가능 => return nullptr
	// Base Class 에 virtual function 이 반드시 하나 존재해야 한다
	Child* ppChild = dynamic_cast<Child*>(pBase);
	Child& refrefChild = dynamic_cast<Child&>(refBase);

	// 생각해봤는데 up cast 에는 dynamic_cast 가 불필요한 거 같다... 뭐 타입이 맞는 지 확인하고 이럴 필요가 없으니까
}