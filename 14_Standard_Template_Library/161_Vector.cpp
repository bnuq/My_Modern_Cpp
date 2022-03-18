#include <iostream>
#include <vector>

int main()
{
	// vector => type, allocator 를 명시 => 여기서는 타입만
	std::vector<int> coll{ 1,2,3,4 };

	for (int i = 0; i < 5; ++i) {
		
		// 벡터 끝에 추가
		coll.push_back(i * 10);

		// size() 를 통해 원소 갯수를 실시간으로 파악할 수 있디
		std::cout << coll.size() << std::endl;
	}

	// random access
	coll[0] = 100;

	// 기존 루프 방식
	//for (int i = 0; i< coll.size(); ++i) {
	//	std::cout << coll[i] << " ";
	//}


	// iterator 를 사용하는 것이 권장
	auto itr = coll.begin();
	while (itr != coll.end())
	{
		// * 로 참조를 먼저하고, 이후 ++
		std::cout << *itr++ << " ";
	}
	std::cout << std::endl;


	// insert => iterator 위치에 원소 추가
	coll.insert(coll.begin()+1, 700);

	// end => iterator 위치에 원소 삭제
	coll.erase(coll.end() - 5);

	// pop_back() => 끝 원소 제거
	coll.pop_back();


	for (auto x : coll)
		std::cout << x << " , ";
	std::cout << std::endl;
}