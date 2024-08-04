#include <iostream>

const int MAX_SIZE {30} ;

class Queue{
    private:
    int front ;
    int rear ;
    int size ;
    int *A ;
    public :
    Queue(int size = MAX_SIZE )
    : size{size} , front{0} , rear{0} , A{std::move(new int [size] )} {};
    ~Queue() { delete [] A ;}
    bool enqueue(int x) ;
    int dequeue() ;

    bool isFull()const  ;
    bool isEmpty()const ;
    int first()const ;
    int last()const ;

    friend std::ostream& operator<<(std::ostream &os , const Queue &q ) ;
};

std::ostream& operator<<(std::ostream &os , const Queue &q ){
    std::cout << "\nQueue : ";
    int i {q.front+1} ;

    do{
        std::cout << q.A[i] << " " ;
        i =(i+1)%q.size ;
    }while(i != (q.rear+1)%q.size);

    std::cout << std::endl ; 
    return os ;
}

bool Queue::isFull()const {
    return ((rear+1)%size == front) ;
}

bool Queue::isEmpty()const{
    return ( rear == front ) ; 
}

int Queue::first()const {
    return A[(front+1)%size] ;
}

int Queue::last()const {
    return A[rear];
}

bool Queue::enqueue(int x) {
    if(isFull()){
        std::cout <<"\nQueue is full" << std::endl ;
        return false ;
    }

    rear = (rear+1)%size ;
    A[rear] = x ;
    return true ;
}

int Queue::dequeue(){
    if(isEmpty()){
        std::cout << "Queue is empty " << std::endl ;
        return -1 ;
    }

    front = (front+1)%size ;
    return A[front] ;
}

int main(){
    Queue q{5} ;
    q.enqueue(3) ;
    q.enqueue(4) ;
    q.enqueue(7) ;
    q.enqueue(9) ;
    q.enqueue(10) ;
    std::cout << q ;
    q.dequeue();
    q.enqueue(2) ;
    std::cout << q.dequeue() << std::endl;
    std::cout << q; 
    return 0 ;
}