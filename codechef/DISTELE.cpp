#include <iostream>
#include <map>

int main() {
    int T;
	std::cin >> T;
	while(T--){
	    int N ;
        std::cin >> N ;
        std::map<int, int> elements;
        long long answer = 1;
        int mod7 {1000'000'007};
        for(int i{} ; i<N ; i++){
            int temp;
            std::cin>>temp;
            elements[temp]++;
        }
        for(auto element : elements){
            answer *= (element.second+1) ;
            answer %= mod7 ;
        }
 
        answer -- ;
 
        std::cout << answer << std::endl ;
	}
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 