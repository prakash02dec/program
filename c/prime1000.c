#include<stdio.h>
int factors (int n) 
{ 
int i; 
int cnt=0; 
for (i=1;i<=n;i++) 
{ 
if (n%i==0) 
cnt++; 
} 
return cnt; 
} 
int prime(int num) 
{ 
int cnt; 
cnt=factors(num); 
if (cnt==2) 
{ 
return 1; 
} 
else 
{ 
return 0; 
} 
}
void main() 
{ 
int i,res , count=0, sum=0 ; 
for (i=1;i<1000;i++) 
{ 
res=prime(i); 
if(res==1) 
{ 
sum+=i;

count++;
} 
} 
printf("%d is sum of %d prime from 1 to 1000",sum , count); 
} 
