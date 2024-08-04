#include<bits/stdc++.h>
using namespace std;

int remainder_(std::string a  , int b){
    int digits {} ;
    int temp {b} ;
    while (temp ){
        digits++ ;
        temp /= 10 ;
    }
    int i {digits} ;
    int num {std::stoi(string {a ,0 , static_cast<unsigned>(digits) })} ;
    while(i< a.length()){
        num = num%b;
        num = num*10 + (a[i++]-'0') ;
    }
    num = num%b ;
    return num ;

}


int gcd(string a , int b){
    if (b==0)
		return std::stoi(a);
	else
		return gcd(std::to_string(b) ,remainder_(a,b));
}

int solve(int a, string b){
    return gcd(b , a) ;
}
int main() {
    // std::cout << remainder_(10 , "11") ;
    std::cout << solve (10 , "11") ;
}