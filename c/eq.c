#include<stdio.h>
#include<math.h>
int main()
{
float a,b,c,d,root1,root2 ,imaginary;
// determinant d
printf("\n enter the value of a,b,c of equation ax^2 + bx +c= 0 \n");
scanf("%f %f %f",&a,&b,&c);
d=b*b-(4*a*c);
switch(d>0)
 {
   case 1: d=sqrt(d);
           root1= (-b-d)/(2*a);
           root2= (-b+d)/(2*a);
           printf("the 2 roots of the equation is %0.3f and %0.3f",root1,root2);
           break;
   case 0: switch(0>d)
           {
             case 0: root2=root1= -b/(2*a);
                     printf("the 2 roots of the equation is %0.3f and %0.3f",root1,root2);
                     break;
             case 1: d=sqrt(-d);
                     root1=root2= (-b/(2*a));
                     imaginary=d/2*a;
                      printf("the 2 roots of the equation is %0.3f +  %0.3f i and %0.3f %0.3f i",root1,imaginary ,root2 , -imaginary); 
                     break;
                                  
           }
 }
    

}