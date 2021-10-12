#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct node
{
    int ssn;
    char name[20],dpt[20],designation[20],phn[10];
    float salary;
    struct node *next;
    struct node *prev;
};
typedef struct node* NODE;
struct node *employee;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        cout<<"Out Of Memory!";
        exit;
    }
    return 0;
}
void read(NODE)
{
    // employee = getnode();
    cout<<"SSN: ";
    cin>>employee->ssn;
    cout<<"Name: ";
    cin>>employee->name;
    cout<<"Department: ";
    cin>>employee->dpt;
    cout<<"Designation: ";
    cin>>employee->designation;
    cout<<"Salary: ";
    cin>>employee->salary;
    cout<<"Phone Number: ";
    cin>>employee->phn;
    employee->prev=NULL;
    employee->next=NULL;
}
NODE front_insertion(NODE head)
{
    NODE employee = (struct node*)malloc(sizeof(struct node));
    cout<<"SSN: ";
    cin>>employee->ssn;
    cout<<"Name: ";
    cin>>employee->name;
    cout<<"Department: ";
    cin>>employee->dpt;
    cout<<"Designation: ";
    cin>>employee->designation;
    cout<<"Salary: ";
    cin>>employee->salary;
    cout<<"Phone Number: ";
    cin>>employee->phn;
    // read(employee);
    if(head==NULL)
        return employee;
    employee->next=head;
    head->prev=employee;
    return employee;
}
NODE rear_insertion(NODE head)
{
    NODE cur;
    read(employee);
    if(head==NULL)
        return employee;
    cur = head;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next=employee;
    employee->prev=cur;
    return head;
}
NODE insertion(NODE head, int posn)
{
    NODE temp;
    read(employee);
    if(head==NULL)
        return employee;
    while(posn-- && temp->next!=NULL)
    {
        temp=temp->next;
        if(posn==0 && temp==NULL)
        {
            cout<<"NO such position exists.";
            exit;
        }
    }
    NODE temp1;
    temp1 = temp->next;
    employee->next=temp1;
    employee->prev=temp;
    temp->next=employee;
    temp1->prev=employee;
    return head;    
}
NODE front_deletion(NODE head)
{
    NODE temp;
    if(head==NULL)
    {
        cout<<"DLL is empty.";
        return NULL;
    }
    if(head->next==NULL)
    {
        cout<<"Employee Details\n SSN:"<<head->ssn<<" Name: "<<head->name<<" Phone Number: "<<head->phn<<" Department: "<<head->dpt<<" Designation: "<<head->designation<<" \n\t has been deleted.";
        free(head);
        return NULL;
    }
    temp= head->next;
    head->prev=NULL;
    cout<<"Employee Details\n SSN:"<<head->ssn<<" Name: "<<head->name<<" Phone Number: "<<head->phn<<" Department: "<<head->dpt<<" Designation: "<<head->designation<<" \n\t has been deleted.";
    free(head);
    return temp;
}
NODE rear_deletion(NODE head)
{
    NODE cur,prev;
    if(head==NULL)
    {
        cout<<"DLL is empty.";
        return head;
    }
    if (head->next == NULL)
    {
        cout<<"Employee Details\n SSN:"<<head->ssn<<" Name: "<<head->name<<" Phone Number: "<<head->phn<<" Department: "<<head->dpt<<" Designation: "<<head->designation<<" \n\t has been deleted.";
        free(head);
        return NULL;
    }
    prev = NULL;
    cur = head;
    while(cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    cout<<"Employee Details\n SSN:"<<cur->ssn<<" Name: "<<cur->name<<" Phone Number: "<<cur->phn<<" Department: "<<cur->dpt<<" Designation: "<<cur->designation<<" \n\t has been deleted.";
    free(cur);
    prev->next=NULL;
    return head;   
}
NODE deletion(NODE head,int posn)
{
    NODE temp;
    if(head==NULL)
    {
        cout<<"DLL is empty.";
        return head;
    }
    while(posn-- && temp->next!=NULL)
    {
        temp=temp->next;
        if(posn==0 && temp==NULL)
        {
            cout<<"NO such position exists.";
            return head;
        }
    }
    NODE temp1 = temp->prev;
    temp1->next=NULL;
    cout<<"Employee Details\n SSN:"<<temp->ssn<<" Name: "<<temp->name<<" Phone Number: "<<temp->phn<<" Department: "<<temp->dpt<<" Designation: "<<temp->designation<<" \n\t has been deleted.";
    free(temp);
    return head;
}
void display(NODE head)
{
    NODE temp,cur;
    int count=0;
    if(head==NULL)
    {
        cout<<"DLL is empty";
        return;
    }
    cur = head;
    while(cur!=NULL)
    {
        count++;
        cout<<"\n"<<count<<". \n Employee Details\n SSN:"<<cur->ssn<<" Name: "<<cur->name<<" Phone Number: "<<cur->phn<<" Department: "<<cur->dpt<<" Designation: "<<cur->designation<<" \n";
        cur=cur->next;
    }
    cout<<"The total number of employees are:  "<<count;
}
int main()
{
    NODE head;
    int choice;
    head = NULL;
    for(;;)
    {
        cout<<"\n1:Insert at Front\n2:Insert at Rear\n3:Insert at Any Position\n4:Delete from Front\n5:Delete from Rear\n6:Delete from Any Position\n7:Display\n8:Exit";
        cout<<"\nPlease Enter your Choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            head = front_insertion(head);
            break;
        case 2:
            head = rear_insertion(head);
            break;
        case 3:
            int posn;
            cout<<"Enter the Position at which you will like to Insert: ";
            cin>>posn;
            head =insertion(head,posn);
            break;
        case 4:
            head = front_deletion(head);
            break;
        case 5:
            head = rear_deletion(head);
            break;
        case 6:
            int posn1;
            cout<<"Enter the Position from which you will like to Delete: ";
            cin>>posn1;
            head =deletion(head,posn1);
            break;
         case 7:
            display(head);
            break;
        case 8:
            exit(0);
        default:
            cout<<"Invalid Choice...Try Again.";
            break;
        }

    }
    return 0;
}