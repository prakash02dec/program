#include <iostream>

// Finding Single Missing Element in an Array
// sum of 1st n natural number approach

int missing_element(int arr[] , int size ){
    int n {arr[size-1]} , sum {};
    int nth_sum { (n*(n+1))/2 } ;
    for(int i {} ; i < size ; i ++){
        sum += arr[i];
    }

    if(nth_sum-sum != 0) 
    return nth_sum-sum ;
}

// 2nd method index and element difference approace
int missing_element2(int arr[] , int size){
    int diff = arr[0]-0;
    for(int i {}; i < size ; i++){
        if(arr[i]-i != diff) return i + diff ; 
    }
}

int multiple_missing(int arr[] , int size){
    int diff = arr[0]-0;
    std::cout<< "element missing are : " ;
    for(int i {}; i < size ; i++){
        if(arr[i]-i != diff) {
            while(diff< arr[i]-i){
                std::cout<< i + diff << " ";
                  diff++;
            }
           // much faster than above
        }
    }
}

// 3rd member by hashing 
int missing_number(int arr[] , int size){
    int max = arr[0];
    for (int i{}; i < size; i++){
        if (arr[i] > max)
            max = arr[i];
    }
    bool hash[max+1] {false};
    for(int i {} ; i< size ; i++){
        hash[arr[i]] = true;
    }
    std::cout << "missing element are : "; 
    for(int i {1  } ; i  < max+1 ; i++){
        if(!hash[i])
        std::cout <<  i <<" ";
    }
    

}


int main (){
    int arr[] {1,2,4,6,7,8,10};
    
    std::cout << missing_element2(arr ,7 ) <<std::endl;
    int n ;
    multiple_missing(arr , 7);
    missing_number(arr,7);
    return 0 ;
}