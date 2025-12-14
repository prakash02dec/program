#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t {};
	std::cin>> t;
	while(t--){
	    int n {} , k {};
        std::cin >> n >> k;
        std::cout << std::ceil(static_cast<double>(n)/k) << std::endl;

	}
	return 0;
}
