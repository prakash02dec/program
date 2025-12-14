#include <stdio.h>
#include<stdlib.h>
int main(void) {
	int T;
	scanf("%d\n",&T);
	while(T--)
	{
	    int n,m;
	    unsigned long long result=0,temp=0;
	    scanf("%d %d",&n,&m);
	    register int b,i, j;
	    long long int arr[n+1];
	   // while(arr==NULL)
	   // arr=(int*)malloc((n+1)*sizeof(int)); 
	    
	    
	    for(i=0;i<n+1;i++)
	    arr[i]=1;
	    
	    for(b=2;b<=n;b++)
	    {
	        temp=m%b;
	        result+=arr[temp];
	        for(j=temp;j<=n;j+=b)
	        arr[j]++;
	        
	        
	        
	    }
	   
	    printf("\n%lld",result);
	   // free(arr);  
	}
	return 0;
}

