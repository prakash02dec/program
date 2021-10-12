#include<stdio.h>

int q[30],top=-1,front=-1,rear=-1,adjancy_matrix[30][30],visited[30],stack[30];
int delete();
void add(int item);
void bfs(int source,int no_of_vertices);
void dfs(int source,int no_of_vertices);
void push(int item);
int pop();

void main()
{
    int no_of_vertices,source,ch;
    register int i ,j ;
    char c,wish;

    printf("Enter the no. of vertices ");
    scanf("%d",&no_of_vertices);

    for(i=1;i<=no_of_vertices;i++)
    for(j=1;j<=no_of_vertices;j++)
    {
        printf("Enter 1 if %d has adjancy_matrix node with %d else 0 ",i,j);
        scanf("%d",&adjancy_matrix[i][j]);
    }

    printf("The adjency matrix is :\no_of_vertices");
    for(i=1;i<=no_of_vertices;i++)
    {
        for(j=1;j<=no_of_vertices;j++)
        printf(" %d",adjancy_matrix[i][j]);
    
        printf("\no_of_vertices");
    }

    do
    {
        for(i=1;i<=no_of_vertices;i++)
        visited[i]=0;
        printf("\nMENU");
        printf("\n1.B.F.S");
        printf("\n2.D.F.S");
        printf("\nEnter your choice");
        scanf("%d",&ch);
        printf("Enter the source vertex :");
        scanf("%d",&source);

        void (*menu[])(int , int )= {bfs,dfs};
        if(ch<3){
            menu[ch-1](source,no_of_vertices);
        }


        printf("Do you want to continue (Y/N) ? ");
        scanf(" %c",&wish);

    }while((wish == 'y')||(wish == 'Y'));
    }


//BFS(breadth-first search)
void bfs(int source,int no_of_vertices)
{
    int p,i;
    
    add(source);
    visited[source]=1;
    p=delete();
    
    if(p!=0)
    printf(" %d",p);
    
    while(p!=0)
    {
        for(i=1;i<=no_of_vertices;i++)
        if((adjancy_matrix[p][i]!=0)&&(visited[i]==0)){
        add(i);
        visited[i]=1;
        }
        
        p=delete();
        if(p!=0)
        printf(" %d ",p);
    }
    for(i=1;i<=no_of_vertices;i++)
    if(visited[i]==0)
    bfs(i,no_of_vertices);
}


void add(int item)
{
    if(rear==29) printf("QUEUE FULL");
    else
    {
        if(rear==-1)
        {
            q[++rear]=item;
            front++;
        }
        else
        q[++rear]=item;
    }
}    
    
int delete()
{
    int k;
    
    if((front>rear)||(front==-1)) return 0;
    else
    {
        return q[front++];
    }
}


//DFS(depth-first search)
void dfs(int source,int no_of_vertices)
{
    int i,k;
    push(source);
    visited[source]=1;
    k=pop();
    if(k!=0)
    printf(" %d ",k);
    while(k!=0)
    {
        for(i=1;i<=no_of_vertices;i++)
        if((adjancy_matrix[k][i]!=0)&&(visited[i]==0))
        {
            push(i);
            visited[i]=1;
        }
        k=pop();
        if(k!=0)
        printf(" %d ",k);
    }
    for(i=1;i<=no_of_vertices;i++)
    if(visited[i]==0)
    dfs(i,no_of_vertices);
}

void push(int item)
{
    if(top==29)
    printf("Stack overflow ");
    else
    stack[++top]=item;
}

int pop()
{
    int k;
    if(top==-1)
    return(0);
    else
    {
        k=stack[top--];
        return k;
    }
}
