#include <iostream>
struct Node {
    int data ;
    struct Node *next ;
};

class Queue{
    private :
    Node *front ;
    Node *rear ;

    public :
    Queue()
    : front{nullptr} , rear{nullptr} {} ;
    ~Queue(){
        Node *temp ;
        while(front != nullptr){
            temp = front ;
            front = front->next ;
            delete temp ;
        }
        rear = nullptr ;
    }

    void enqueue(int x) ;
    int dequeue() ;
    
    bool isEmpty()const ;
    int first()const ;
    int last()const ;

    friend std::ostream& operator<<(std::ostream &os , const Queue &q) ;

};

std::ostream& operator<<(std::ostream &os , const Queue &q){
    Node *temp {q.front} ;
    std::cout << "\nQueue : " ;
    while(temp != nullptr){
        std::cout << temp->data << " " ;
        temp = temp->next ;
    }
    std::cout << std::endl ;

    return os ;
}


bool Queue::isEmpty()const{
    return (front == nullptr) ;
}

void Queue::enqueue(int x){
    Node *temp {new Node} ;
    if(temp == nullptr){
        std::cout << "Queue is full \n" ;
        return ;
    }else{
        temp->data = x ;
        temp->next = nullptr ;
        if( isEmpty()){
            front = rear = temp ;
        }else{
            rear->next = temp ;
            rear = temp ;

        }
    }
}



int Queue::dequeue(){
    int x {-1} ;
    Node *temp {} ;
    if(isEmpty()){
        std::cout << "Queue is Empty \n" ;
    }else{
        x = front->data ;
        temp = front ;
        front = front -> next ;
        
        if(front == nullptr)
            rear = nullptr ;
        
        delete temp ;
    }
    return x;
}


int Queue::first()const{
    return front->data ;
} ;

int Queue::last()const{
    return rear->data ;
} 

int main(){
    Queue q{} ;
    q.enqueue(3) ;
    q.enqueue(4) ;
    q.enqueue(7) ;
    std::cout << q ;
    std::cout << q.dequeue() << std::endl;
    std::cout << q; 
    return 0 ;
}