#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);  /* no of test */
    while(t>0)
    {   
        int i , k, d, total=0 ;
        scanf("\n%d",&i); /* no of setter */
        scanf("\t%d",&k); /* no of question */ 
        scanf("\t%d",&d); /* no of days */ 
        if(k!=0)
        {
        int a[i];
        for(i;i>0;i--)
        {
            scanf("\n%d\t", &a[i-1]); /* no of question set */
            total+=a[i-1];
        }
            if(total/k>d)
             printf("\n %d", d);
            else
             printf("\n %d", total/k );
        }
        t--;

    }
}