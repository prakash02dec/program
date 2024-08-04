#include<bits/stdc++.h>
using namespace std;


int solve(int n, vector<int> a){
    int count {}  ;
    
    for(int i {} ; i< n ; i++){
            if( a[i] == 0 && (count%2 == 0)){
                count++ ;
            }
            if( count%2 !=0 & a[i] == 1){
                count++ ;
            }
        }
    return count ;   

}

int main() {
    std::cout << solve(4 ,{0, 1, 0, 1 }) ;
    return 0 ;
}