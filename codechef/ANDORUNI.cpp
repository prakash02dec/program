#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int t {};
	std::cin>> t;
	while(t--){
	    int n;
        std::cin >> n;
        std::vector<int> a(n) ;
        int ans_bits[32] {0} ;
        for(int i {} ; i < n; i++ ){
            int temp {};
            std::cin >> a[i] ;
            for(int j {} ; j< 32 ; j++){
                temp = a[i]>>j;
                if(temp & 1) ans_bits[j]++;
            }
        }
        int ans {};
        for(int i {} ; i < 32 ; i++){
            if(ans_bits[i]>1) ans += std::pow(2,i);
        }
        std::cout << ans << std::endl;
        
	}
	return 0;
}
