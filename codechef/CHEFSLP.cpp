#include <iostream>
using namespace std;

int main() {
    int T;
	std::cin >> T;
	while(T--){
	    int N , L , X ;
	    std::cin >> N >> L >> X ;
	    int R {N-L} ;
        R > L ? (std::cout << L * X << std::endl ) : (std::cout << R*X << std::endl );
	}
	return 0;
}
