#include <iostream>
#include <stack>

class Queue{
    private:
    std::stack<int> stk1 , stk2 ;

    public:
    Queue() = default ;
    ~Queue() = default ;
    void enqueue(int x) ;
    int dequeue() ;

};

void Queue::enqueue(int x){
    stk1.push(x) ;
}

int Queue::dequeue(){
    int x {-1} ;
    if(stk2.empty()){
        if(stk1.empty())
            return x ;

        while(!stk1.empty()){
            stk2.push(stk1.top()) ;
            stk1.pop();
        }

    }

    x = stk2.top();
    stk2.pop();
        
    return x ;

}

int main() {
    return 0 ;
}