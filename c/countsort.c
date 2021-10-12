#include<stdio.h>
int main()
{
  int a[8]={1,3,6,2,8,2,5,9} , min , max ;
  register int i,j;
  min=max=a[0];
  
  for(i=0;i<8;i++)
  {
    if(min>a[i])
    min=a[i];
    if(max<a[i])
    max=a[i];  
  }
  printf("%d %d\n", min , max);
  int n=max-min;
  int book[n+1];
  for(i=0;i<=n;i++)
  {
    book[i]=0;
  }

  int temp;
  for(i=0;i<8;i++)
  {
    temp=a[i];
    book[temp-min]++;
  }
  
  int k=0;
  i=min;
  while(i-min<=n)
  {
    if (book[i-min]!=0)
    {
       a[k]=i;
       book[i-min]--;
       k++;
    }
    if (book[i-min]==0)
    {
      i++;
    }
  }
    for(i=0; i<8 ; i++)
    {
      printf("%d",a[i]);
    }

  return 0;
}
