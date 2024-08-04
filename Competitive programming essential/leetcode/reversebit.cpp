#include<bits/stdc++.h>
using namespace std ;

uint32_t reverseBits(uint32_t n) {
        uint32_t ans {} ;
        for(int i {} ; i < 32 ; i++){
            int lastbit {} ;
            lastbit = (n>>i)&1 ;
            cout << lastbit << " " <<(lastbit<<(31-i))  ;
            if(lastbit)
            ans = ans|(1<<(31-i)) ;
            cout << " " << ans << endl ;
        }
        return ans ;
    }

int main() {
    cout<< reverseBits(48) ;
    return 0 ;
}