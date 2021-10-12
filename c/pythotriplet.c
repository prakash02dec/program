#include<stdio.h>
#include<math.h>
int main()
{
int i , j , k;
printf("pythagorean triplet with side less than or eqaul to 30\n");
for(i=1;i<=30;i++)
for(j=1;j<=30;j++)
for(k=1;k<=30;k++)
if(pow(i,2)==pow(j,2)+pow(k,2) && k>j)
printf("\n sum of sq of %d and %d is equal to sq of %d", j , k , i);
return 0;
}
