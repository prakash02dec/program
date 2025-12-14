#include <iostream>

struct Node{
    Node *lchild ;
    int data ;
    int height ;
    Node *rchild ;
}*root = nullptr ;

int nodeHeight(Node *node){
    int hl{} , hr{} ;
    hl = node && node->lchild ? node->lchild->height : 0 ;
    hr = node && node->rchild ? node->rchild->height : 0 ;
    return hl > hr ? hl+1 : hr+1 ;

}

int balanceFactor(Node* node){
    int hl{} , hr{} ;
    hl = node && node->lchild ? node->lchild->height : 0 ;
    hr = node && node->rchild ? node->rchild->height : 0 ;
    return hl-hr ;
}

Node* LLRotation(Node *p){
    Node *pl { p->lchild} ;
    Node *plr  {pl->rchild};
    pl->rchild = p ;
    p->lchild =plr ;
    // plr remain same

    p->height = nodeHeight(p) ;
    pl->height = nodeHeight(pl) ;

    if(root == p){
        root = pl ;
    }

    return pl ;
    
}

Node* RRRotation(Node* p){
   
    Node *pr { p->rchild} ;
    Node *prl  {pr->lchild};
    pr->lchild = p ;
    p->rchild =prl ;
    // plr remain same

    p->height = nodeHeight(p) ;
    pr->height = nodeHeight(pr) ;

    if(root == p){
        root = pr ;
    }
    
    return pr;
}

Node* LRRotation(Node *p){

    Node *pl = p->lchild ;
    Node *plr = pl->rchild ;

    pl->rchild = plr->lchild ;
    p->lchild = plr->rchild ;

    plr->lchild = pl ;
    plr->rchild = p ;

    // update height also
    pl->height = nodeHeight(pl) ;
    p->height = nodeHeight(p) ;

    plr->height = nodeHeight(plr) ;
 
    if(p== root) {
        root = plr ;
    }

    return plr ;

}

Node* RLRotation(Node *p){
    Node *pr = p->rchild ;
    Node *prl = pr->lchild ;

    pr->lchild = prl->rchild ;
    p->rchild = prl->lchild ;

    prl->rchild = pr ;
    prl->lchild = p ;

    // update height also
    pr->height = nodeHeight(pr) ;
    p->height = nodeHeight(p) ;

    prl->height = nodeHeight(prl) ;
 
    if(p== root) {
        root = prl ;
    }

    return prl ;
}

Node* Rinsert(Node *node , int key ){
    
    // we having height from 1 but not from 0
    if(node == nullptr){
        Node *temp{new Node} ;
        temp->data = key ;
        temp->height = 1 ;
        temp->lchild = temp->rchild = nullptr ;
        return temp ;
    }

    if(key < node->data ) 
        node->lchild = Rinsert(node->lchild , key) ;
    else if(key > node->data){
        node->rchild = Rinsert(node->rchild , key ) ;
    }

    node->height = nodeHeight(node) ;

    if( balanceFactor(node)==2 && balanceFactor(node->lchild)==1 )
        return LLRotation(node) ;
    else if( balanceFactor(node)==2 && balanceFactor(node->lchild)==-1 )
        return LRRotation(node) ;
    else if( balanceFactor(node)==-2 && balanceFactor(node->rchild)==-1 )
        return RRRotation(node) ;
    else if( balanceFactor(node)==-2 && balanceFactor(node->rchild)==1 )
        return RLRotation(node) ;


    return node ;

}




int main() {
    root = Rinsert(root , 10) ;
    Rinsert(root , 5) ;
    Rinsert(root , 2) ;

    return 0 ;
}