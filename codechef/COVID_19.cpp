#include <iostream>
using namespace std;

int main() {
	int t {};
	std::cin>> t;
	while(t--){
	    int n , m ;
        cin >> n >> m ;
        n = n/2 +1;
        m = m/2 +1 ;
        std::cout << m*n << endl;

	}
	return 0;
}
