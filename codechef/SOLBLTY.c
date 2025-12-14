#include <stdio.h>

int main(void) {
	int T;
	scanf("%d\n",&T);
	while(T--)
	{
	    int  X,A, B;
	    scanf("%d %d %d",&X,&A,&B);
	    int sol=A+(100-X)*B;
	    printf("\n%d",sol*10);
	    
	}
	return 0;
}

