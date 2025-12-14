#include<iostream>
#include<iomanip>
#include<ctime>
#include<random>
#include<chrono>

constexpr int n {1000};


bool binary_search(int arr[] , int key){
    int  low {0}, high {n-1}, mid {(low+high)/2};

    while (low <= high) {
        if (arr[mid] < key)
        low = mid + 1;
        else if (arr[mid] == key) {
        return true;
        }
        else
        high = mid - 1;
        mid = (low + high)/2;
  }
  
  return false;
}

bool linear_search( const int arr[] , int key){
    for(size_t i {0} ; i<n; i++)
    if(arr[i] == key)
    {
        return true;
    }

    return false;
}
void insertion_sort(int arr []){
    
    int  temp{};
    size_t  i{}, j{};
    for (i = 1; i <= n - 1; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }


}

int main()
{
    std::cout<<std::endl<< "execution time calcultion for "<< n <<" elements";

    int random_number {};           
    int min {1};                
    int max {n};  
          
    srand(time(nullptr));  
    
    int arr[n] {}, arr1[n] {} ;
    
    for (size_t i{0}; i<n; ++i){
        random_number = rand() % max + min;
        arr[i] =  random_number;
    }

    // merge_sort(0,n,arr);
    insertion_sort(arr);
    for (size_t i = 0; i < n; i++)
    {
        arr1[i]=arr[i];
    }

    

    int key {arr[n-1]}; 
    std::cout<<"\ncase 3 finding any middle element "<< key<<std::endl;
    
    
    std::cout << std::fixed << std::setprecision(10);

    auto start1 = std::chrono::high_resolution_clock::now();
    // clock_t start1{}, end1{};
    // start1 = clock();

    if(linear_search(arr , key)) std::cout<<"found";
    else std:: cout<< "not found";
    std::cout<<std::endl;

    auto stop1 = std::chrono::high_resolution_clock::now();
    // end1 = clock();


    // double time_taken1 = static_cast<double> (end1 - start1) / static_cast<double>CLOCKS_PER_SEC;
     auto time_taken1 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop1 - start1);
    std::cout << "\nTime taken by  linear_search  is : " <<time_taken1.count()<< " nanosec "<<std::endl ;

    // clock_t start2{}, end2{};
    // start2=clock();
    auto start2 = std::chrono::high_resolution_clock::now();
    
    binary_search(arr1, key );
    if(binary_search(arr , key)) std::cout<<"found";
    else std:: cout<< "not found";
    std::cout<<std::endl;
   
    auto stop2 = std::chrono::high_resolution_clock::now();
    // end2= clock();

    // double time_taken2 = static_cast<double> (end2 - start2) /static_cast<double>CLOCKS_PER_SEC;
     auto time_taken2 = std::chrono::duration_cast<std::chrono::seconds>(stop2 - start2);
    std::cout << "\nTime taken by binary_search  is : "<< time_taken2.count()<< " nanosec " <<std::endl;
    return 0;
}