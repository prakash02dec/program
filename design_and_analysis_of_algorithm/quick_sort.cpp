#include<iostream>
#include<iomanip>
#include<ctime>

void quick_sort(int , int , int*);
int partition( int , int , int* );
void swap(int* , int* );

bool ascending {true};

int size {1000};



void quick_sort(int low , int high , int arr[]){
    if( low < high ){
        int pivote { partition(low , high , arr ) };
        quick_sort(low , pivote -1 , arr);
        quick_sort( pivote +1 , high , arr );
    }
}



int partition(int low , int high , int arr[]){
    if (ascending){
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
    int pivote {arr[high]} , left{low} , right {high} ;
    
    while(left < right){
        while(arr[left] > pivote )
        left++;
        while( arr[right] <= pivote )
        right--;
        
        if( left < right ){
            int temp {arr[left]};
            arr[left] = arr [right];
            arr[right] = temp;
        }

    }
    arr[high] = arr [left];
    arr[left] = pivote;
    return left;


}


int main(){

    char response;
    // std::cout<<std::endl<< "do you want sort in descending (y/n)" << std::endl;
    // std::cin >> response;
    // if(response == 'y' || response == 'Y'){
    //     ascending = false;
    // }
    

    std::cout<<std::endl<<"Enter the size of input for comparison"<<std::endl;
    std::cin>>size;

    std::cout << std::endl << "================================================================================================================="<<std::endl;
    std::cout << "execution time calculation comparsion  quick sort  for  "<< size <<"  no of random no input" << std::endl;
    std::cout << "================================================================================================================="<<std::endl;

    int random_number {};           
    int min {1};                
    int max {size};                 
    srand(time(0));  
    
    int arr[size] ;
    for (size_t i{0}; i<size; ++i){
        random_number = rand() % max + min;
        arr[i] = random_number;

    }

    // for (auto ele : arr) std:: cout << "\t" << ele;
    // std::cout<<std::endl;
    std::cout << std::fixed << std::setprecision(7);
    
    auto start1 = clock();
    quick_sort(0 , size-1 , arr);
    auto stop1 = clock();
    
    auto time_taken1 = static_cast<double> (stop1 - start1) / static_cast<double>CLOCKS_PER_SEC;
    // for (auto ele : arr) std:: cout << "\t" << ele;
    // std::cout<<std::endl;

    std::cout << "================================================================================================================="<<std::endl;
    std::cout << "\nTime taken by quick sort for random input is : " << time_taken1 << " sec "<< std::endl ;
    std::cout << "================================================================================================================="<<std::endl;




    std::cout << std::endl << "================================================================================================================="<<std::endl;
    std::cout << "execution time calculation comparsion  quick sort  for  "<< size <<"  no of soted input in increasing order" << std::endl;
    std::cout << "================================================================================================================="<<std::endl;

    // for (auto ele : arr) std:: cout << "\t" << ele;
    // std::cout<<std::endl;
    std::cout << std::fixed << std::setprecision(7);
    
    auto start2 = clock();
    quick_sort(0 , size-1 , arr);
    auto stop2 = clock();
    
    auto time_taken2 = static_cast<double> (stop2 - start2) / static_cast<double>CLOCKS_PER_SEC;
    // for (auto ele : arr) std:: cout << "\t" << ele;
    // std::cout<<std::endl;

    std::cout << "================================================================================================================="<<std::endl;
    std::cout << "\nTime taken by quick sort for  input increasing order is : " << time_taken2 << " sec "<< std::endl ;
    std::cout << "================================================================================================================="<<std::endl;




    ascending=false;
    quick_sort(0 , size-1 , arr);
    ascending = true;

    std::cout << std::endl << "================================================================================================================="<<std::endl;
    std::cout << "execution time calculation comparsion  quick sort  for  "<< size <<"  no of input in decreasing input" << std::endl;
    std::cout << "================================================================================================================="<<std::endl;

    // for (auto ele : arr) std:: cout << "\t" << ele;
    // std::cout<<std::endl;
    std::cout << std::fixed << std::setprecision(7);
    
    auto start3 = clock();
    quick_sort(0 , size-1 , arr);
    auto stop3 = clock();
    
    auto time_taken3 = static_cast<double> (stop3 - start3 ) / static_cast<double>CLOCKS_PER_SEC;
    // for (auto ele : arr) std:: cout << "\t" << ele;
    // std::cout<<std::endl;

    std::cout << "================================================================================================================="<<std::endl;
    std::cout << "\nTime taken by quick sort for input in decreasing is : " << time_taken3 << " sec "<< std::endl ;
    std::cout << "================================================================================================================="<<std::endl;




    std::cout << std::endl << "================================================================================================================="<<std::endl;
    std::cout << "execution time calculation comparsion  quick sort  for  "<< size <<"  no of same input" << std::endl;
    std::cout << "================================================================================================================="<<std::endl;

    for (auto &ele : arr) ele = arr[0] ;
    std::cout << std::fixed << std::setprecision(7);
    
    auto start4 = clock();
    quick_sort(0 , size-1 , arr);
    auto stop4 = clock();
    
    auto time_taken4 = static_cast<double> (stop4 - start4) / static_cast<double>CLOCKS_PER_SEC;
    // for (auto ele : arr) std:: cout << "\t" << ele;
    // std::cout<<std::endl;

    std::cout << "================================================================================================================="<<std::endl;
    std::cout << "\nTime taken by quick sort for same input is : " << time_taken4 << " sec "<< std::endl ;
    std::cout << "================================================================================================================="<<std::endl;
    
    return 0;
}