#include<stdio.h>
#include<math.h>
int main() 
{
	int t, k , n;
    
    scanf("%d",&t);
    while(t>0)
    {
        scanf("\n%d",&n);
        char x[n];
        scanf("\n %d",&k);
        if(n>k)
        {
            printf("%d",-1);
            break;
        }
        if(k%2==1)
        {
            x[n-1]=97;
            n--;
            k--;
        }
        k=log2(k);
        if(n==1)
        {
            x[n-1]=97+k;
        }
        if(k%n==0)
        {
            k/=n;
            while(n>0)
            {
                x[n-1]=97+k;
                n--;
            }
        }
        else if(k%n!=0)
        {
            x[n-1]=97+(k%n)+k/n;
            k=k-k%n -k/n;
            n--;
            k=k/n;
            while(n>0)
            {
                x[n-1]=97+k;
                n--;
            }

        }
         printf("\n %s \n",x);
         t--;

    }
 return 0;
}