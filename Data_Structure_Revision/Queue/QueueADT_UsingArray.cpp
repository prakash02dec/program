#include <iostream>

const int MAX_SIZE {50} ;

class Queue{
    private:
    int size ;
    int front ;
    int rear ;
    int *A ;

    public :
    Queue(int size=MAX_SIZE)
    : size {size} , front{-1} , rear{-1} , A{std::move(new int [size])} {};
    ~Queue(){ delete [] A ; } ;

    bool enqueue(int x);
    int dequeue() ;

    bool isFull()const ;
    bool isEmpty()const ;
    int first () const ;
    int last () const ; 

    friend std::ostream& operator<<(std::ostream &os , const Queue &q ) ;
};

std::ostream& operator<<(std::ostream &os , const Queue &q ){
    std::cout << "\nQueue : " << std::endl ;
    for(int i {q.front+1} ; i <= q.rear ; i++) std::cout << q.A[i] << " " ;
    std::cout << std::endl ; 
    return os ;
}

bool Queue::isFull()const {
    return (rear==size-1) ;
}

bool Queue::isEmpty()const{
    return ( rear == front ) ; 
}

int Queue::first()const {
    return A[front+1] ;
}

int Queue::last()const {
    return A[rear];
}

bool Queue::enqueue(int x) {
    if(isFull()){
        std::cout <<"Queue is full" << std::endl ;
        return false ;
    }

    rear++ ;
    A[rear] = x ;
    return true ;
}

int Queue::dequeue(){
    if(isEmpty()){
        std::cout << "Queue is empty " << std::endl ;
        return -1 ;
    }

    front++ ;
    return A[front] ;
}

int main(){
    Queue q{10} ;
    q.enqueue(3) ;
    q.enqueue(4) ;
    q.enqueue(7) ;
    std::cout << q ;
    std::cout << q.dequeue() << std::endl;
    std::cout << q; 
    return 0 ;
}