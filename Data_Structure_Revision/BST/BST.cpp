#include<iostream>
#include <stack>

struct Node{
    Node *lchild ;
    int data ;
    Node *rchild ;
}*root = nullptr ;

void insert(int key) {
    Node *node{root} ;
    Node *last{} , *temp {nullptr} ;

    if(root == nullptr){
        temp = new Node ;
        temp ->data = key ;
        temp->lchild = temp ->rchild = nullptr ;
        root = temp ;
        return ;
    }
    while( node != nullptr){
        last = node ;
        if(key < node->data)
            node = node->lchild ;
        else if(key > node->data)
            node = node->rchild ;
        else 
            return ;
    }
    temp = new Node ;
    temp->data = key ;
    temp->lchild = temp->rchild = nullptr ;

    if(key < last->data) 
        last->lchild = temp ;
    else 
        last->rchild = temp ;

}

void inorder(Node *parent){
    if(parent){
        inorder( parent->lchild) ;
        std::cout << parent->data << " " ;
        inorder( parent->rchild) ;
    }

}

Node* search(int key){
    Node* last{root} ;
    while(last != nullptr){
        if(key == last->data ) return last ;
        else if(key < last->data) last = last->lchild ;
        else if(key > last->data) last = last->rchild ;
    }
    return nullptr ;
}

Node* Rinsert(Node *node , int key ){
    // if root node is equal to null
    if(node == nullptr){
        Node *temp{new Node} ;
        temp->data = key ;
        temp->lchild = temp->rchild = nullptr ;
        return temp ;
    }

    if(key < node->data ) 
        node->lchild = Rinsert(node->lchild , key) ;
    else if(key > node->data){
        node->rchild = Rinsert(node->rchild , key ) ;
    }

    return node ;

}

int height(Node* root){
    int x{} , y{} ;
    if(!root)
        return 0 ;
    x = height(root->lchild) ;
    y = height(root->rchild) ;
    
    return (x>y)? x+1 : y+1 ;
    
}

Node* InPre(Node *node){
    while(node && node->rchild ){
        node= node->rchild ;
    }
    return node ;
}

Node* InSucc(Node *node){
    while(node && node->lchild ){
        node= node->lchild ;
    }
    return node ;
}

Node *Delete(Node* node , int key ){
    if(node == nullptr) return nullptr ;
    if( !node->lchild && !node->rchild){
        if(node == root){
            root == nullptr ;
        }
        delete node ;
        return nullptr ;
    }

    if(key < node->data)
        // key is in left sub tree 
        // delete from left sub tree 
        node->lchild = Delete(node->lchild , key);
    else if(key > node->data)        
        // key is in left sub tree 
        // delete from left sub tree 

        node->rchild = Delete(node->rchild , key);
    else{
        // delete a key now mean key is found
        if(height(node->lchild)>height(node->rchild)){
            Node *temp{} ;
            temp=InPre(node->lchild) ;
            node->data = temp->data ;
            node->lchild = Delete(node->lchild , temp->data);
        }
        else{
            Node *temp{} ;
            temp=InSucc(node->rchild) ;
            node->data = temp->data ;
            node->rchild = Delete(node->rchild , temp->data);
        }
    }
    return node ;
}

void create_from_preorder(int pre[] , int n){
    std::stack<Node *> stk ;
    stk.emplace(nullptr , INT_MAX , nullptr) ;
    Node *t {} , *p {} ;
    int i {} ;
    root = new Node ;
    root ->data = pre[i++] ;
    root->lchild = root->rchild = nullptr ; 
    p = root ;
    while(i < n){
        if(p->data < pre[i]){
        
            t = new Node ;
            t->data = pre[i++] ;
            t->lchild = t->rchild = nullptr ;
            p->lchild = t ;
            stk.push(p);
            p = p->lchild ;
        
        }else if (pre[i] > p->data && pre[i] < stk.top()->data){
            
            t = new Node ;
            t->data = pre[i++] ;
            t->lchild = t->rchild = nullptr ;
            p->rchild = t ;
            p = p->rchild ;

        }else {
            p = stk.top() ; 
            stk.pop() ;
        }
    }

}

int main() {
    insert(10);
    insert(5) ;
    insert(20) ;
    insert(30) ;
    insert(8) ;
    insert(30) ;
    Rinsert(root ,80) ;
    Delete(root , 20) ;
    inorder(root) ;
    std::cout << std::endl ;
    std::cout << (search(30))->data << std::endl ;
    return 0 ;
}