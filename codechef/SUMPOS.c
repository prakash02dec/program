#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t>0)
    {
        int x , y , z;
        scanf("\n%d %d %d",&x,&y,&z);
        if((x+y)==z || (x+z)==y || (z+y)==x)
        {
            printf("\nYES");
        }
        else
        {
            printf("\nNO");
        }
        
        t--;
    }
    return 0;
}