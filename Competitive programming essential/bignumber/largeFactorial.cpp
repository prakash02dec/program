#include <bits/stdc++.h> 

void multiply(std::vector<int> &a , int no , int &size){
    int carry {} ;
    for(int i {} ; i<size ; i++){
        int product {a[i]*no + carry} ;  
        carry  = product/10 ;
        a[i] = product%10 ;
    }
    while(carry){
        a[size] = carry%10 ; 
        carry /= 10 ; 
        size++ ; 
    }
}

void bigFactorial(int n){
    std::vector<int> a(10000000 , 0) ;
    a[0] = 1 ;
    int size {1} ;
    for (int i {2} ; i<=n ; i++){
        multiply(a , i , size) ;
    }
    // print the result in the reverse order 
    // size -1 to 0 ;
    for (int i {size-1} ; i>=0 ; i--){
        std::cout << a[i] ;
    }
    std::cout <<std::endl <<  "size : " << size ; 

}


int main() {
    int n {} ;
    std::cin >> n ;
    bigFactorial(n) ;
    return 0 ;
}