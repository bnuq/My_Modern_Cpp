#include <iostream>
#include <string>


//Unordered Container => Hash 구조를 사용
#include <unordered_set> // key=value 저장
#include <unordered_map> // key+value = pair 저장


int main() {

	/*
		Unordered Set/MultiSet

		type, hash function, equal_to, allocator
		Hash 에 일반 key 를 저장
	*/
	std::unordered_set<std::string> col;		// key 중복 허용안함
	std::unordered_multiset<std::string> coll;	// key 중복 가능
	
												
	//elements are stored based on the hash, but in unspecified order
	//검색은 쉽지만, 순서는 알 수 없다
	coll.insert("Hulk");
	coll.insert("Batman");
	coll.insert("Green Lantern");
	coll.insert("The Flash");
	coll.insert("Wonder Woman");


	//multiset => key 중복 가능
	coll.insert("Iron man");
	coll.insert("Iron man");
	coll.insert("Iron man");

	coll.insert("Wolverine");
	coll.insert("Dr. Strange");
	coll.insert("Hawkman");


	for (const auto x : coll) { //x = unordered container 에 저장된 타입
								 //bucket()		
								 //해당 요소의 bucket 번호 리턴
		std::cout << "Bucket #:" << coll.bucket(x) << " contains :" << x << std::endl;
	}


	//buck_count() => 미리 할당해 놓은 메모리, growing 없이 저장할 수 있는 총 개수
	//= Capacity
	std::cout << "Bucket count:" << coll.bucket_count() << std::endl;

	//size() => 실제 할당된 요소들의 개수
	//= Entries
	std::cout << "Number of elements:" << coll.size() << std::endl;

	//load_factor = size / bucket_count
	std::cout << "Load factor:" << coll.load_factor() << std::endl;

	std::cout << std::endl << std::endl;



	/*
		Unordered Map/MultiMap

		Hash에 pair 를 저장
	*/
	std::unordered_map<std::string, std::string> unordMap;
	std::unordered_multimap<std::string, std::string> unordMultiMap;
	

	//Only unordered_map support [] operator => 특이 케이스
	//key를 통해 찾고 => value를 대입
	unordMap["Batman"] = "Brue Wayne";
	unordMap["Superman"] = "Clark Kent";
	unordMap["Hulk"] = "Bruce Banner";


	// insert 도 가능
	unordMap.insert(std::make_pair("UNIST", "DH"));


	
	//multimap => 중복허용이 되니 key 하나로 검색이 안된다
	//insert 함수 사용
	unordMultiMap.insert(std::make_pair("Batman", "Bruce Wayne"));
	unordMultiMap.insert(std::make_pair("Batman", "Matches Malone"));
	unordMultiMap.insert(std::make_pair("Superman", "Clark Kent"));
	unordMultiMap.insert(std::make_pair("Hulk", "Bruce Banner"));

	
	std::cout << "In unordered map" << std::endl;
	for (const auto& x : unordMap) {
		std::cout << "Bucket #:" << unordMap.bucket(x.first) << " ->" << x.first << ":" << x.second << std::endl;
	}


	//unordered map, unordered multimap 에서도 unordered set/multiset 과 동일한 함수를 사용할 수 있다
	//같은 구조니까?
	std::cout << "In unordered multimap" << std::endl;
	std::cout << "Bucket count:" << unordMultiMap.bucket_count() << std::endl;
	std::cout << "Number of elements:" << unordMultiMap.size() << std::endl;
	std::cout << "Load factor:" << unordMultiMap.load_factor() << std::endl;
}