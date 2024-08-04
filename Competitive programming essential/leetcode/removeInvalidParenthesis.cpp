#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void dp(const string &s ,int idx , string temp , int open , int close ,set <string> &ans , int total_remove , int &global_min_remove  ){
        if(open == close && idx == s.length() ){
            if(total_remove < global_min_remove ) {
                ans = {temp} ;
                global_min_remove = total_remove ;
            }
            else if(total_remove == global_min_remove){
            //    if( find(ans.begin(), ans.end(), temp) == ans.end())
                ans.insert(temp) ;}
        }
        if(idx == s.length()) return ;
        if(s[idx] == '(' && close <= open ){
            dp(s , idx+1 , temp+"(" , open +1 , close , ans , total_remove , global_min_remove) ;
            dp(s , idx+1 , temp , open , close , ans , total_remove+1 , global_min_remove) ;
        }
        else if(s[idx] == ')'  ){
            if( close < open)
            dp(s , idx+1 , temp+")" , open , close +1 , ans , total_remove , global_min_remove) ;
            dp(s , idx+1 , temp , open , close , ans , total_remove+1 , global_min_remove) ;
        }else{
            dp(s , idx+1 , temp+s[idx] , open , close , ans , total_remove , global_min_remove) ;
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        set<string> ss  ;
        int min = 1000 ;
        cout << s.length() ;
        dp(s ,0 , "" , 0 , 0 , ss , 0 , min) ;
        vector<string> ans {ss.begin() , ss.end()} ;
        return ans ;
    }
};

int32_t main(){
    vector<string> ans = removeInvalidParentheses("(a)())()") ;
    for(auto s : ans){
        cout << s << " " ;
    }
    cout << endl ;
    return 0 ;
}			