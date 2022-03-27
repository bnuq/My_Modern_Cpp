#include <iostream>
#include <string>
#include <vector>

// Scoped Enum
// ��ҹ��ڸ� �����ϴ� ��, �ƴ���
enum class Case { SENSITIVE, INSENSITIVE };


// Assignment 2
size_t Find(
    const std::string& source,         //Source string to be searched
    const std::string& search_string,  //The string to search for
    Case searchCase = Case::INSENSITIVE,//Choose case sensitive/insensitive search
    size_t offset = 0) {                //Start the search from this offset
        //Implementation

    for (size_t i = offset; i < source.length(); i++) {
        if (source[i] != search_string[0]) continue;
        else {
            bool goodMatch{ true };
            for (size_t j = 1; j < search_string.length() and i+j < source.length(); j++) {
                // ��ҹ��ڸ� �����ؾ� �Ѵ� => �׳� �ٷ� 1 �� 1 ��
                if (searchCase == Case::SENSITIVE) {
                    if (source[i + j] != search_string[j]) {
                        goodMatch = false;
                        break;
                    }
                }
                // ��ҹ��� ���� ���� => �Ѵ� �ҹ��ڷ� �ٲ㼭 ��
                else if (searchCase == Case::INSENSITIVE) {
                    char surCh = tolower(source[i + j]);
                    char serCh = tolower(search_string[j]);
                    if (surCh != serCh) {
                        goodMatch = false;
                        break;
                    }
                }
            }
            if (goodMatch) {
                return i;
            }
        }
    }

    /*
    return position of the first character
    of the substring, else std::string::npos
    */
    return std::string::npos;
}


// string::find() method �� ����ϴ� ����
// ���� �޸𸮿� ���� �������� �ʴ� ���� ����, �־��� �޼��带 �� Ȱ���ϴ� ���� ����
size_t Find2(const std::string& source, const std::string& search_string, Case searchCase = Case::INSENSITIVE, size_t offset = 0) {
    if (searchCase == Case::SENSITIVE) {
        return source.find(search_string, offset);
    }
    else if (searchCase == Case::INSENSITIVE) {
        std::string dup_source{ source };
        std::string dup_search_string{ search_string };

        for (char& ch : dup_source)
            ch = tolower(ch);

        for (char& ch : dup_search_string)
            ch = tolower(ch);

        return dup_source.find(dup_search_string, offset);
    }
}



// Assignment 3
std::vector<int>
FindAll(
    const std::string& target,              //Target string to be searched
    const std::string& search_string,       //The string to search for
    Case searchCase = Case::INSENSITIVE,    //Choose case sensitive/insensitive search
    size_t offset = 0) {                    //Start the search from this offset
        //Implementation
    
    std::vector<int> res{};

    for (int i = offset; i < target.length(); i++) {
        if (target[i] != search_string[0]) continue;
        else {
            bool goodMatch{ true };

            for (int j = 1; j < search_string.length() and i + j < target.length(); j++) {
                
                // ��ҹ��ڸ� �����ؾ� �Ѵ� => �׳� �ٷ� 1 �� 1 ��
                if (searchCase == Case::SENSITIVE) {
                    if (target[i + j] != search_string[j]) {
                        goodMatch = false;
                        break;
                    }
                }
                // ��ҹ��� ���� ���� => �Ѵ� �ҹ��ڷ� �ٲ㼭 ��
                else if (searchCase == Case::INSENSITIVE) {
                    char surCh = tolower(target[i + j]);
                    char serCh = tolower(search_string[j]);
                    if (surCh != serCh) {
                        goodMatch = false;
                        break;
                    }
                }
            }

            if (goodMatch) {
                res.push_back(i);
            }
        }
    }
       /*
       Return indices of found strings,
       else an empty vector
       */

    return res;
}


// string::find() method �� ����ϴ� ����
// find() method ���� �˻��� �����ϴ� offset �� ������ �� �ִٴ� ���� �̿��Ѵ�
std::vector<int> FindAll2(const std::string& source, const std::string& search_string, Case searchCase = Case::INSENSITIVE, size_t offset = 0) {

    std::vector<int> res{};

    std::string dup_source{ source };
    std::string dup_search_string{ search_string };

    if (searchCase == Case::INSENSITIVE) {
        for (char& ch : dup_source)
            ch = tolower(ch);
        for (char& ch : dup_search_string)
            ch = tolower(ch);
    }

    int index{};

    // dup_source ���� dup_search_string �� ã�´ٸ�, �� ��ġ �ε����� �����Ѵ�
    while ((index = dup_source.find(dup_search_string, offset)) != std::string::npos) {
        // ã�� ��ġ �ε����� ���Ϳ� �߰��ϰ�
        res.push_back(index);

        // ã�� �ε�����, �� ���� ��ġ���� ���� �ٽ� �˻��� �����Ѵ�
        offset = index + 1;
    }

    return res;
}



int main() {
    std::string source{ "kim dong hyeon" };
    //std::cout << Find2(source, "g dhy", Case::SENSITIVE) << std::endl;

    std::string target{ "kim kimkindkibdmikimkim" };
    std::vector<int> res = FindAll2(target, "kim");

    std::cout << res.size() << std::endl;
    
    for (auto x : res)
        std::cout << x << ", ";
}