#include <iostream>

typedef long long ll;

int main() {
	int t {};
	std::cin>> t;
	while(t--){
	    ll sum {};
		int x{} , y {};
		std::cin >> x >> y;
		sum = x + 2*y;
		if(sum%2==0)
		std::cout<< "YES" << std::endl;
		else
		std::cout << "NO" << std::endl;
	}   
	return 0;
}