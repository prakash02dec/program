// using recursion

#include<iostream>
using namespace std;

double exp(int x , int n){
    static double p=1 , f=1 ;
    double r; 
    if(n == 0)
        return 1 ;
    r = exp(x , n-1);
    p = p*x;
    f = f*n;
    return r + p/f ;
}
// now with honors rule

double exp1(int x , int n){
    static double s; 
    if(n == 0)
        return s;
    s= 1+ x* s/n;
    return exp1(x , n-1);
}


int main (){
    cout << exp1(2,10);
    return 0 ;
}