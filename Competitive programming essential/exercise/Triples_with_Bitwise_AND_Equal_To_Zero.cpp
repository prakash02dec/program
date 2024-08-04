#include<bits/stdc++.h>
using namespace std;

int countTriplets(vector<int> nums) {
    std::map<int, int> AND_of_Two ; // we storing the frequency of result of and of two number
    for(auto x : nums)
        for(auto y : nums)
            AND_of_Two[x&y]++ ;
    int ans {} ;
    for(auto twos_and : AND_of_Two)
        for(auto x : nums){
            if((twos_and.first&x) == 0)
                ans += twos_and.second ;
        }
    return ans ;
}

int main() {
    return 0 ;
}