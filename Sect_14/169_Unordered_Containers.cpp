#include <iostream>
#include <string>

#include <unordered_set> // key=value 저장
#include <unordered_map> // key+value = pair 저장


int main()
{
	// type, hash function, equal_to, allocator
	std::unordered_set<std::string> col;		// key 중복 허용안함
	std::unordered_multiset<std::string> coll;	// key 중복 가능
	
												
	//elements are stored based on the hash, but in unspecified order, 
	coll.insert("Hulk");
	coll.insert("Batman");
	coll.insert("Green Lantern");
	coll.insert("The Flash");
	coll.insert("Wonder Woman");

	// key 중복
	coll.insert("Iron man");
	coll.insert("Iron man");
	coll.insert("Iron man");

	coll.insert("Wolverine");
	coll.insert("Dr. Strange");
	coll.insert("Hawkman");


	for (const auto x : coll) {
										// bucket 번호, 해쉬 결과 출력
		std::cout << "Bucket #:" << coll.bucket(x) << " contains :" << x << std::endl;
	}

	std::cout << "Bucket count:" << coll.bucket_count() << std::endl;
	std::cout << "Number of elements:" << coll.size() << std::endl;

	// load_factor = size / bucket_count
	std::cout << "Load factor:" << coll.load_factor() << std::endl;




	std::cout << std::endl << std::endl;


	std::unordered_map<std::string, std::string> unordMap;
	std::unordered_multimap<std::string, std::string> unordMultiMap;
	
	//Only unordered_map support [] operator
	unordMap["Batman"] = "Brue Wayne";
	unordMap["Superman"] = "Clark Kent";
	unordMap["Hulk"] = "Bruce Banner";
	// insert 도 가능
	unordMap.insert(std::make_pair("UNIST", "DH"));


	
	// multimap => 중복허용이 되니 key 하나로 검색이 안된다
	// insert 함수 사용
	unordMultiMap.insert(std::make_pair("Batman", "Bruce Wayne"));
	unordMultiMap.insert(std::make_pair("Batman", "Matches Malone"));
	unordMultiMap.insert(std::make_pair("Superman", "Clark Kent"));
	unordMultiMap.insert(std::make_pair("Hulk", "Bruce Banner"));

	
	std::cout << "In unordered map" << std::endl;
	for (const auto& x : unordMap) {
		std::cout << "Bucket #:" << unordMap.bucket(x.first) << " ->" << x.first << ":" << x.second << std::endl;
	}


	// unordered map, unordered multimap 에서도 unordered set/multiset 과 동일한 함수를 사용할 수 있다
	std::cout << "In unordered multimap" << std::endl;
	std::cout << "Bucket count:" << unordMultiMap.bucket_count() << std::endl;
	std::cout << "Number of elements:" << unordMultiMap.size() << std::endl;
	std::cout << "Load factor:" << unordMultiMap.load_factor() << std::endl;
}