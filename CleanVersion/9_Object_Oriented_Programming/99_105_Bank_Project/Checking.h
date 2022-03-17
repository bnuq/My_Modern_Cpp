#pragma once
#include "Account.h"

/*
	constructor
	destuctor
	assignment operator
	이 3가지는 물려지지 않는다, 각 클래스마다 지정을 해주어야 한다
	아니면 그냥 default version 을 사용하거나
*/
// 통장 클래스를 물려받는 또다른 클래스 => 그냥 체크만하는 통장
class Checking final : public Account {
	// Non-Static member initialization
	float m_MinimumBalance { 20 }; // 혹시 Checking 의 ctor 이 호출되지 않는 경우, 자동으로 초기화 되게 한다

public:
	/*
		Inherit Constructor
		
		자식 클래스 생성자에서 추가적으로 할 작업이 없는 경우
		child class 의 생성자를 굳이 작성하지 않고,
		그냥 base class 의 constructor 를 물려받아서 그것만 사용할 수 있다

		child class 의 생성자는 아예 작성하지 않고, 그냥 base class 의 생성자로 대체

		생성자 인수로 받은 것을 파악 -> base class 에서 적절한 생성자를 찾아 호출한다
	 */
	// base class 의 ctor 가져옴
	// string, float 를 인수로 받는 생성자가 있으므로 그것을 사용한다
	using Account::Account; 
	
	// 다른 생성자
	Checking(const std::string& name, float balance, float minbalance);

	// base class 의 virtual function 을 재정의하는 경우, 확실하게 재정의한다는 의미에서
	// override keyword 사용 => virtual 유무 + 함수 시그니처 를 확인한다
	~Checking() override;
	void Withdraw(float amount) override;

	// 자식 클래스에서 추가하는 멤버 함수
	float GetMinimumBalance() const;
};
