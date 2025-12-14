#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int t {};
	std::cin>> t;
	while(t--){
        int n;
        std::cin >> n ;
	    std::string a{} , b{} ;
        std::cin >> a >> b;
        int answer {};
        bool pre_greater{false};
        for(int i {n-1} ; i >= 0 ; i-- ){
            if(a[i] < b[i] || (a[i]==b[i] && pre_greater == true)) {
                answer++ ;
                pre_greater = true;
            }
            else pre_greater = false;
        }
        std::cout << answer << std::endl ;
	}
	return 0;
}
