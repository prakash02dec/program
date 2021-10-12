#include<stdio.h>
int main()
{
    int i ;
    long int revnum= 0, no , n ;
    printf("enter 5 digit no");
    scanf("%d",&no);
    n=no;
    for(i=0 ; i<5 ; i++)
   {   revnum*=10;
       revnum = revnum+(n%10);
    
       n=n/10; 
   } 
   printf(" \n reverse no %d",revnum);
   return 0;
}