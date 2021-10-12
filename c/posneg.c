#include<stdio.h>
int main()
{
int no;
printf("enter the number\n");
scanf("%d", &no);
switch(no>0)
{
case 1: printf("it is a positive no");
        break;
case 0: switch(no<0)
        {
          case 1: printf(" its a negative no");
                  break;
          case 0: printf(" its a zero");
                  break;
        }
}
return 0;
}