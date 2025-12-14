#include<bits/stdc++.h>
using namespace std;

void combinations(const std::string &digits ,size_t n ,std::string temp ,  std::vector<std::string> &ans){
    
    if(n == digits.length() ){
        ans.push_back(temp) ;
        return ;
    }
    int digit {digits[n] - '0'} ;
    for(int i {} ; i < 3 ; i++ ){
        char ch {static_cast<char>(97 + 3*(digit - 2) + i)} ;
        combinations(digits , n+1 , temp+ch , ans );
    }
}

vector<string> letterCombinations(string digits) {
    if(digits.length() == 0) return { } ;
    std::vector<string> ans {} ;
    combinations(digits , 0 ,"" , ans) ;
    return ans ;
}

int main() {
    std::vector <string > ans {letterCombinations("23")};
    for(const auto &ele : ans ){
        std::cout << ele << " " ;
    }
    return 0 ;
}