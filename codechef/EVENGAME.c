#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d\n",&t);
	while(t>0)
	{
	 int i ,n , sum=0 ;
	 scanf("%d\n",&n);
	 int a[n];
	 for(i=0;i<n;i++)
	 {
	     scanf("%d",&a[i]);
	 }
	 for (i=0;i<n;i++)
      {
          sum += a[i];
      }
    
      if(sum%2==0)
      {
          printf("\n1");
      }
      else
          printf("\n2");
          t--;
	}
	return 0;
}

