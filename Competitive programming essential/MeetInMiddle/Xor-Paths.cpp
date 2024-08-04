#include<bits/stdc++.h>
using namespace std;

void top_xor(int x , int y ,int n , int m ,int steps, auto a , int cur_xor , auto &xor_table){
    if(steps== 0){
        cur_xor ^= a[x][y] ;
        xor_table[x][y][cur_xor]++ ;
        return ;
    }
    if(x+1< n)
        top_xor(x+1 , y , n , m , steps-1 , a , cur_xor^a[x][y] , xor_table) ;
    if(y+1 < m)
        top_xor(x , y+1 , n , m , steps-1 , a , cur_xor^a[x][y] , xor_table) ;
}

int bottom_xor(int x , int y ,int n  , int m ,int steps , auto a , int cur_xor , auto &xor_table  ){
    if(steps== 0){
        return xor_table[x][y][cur_xor] ; 
    }
    int total {} ;
    if(x-1 >=0)
        total += bottom_xor(x-1 , y , n , m , steps-1 , a , cur_xor^a[x][y] , xor_table) ;
    if(y-1 >=0)
        total += bottom_xor(x , y-1 , n , m , steps-1 , a , cur_xor^a[x][y] , xor_table) ;
        
    return total ;
}


long long solve(int n, int m, long long k, vector<vector<long long>> a){
    // n= 3 ; m= 3 ; k= 11 ; a= {{2, 1, 5}, {7, 10, 0}, {12, 6, 4}} ;
    std::map<int , int> xor_table[21][21] ;
    cerr << n << " " << m << endl ;
    int steps {n+m-2} ;
    top_xor(0 , 0 ,n , m ,steps/2, a , 0 , xor_table) ;
    int ans = bottom_xor(n-1 , m-1 ,n, m ,steps-steps/2, a , k , xor_table) ;
    cerr << ans ;
    return ans ;

}