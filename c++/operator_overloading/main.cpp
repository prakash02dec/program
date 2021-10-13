#include<iostream>
#include"mystring.hpp"

int main(){
    mystring empty;
    mystring carry("carry");
    mystring box {carry};

    empty.display();
    carry.display();
    box.display();

    std::cout<<std::endl;
    return 0; 
}