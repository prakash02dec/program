#include<bits/stdc++.h>
using namespace std ;

string convert(string s, int numRows) {
        string k[1001] ;
        string ans ;
        int i {} , j {} ;
        while(s.length() != i){
            j = i/numRows ;
            if(j&1 ){
                k[numRows -1 - (i%numRows) ] += s[i] ;
            }else{
                k[(i%numRows) ] += s[i] ;
            }
            i++ ;
        }
        for( i = 0 ; i < numRows ;i++){
            cout << k[i] <<endl ;
            ans += k[i] ;
        }
        return ans ;
    }

int32_t main(){
    string ans = convert("PAYPALISHIRING" , 3) ;
    cout << ans ;
    return 0 ;
}			