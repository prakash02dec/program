#include<stdio.h>
void palindrome();
int no;
int main()
{ 
int n ;
printf("\n enter number \n");
scanf("%d",&n);
no=n;
palindrome(n);
return 0;
}
void palindrome(int n)
{
static int sum=0;
if(n!=0)
{sum*=10;
sum+=n%10;
n/=10;
palindrome(n);
}
else if(sum==no)
printf(" it is  a palindrome no ");
else
printf(" it is not a palindrome no ");
}


