#include <iostream>

// 어떤 거리 를 나타내는 클래스
class Distance {
	// 킬로미터 단위로 거리를 저장한다
	long double m_kilometer{};
	
public:
	Distance(long double km) : m_kilometer{ km } {

	}

	long double getKm() const {
		return m_kilometer;
	}

	void setKm(long double val) {
		m_kilometer = val;
	}
};


/*
	User Defined Literals
	operator"" 로 정의
	global function 만 가능
	_ 로 시작하는 리터럴만 만들 수 있다
	_ 로 시작하지 않아도 만들 수는 있는데, 경고가 발생한다
*/
Distance operator"" _mi(long double val) { // val 이 마일 단위 값이라는 뜻에서 _mi 를 붙임
	// 마일 단위 값을 킬로미터 단위로 바꿔서 저장한 Distance 를 리턴한다
	// 리터럴 이라는 게, 어떻게 보면 되게 간단한 변환작업이다
	return Distance{ val * 1.6 };
}
long double operator"" _mi_to_km(long double val) { // 그냥 단순히 마일 값을 킬로미터 값으로 바꾸는 리터럴
	return val * 1.6;
}


int main() {
	Distance d1{ 10 };
	/*
		20.0 이 마일 값이다
		그래서 _mi 를 붙여서 마일 값이라는 걸 알리고
		동시에 킬로미터로 값을 바꾼 뒤, 저장한 Distance 를 리턴해 버린다
	*/
	Distance d2{ 20.0_mi }; // copy constructor
	Distance d3{ 30.0_mi_to_km }; // para ctor

	std::cout << d2.getKm() << " : " << d3.getKm() << std::endl;
}