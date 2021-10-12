#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};
  
struct Queue {
    struct Node *front, *rear;
};
  
void enQueue(struct Queue* q, int value)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    if (q->front == NULL)
        q->front = temp;
    else
        q->rear->next = temp;
  
    q->rear = temp;
    q->rear->next = q->front;
}
  
int deQueue(struct Queue* q)
{
    if (q->front == NULL) {
        printf("Queue is empty");
        return 0;
    }
    int value; 
    
    if (q->front == q->rear) {
        value = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    }
    else 
    
    {
        struct Node* temp = q->front;
        value = temp->data;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }
  
    return value;
}


void displayQueue(struct Queue* q)
{
    struct Node* temp = q->front;
    printf("\nElements in Circular Queue are: ");
    while (temp->next != q->front) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}


int main()
{


    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
  
    enQueue(q, 14);
    enQueue(q, 56);
    enQueue(q, 23);
    enQueue(q, 95);
    enQueue(q, 21);
    displayQueue(q);
    printf("\nDeleted value = %d", deQueue(q));
    printf("\nDeleted value = %d", deQueue(q));
    displayQueue(q);
  
    return 0;
}