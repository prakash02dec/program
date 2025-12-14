#include<bits/stdc++.h> 
using namespace std ;

const int N {3000} ;

vector<vector<int>>  memo(N+1 , vector<int> (N+1 , -1)) ;

int get_lcs(const string &s ,const string &t ,int i=0 , int j=0 ){
    int &ans = memo[i][j] ;
    
    if( i == s.length()  || j == t.length() ){
        return 0 ;
    }

    if(ans != -1) return ans ;


    if(s[i] == t[j]){
        ans = 1 + get_lcs( s , t , i+ 1  , j + 1) ;
    } else {
        ans = max(get_lcs( s , t , i+1 , j ) , get_lcs( s ,t , i , j+1 ));

    }
    
    return ans ;
}

void trace_back(const string &s , const string &t , string &res , int i= 0  , int j= 0 ){
    if( i == s.length()  || j == t.length() ){
        return  ;
    }
    if(s[i] == t[j])
       res += s[i] , trace_back(s , t , res , i+1  , j + 1) ;
    else {
        if(get_lcs(s , t, i+1 , j ) == get_lcs(s , t , i ,j)) trace_back(s , t , res , i+1 , j ) ;
        else trace_back(s , t , res , i, j+1 ) ;
    }

}

int main(){

    string s , t ;
    // cin >> s >> t ;
    s = "axyb" ;
    t = "abyxb" ;

    // cout << get_lcs( s , t )  ;
    string result ;
    trace_back(s , t , result) ;
    cout << result ;
    return 0 ;

}