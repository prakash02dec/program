// write a function to check if linked list contain a cycle using hash table

#include<iostream>
#include<unordered_map>

class node{
    public:
    int data ; 
    node* next ;

    node(int data){
        this->data = data ;
        next = nullptr ;
    }
};

bool constainsCycle(node *head){
    std::unordered_map<node* , bool>hashtable ;
    node* temp {head} ;
    while(temp != nullptr){
        // check if temp already exist in the hashtable
        if(hashtable.count(temp) != 0 ){
            return true ;
        }
        // insert in the hashtable if no
        hashtable[temp] = true ;
        temp = temp->next ;
    }
    return false ;
}

int main(){
    return 0 ;
}