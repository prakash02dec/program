#include <stdio.h>

int main(void) 
{
    int t;
    scanf("%d",&t);
    int prime[1000001];
    int i_prime[1000001]={0,0};
    for(int i=0;i<1000001;i++)
    {
        prime[i]=1;
    }
    for (int p=2; p*p<1000001; p++) 
    { 
        if (prime[p] == 1) 
        {  
            for(int i=p*p; i<1000001;i+=p) 
                prime[i] = 0;
        } 
    } 
    for(int i=2;i<1000001;i++)
    {
        i_prime[i]=i_prime[i-1];
        if(prime[i])
            i_prime[i]++;
    }
    while(t--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(i_prime[x]>y)
            printf("Divyam\n");
        else
        printf("Chef\n");
    }

	return 0;
}

