#include <stdio.h>

int main(void) {
    int T;
	scanf("%d\n",&T);
	while(T--)
	{
	    int N,x,k,flag=0;
	    scanf("%d %d %d",&N,&x,&k);
	    
	    
	    if((N+1)%k==(x%k) || x%k==0)
	    flag=1;
	    
	    
	    
	       // for(int i=0;i*k<=N+1;i++)
	       // {
	       //     if((i*k)==x || (N+1-(i*k) )==x )
	       //     {flag=1;
	       //     break;
	       //     }
	       // }
	    
	    
	    if(flag==1)
	    printf("\nYES");
	    else
	    printf("\nNO");
	    
	}
	
	return 0;
}

