#include <cctype>
#include <deque>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string& s){
    std::stack<char> str ;
    std::queue<char> str1 ;

    for(const char &c : s){
        if(std::isalpha(c)){
            str.push(std::toupper(c));
            str1.push(std::toupper(c));
        }
    }
    while(!str.empty()){
        if (str.top() == str1.front()){
            str.pop(); 
            str1.pop();
            continue;
        }
        return false;
    }
    return true;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}