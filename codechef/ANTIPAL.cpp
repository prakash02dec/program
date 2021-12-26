#include <iostream>
#include <deque>

int main() {
    int T;
	std::cin >> T;
	while(T--){
	int N;
    std::cin >> N;
    if( N%2 == 0 ){
        std::deque<int> string;
        for(int i {}; i <N/2 ; i++){
            if(i%2 ==0){
            string.push_front(1);
            string.push_back(0);
            }else{
            string.push_front(0);
            string.push_back(1); 
            }
        }   
        
        for (auto it = string.begin(); it != string.end(); ++it)
            std::cout << *it;
        
    }else{
        std::cout<<"-1";
    }
    std::cout << std::endl;
	}
	return 0;
}
