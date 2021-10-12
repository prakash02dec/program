#include <stdio.h>
#include<stdbool.h>

bool verify(int a, int b,int c);

int main()
{
	int side[3] ,i ;
	for (i=0;i < 3;i++)
	{
			printf("Enter Side length %d\n", i);
			scanf("%d", &side[i]);
		
	}
	bool final = verify(side[0],side[1],side[2]);
	if (final==true)
	{
		printf("The 3 sides form a triangle");
	}
	else
	{
		printf("No,it does not form a triangle");
	}
}

bool verify(int a, int b,int c)
{
	if (a+b>c && b+c>a && c+a>b)
	{
		return true;
	}
	else
	{
		return false;
	}
}