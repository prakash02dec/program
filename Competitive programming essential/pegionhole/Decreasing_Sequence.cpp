#include<bits/stdc++.h>
using namespace std;

int solve(int L, int R){
    std::cout << L << " " << R << std::endl; 
    if(L==1 || R-L >= L ){
        return -1 ;
    }else{
        return R ;
    }
}