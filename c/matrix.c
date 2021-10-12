#include<stdio.h>
int main()
{
    int i,j,n,sum_1,sum_2,diff,t,k,x;
    printf("enter size \n");
    scanf("%d",&n);
    int a[n][n];
    sum_1=sum_2=diff=0;
    for (i=0;(i<=(n-1));i++) 
    {
        for (j=0;j<=(n-1);j++)
        {
            scanf("%d",&x);
            if (x>=-100 && x<=100)
            {
                a[i][j]=x;
            }
        }
    }
    for (t=0;t<=(n-1);t++)
    {
        sum_1+=a[t][t];
    }
    for (k=0;k<=(n-1);k++)
    {
        sum_2+=a[k][(n-1)-k];
    }
    printf("%d", sum_1-sum_2);
    return 0;
}
