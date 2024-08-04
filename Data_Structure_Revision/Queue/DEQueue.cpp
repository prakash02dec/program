#include <iostream>

const int MAX_SIZE {30} ;
 
class DEQueue{
private:
    int front;
    int rear;
    int size;
    int* Q;
 
public:
    DEQueue(int size = MAX_SIZE)
    :size{size} , rear{-1} , front {-1} , Q{std::move(new int [size])} {};
    ~DEQueue() { delete [] Q; }
    void enqueueFront(int x);
    void enqueueRear(int x);
    int dequeueFront();
    int dequeueRear();
    bool isEmpty()const ;
    bool isFull()const ;

    friend std::ostream& operator<<(std::ostream &os , const DEQueue &q ) ;
};


bool DEQueue::isEmpty()const {
    return front == rear ;
}

bool DEQueue::isFull()const {
    return rear == size-1 ;
}


void DEQueue::enqueueFront(int x){
    if(front == -1){
        std::cout << " DEQueue is overflow " << std::endl ;
    }else{
        // because front point at just before element.. hence front pointing to blank space
        Q[front] = x ;
        front-- ;
    }
}

int DEQueue::dequeueFront(){
    int x {-1} ;
    if(isEmpty()){
        std::cout << "DEQueue is Underflow" <<std::endl ;
    }else{
        front++ ;
        x = Q[front] ;
    }
    return x ;
}

void DEQueue::enqueueRear(int x){
    if(isFull()){
        std::cout << "DEQueue is overflow " << std::endl ;
    }else{
        rear++ ;
        Q[rear] = x ;
    }
}

int DEQueue::dequeueRear(){
    int x {-1} ;
    if(isEmpty() ){
        std::cout << "DEQueue is underflow" << std::endl ;
    }else{
        // bcoz rear points at the last value
        x =  Q[rear] ;
        rear-- ;

    }
    return x ;
}

std::ostream& operator<<(std::ostream &os , const DEQueue &q ) {
    std::cout<<"Queue : " ;
    for (int i=q.front+1; i<=q.rear; i++) {
        std::cout << q.Q[i] << " " ;
    }
    std::cout << std::endl;
}
 
int main() {
 
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8};
 
    DEQueue deq(sizeof(A)/sizeof(A[0]));
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.enqueueRear(A[i]);
    }
    std::cout << deq;
    deq.enqueueRear(11);
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.dequeueFront();
    }
    deq.dequeueFront();
 
    std::cout << std::endl;
 
    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.enqueueFront(B[i]);
    }
    std::cout << deq;
    deq.enqueueFront(10);
    deq.enqueueFront(12);
 
    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.dequeueRear();
    }
    std::cout << deq;
    deq.dequeueRear();
    deq.dequeueRear();
 
    return 0;
}