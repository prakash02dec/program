#include <iostream>

const int SIZE {10} ;
 
// H() hash function
int hash(int key){
    return key%SIZE ;
}

// H'() hash function
int probe(int H[] , int key){
    int index {hash(key)} ;
    int i {} ;
    while(H[index + i]%SIZE !=0 ){
        i++ ;
    }
    return (index+i)%SIZE ;
}

void Insert (int H[] , int key){
    int index {hash(key)} ;

    if(H[index] != 0)
        index = probe(H, key) ;
    H[index] = key ; 
}

int search(int H[] , int key){
    int index {hash(key)} ;

    int i {} ;
    while(H[(index+i)%SIZE] != key )
        i++ ;
    return  (index + i) %SIZE ;

}

int main(){
    int HT[10] {};

    Insert(HT , 12) ;
    Insert(HT , 25) ;
    Insert(HT , 35);
    Insert(HT ,26 ) ;

    std::cout << "key is found " << HT[search(HT ,35)] << std::endl ;
          
    return 0 ;
}