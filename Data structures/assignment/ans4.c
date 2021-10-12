#include<stdio.h>

int main(){
    int n, i;

    printf("\nEnter size of array: ");
    scanf("%d", &n);
    int arr[n];
    int *ptr = arr; 

    printf("\nEnter elements in array : \n");
    
    for (i=0 ; i<n ; i++)
    scanf("%d", ptr++);
    
    ptr = arr;

    printf("\nArray elements : ");
    for (i = 0;i<n ; i++)
    printf("%d ", *ptr++);

    printf("\n");
    return 0;
}