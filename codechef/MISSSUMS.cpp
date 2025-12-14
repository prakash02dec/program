#include <iostream>

using namespace std;

int main() {
	int t {};
	std::cin>> t;
	while(t--){
	    int n;
        std::cin >> n;
        for(size_t i{1} ; i<=100'000 && n >0; i++)
        if(i%2 != 0) {
            std::cout << i <<" ";
            n--;
        }
        std::cout << std::endl;
	}
	return 0;
}
