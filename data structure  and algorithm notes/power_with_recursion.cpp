#include<iostream>

using namespace std;

int power(int m , int n ){
    if(n==0){
        return 1;
    }
    if(n % 2 == 0){
        return power(m*m , n/2);
    }else{
        return m * power( m * m , (n-1)/2 );
    }
}

int ipower(int m , int n ){
    int result {1};
    while ( n > 0 ){
        if(n%2 == 0){
        m = m*m ;
        n /= 2 ;
        }
        else{
            result *= m ;
            n = (n-1) ;
        } 
    }
    return result ;
}

int main (){
    int r = ipower(2,3);
    cout << r << endl ; 

    return 0 ;

}