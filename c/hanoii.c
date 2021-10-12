#include<stdio.h>
void hanoi(int n,int l, int r, int c)
{
	if(n==1)
	{
		printf("disc %d is moved from %d tower to %d tower\n",n,l,r);
	}
	else
	{
		hanoi(n-1,l,c,r);
		printf("disc %d is moved from %d tower to %d tower\n",n,l,r);
		hanoi(n-1,c,r,l);
	}
}
void main()
{
	hanoi(3,1,3,2);
}