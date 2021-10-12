#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
    int size, front, rear ,  *arr;
}QUEUE;

int isempty(QUEUE *q)
{
    if(q->front==q->rear) return 1 ;
    else return 0;
}


int isfull(QUEUE *q)
{
    if(q->rear==q->size-1) return 1;
    else return 0; 

}


void enqueue(QUEUE *q,int value)
{
    if(isfull(q)) printf("\n This queue is full");

    else{
        q->rear++;
        q->arr[q->rear]=value;
        printf("\n%d is add to the queue",value);
    }
}
void dequeue (QUEUE *q)
{
    if(isempty(q)) printf("\nTHis queue is empty ");

    else{
        q->front++;
        int elem=q->arr[q->front];
        printf("\n %d is the deleted element int the queue",elem);        
    }
}

void display(QUEUE q)
{
    printf("\nthe element in the queue:\n");

    while(q.front!=q.rear){
        q.front++;
        printf("%d ",q.arr[q.front]);
    }
}

int peek(QUEUE q)
{
    if(isempty(&q)) printf("\nTHis queue is empty ");

    else printf("\n%d is the front element",q.arr[q.front+1] );   
}

int main(){
    QUEUE q;
    q.size=100;
    q.rear=q.front=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));

    enqueue(&q,13);
    enqueue(&q,56);
    enqueue(&q,78);
    enqueue(&q,45);
    display(q);
    peek(q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q,32);
    printf("\n");
    
    return 0;
}