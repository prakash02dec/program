#include<stdio.h>
#include<math.h>
int main()
{
int no , n , octal=0 , p=0;
printf("\n enter a no ");
scanf("\n%d",&no);
n=no;
while(n!=0)
{

octal+=(n%8)*pow(10,p++);
n/=8;
}
printf("\n octal equaivalent of a no %d is %d ",no , octal);

return 0;
}

