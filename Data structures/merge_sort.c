#include <stdio.h>

int n=0;




void merging(int low, int mid, int high ,int arr[]) {
   int l1, l2, i , b[n];

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(arr[l1] <= arr[l2])
         b[i] = arr[l1++];
      else
         b[i] = arr[l2++];
   }
   
   while(l1 <= mid)    
      b[i++] = arr[l1++];

   while(l2 <= high)   
      b[i++] = arr[l2++];

   for(i = low; i <= high; i++)
      arr[i] = b[i];
}

void sort(int low, int high , int arr[]) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid , arr);
      sort(mid+1, high , arr);
      merging(low, mid, high , arr);
   } else { 
      return;
   }   
}

int main() { 
   int register i , j ;

   printf("Enter number of elements\n");
   scanf("%d", &n);
   int arr[n];

   for (i = 0; i < n; i++)
   scanf("%d", &arr[i]);

   sort(0, n , arr);

   printf("\nsorted\n");
   
   for(i = 0; i < n; i++)
      printf("%d ", arr[i]);

   return 0;
}
