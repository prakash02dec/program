#include<stdio.h>
#include<stdlib.h>

int main()
{
    int no;
    printf("no of people in auction \n");
    scanf("%d",&no);
    int *bid;
    bid=(int*)malloc(sizeof(int)*no);

    for(int i=0;i<no; i++)
    {
        scanf("%d",&bid[i]);
    }

    for(int i=0;i<12;i++)
    {
        for(int j=0;j<11-i;j++)
        {
            if(bid[i+1]<bid[i])
            {
                int temp; 
                temp=bid[i+1];
                bid[i+1]=bid[i];
                bid[i]=temp;
            }
        }
    }

    printf("\nthe highest bid by the people is %d \n second highest by people is %d \n the difference between highest and second highest bid is %d\n",bid[no-1],bid[no-2],(bid[no-1]-bid[no-2]));

    return 0;

    
}