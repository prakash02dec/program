#include<iostream>

void print(const int *arr, size_t size);
int *apply_all(int *array1, size_t array1_size,int *array2, size_t array2_size);

int main(){
    const size_t array1_size {5};
    const size_t array2_size {3};
    
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};

    std::cout<<"\nArray1 : ";
    print(array1,array1_size);

    std::cout<<"\nArray2 : ";
    print(array2, array2_size);
    
    int *result=apply_all(array1,array1_size,array2,array2_size);
    constexpr size_t result_size {array1_size*array2_size};

    std::cout<<"\nResult : ";
    print(result,result_size);

    delete [] result;

    std::cout<<std::endl;
    return 0;
}

void print(const int *const arr, size_t size)
{
    std::cout<<"[ ";

    for(size_t i {0} ;i<size; i++)
        std::cout<<arr[i]<<" ";
    
    std::cout<<"]";
}

int *apply_all(int *array1, size_t array1_size,int *array2, size_t array2_size)
{
    size_t new_size=array2_size*array1_size;
    int *new_array {nullptr};
    new_array= new int[new_size];
    
    int *arr {new_array};

    for(size_t i {0};i<array2_size; i++)
        for(size_t j {0} ; j<array1_size; j++)
        {
            *arr++=array1[j]*array2[i];
        }
    


    return new_array ;
}

