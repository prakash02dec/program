#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d\n",&t);
	while(t>0)
	{
	 int i ,j , n, count=0;
	 scanf("%d\n",&n);
	 int a[n];
	 for(i=0;i<n;i++)
	 {
	     scanf("%d",&a[i]);
	 }
	 for(i=0;i<n;i++)
	 for(j=0;j<n;j++)
	 {
	     if(a[i]%2!=0 && a[j]%2!=0 && (a[i]-a[j])%2==0)
	     {
	         j=n;
	         count++;
	     }
	 }
	 printf("\n%d",count);
	 t--;
	}
	return 0;
}
