#include<iostream>
#include<iomanip>
#include<ctime>

void merge_sort(int  , int  , int *);
void merge(int , int , int , int* );
void quick_sort(int , int , int*);
int partition( int , int , int* );
void swap(int* , int* );

int size {1000};


void merge_sort(int low , int high , int* arr ){

    if(low < high){
        int mid = (low + high)/2;
        merge_sort(low , mid , arr);
        merge_sort(mid+1, high , arr);
        merge(low, mid , high , arr);
    }
    else 
    return ;

}

void merge(int low , int mid , int high , int* arr){

    int left {low} ;
    int  right {mid+1};
    int temp[size];
    
    size_t i {};
    for( i = low  ; left <= mid && right <= high ; i++){
        if (arr[left] <= arr [right])
            temp[i] = arr[left++];
        else
            temp[i] = arr[right++];
    }

    while(left <= mid )
        temp[i++] = arr[left++];
    
    while(right <= high)
        temp[i++] = arr[right++];
    
    for (i =low ; i<=high ; i++)
        arr[i] = temp [i];

}


void quick_sort(int low , int high , int arr[]){
    if( low < high ){
        int pivote { partition(low , high , arr ) };
        quick_sort(low , pivote -1 , arr);
        quick_sort( pivote +1 , high , arr );
    }
}

int partition(int low , int high , int arr[]){
    int pivote {arr[low]} , left{low} , right {high} ;

    while(left < right){
        while(arr[left] <= pivote )
        left++;
        while( arr[right] > pivote )
        right--;
        
        if( left < right ){
            int temp {arr[left]};
            arr[left] = arr [right];
            arr[right] = temp;
        }

    }
    arr[low] = arr [right];
    arr[right] = pivote;
    return right;
}


int main(){

    std::cout<<std::endl<<"Enter the size of input for comparison"<<std::endl;
    std::cin>>size;

    std::cout << "================================================================================================================="<<std::endl;
    std::cout << "execution time calcultion comparasion of merge sort and quick sort  for "<< size <<"  no of elements" << std::endl;
    std::cout << "================================================================================================================="<<std::endl;

    int random_number {};           
    int min {1};                
    int max {size};                 
    srand(time(0));  
    
    int arr1[size] ,  arr2[size];
    
    for (size_t i{0}; i<size; ++i){
        random_number = rand() % max + min;
        arr1[i] = arr2[i] = random_number;

    }

    std::cout << std::fixed << std::setprecision(14);
    
    auto start1 = clock();
    merge_sort(0 , size-1 , arr1);
    auto stop1 = clock();
    
    auto time_taken1 = static_cast<double> (stop1 - start1) / static_cast<double>CLOCKS_PER_SEC;
    
    std::cout << "================================================================================================================="<<std::endl;
    std::cout << "\nTime taken by merge sort is : " << time_taken1 << " sec "<< std::endl ;
    std::cout << "================================================================================================================="<<std::endl;

    auto start2 = clock();
    quick_sort(0, size-1 , arr2);
    auto stop2 = clock();

    double time_taken2 = static_cast<double> (stop2 - start2) / static_cast<double>CLOCKS_PER_SEC;

    // for(auto i : arr1){
    //     std::cout<<i<< "\t";
    // }
    // std::cout<<std::endl;
    // std::cout << "================================================================================================================="<<std::endl;
    // std::cout << "================================================================================================================="<<std::endl;
    // for(auto i : arr2){
    //     std::cout<<i<< "\t";
    // }
    // std::cout<<std::endl;

    std::cout << "================================================================================================================="<<std::endl;
    std::cout << "\nTime taken by quick sort is : " << time_taken2 << " sec "<< std::endl ;
    std::cout << "================================================================================================================="<<std::endl;
    
    return 0;
}