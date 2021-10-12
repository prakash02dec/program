#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
    int data;
    struct node *next;
}QUEUE;
 
QUEUE *front = NULL, *rear = NULL;
 
void enqueue(int value)
{
    QUEUE *newNode = malloc(sizeof(QUEUE));
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL && rear == NULL)
        front = rear = newNode;
    else{
        rear->next = newNode;
        rear = newNode;
    }
    printf("\n%d is add to the queue",value);
}
 
void dequeue()
{
    QUEUE *temp;
 
    if (front == NULL) {
        printf("Queue is Empty. Unable to perform dequeue\n");
        return;
        }
    else{
        temp = front;
        int elem=temp->data;
        front = front->next;

        if (front == NULL) rear = NULL;

        free(temp);
        printf("\n %d is the deleted element int the queue",elem);
        return;
    }
}

int peak(){
    
    if (front != NULL) return front->data;
    else return 0;
}


int queue_size()
{
    QUEUE *temp = front;
    int count=0;
    
    while(temp!=NULL){
    temp=temp->next;
    count++;
    }
    
    return count;
}

 
void display()
{
    printf("\nQueue :");

    QUEUE *temp = front;
    
    while (temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }

}
 
int main()
{
    enqueue(34);
    enqueue(65);
    enqueue(87);
    enqueue(37);
    enqueue(32);
    peak();
    printf("\n queue size right now %d ",queue_size());
    display();
    dequeue();
    dequeue();
    display();

    printf("\n");
    return 0;
}