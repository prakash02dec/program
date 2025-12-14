#include<bits/stdc++.h>
using namespace std;

string getHint(string secret, string guess) {
    int bulls {} , cows{} ;
    std::unordered_map<char , int > count1 {} , count2 {} ;
    for(size_t i {} ; i < secret.length() ; i++){
        if( secret[i] == guess[i] ) bulls++ ;
        else{
            count1[secret[i]]++ ;
            count2[guess[i]]++ ;
        }
    }
    for(auto it : count1){
        int x  {count2[it.first]} ; // frequecy of character in guess as same character in secret 
        int y {it.second} ;
        cows += min(x,y) ;
    }
    return std::to_string(bulls) + "A" + std::to_string(cows) + "B" ;
    
}