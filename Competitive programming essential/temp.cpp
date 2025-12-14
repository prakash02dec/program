class Solution {
public:

    bool hasIncreasingSubarrays(const vector<int>& nums,const int k) {
        bool ans {false} ;
        int n {(int)nums.size()} ;

        if(k == 1 && n >= 2) return true ;

        for(int i {} ; i < n - 2*k +1 ; i++){
            int j {i+1} ;
            while(j < n && j-i +1 <= k && nums[j] > nums[j-1] ){
                j++ ;
            }
            j-- ;
            if(j-i+1 == k ){
                ans = true ;
            }else{
                ans = false ;
                continue ;
            }
            // cout << "j : " << j << endl ;
            j++ ;
            int l {j+1} ;
            while(l < n && l-j +1 <= k && nums[l] > nums[l-1] ){
                l++ ;
            }
            l-- ;
            if(l-j+1 == k ){
                ans = ans & true ;
            }else{
                ans = ans & false ;
                continue ;
            }
            // cout << "l : " << l << endl ;
            if(ans){
                return ans ;
            }
        }

        return false ;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n {(int)nums.size()} ;
        int e {n/2 +1} ;
        int s {1} ;
        int ans {};
        while(s <= e){
            int k = (s+e)/2 ; // mid
            if(hasIncreasingSubarrays(nums, k)){
                ans = k ;
                s = k+1 ;
            }else {
                e = k-1 ;
            }
        }
        return ans ;
    }
};