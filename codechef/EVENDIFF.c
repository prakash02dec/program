#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d\n",&t);
	while(t>0)
	{
	 int i ,j , n, count=0, odd=0;
	 scanf("%d\n",&n);
	 int a[n];
	 for(i=0;i<n;i++)
	 {
	     scanf("%d",&a[i]);
	     if(a[i]%2!=0)
	     {
	         odd++;
	     }
	 }
	if(((n/2)+1)>odd)
	printf("\n%d",odd);
	else
	printf("\n%d",n-odd);
	
	 t--;
	}
	return 0;
}

