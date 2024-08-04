#include <iostream>

// duplicate finding method one 
// O(n)
void duplicate1(int arr[] , int size){
    int lastDuplicate {} ;
    std::cout << std::endl << "duplicate elements are : ";
    for(int i{} ; i < size-1 ; i++ ){
        if(arr[i] == arr[i+1] && arr[i] != lastDuplicate){
            std::cout << arr[i] <<" ";
        }
    }
}

//  duplicate finding with freqency 
// O(n)
void duplicate2(int arr[] , int size ) {
    std::cout << "\nduplicate element : \n";
    for(int i {} ; i <size-1 ; i++){
        if(arr[i]==arr[i+1]){
            int j = i+1 ;
            while(arr[i]== arr[j]) j++;
            std::cout << arr[i] << " : " << j-i << std::endl;
        }
    }
}

// duplicate with hashing 
void duplicate3(int arr[] , int size){
    std::cout << "\n duplicate element : \n";
    int hash[ arr[size-1]+1 ] {0 };
    for(int i {} ; i < size ; i++){
        hash[arr[i]]++;
    }
    for(int i {} ; i < arr[size-1]+1 ; i++){
        if(hash[i]>1) std::cout<<i <<" "<< hash[i] <<std::endl;
    }
}
// duplicates in a unsorted array O(n2)
void duplicate4(int arr[] , int size){
    for(int i {}; i < size ; i++){
        int count {1};
        if(arr[i] != -1 )
        for(int j {i+1 } ; j < size ; j++){
            if(arr[i] == arr[j] ){
                arr[j] = -1;
                count++;
            }
        }
        std::cout << arr[i] << " " << count ;
    }   
}

// duplicated in a unsorted array with hashing O(n)

int main(){
    int arr [] {1 ,1 ,2,3,4,4 ,5 ,6,7,8,8,9} ;
    duplicate2(arr ,12 );


    return 0 ; 
}