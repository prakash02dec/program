#include<bits/stdc++.h>
using namespace std;

int distributeCandies(vector<int> candies) {
   std::unordered_set<int> set {candies.begin(),candies.end()} ;
   return (set.size()<candies.size()/2 ? set.size() : candies.size()/2 ) ;
}

int main(){
    return 0 ;
}