#include<stdio.h>
#include<stdlib.h>

typedef struct BS_tree{
    int data;
    struct BS_tree *left ;
    struct BS_tree *right;

}NODE;

int count_nonleaf(struct BS_tree* root);

void insert_node(NODE **node, int data){
    
    if(*node == NULL){
        NODE *temp=NULL;
        temp = (NODE *)malloc(sizeof(NODE));
        temp->data = data;
        temp->left = temp-> right = NULL;
        *node=temp;
        
    }
    else if(data< (*node)->data) insert_node(&((*node)->left),data);

    else if(data > (*node)->data) insert_node(&((*node)->right),data);

}

void create_tree(NODE **root){
    printf("\nEnter the no of the element you want in tree : ");
    int no_of_element=0;
    scanf(" %d",&no_of_element);
    for(int i=0;i<no_of_element; i++){
        int data=0;
        printf("\nEnter the element : ");
        scanf(" %d",&data);
        insert_node(root, data);
        printf("\n%d is added in Tree",data);

    }
}

void inorder( NODE *node){
    if(node != NULL){
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}



void create_mirror(NODE* root, NODE** mirror)
{
    if (root == NULL) {
        mirror = NULL;
        return;
    }

    *mirror = (NODE*)malloc(sizeof(NODE));
    (*mirror)->data = root->data ;
    (*mirror)->left = NULL;
    (*mirror)->right = NULL;
    create_mirror(root->left, &((*mirror)->right));
    create_mirror(root->right, &((*mirror)->left));
}
 
int main(){
    NODE *root = NULL;
    create_tree(&root);

    printf("\nTree element in inorder transversal is  [ ");
    inorder(root);
    printf("]");

    NODE *mirror = NULL;
    create_mirror(root, &mirror);
    printf("\nMirror tree element in inorder transversal is  [ ");
    inorder(mirror);
    printf("]");

    printf("\n");
    return 0;
}




