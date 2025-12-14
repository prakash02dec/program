#include<bits/stdc++.h>
using namespace std;

int count_bits_hack(int n){
    int count {} ;
    while(n>0){
        // remove the last set bit from the current number 
        n = n & (n-1) ;
        count++ ;
    }
    return count ;
}

bool comp(const int &a , const int &b){
    int count_a {count_bits_hack(a) } ;  // __builtin_popcount(a)
    int count_b {count_bits_hack(b) } ;     // __builtin_popcount(b)
    if(count_a == count_b) 
        return a<b ;
    else 
        return count_a < count_b ;
}


vector<int> sortByBits(vector<int> arr) {
    std::sort(arr.begin(), arr.end() , comp) ;       
    return arr ;
}