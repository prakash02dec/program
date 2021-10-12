#include <stdio.h>
int main()
{
  int  low, high, mid, n, key, arr[100];

  printf("Enter number of elements\n");
  scanf("%d", &n);
  register int i;
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  printf("Enter value to find\n");
  scanf("%d", &key);

  low = 0;
  high = n - 1;
  mid = (low+high)/2;

  while (low <= high) {
    if (arr[mid] < key)
      low = mid + 1;
    else if (arr[mid] == key) {
      printf("%d found at location %d.\n", key, mid+1);
      break;
    }
    else
      high = mid - 1;

    mid = (low + high)/2;
  }
  if (low > high)
    printf("Not found! %d isn't present in the list.\n", key);

  return 0;
}
