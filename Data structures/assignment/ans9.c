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

int count_nonleaf(struct BS_tree* root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;

    return 1 + count_nonleaf(root->left) + count_nonleaf(root->right);
}
int count_leaf(struct BS_tree* root)
{
  if(root == NULL)      
    return 0;
  if(root->left == NULL && root->right==NULL)     
    return 1;           
  else
    return count_leaf(root->left)+ count_leaf(root->right);     
}

int main(){
    NODE *root = NULL;
    create_tree(&root);
    printf("tree element in inorder transversal is  [ ");
    inorder(root);
    printf("]");
    printf("\nNO of leaf node : %d",count_leaf(root));
    printf("\nNO of non leaf node : %d",count_nonleaf(root));


    printf("\n");
    return 0;
}