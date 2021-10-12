#include<iostream>
#include"mystring.hpp"

int main(){
    std::cout<<std::boolalpha;
    mystring empty;
    mystring carry{"carry"};
    mystring box {carry};

    empty = "FDSGJHKJSHDA";
    empty = -empty;
    box = empty + carry;
    std::cout<<(carry != empty)<<std::endl;

    
    std::cout<<empty*3<<std::endl;
    std::cout<< carry<<std::endl;
    std::cout<< box<<std::endl;

    // empty.display();
    // carry.display();
    // box.display();

    std::cout<<empty<<std::endl;
    std::cout<< carry<<std::endl;
    std::cout<< box<<std::endl;
 
    std::cout<<std::endl;
    return 0; 
}