#include <bits/stdc++.h>

int singleNumber(std::vector<int>& nums) {
    int ans {} ;
    for(const auto no : nums)
        ans = ans^no ;
    return ans ;
}