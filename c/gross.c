#include<stdio.h>
int main()
{
  float bs , da , hr , grosspay ;
  printf("\n enter your basic salary\n");
  scanf("%f",&bs);
  da=0.4*bs;
  hr=0.2*bs;
  grosspay= bs + da + hr ;
  printf("\n your basic salary = %f\t", bs);
  printf("\n your dearness allowance = %f\t",da);
  printf("\n your house rent= %f\t", hr);
  printf("\n\n your gross pay=%f\t", grosspay);
  return 0;   
}