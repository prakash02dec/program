#include<stdio.h>
int main()
{
int m1 ,m2 , m3 , m4 , m5 , total;
float per;
printf("\n enter 1st subject marks \n");
scanf("%d",&m1);
printf(" enter 2nd subject marks \n");
scanf("%d",&m2);
printf(" enter 3rd subject marks \n");
scanf("%d",&m3);
printf(" enter 4th subject marks \n");
scanf("%d",&m4);
printf(" enter 5th subject marks \n");
scanf("%d",&m5);
total=m1+m2+m3+m4+m5;
per=total/5;
printf("\n your aggregiatte marks is %d \n your percentage is %f", total ,per);
return 0;
}
