#include <stdio.h>
#include <stdlib.h>


int main() {
    int n=0 , count=0 , max=0;
    printf("\nEnter the size of an array : ");
    scanf("%d",&n);
    int a[n] ,size=-1;
    int *freq=NULL;    
    while(freq==NULL)
    freq=(int *)malloc(sizeof(int)*n) ; 
    
    register int j=0 , i=0;
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        for(j=0;j<=size;j++)
        {
            if(a[i]==freq[j])
            {
            count++;
            break;
            }
        }
        if(j>size)
        {
            size++;
            freq[size]=a[i];

        }

    }
    free(freq);

    printf("\nNo of duplicate element found in array is : %d",count);
    
	return 0;
}

