#include <iostream>

[[deprecated("Use the template version instead")]] // �� ������ ������� ���ƶ�
[[nodiscard]]
int* CreateIntArray(size_t size) {
	return new int[size];
}

template<typename T>
[[nodiscard]] // ���� Ÿ���� �� ì�ܶ�
T* CreateArray(size_t size) {
	return new T[size];
}

// �� Ŭ���� Ÿ���� ������ ���� ������ �޾ƾ� �Ѵ�
class [[nodiscard]] Number {

};

Number GetNumber(int x) { // Number �� nodiscared attribute �� ������ �־,
						  // �� �Լ� ���� ���� ���� ������ ��� ���
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