#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main() {
	int t {};
	std::cin>> t;
	while(t--){
        int n;
	    std::cin >> n;
        int a[n];
        std::map<int, int > remainder ;
        remainder[0] = remainder[2] = remainder[1] =0 ;
        for(size_t i {}; i<n ; i++){
            std::cin >> a[i];
            remainder[ a[i]%3 ]++;
        }
        int answer {0};
        if(remainder[2] == remainder[1])
        std::cout << remainder[2] << std::endl ;
        else{
        answer = abs( remainder[2] - remainder[1]);
        if(answer %3 == 0 && remainder[2] > remainder[1]){
             std::cout << remainder[2] -1 << std::endl ;
        }
        else
        std::cout << "-1"<<std::endl;
        }
	}
	return 0;
}