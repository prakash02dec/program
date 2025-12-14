#include<bits/stdc++.h>
using namespace std;

int gcd(int a , int b){
    if(b == 0 ) return a ;
    return gcd(b , a%b);
}

vector<int>solve(int n,int m, vector<int> a, vector<int> b){
    int gcd_common {0} ;
    std::cerr << n << " " << m << " " << std::endl ;

    vector<int> ans ; 
    for(int i {1} ; i<n ; i++){
        gcd_common = gcd(abs(a[i]-a[0]) , gcd_common) ;
    }
    for(int i {0} ; i <m ; i++ ){
        ans.push_back(gcd( a[0] + b[i] , gcd_common));
    }
    return ans ;
       
}

int main() {
    vector<int> ans = solve(4 ,4 ,{1, 25, 121, 169}, {1, 2, 7, 23}) ;
    std::cout << gcd(2, 24) ;
    for(auto ele : ans){
        std::cout << ele << " " ;
    }
    return 0 ;
}