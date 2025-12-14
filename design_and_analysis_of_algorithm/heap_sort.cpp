#include<iostream>
#include<iomanip>
#include<ctime>

void swap(int &a ,int &b){
    int temp = a;
    a = b ;
    b = temp;
}

int left_child( int index , int size){
    int left = 2* index + 1;
    if(left >= size )
        return -1;
    return left;
}

int right_child( int index , int size){
    int right = 2* index +2;
    if(right >= size)
        return -1;
    return right;
}

void max_heapify(int *arr , int index , int size ){
    int left = left_child( index , size);
    int right = right_child( index , size);
    int max {};
    if( left != -1 && arr[left] > arr[index]) max = left; else max = index;
    if( right != -1 && arr[right]> arr[max]) max = right;

    if(max != index){
        swap(arr[index], arr[max]);
        max_heapify(arr , max , size);
    }
}

void build_heap(int *arr , int size ){
    for(int i {(size-1)/2 } ; i>=0 ; i-- )
        max_heapify(arr , i , size);
}

void heap_sort(int *arr , int size  )
{
    build_heap(arr , size);
    for(int i=size-1 ; i>0 ; i--){
        swap(arr[0], arr[size-1]);
        size--;
        max_heapify(arr, 0 , size);
    }
}

int main(){
    int size ;
    std::cout<<std::endl<<"Enter the size of input for comparison"<<std::endl;
    std::cin>>size;

    std::cout << "================================================================================================================="<<std::endl;
    std::cout << "execution time calcultion comparasion of heap sort  for "<< size <<"  no of elements" << std::endl;
    std::cout << "================================================================================================================="<<std::endl;

    int random_number {};           
    int min {1};                
    int max {size};                 
    srand(time(0));  
    
    int arr[size];
    // int arr[size] {2, 5,1,7,3,6,4} ;
    // build_heap(arr , size);

    for (size_t i{0}; i<size; ++i){
        random_number = rand() % max + min;
        arr[i] = random_number;

    }

    // std::cout<<std::endl;
    // for (size_t i{0}; i<size; ++i){
    //     std::cout<< arr[i] <<"\t";
    // }


    std::cout << std::fixed << std::setprecision(14);
    
    auto start1 = clock();
    heap_sort(arr , size);
    auto stop1 = clock();
    
    auto time_taken1 = static_cast<double> (stop1 - start1) / static_cast<double>CLOCKS_PER_SEC;

    // std::cout<<std::endl;
    // for (size_t i{0}; i<size; ++i){
    //     std::cout<< arr[i] <<"\t";
    // }
    
    std::cout << std::endl <<"================================================================================================================="<<std::endl;
    std::cout << "\nTime taken by merge sort is : " << time_taken1 << " sec "<< std::endl ;
    std::cout << "================================================================================================================="<<std::endl;

    return 0;

}