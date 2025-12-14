#include <iostream>
#include <climits>

struct Node {
    int data ;
    Node *next ; 
}*first ;

// function to create a linked list from given array
void create(int A[] , int n){
    Node *temp {} , *last {} ; 
    first = new Node ;
    first->data = A[0] ;
    first->next = nullptr ;
    last = first ; 
    for(int i{1} ; i < n  ; i++){
        temp = new Node ;
        temp->data = A[i] ;
        temp->next = nullptr ;
        last->next = temp ;
        last = temp ;
    }

}

// function to write display 
void Display(Node *node){
    std::cout << "Linked List : " ; 
    while(node!=nullptr){
        std::cout << node->data << " " ; 
        node = node->next ;
    }
     std::cout << std::endl ;
}

// func to count number of arrays
int Count(Node *node){
    int count {} ;
    while( node != nullptr){
        count++ ;
        node = node->next ; 
    }
    return count ;
}
// recursive count
int Rcount(Node *node){
    if( node == nullptr){
        return 0 ;
    }else{
        return Rcount(node->next) + 1 ;
    }
}

// insert before first node
void push(Node *node , int x){
    Node *temp {new Node} ;
    temp->data = x ;
    temp->next = first ;
    first = temp ;
    
}

// insert node at last
void append(Node *node , int x){
    Node *last {node} ;
    while(last != nullptr && last->next != nullptr ){
        last = last->next ;
    }

    Node *temp {new Node} ;
    temp->data = x ;
    temp->next = nullptr ;    

    if(first == nullptr){
        first = last = temp ;
    }
    else{
    last->next = temp ;
    last = temp ;
    }
}

// func to insert a node at given position
void insert(Node *node , int x , int pos){
    Node *temp {new Node} ;
    temp->data = x ;
    temp->next = nullptr ;

    if(pos == 0 ){
        temp->next = first ;
        first = temp ;
        return  ;
    }
    int i {1} ;
    while(node != nullptr){
        if(i==pos){
            temp->next = node->next ;
            node->next = temp ;
            return ;
        }
        i++ ;
        node =node->next ;
    }
    std::cout << "invalid operation" ;
}

// func to delete a node 
int Delete(Node *node , int pos){
    int x ;
    if(pos >Count(node) && pos < 1)
        return -1 ;

    if(pos == 1){
        x = node->data ;
        first = node->next ;
        delete node ;
    }else{
        int i {1} ;
        Node* last {nullptr} ; 
        while(node != nullptr && i<pos ){
            last = node ;
            node = node->next ;
            i++;
        }
        if(i == pos && node != nullptr){
            last->next = node->next ;
            x = node->data ;
            delete node ;
        }

    }
    return x ;
}

// func for linear search 
Node* Linear_search(Node *node , int key){
    while(node != nullptr){
        if( node->data == key ){
            return node ;
        }
        node = node->next ;
    }
    return nullptr ;
}

// Recursive linear search func
Node* RLinear_search(Node *node , int key){
    if(node == nullptr)
        return nullptr ;
    if(node->data == key)
        return node ;
    else
        return RLinear_search(node->next , key) ;
}

// Improved version of linear search 
Node* Linear_search_Improved(Node *node , int key){
    Node *last {nullptr} ;
    while(node != nullptr){
        if(node->data == key){
            last->next = node->next ;
            node->next = first ;
            first = node ;
        }
        last = node ; 
        node = node->next ;
    }
}

// func for max finding func 
int max(Node *node){
    int max {INT_MIN} ;
    while(node != nullptr){
        if(node->data > max)
            max = node->data ;
            node = node->next ;
    }
    return max ;
}

// recusive version of max finding funct 
int R_max(Node *node){
    int x {} ;
    if(node == nullptr)
        return INT_MIN ;

    x= max(node->next) ;
    return x>node->data ? x : node->data ; 
}

// func to add all value of nodes
int Add(Node *node){
    int sum {} ; 
    while(node != nullptr){
        sum += node->data ;
        node = node->next ;
    }
    return sum ;
}

// func to check all the nodes are sorted or not
bool is_sorted(Node *node){
    int x{INT_MIN} ;
    while(node != nullptr){
        if( node->data < x)
            return false;
        
        x = node->data ;
        node = node->next ;
    }
    return true ;
}

// function to remove duplicates 
void RemoveDuplicates(Node *node){
    Node* last{node} ;
    node = node->next ;
    while( node != nullptr){
        if( node->data == last->data ){
            last->next = node->next ;
            delete node ;
            node = last->next ;
        }else{
            last = node;
            node = node->next ;
        }
        
    }
}

// reversing a linked list
// there are two ways
// reversing by element 
// reversing by links i.e using sliding pointer

// In a linked list we prefer reversing a linked list by reversing links

// by reversing the element using auxillary array
void LL_Reverse(Node *node){
    int i {} ;
    int A[Count(node)];
    Node* temp{node} ;
    
    while(temp != nullptr){
        A[i++] = temp->data ;
        temp = temp->next ;
    }
    
    temp = node ;
    i-- ;
    while( temp != nullptr ){
        temp->data = A[i--] ;
        temp = temp->next ;
    }

}

// sliding pointer method
// r q p
void LL_Reverse2(Node *node){
    Node *p{node} , *q{nullptr} , *r{nullptr};
    while(p != nullptr){
        // first three step is only for sliding pointer
        r = q ;
        q = p ;
        p = p->next ;
        
        q -> next = r ;
    }
    first = q ;
}

// sliding pointer method
// recusion version
void R_LL_Reverse2(Node *q , Node* p){
    if(p != nullptr){
        R_LL_Reverse2(p , p->next) ;
        p->next = q ;
    }else{
        first = q ;
    }

}

// concatenation of two linked list
void Concate(Node *node1 , Node *node2){
    while(node1->next != nullptr){
        node1 = node1->next ;
    }
    node1->next = node2 ;
    node2 = nullptr ;
}

// merging is process of merging two sorted list into one sorted list
Node* merge(Node* first , Node *second){
    Node *third{}  , *last{};
    if(first->data < second->data){
        third = last = first ;
        first = first -> next ;
        last -> next = nullptr ;
    }else{
        third = last = second ;
        second = second -> next ;
        last -> next = nullptr ;
    }
    while( first != nullptr && second != nullptr){
        if(first->data < second->data){
            last->next = first ;
            last = first ;
            first = first->next ;
            last->next = nullptr ;
        }else if(second->data < first->data){
            last->next = second ;
            last = second ;
            second = second->next ;
            last->next = nullptr ;
        }else {
            last->next = first ;
            last = first ;
            first = first->next ;
            last->next = nullptr ;
            Node* temp {second} ;
            second = second->next ;
            delete temp ;
        }
    }
    if(first != nullptr){
        last->next = first 

    }
    if(second != nullptr){
        last->next = second ;
    }
    return third ;

} 

// 1. stored the address of all nodes if the address repeat mean there is loop
// 2. stored all elements if uniques then on repeatation we can say there is loop
bool Is_loop(Node *node){
    Node *p {node} , *q{node} ;
    while(p != nullptr && q != nullptr){
        p = p->next;
        q= q->next;
        q = (q != nullptr) ? q ->next : nullptr ;  
        if(p == q){
            return true ;
        }
    }
    return false ;
}

int main(){
    int A[]  {3,5,7,10,15} ;
    create(A , 5) ;
    Display(first) ;
    LL_Reverse(first);
    Display(first) ;
    std::cout<< Is_loop(first) ;

    return 0 ;
}