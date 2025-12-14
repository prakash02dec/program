#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(auto s , int i , int j){
    while(i<j){
        if(s[i] != s[j]) return false ; 
        i++ ,j-- ;
    }
    return true ;
}

void split(const std::string &s , size_t start , std::vector<std::string> sub , auto &lists){
    if(start == s.length()){
        lists.push_back(sub) ;
        return ;
    }
    for(size_t i {start} ; i<s.length() ; i++){
        if(isPalindrome(s , start , i)){
            std::string temp {s ,start ,i+1} ;
            
            sub.push_back(s.substr(start , i-start+1)) ;
            split(s , i+1 , sub , lists) ;
            sub.pop_back() ;

        }
    }
}



vector<vector<string>> partition(string s) {
    std::vector<std::vector<std::string>> lists {} ;
    split(s , 0 , {} , lists);
    return lists ;
}
int main() {
    std::string example {"aab"} ;
    auto ans = partition(example) ;
    for(auto arr : ans){
        for(auto sub : arr){
            std::cout << sub << " " ;
        }
        std::cout << endl ;
    }
    // std::cout << isPalindrome(example , 0 , example.length()-1) ;
    return 0 ;
}