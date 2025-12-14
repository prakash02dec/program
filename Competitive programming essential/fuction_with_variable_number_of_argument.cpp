#include<iostream>

// function with variable number of arguments

// veriadic functions
int sum(){
    return 0 ;
}

template<typename... T>
int sum(int a, T... args ){
    return a+sum(args...);
}


int main(){
    std::cout << sum(1,2,3,4,5,6,7,8) << std::endl ;
    std::cout << sum(1,2) << std::endl ;

    return 0 ;
}
cp