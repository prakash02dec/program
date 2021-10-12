#include<stdio.h>
#include<math.h>
int main()
{
int no ,i , n , range=0 , s=0 , b=0 ;
printf("\n enter the number of numbers you want to insert");
scanf("\n%d", &n);
for(i=0;i<n;i++)
{
printf("\n enter number");
scanf("\n%d", &no);
if(i==0)
s=b=no;
else if(s>no)
s=no;
else if(b<no)
b=no;
}
range=b-s;
if(range<0)  vvvvvvvvvvvvvvvvvc
range*=-1;

printf("\n range of no you entered \t %d", range);
 return 0;
}

