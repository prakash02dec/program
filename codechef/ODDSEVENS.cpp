#include <iostream>
using namespace std;

int main() {
	int t {};
	std::cin>> t;
	while(t--){
	    int a {} , b{};
        std::cin >> a >> b;
        int n{a+b};
        if(n%2==0)
        std::cout << "Bob" <<std::endl;
        else
        std::cout << "Alice" <<std::endl;
	}
	return 0;
}
