#ifndef _Queue_
#define _Queue_

#include <iostream>
const int MAX_SIZE {50} ;

struct Node{
    Node *lchild ;
    int data ;
    Node *rchild ;
};

class Queue{
    private:
    int size ;
    int front ;
    int rear ;
    Node **Q ;

    public :
    Queue(int size=MAX_SIZE)
    : size {size} , front{0} , rear{0} , Q{std::move(new Node* [size])} {};
    ~Queue(){ delete [] Q ; } ;

    bool enqueue(Node* x);
    Node* dequeue() ;

    bool isFull()const ;
    bool isEmpty()const ;


};


bool Queue::isFull()const {
    return ((rear+1)%size == front) ;
}

bool Queue::isEmpty()const{
    return ( rear == front ) ; 
}


bool Queue::enqueue(Node* x) {
    if(isFull()){
        std::cout <<"\nQueue is full" << std::endl ;
        return false ;
    }

    rear = (rear+1)%size ;
    Q[rear] = x ;
    return true ;
}

Node* Queue::dequeue(){
    if(isEmpty()){
        std::cout << "Queue is empty " << std::endl ;
        return nullptr ; 
    }

    front = (front+1)%size ;
    return Q[front] ;
}


#endif