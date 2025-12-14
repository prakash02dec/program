#include<bits/stdc++.h>
using namespace std;


int solve(int n,int m, vector<int> a){
    if(n>=m){
        return 0 ;
    }
    for(int &num : a){
        num = num%m ;
    }
    int ans {1} ;
    for(int i {} ; i<n ; i++){
        for(int j {i+1} ; j<n ; j++){
            ans *=a[i]-a[j] ;
        }
        if(!ans)
            return ans ;
    }
    return ans ;
}
