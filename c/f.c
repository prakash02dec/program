#include<stdio.h>
int main(void) {
  int t;
  while(t--)
  {
      int n;
      scanf("%d",n);
      int arr[n],sume=0,sumo=0;
      for(int i=0;i<n;i++)
      {
          scanf("%d",&arr[i]);
      }
      for (int i=0;i<n;i=i+2)
      {
          sume += arr[i];
      }
      for (int j=1;j<n;j=j+2)
      {
          sumo += arr[j];
      }
      if((sume-sumo)%2==0)
      {
          printf("1");
      }
      else
          printf("2");
  }
  return 0;
