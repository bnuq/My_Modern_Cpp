#include <iostream>
#include <string>

#include <unordered_set> // key=value ����
#include <unordered_map> // key+value = pair ����


int main()
{
	// type, hash function, equal_to, allocator
	std::unordered_set<std::string> col;		// key �ߺ� ������
	std::unordered_multiset<std::string> coll;	// key �ߺ� ����
	
												
	//elements are stored based on the hash, but in unspecified order, 
	coll.insert("Hulk");
	coll.insert("Batman");
	coll.insert("Green Lantern");
	coll.insert("The Flash");
	coll.insert("Wonder Woman");

	// key �ߺ�
	coll.insert("Iron man");
	coll.insert("Iron man");
	coll.insert("Iron man");

	coll.insert("Wolverine");
	coll.insert("Dr. Strange");
	coll.insert("Hawkman");


	for (const auto x : coll) {
										// bucket ��ȣ, �ؽ� ��� ���
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
	// insert �� ����
	unordMap.insert(std::make_pair("UNIST", "DH"));


	
	// multimap => �ߺ������ �Ǵ� key �ϳ��� �˻��� �ȵȴ�
	// insert �Լ� ���
	unordMultiMap.insert(std::make_pair("Batman", "Bruce Wayne"));
	unordMultiMap.insert(std::make_pair("Batman", "Matches Malone"));
	unordMultiMap.insert(std::make_pair("Superman", "Clark Kent"));
	unordMultiMap.insert(std::make_pair("Hulk", "Bruce Banner"));

	
	std::cout << "In unordered map" << std::endl;
	for (const auto& x : unordMap) {
		std::cout << "Bucket #:" << unordMap.bucket(x.first) << " ->" << x.first << ":" << x.second << std::endl;
	}


	// unordered map, unordered multimap ������ unordered set/multiset �� ������ �Լ��� ����� �� �ִ�
	std::cout << "In unordered multimap" << std::endl;
	std::cout << "Bucket count:" << unordMultiMap.bucket_count() << std::endl;
	std::cout << "Number of elements:" << unordMultiMap.size() << std::endl;
	std::cout << "Load factor:" << unordMultiMap.load_factor() << std::endl;
}