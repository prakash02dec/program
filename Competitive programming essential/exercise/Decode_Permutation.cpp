#include<bits/stdc++.h>
using namespace std;

vector<int> decode(vector<int> encoded) {
    int total_xor {} , n {encoded.size()+1} ; // n => first n natural number 
    for(int i {1} ; i<=n ; i++){
        total_xor = total_xor^i ;
    }
    int x {} ; // xor of all the number except first 
    for(int i {1} ; i < encoded.size() ; i+=2){
        x = x^encoded.at(i) ;
    }
    int first {x^total_xor} ;
    std::vector<int> ans (n) ;
    ans[0] = first ; 
    for(int i {1} ; i < n ; i++){
        ans[i] = ans[i-1]^encoded[i-1] ;
    }
    return ans ;
}