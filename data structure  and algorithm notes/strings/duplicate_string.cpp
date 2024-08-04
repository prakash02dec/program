#include <iostream>

int main(){
    char a[] = "finding" ;
    long int h { 0} , x  {0} ;
    for( int i = 0 ; a[i] !='\0' ; i++){
        x = 1;
        x = x << (a[i]-97);
        if(x&h){
            std::cout << a[i] << " is duplicate \n";
        } else{
            h= h | x; 
        }
    }
    return 0 ;

}