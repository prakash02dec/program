#include <stdio.h>

int main() 
{
	int n , i,max=1;
	scanf("%d",&n);
	for(i=1;i<=10;i++)
	{
	    if(n%i==0)
	    max=i;
	}
	printf("\n%d",max);
	return 0;
}

