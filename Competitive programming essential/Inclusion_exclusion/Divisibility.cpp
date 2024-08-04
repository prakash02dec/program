#include<bits/stdc++.h>
using namespace std;

int numDivisible(int l,int r, vector<int> arr){
    sort(arr.begin(),arr.end()) ;
    int ans {} ;
    cerr << "l : " << l << " r : " << r << endl ;
    for (auto ele : arr) cerr << ele << " " ;
    for (int i {1} ; i < (1<<arr.size()) ; i++){
        int lcm {1} ;  
        for ( int j {0} ; j< arr.size() ; j++){
            if(i&(1<<j)){
                cerr << arr[j] << "*" ;
                lcm *= arr[j] ;
            }
            if(lcm >r )  break ;
            
        }
        cerr << " : " << (int)r/lcm - (int)l/lcm<< endl ;
        if(lcm > r) continue ;
        if(__builtin_popcount(i)&1) ans += (int)r/lcm - (int)l/lcm ;
        else ans -= r/lcm - l/lcm ;
        
    }

    return ans ;
}