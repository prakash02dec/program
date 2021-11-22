#include <iostream>
using namespace std;

int main() {
	int t {};
	std::cin>> t;
	while(t--){
	    int n;
        std::cin >> n;
        if(n%2==0)
        std::cout << n <<std::endl;
        else
        std::cout << n-1 <<std::endl;
	}
	return 0;
}
