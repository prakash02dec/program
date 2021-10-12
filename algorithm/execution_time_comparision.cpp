#include<iostream>
#include<iomanip>
#include<ctime>
#include<random>

constexpr int n {10000};

void merging(int low, int mid, int high, int arr[])
{
    int left {}, right {}, i, temp[n];

    for (left = low, right = mid + 1, i = low; left <= mid && right <= high; i++)
    {
        if (arr[left] <= arr[right])
            temp[i] = arr[left++];
        else
            temp[i] = arr[right++];
    }

    while (left <= mid)
        temp[i++] = arr[left++];

    while (right <= high)
        temp[i++] = arr[right++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}

void merge_sort(int low, int high, int arr[])
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(low, mid, arr);
        merge_sort(mid + 1, high, arr);
        merging(low, mid, high, arr);
    }
    else
    {
        return;
    }
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
void bubble_sort(int arr[]){
    int  temp{};
    size_t i {}, j{};

    for (i = 0; i < n-1; i++)      
        for (j = 0; j < n-i-1; j++) 
        {   
            if (arr[j] > arr[j+1])
           {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            }
        }      


}
int main()
{
    std::cout<<std::endl<< "execution time calcultion for "<< n <<" elements";

    int random_number {};           
    int min {1};                
    int max {n};                 
    srand(time(0));  
    
    int arr[n] {} , arr1[n] {} , arr2[n] {};
    
    for (size_t i{0}; i<n; ++i){
        random_number = rand() % max + min;
        arr[i]=arr1[i]=arr2[i] = random_number;

    }

    std::cout << std::fixed << std::setprecision(10);

    clock_t start1{}, end1{};
    start1 = clock();

    insertion_sort(arr);


    end1 = clock();

    double time_taken1 = static_cast<double> (end1 - start1) / static_cast<double>CLOCKS_PER_SEC;
    std::cout << "\nTime taken by  insertion sort  is : " << time_taken1<< " sec " ;

    clock_t start2{}, end2{};
    start2=clock();
    
    bubble_sort(arr1);
   

    end2= clock();

    double time_taken2 = static_cast<double> (end2 - start2) /static_cast<double>CLOCKS_PER_SEC;
    std::cout << "\nTime taken by bubble sort  is : " << time_taken2 << " sec " ;
    
    clock_t start3{}, end3{};
    start3=clock();

    merge_sort(0, n, arr2);

    end3= clock();

    double time_taken3 = static_cast<double> (end3 - start3) /static_cast<double>CLOCKS_PER_SEC;
    std::cout << "\nTime taken by merge sort  is : " << time_taken3<< " sec " <<std::endl;
    return 0;
}