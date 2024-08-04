#include<bits/stdc++.h>
using namespace std;

vector<long long> SubsetSum(const vector<int> &a ){
    int n {(int)a.size()} ;
    vector<long long> sums {} ;
    for(int i{} ; i< (1<<n) ; i++){
        long long sum {} ;
        for(int j {} ; j < n ; j++ ){
            if(i&(1<<j)) sum += a[j] ;
        }
        sums.push_back(sum) ;
    }
    // for(const auto &ele : sums) cerr<< ele << " " ; 
    // cerr << endl ;
    return sums ;
}


long long solve(int n,int x, vector<int> a){
    std::vector<int> left , right ;
    
    for(const auto &ele : a) cerr<< ele << " " ; 
    cerr << endl ;
    
    for(int i {} ; i<n ; i++)
        (i<=n/2) ? left.push_back(a[i]) : right.push_back(a[i]) ;
    
    for(const auto &ele : left) cerr<< ele << " " ; 
    cerr << endl ;
    for(const auto &ele : right) cerr<< ele << " " ; 
    cerr << endl ;
    vector<long long> leftSubsetSum {SubsetSum(left)} ;
    vector<long long> rightSubsetSum {SubsetSum(right)} ;
    for(const auto &ele : leftSubsetSum) cerr<< ele << " " ; 
    cerr << endl ;
    sort(rightSubsetSum.begin() , rightSubsetSum.end() ) ;
    int ans {} ;
    for(const auto &ele : leftSubsetSum){
        ans += upper_bound(rightSubsetSum.begin() , rightSubsetSum.end() , x - ele) - lower_bound(rightSubsetSum.begin() , rightSubsetSum.end() , x-ele ) ;
    }
    
    return ans ;
    
    
}