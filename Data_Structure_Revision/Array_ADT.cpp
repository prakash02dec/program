#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <iomanip>

const size_t MAX_CAPACITY {100};


struct Array {

    int *array;
    size_t size; // current size of the array 
    size_t capacity ; // maximum memory alocated
    
    Array( size_t capacity = MAX_CAPACITY)
    : array{std::move(new int [capacity] {})} , size{0} , capacity{capacity} {
    };
    
    Array(const Array &src)
    : array{std::move(new int [src.capacity]{})} , size{src.size} , capacity{src.capacity} {
        for(size_t i {} ; i < size  ; i++ ){
            array[i] = src.array[i] ;
        }
    }
    
    ~Array(){
        delete [] array;
    }
    
    // Operations 
    int Max() const ;
    int Min() const ;
    int Sum() const ;
    double Avg() const ;

    int Get(size_t index) const ;
    bool Set(int x , size_t index) ;
    int Capacity() const;
    int Size() const ;
    
    void Display() const ;
    
    void User_Intialize();
    void Intialize(int A[] , int n);
    bool Insert(int x , size_t index ) ;
    int Delete(size_t index) ;
    void append(int x);
    
    void Reverse() ;
    void Left_shift() ;
    void Right_shift() ;
    void Left_Rotate() ;
    void Right_Rotate() ;

    bool is_sort() const;
    void insert_in_sorted(int x); // only for acending

    void negative_on_left();
    
    int Linear_search(int key) const;
    int Linear_search_improved(int key) const;
    int Binary_search(int key) const;
    int Binary_search_rec(int key , int low , int high ) const;

};

// function for swapping
void swap(int &a , int &b){
    int temp {a} ;
    a = b ;
    b = temp ;
}
// let the size of first array be m 
// and size of second array be n 
// then the complexity of the merge is O(m+n)
int* merge(const Array a ,const Array b){
    size_t i {} , j{} , k{} ;
    int* arr {new int [a.size + b.size]};
    while( i < a.size && j < b.size ){
        if(a.array[i] < b.array[j]){
            arr[k++] = a.array[i++] ;
        }
        else
            arr[k++] = b.array[j++] ;
    }
    // copy the remaining element
    while(i<a.size)
        arr[k++] = a.array[i++] ;
    while(j<b.size) 
        arr[k++] = b.array[j++] ;

    

    return arr ;
}

// SET OPERATIONS ON ARRAY
// O(n^2) 
Array Union(const Array a , const Array b ){
    Array c ;
    c.size = a.size ;
    for(size_t i{} ; i<a.size ; i++ ) c.array[i] = a.array[i] ;
    
    for(size_t i {} ; i< b.size ; i++){
        size_t j{0} ;
        for(  ; j<c.size ; j++){
            if(b.array[i] == c.array[j])
                break ;
        }
        if(j == c.size ){
            c.array[j] = b.array[i] ;
            c.size++ ;
        }
    }
    return c ;

}

// only if both sorted 
// similar like merging of array
Array Union2(const Array a , const Array b){
    Array c ; 
    size_t i{} , j {} ;
    while(i < a.size && j < b.size){
        if(a.array[i] < b.array[j]){
            c.array[c.size++] = a.array[i++];
        }
        else if(b.array[j] < a.array[i]){
            c.array[c.size++] = b.array[j++];
        }
        else{
            c.array[c.size++] = b.array[j++];
            i++ ;
        }
    }
    //  copy the remaining element
    while(i<a.size){
        c.array[c.size++] = a.array[i++];
    }
    while(j<b.size){
        c.array[c.size++] = b.array[j++];
    }

    return c ;

}

// INTERSACTION SET OPERATION ON ARRAY
Array intersaction(const Array a , const Array b){
    Array c ; 
    size_t i{} , j {} ;
    while(i < a.size && j < b.size){
        if(a.array[i] < b.array[j]){
            i++ ;
        }
        else if(b.array[j] < a.array[i]){
            j++;
        }
        else{
            c.array[c.size++] = b.array[j++];
            i++ ;
        }
    }

    return c ;

}


//  DIFFERENCE SET OPERATION
Array difference(const Array a , const Array b){
    Array c ; 
    size_t i{} , j {} ;
    while(i < a.size && j < b.size){
        if(a.array[i] < b.array[j]){
            c.array[c.size++] = a.array[i++];
        }
        else if(b.array[j] < a.array[i]){
            j++ ;
        }
        else{
            j++ ;
            i++ ;
        }
    }
    while(i<a.size){
        c.array[c.size++] = a.array[i++];
    }
    return c ;

}

// Single Missing Element in a Sorted Array
// if it start from 1
int single_missing_element(Array a){
    int actual_sum{a.Sum()} ;
    int n {a.array[a.size-1]} ;
    int sum {(n*(n+1))/2} ;
    return sum - actual_sum ;
}

// only for sequence of sorted element
// Single Missing Element in a Sorted Array
// WITH ELEMENT AND INDEX DIFFERCE METHOD
int single_missing_element2(Array a){
    // dif = element - respective index
    // this diff must be maintained in a sequence
    int diff {a.array[0]-0} ;
    for(size_t i {1} ; i< a.size ; i++){
        if( (a.array[i]-i) != diff ){
            return diff + i ;
        }
    }
}

// only for sequence of sorted element
// Multiple Missing Element in a Sorted Array
// WITH ELEMENT AND INDEX DIFFERCE METHOD
std::vector<int> multiple_missing_element(Array a){
    // dif = element - respective index
    // this diff must be maintained in a sequence
    std::vector<int> missing_element ;
    int diff {a.array[0]-0} ;
    for(size_t i {1} ; i< a.size ; i++){
        if( (a.array[i]-i) != diff ){
            int new_diff= a.array[i] - i ;
            while(diff<new_diff){
                missing_element.push_back(diff+i);
                diff++ ;
            }
        }
    }
    return missing_element ;
}

// finding missing element using the hash table
// advance use std::map for hash table
// only for limited space
// now we have abandoned of storage so we hardly bothered about spaces
std::vector<int> multiple_missing_element2(Array a){
    size_t max {static_cast<unsigned int>(a.Max())} ;
    size_t min {static_cast<unsigned int>(a.Min())} ;
    int hash_table[max+1] {0};
    std::vector<int> missing ;
    for(size_t i {} ; i < a.size ; i++ ){
        hash_table[a.array[i]] = 1  ;     
    }
    for(size_t i {min} ; i < max ; i++ ){
        if( hash_table[i] == 0)
            missing.push_back(i);
    }

    return missing ;

}

// finding duplicates in sorted array
void duplicate_element (Array a) {
    std::sort(a.array , a.array + a.size) ;
    int last_duplicate {};
    for(size_t i {} ; i < a.size-1 ; i++){
        if(a.array[i] == a.array[i+1] && last_duplicate != a.array[i]){
            std::cout << a.array[i] << " " ;
            last_duplicate = a.array[i] ;
        }
    }

}


// counting duplicates in sorted array
void count_duplicate_element(Array a){
    std::sort(a.array , a.array + a.size) ;
    for(size_t i {} ; i < a.size-1 ; i++){
        if(a.array[i] == a.array[i+1] ){
            size_t j {i+1} ;
            while(a.array[i] == a.array[j]) j++ ;
            std::cout << a.array[i] << " : " << j-i << " times" << std::endl;
            i = j -1 ;
        }
    }

}

// counting and finding duplicates in sorted array using hash tables of array index
// cant be done for negative element but can be done using std::map
void count_duplicate_element2 (Array a) {
    std::sort(a.array , a.array + a.size) ;
    int min {a.array[0] } ;
    int max {a.array[a.size-1]} ; 
    int hash_table[max+1] {0};
    for(size_t i {} ; i < a.size ; i++){
            hash_table[a.array[i]]++ ;
    }

    for(int i {min} ; i < max+1 ; i++ ){
        if( hash_table[i] > 1 )
           std::cout << a.array[i] << " : " << hash_table[i] << " times" << std::endl;
    }

}

// finding duplicates in unsorted array 
void count_duplicate_element3(Array a){
    for(size_t i {} ; i < a.size-1 ; i++){
        int count {1} ;
        if(a.array[i] != -1)
            for(size_t j {i+1} ; j < a.size  ; j++){
                if( a.array[i] == a.array[j] ){
                    count++ ;
                    a.array[j] = -1 ;
                }
            }
        if(count > 1)
            std::cout << a.array[i] << " : " << count << " times" << std::endl ;
    }
}


// a pair of element whose sum is k
// no duplicates
void sum_of_pair(Array a , int k ){
    for(size_t i {} ; i < a.size-1 ; i++){
        for(size_t j {i+1} ; j < a.size ; j++){
            if(a.array[i] + a.array[j] == k)
                std::cout << a.array[i] << " + " << a.array[j] << " = " << k ; 
        }
    } 
}

// a pair of element whose sum is k using hashing 
// no duplicates
void sum_of_pair2(Array a , int k ){
    int max {a.Max()} ;
    int hash_table[max+1] {};
    for(int i {} ; i < a.size ; i++){
        if(hash_table[k-a.array[i]]!=0){
            std::cout << a.array[i] << " + " << k-a.array[i] << " = " << k ;
        }
        hash_table[a.array[i]]++ ;
    }
} 
// there is trade of time and space

// a pair of element whose sum is k in sorted array
void sum_of_pair3(Array a , int k ){
    size_t i {0} , j {a.size -1 } ;
    
    while( i < j){
        if(a.array[i]+ a.array[j] > k) {
            j-- ;
        } else if (a.array[i] + a.array[j] < k){
            i++;
        }else {
            std::cout << a.array[i] << " + " << a.array[j] << " = " << k ; 
            i++;
            j--; 
        }
    } 
} 


// best case comparision during descending order sorted coz one time if comparison
// worst case comparison during ascending oreder bcoz two time if comparison
int max_and_min(Array a){
    int max {a.array[0]} ;
    int min {a.array[0]} ;
    for(size_t i {1} ; i < a.size ; i++ ){
        if(a.array[i] < min) {
            min = a.array[i] ;
        }
        else{ 
            max = a.array[i] ;
        }    
    }
}

// ###############################################################################################
int main(){

    // Array a;
    // int A[] {1,34,2,-36,-7,21,8,-9,22} ;
    // a.Intialize(A , 9);
    // a.Display();
    // a.append(4);
    // a.Insert(90 , 4) ;
    // a.Display();
    // a.Delete(4) ;
    // a.Display();
    // a.Reverse();
    // a.Display();
    // a.Right_Rotate() ;
    // a.Display();
    // a.negative_on_left();
    // a.Display();


    // std::cout <<"\n Index = " << a.Linear_search_improved(2) << std::endl ;
    // a.Display();
    // std::sort(a.array , a.array+a.size);
    // std::cout << std::boolalpha<<"\n a is sorted : " << a.is_sort() << std::endl << std::noboolalpha;
    // a.Display();
    // std::cout <<"\n Index = " << a.Binary_search(4) << std::endl ;
    // std::cout <<"\n Index = " << a.Binary_search_rec(4 , 0 , a.size-1 ) << std::endl ;
    // a.Display();

    // Array b;
    // int B[] {1,3,2,-6,-3,28,8,49,62} ;
    // b.Intialize(B , 9);
    // std::sort(b.array , b.array+b.size);
    // std::cout << std::boolalpha<<"\n b is sorted : " << b.is_sort() << std::endl << std::noboolalpha;

    // a.Display();
    // b.Display();
    // int *arr{merge(a ,b)} ;
    // Array c ;
    // c.Intialize(arr , (a.size+b.size) ) ;
    // a.Display();
    // b.Display();
    // c.Display();

    // Array d {Union2(a,b)};
    // d.Display(); 
    // Array e {Union(a,b)};
    // e.Display(); 

    // Array f {intersaction(a,b)};
    // f.Display(); 

    // std::vector<int> miss {multiple_missing_element2(f)};
    // std::cout << std::endl ;
    // for(const auto num : miss){
    //     std::cout << num <<" ";
    // }
    // std::cout << std::endl ;

    Array p;
    int P[] {1,3,2,6,3,8,8,3,1} ;
    p.Intialize(P , 9);
    count_duplicate_element3(p);
 
    return 0 ;
}


// #########################################################################################

// function to return capacity of the array 
int Array::Capacity() const{
    return capacity;
}

// function to return current size of the array 
int Array::Size() const {
    return size ;
}

// function to return element at given index
int Array::Get(size_t index) const {
    if(index < size )
        return array[index] ;
}

// function to set given value at given index
bool Array::Set(int x , size_t index) {
    if(index < size ){
        array[index] = x ;
        return true ;
    }
    return false ; 
}

// function to find max element in unsorted array
int Array::Max() const {
    int max {array[0]} ;
    for(size_t i {1} ; i < size ; i++ ){
        if(array[i] > max) max = array[i] ;
    }
    return max ; 
}

// function to find min element in unsorted array
int Array::Min() const {
    int min {array[0]} ;
    for(size_t i {1} ; i < size ; i++ ){
        if(array[i] < min) min = array[i] ;
    }
    return min ; 
}

// function to get sum of all element 
int Array::Sum() const {
    int sum {} ;
    for(size_t i {} ; i < size ; i++ ){
        sum += array[i] ;
    }
    return sum ; 
}

// function to find average of all element 
double Array::Avg() const {
    return static_cast<double>(Sum()/size) ; 
}

// function to display array
void Array::Display() const{
    std::cout << "\n Array : [ ";
    for(size_t i {} ; i < size ; i++)
        std::cout << array[i] << " ";
    std::cout << "]" << std::endl;
}

// function to intialize element in the array 
void Array::User_Intialize(){
    std::cout << "Enter the no of element you to enter" << std::endl ;
    int n {};
    std::cin >> n ;
    if(n <= capacity){ 
        size = n;
        for(size_t i {} ; i < size; i++ ){
            int input {};
            std::cin >> input;
            array[i] = input ;
        }
    } else {
        std::cout << "no of elements is more than the array capacity" ;
    }
}
// function to intialize element in the array 
void Array::Intialize(int A[] , int n){
    for(size_t i {} ; i < n; i++ ){
        array[i] = A[i] ;
    }
    size = n ;

}

//  function to insert an element at given index
bool Array::Insert(int x , size_t index){
    if (index > size   || (size + 1) > capacity){
        std::cout << "invalid index" << std::endl ;
        return false ;
    }else {
        for(size_t i {this->size} ; i != index ; i--)
            array[i] = array[i-1];
        array[index] = x ;
        size++;
        return true ; 
    }
}

// function to append an element to the array
void Array::append(int x){
    if(size < capacity-1 ){
        array[size++] = x ;
    }
}

// function to delete an element at given index 
int Array::Delete(size_t index){
    if(index > size ) return INT_MAX ;
    int elem {array[index]} ;
    for(size_t i {index} ; i < size-1 ; i++)
        array[i] = array[i+1];
    size--;
    return elem ;
    
}

// searching an element and return index
// linear search method 
int Array::Linear_search(int key) const {
    for(size_t i {} ; i < size ; i++ ){
        if(array[i] == key) return i ;
    }
    return -1  ;
}

// Linear searched method improve by Transposition concept
// what is Transpositon ? ANSWER = transposition is bring element forward by one step so
// that next search faster as we search one step less i.e most search element is always 
// on top.. 
int Array::Linear_search_improved(int key) const {
    for(size_t i {} ; i < size ; i++ ){
        if(array[i] == key){ 
            swap(array[i] , array[i-1]);
            return i-1 ;
        }
    }
    return -1  ;
}

// second  method of improving is  move to head or move to front (swap with front)
// first method its slow reduction time search but in second method its suddent reduction



// Binary search method
int Array::Binary_search(int key) const{
    size_t low {0} , high {size-1} , mid ;
    while(low <= high){
        mid = high - (high - low)/2  ;
        if( key < array[mid] ) 
            high = mid - 1 ;
        else if ( key > array[mid] )
            low = mid + 1 ;
        else 
            return mid ; 
    }
    return -1 ;
}

// Binary search method (recursive  version )
int Array::Binary_search_rec(int key , int low , int high )const {
    
    if(low > high )
        return -1 ;
    
    int mid = high - (high-low)/2 ;
    
    if(array[mid] == key )
        return mid ;
    
    if(key < array[mid])
        return Binary_search_rec(key, low , mid - 1 ) ;
    else
        return Binary_search_rec(key, mid + 1 , high ) ;
}


// function to reverse the array 
void Array::Reverse(){
    for(size_t i {} ; i < size/2 ; i++)
        swap(array[i] , array[size-i-1]) ;
    return ; 
}

// function to left shift array 
void Array::Left_shift(){
    for(size_t i {} ; i < size-1; i++){
        array[i] = array[i+1] ;
    }
    array[size-1] = 0 ;
}

// function to right shift array 
void Array::Right_shift(){
    for(size_t i {size-1} ; i > 0; i--){
        array[i] = array[i-1] ;
    }
    array[0] = 0 ;
}


// rotate is used in LED display board

// function to left rotate array 
void Array::Left_Rotate(){
    int temp {array[0]} ;
    for(size_t i {} ; i < size-1; i++){
        array[i] = array[i+1] ;
    }
    array[size-1] = temp ;
}

// function to right rotate array 
void Array::Right_Rotate(){
    int temp {array[size-1]} ;
    for(size_t i {size-1} ; i > 0; i--){
        array[i] = array[i-1] ;
    }
    array[0] = temp ;
}

bool Array::is_sort() const{
    size_t i {} ;
    // for ascending
    for( i=0 ; i < size-1 ; i++  )
        if( array[i] > array[i+1] ) break;
    
    if (i == size-1 )
        return true ;
    //  for decending
    for( i=0 ; i < size-1 ; i++  )
        if( array[i] < array[i+1] ) break;
    
    if (i == size-1 )
        return true ;

    return false ;
}


// assume it for array is sorted in  accending  
void Array::insert_in_sorted(int x){
    size_t i {size-1} ;
    while(i>=0 && array[i] > x){
        array[i+1] = array[i] ;
        i-- ;
    }
    array[i+1] = x ;
    size++ ;

}

// function to put all negative numbers on left
void Array::negative_on_left(){
//  i is from start and j from end ..
// if i index found positive number it will stop 
//  if j index found negative number it will stop 
//  now i and j will swap
    size_t i {0} , j{size-1} ;
    while(i<j){
        while(array[i]<0)
            i++ ;
        
        while(array[j]>=0)
            j-- ;

        if(i<j)
        swap(array[i] , array[j]);
    }
}

