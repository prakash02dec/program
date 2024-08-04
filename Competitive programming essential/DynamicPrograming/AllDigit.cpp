#include<bits/stdc++.h>
#define int long long
using namespace std ;

void go(int i , int num){
    if( i == 3) {
        cout << num <<endl ;
        return ;
    }
    for(int digits {} ; digits <= 9 ; digits++){
        
        go(i+1 , num*10 + digits ) ;
    }
}

string s ;
void go(int i , bool last  , int num){
    if(i == s.size() ){
        cout << num << endl ;
        return ;
    }

    int till = last ? (s[i] - '0') : 9 ;
    for (int digits {} ; digits <= till ; digits++){
        go(i +1 , last && (digits == till ) , num*10 + digits ) ;
    }
}




int32_t main(){ 
    cin >> s;

    go(0, 1 , 0) ;

    return 0 ;
}