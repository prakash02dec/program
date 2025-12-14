#include<bits/stdc++.h>
using namespace std; 

int longestValidParentheses(string s) {
    stack<int> st ;
    st.push(-1) ;
    int maxLength {} ; 

    for(int idx {} ; idx < s.size()  ; idx) {
        if(s[idx]  == '(' ){
            st.push(idx) ;
        }else{
            st.pop() ;
            if(st.empty()){
                st.push(idx) ;
            }else{
                maxLength = max(maxLength , idx - st.top()) ;
            }

        }

    }
    return maxLength ;
}


int main() {
    cout <<longestValidParentheses(")()()") ;
    return 0 ;
}