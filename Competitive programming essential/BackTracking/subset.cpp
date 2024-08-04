#include <bits/stdc++.h> 

void findSubset(char *input , char *output , int i  , int j){
    if(input[i] == '\0'){
        output[j] = '\0' ;
        std::cout << output << std::endl;
        return ;
    }
    output[j] = input[i] ;
    findSubset(input , output , i+1 , j+1) ; // include ith
    findSubset(input , output , i+1 , j) ; // exclude ith
}


int main() {
    char input[100]  {"abc"};
    char output [100] {};
    findSubset(input , output ,0,0 );


    return 0 ;
}