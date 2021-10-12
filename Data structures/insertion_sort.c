#include <stdio.h>
int main()
{
    int n, temp;
    int register i , j ;

    printf("Enter number of elements\n");
    scanf("%d", &n);
    int arr[n];

    for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
    
    for (i = 1 ; i <= n - 1; i++)
    {
	    j = i;
        while ( j > 0 && arr[j-1] > arr[j])
        {	        
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
    
    printf("Sorted list in ascending order:\n");
    
    for (i = 0; i <= n - 1; i++)
    printf("%d\n", arr[i]);

    return 0;
}
