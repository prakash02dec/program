#include <iostream>
using namespace std;

int main() {
	int t {};
	std::cin>> t;
	while(t--){
	    int x{} , y{} , a{} , b{} , k{} ;
	    std::cin >> x >> y >>a >>b >>k;
	    x += a*k;
	    y += b*k;
	    if(x<y)
	    std::cout << "PETROL" << std::endl;
	    else if(x>y)
	    std::cout << "DIESEL" << std::endl;
	    else
	    std::cout << "SAME PRICE" << std::endl;
	}   
	return 0;
}