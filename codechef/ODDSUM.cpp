#include <iostream>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while(T--){
        long long N;
        std::cin >> N;
        // if(N ==1 ){
        //     std::cout << "0\n";
        // }
        long long answer {1};
        if(N <= 2 ){
            std::cout << answer <<"\n";
        }
        else{
            N=N-2;
            // std::cout << N << "\n";
            answer += N*( 4 + (N-1)*2)/2 ;
            std::cout << answer << "\n";
        }
    }
	return 0;
}
