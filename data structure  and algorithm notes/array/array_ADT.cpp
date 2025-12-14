#include <iostream>
#include <cstdlib>

class array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

public:
    array() : size{20}, length{0}, A{new int[20]} {}
    array(int size) : size{size}, length{0}, A{new int[size]} {}
    ~array() { delete[] A; }

    void display() const;
    void append(int x);
    void insert(int index, int x);
    int Delete( int index);
    int linear_search(int key);
    int binary_search(int key) const;
    int rbinary_search(int key, int low, int high) const;
    int get(int index)const;
    void set( int index, int x);
    int max()const;
    int min()const;
    int sum()const;
    float avg()const;
    void reverse();
    void left_shift();
    void right_shift();
    void left_rotate();
    void right_rotate();
    void insert_sort( int x);
    bool is_sorted()const;
    void negative_rearrange();
    array *Merge( array arr2) const;
    array *Union( array arr2) const;
    array *Intersaction( array arr2) const;
    array *difference( array arr2) const;

};

// display function
void array::display()const{
    std::cout << "element are [ ";
    for (int i{}; i < length; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << "]";
}

// append function
void array::append(int x){
    if (length < size){
        A[length++] = x;
    }
}
// insert function
void array::insert( int index, int x){
    if (index >= 0 && index <= length){
        for (int i{length}; i > index; i--){
            A[i] = A[i - 1];
        }
        A[index] = x;
        length++;
    }
}

// delete function
int array::Delete( int index){
    if (index >= 0 && index < length){
        int temp{A[index]};
        for (int i{index}; i < length - 1; i++){
            A[i] = A[i + 1];
        }
        length--;
        return temp;
    }
}

// linear search
int array::linear_search( int key){
    for (int i{}; i < length; i++){
        if (key == A[i]){
            // improve version
            swap(&A[i], &A[i - 1]); // by tranposition method
            // swap(&(arr->A[i]) ,&(arr->A[0])); // by move to front or move to head
            std::cout << "element is found" << std::endl;
            return i;
        }
    }
    std::cout << "element is not found" << std::endl;
    return -1;
}

// binary search
int array::binary_search( int key)const{
    int low{0}, high{length - 1}, mid;
    while (low <= high){
        mid = (low + high) / 2;
        if (A[mid] == key)
            return mid;
        else if (A[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// binary with recursion
int array::rbinary_search( int key, int low, int high)const{
    while (low <= high){
        int mid{low + (high - low) / 2};
        if (A[mid] == key)
            return mid;
        else if (A[mid] > key)
            return rbinary_search( key, low, mid - 1);
        else
            return rbinary_search( key, mid + 1, high);
    }
    return -1;
}

// get index
int array::get( int index)const{
    if (index >= 0 && index < length){
        return A[index];
    }
    return -1;
}

// set element at given index
void array::set( int index, int x){
    if (index >= 0 && index < length){
        A[index] = x;
    }
}

// return max element
int array::max()const{
    int max = A[0];
    for (int i{}; i < length; i++){
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

// return min element
int array::min()const{
    int min = A[0];
    for (int i{}; i < length; i++){
        if (A[i] < min)
            min = A[i];
    }
    return min;
}

// return the sum of all element
int array::sum()const{
    int sum{};
    for (int i{}; i < length; i++){
        sum += A[i];
    }
    return sum;
}

// return avg of array
float array::avg()const{
    return (float)sum()/length;
}

// reversing an array
void array::reverse(){
    for (int i{}; i < length / 2; i++){
        swap(&A[i], &A[length - 1 - i]);
    }
}

// left shifting of array
void array::left_shift(){
    for (int i{}; i < length - 1; i++){
        A[i] = A[i + 1];
    }
    A[length - 1] = 0;
}

// right shifting of array
void array::right_shift(){
    for (int i{length - 1}; i > 0; i--){
        A[i] = A[i - 1];
    }
    A[0] = 0;
}

// left rotation
void array::left_rotate(){
    int temp = A[0];
    left_shift();
    A[length - 1] = temp;
}

// right rotation
void array::right_rotate(){
    int temp = A[length - 1];
    right_shift();
    A[0] = temp;
}

// insert into shorted array
void array::insert_sort( int x){
    int i{length - 1};
    if (length == size) return;
    while (A[i] > x){ 
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}

// is array sorted
bool array::is_sorted()const{
    for (int i{}; i < length - 1; i++){
        if (A[i] > A[i + 1])
            return false;
    }
    return true;
}

// negative number on one side .. let it be on left side , O(n)
void array::negative_rearrange(){
    int i{}, j{length - 1};
    while (i < j){
        while (A[i] < 0) { i++; }
        while (A[j] >= 0) { j--; }
        if (i < j){ swap(&A[i], &A[j]); }
    }
}

// merging two arrays
array* array::Merge( array arr2)const{
    int i{}, j{}, k{};
    array *arr3 = new array( length + arr2.length);
    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }
    while (i < length)
    {
        arr3->A[k++] = A[i++];
    }
    while (j < arr2.length)
    {
        arr3->A[k++] = arr2.A[j++];
    }
    arr3->length = length + arr2.length;
    arr3->size = 20;
    return arr3;
}
// set operation on arrays
// union of two arrays as set
array* array::Union( array arr2)const{
    int i{}, j{}, k{};
    array *arr3 = new array ;
    while ( i < length && j < arr2.length){
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            arr3->A[k++] = arr2.A[j++];
        else if (arr2.A[j] == A[i]){
            arr3->A[k++] = arr2.A[j++];
            i++;
        }
    }
    while (i < length)
    {
        arr3->A[k++] = A[i++];
    }
    while (j < arr2.length)
    {
        arr3->A[k++] = arr2.A[j++];
    }
    arr3->length = k;
    arr3->size = 20;
    return arr3;
}

// intersection of arrays as set
array* array::Intersaction( array arr2)const{
    int i{}, j{}, k{};
    array *arr3 = new array ;
    while (i < length && j < arr2.length){
        if ( A[i] < arr2.A[j])
            i++;
        else if (arr2.A[j] < A[i])
            j++;
        else if (arr2.A[j] == A[i]){
            arr3->A[k++] = arr2.A[j++];
            i++;
        }
    }
    arr3->length = k;
    arr3->size = 20;
    return arr3;
}

// difference of two arrays as set
array *array::difference( array arr2)const{
    int i{}, j{}, k{};
    struct array *arr3 = new array;
    while (i < length && j < arr2.length) {
        if ( A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            j++;
        else if (arr2.A[j] == A[i]) {
            j++;
            i++;
        }
    }
    while (i < length){
        arr3->A[k++] = A[i++];
    }
    arr3->length = k;
    arr3->size = 20;
    return arr3;
}

int main()
{
    array *arr1{nullptr};
    int choice ,size;
    int x, index;
    std::cout << "Enter Size of Array : " << std::endl;
    std::cin >> size;
    arr1 = new array( size );
    do {
        std::cout << "\nMenu\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Delete\n";
        std::cout << "3. Search\n";
        std::cout << "4. Sum\n";
        std::cout << "5. Display\n";
        std::cout << "6.Exit\n";

        std::cout << "enter you choice ";
        std::cin >> choice;
        switch (choice){
        case 1:
            std::cout << "Enter an element  : " ;
            std::cin >> x ; 
            std::cout << "\n and index : "; 
            std::cin >> index;
            arr1->insert(index, x);
            break;
        case 2:
            std::cout << "Enter index : ";
            std::cin >> index;
            std::cout << "Deleted Element is : " << arr1->Delete( index) << std::endl;
            break;
        case 3:
            std ::cout << "Enter element to search : ";
            std::cin >> x;
            std::cout << "Element index : " << arr1->linear_search( x);
            break;
        case 4:
            std::cout << "Sum is : "
                      << arr1->sum();
            break;
        case 5:
            arr1->display();
        }
    } while (choice < 6);

    return 0;
}
