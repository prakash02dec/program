#include <stdio.h>

int main(void) {
	int t;
	scanf("%d\n",&t);
	while(t--)
	{
	    int n,i,t=0 ,count=0;
	    scanf("%d\n",&n);
	    int w[n],l[n] , temp[n];
	    for(i=0;i<n;i++)
	    {
	        scanf("%d",&w[i]);
	        temp[w[i]-1]=i;
	    }
	    for(i=0;i<n;i++)
	    {
	        scanf("%d",&l[i]);
	    }
	    for(i=0;i<n-1;i++)
	    {
	        t=temp[i+1];
	        while(temp[i+1]<=temp[i])
	        {
	            temp[i+1]+=l[t];
	            count++;
	        }
	    }
	    printf("%d\n",count);
	}
	return 0;
}

