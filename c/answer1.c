#include<stdio.h>
#include<string.h>

int main()
{
   char arr[100], temp[100];
   printf("enter the string \n");
   scanf(" %[^\n]s",arr);
   strcpy(temp,arr);
   strrev(temp);
   printf("\n the reverse string is %s",arr);
   if(strcmp(arr,temp)==0)
       printf("string is palindrome");
   else 
    printf("its is not a palindrome");
   return 0;
}
