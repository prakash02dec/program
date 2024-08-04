// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
#include<bits/stdc++.h>

int firstUniqChar(std::string s) {
       std::unordered_map<char , int > hash {} ;
       for(int i {}; i< s.length(); i++){
           hash[s[i]]++ ;
       }
       for(int i {}; i< s.length(); i++){
           if(hash[s[i]] == 1 ){
               return i ; 
           }
       }
       return -1  ;
}

int main(){
    std::string s{"codingminute"};
    std::cout << firstUniqChar(s) ;
    return 0 ;
}