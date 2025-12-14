#include<bits/stdc++.h>
using namespace std ;


vector<int> sortArrayByParity(vector<int>& nums) {
        
        int i {} , j {(int)nums.size()-1} ;
        
        while(i < j){
            
            while( (nums[i]&1) != 1)
                i++ ;
            
            
            while( (nums[j]&1) == 1)
                j-- ;
            
            
            if(i < j)
            swap(nums[i] , nums[j] ) ;
        
        }

        return nums ;
    }

int main(){

    vector<int> event {0,2,4} ;
    
    auto ans = sortArrayByParity(event) ;
    for(auto ele : ans ) cout << ele << " " ;

    return 0 ;
}