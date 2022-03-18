// 윈도우에서만 디렉터리를 백슬래쉬로 구분한다

#include <iostream>
// experimental 은 이제 deprecated => 그냥 filesystem 사용
#include <filesystem>


int main() {

	// <filesystem> 에 속하는 요소들은 filesystem namespace 에 존재
	// namespace 까지 따로 지정해주어야 한다
	using namespace std::filesystem;
	

	/*
		path
		파일 경로 문자열을 저장 => Raw String Literal 을 이용해서 초기화
		문자열 리터럴 정보만 저장, 실제로 이런 파일이 존재하는 지는 검사하지 않는다
	*/
	path p{ R"(c:/Windows)" }; // directory path
		
	// path :: has_filename() => path 의 filename 이 존재하는 지, 아닌지를 리턴한다
	if (p.has_filename())
		// path :: filename() => path 가 저장한 경로 문자열에서, 가장 마지막에 해당하는 파일 또는 디렉토리
		// 경로 문자열 가장 마지막 요소를 path 로 리턴한다
		std::cout << p.filename() << std::endl;

	
	path e{ R"(e:/temp/temp2/test.txt)" }; // file path

	if (e.has_filename())
		std::cout << e.filename() << std::endl;



	/*
		Range based for loop + path
		path 를 구성하는 각 파일들을 하나씩 가리킬 수 있다
		
		근데 첫번째 / 는 왜 인식하는 거지? 첫번째 것만 인식한다
	*/
	for (const auto& x : e)
		std::cout << x << std::endl;


	/*
		directory_iterator
		path 가 directory path 일 때만 유효 => file path 면 exception 발생
		해당 path directory 안에 존재하는 내용물, 파일들을 가리키는 iterator
	*/
	directory_iterator beg{ p }; // 첫 번째 파일
	directory_iterator end{};
	while (beg != end)
	{
		// * 로 역참조 => 해당 파일의 path 를 리턴
		std::cout << *beg << std::endl;
		++beg; // 파일들을 하나하나씩 가리킨다
	}
}