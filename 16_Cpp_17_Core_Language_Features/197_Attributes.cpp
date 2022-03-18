#include <iostream>

[[deprecated("Use the template version instead")]] // 이 버전은 사용하지 말아라
[[nodiscard]]
int* CreateIntArray(size_t size) {
	return new int[size];
}

template<typename T>
[[nodiscard]] // 리턴 타입을 꼭 챙겨라
T* CreateArray(size_t size) {
	return new T[size];
}

// 이 클래스 타입을 리턴할 때는 무조건 받아야 한다
class [[nodiscard]] Number {

};

Number GetNumber(int x) { // Number 가 nodiscared attribute 를 가지고 있어서,
						  // 이 함수 리턴 값을 받지 않으면 경고가 뜬다
	return Number{};
}

class [[deprecated("This class is replaced by NewTest class")]] Test {

};

namespace [[deprecated("NameSpace Deprecated")]] A {

}

int main() {
	//CreateIntArray(5) ;
	auto p = CreateArray<int>(3) ;
	auto q = GetNumber(3);
}