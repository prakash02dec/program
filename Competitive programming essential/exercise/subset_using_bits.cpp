#include <iostream>
#include <cstring>

void overlayNumber(char arr[] , int number){
    int j {} ;
    while(number){
        if(number&1){   
            std::cout<<arr[j] ;
        }
        number >>= 1 ;
        j++ ;
    }
    std::cout << std::endl ;
}

void generateAllSubsequences(char arr[]){
    int n= strlen(arr) ;
    for(int i {} ; i < (1<<n) ; i++){
        overlayNumber(arr , i ) ;
    }
}

int main(){
    // subsets / subsequences
    char A[100] ;
    std::cin>> A ;
    generateAllSubsequences(A) ;
    return 0 ;
}