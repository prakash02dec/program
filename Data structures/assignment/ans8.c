#include <stdio.h>
#include <stdlib.h>
 
typedef struct node {
    int data;
    int priority;
 
    struct node* next;
 
} Node;


Node* newNode(int d, int p)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;
 
    return temp;
}
 

int peek(Node** head)
{
    if(*head!= NULL)
    return (*head)->data;
}
 

void pop(Node** head)
{
    if(*head!= NULL){
        Node* temp = *head;
        (*head) = (*head)->next;
        free(temp);
    }
}
 

void push(Node** head, int d, int p)
{
    Node* start = (*head);

    Node* temp = newNode(d, p);

    if ((*head)->priority > p) {

        temp->next = *head;
        (*head) = temp;
    }
    else {
 
        while (start->next != NULL &&
            start->next->priority < p) {
            start = start->next;
        }
 
        temp->next = start->next;
        start->next = temp;
    }
}



void display(Node *head)
{
    printf("\nThe priority queue is : ");
    while(head!=NULL){
    printf("%d ",head->data);
    head=head->next;
    }
}
 
int main()
{
    Node* priority_list = newNode(21, 1);
    push(&priority_list, 32, 2);
    push(&priority_list, 43, 3);
    push(&priority_list, 12, 0);
    push(&priority_list, 421, 4);
    push(&priority_list, 234, 0);
    
    printf("\nElement in the list is : ");
    display(priority_list);

    printf("\nPeak value before pop %d ", peek(&priority_list));
    pop(&priority_list);
    printf("\nPeak value after pop %d ", peek(&priority_list));

    printf("\n");
    return 0;
}