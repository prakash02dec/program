#include <stdio.h>

int main()
{
    int n;
    register int i, j;
  
    printf("Enter number of elements in the array : ");
    scanf("%d",&n);
  
    int arr1[n];

    for(i=0;i<n;i++)
    scanf("%d",&arr1[i]);
	
    printf("\nThe unique elements found in the array are : ");
  
    for(i=0; i<n; i++)
    {
        int count=0;
        for(j=0; j<n ; j++)
        if(arr1[i]==arr1[j] && j!=i ) {
            count++;
            break;
        }
        if(count==0)
        printf("%d ",arr1[i]);
    }
  printf("\n");
  return 0;
}
