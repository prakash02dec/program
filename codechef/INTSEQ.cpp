#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t {};
	std::cin>> t;
	while(t--){
        int k {};
        std::cin >> k ;
        int ans {};
        while(k%2 == 0){
            ans++;
            k/=2;
        }
        std::cout << ans <<endl;
        
	}
	return 0;
}
