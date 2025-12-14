#include<bits/stdc++.h>
using namespace std;

int rangeBitwiseAnd(int left, int right) {
    int count {} ;
    while(left != right){
        left >>= 1 ;
        right >>= 1 ;
        count++ ;
    }
    return left <<= count ;
}