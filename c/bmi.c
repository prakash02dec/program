#include<stdio.h>
#include<conio.h>
int main()
{
float w , h , bmi ;
printf("\n TO CALCULATE THE BODY MASS INDEX ");
printf("\n enter the weight in kg \n");
scanf("%f",&w);
printf("\n enter the height in meter\n");
scanf("%f",&h);
bmi=w/(h*h);
printf("\nBMI CATEGORY");
if(bmi<=15)
printf("\n Starvation");
else if(bmi>15 && bmi<=17.5)
printf("\n anorexic");
else if(bmi>17.5 && bmi<=18.5)
printf("\n underweight");
else if(bmi>18.5 && bmi<=24.9)
printf("\n ideal");
else if(bmi>=25 && bmi<30)
printf("\n overweight");
else if(bmi>=30 && bmi<40)
printf("\n obese");
else if(bmi>=40)
printf("\n morbidly obese ");
getch();
return 0;
}