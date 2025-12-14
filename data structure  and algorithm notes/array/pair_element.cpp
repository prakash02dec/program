#include <iostream>

// sum pair element in sorted array
void pair_element(int arr[] , int size , int sum){
    int i {} , j {size -1} ;
    while(i < j){
        if(arr[i]+arr[j] == sum){
            std::cout << arr[i] << "+" << arr[j] << "=" << sum <<std::endl;
            i++;
            j--;
        }else if(arr[i]+arr[j] < sum) i++ ;
        else j-- ;
    }
}

int main (){
    int arr[] {1,2,3,4,5,6,7,8,9,10};
    pair_element(arr, 10 , 10);

    return 0 ;
}