#include <iostream>
#include <algorithm>
#include <array>

typedef long long ll;

int main(){
    int t;
    std::cin>> t;
    while (t--){
        int n;
        std::cin >> n ;
        int a[n];
        int total_odd {};
        for(size_t i {}; i < n ; i++){
            std::cin >> a[i];
            if(a[i]%2 != 0)
            total_odd++;
        }        
        std::cout << total_odd/2 <<std::endl;

    }
    return 0;
}