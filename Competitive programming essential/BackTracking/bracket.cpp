#include <bits/stdc++.h>

void bracket(std::string brac , int n , int open , int close){
    if(open == n && close == n) {
        std::cout << brac << std::endl ;
        return ;
    }
    if(open < n) bracket(brac + "(" , n , open+1 , close) ;
    if(close < open) bracket(brac + ")" , n , open , close+1) ;
}

int main() {
    bracket("" , 2 , 0 , 0) ;
    return 0 ;
}