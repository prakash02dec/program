#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

void push(struct Node** head, int new_data)
{
	
	struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

	new_node->next = (*head);
	new_node->prev = NULL;

	if ((*head) != NULL)
	    (*head)->prev = new_node;

	(*head) = new_node;
}

void delete_element(struct Node** head , int key)
{
    struct Node* temp =*head;
    while(temp!=NULL && temp->data != key)
    	temp=temp->next;

    if (*head == NULL || temp == NULL)
        return;
 
    if (*head == temp)
        *head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
 
    free(temp);
    return;
}

void display(struct Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}


int main()
{
	struct Node* head = NULL;
	push(&head, 2);
	push(&head, 3);
	push(&head, 6);
	push(&head, 17);
	push(&head, 32);
	push(&head, 18);
	push(&head, 71);
	push(&head, 34);
	push(&head, 77);
	push(&head, 43);
	printf("\nDoubly Linked List before deleting is : ");
	display(head);
    // delete(&head, 18);
    delete_element(&head,34);
	printf("\n\nDoubly Linked List after  deleting is : ");
    display(head);
    printf("\n");
	return 0;
}