#include<stdio.h>
int no=0;
int factors (int n) 
{ 
    int i; 
    int count=0; 
    for (i=1;i<=n;i++) 
    { 
        if (n%i==0) 
        count++; 
    } 
    return count; 
} 
int palindrome(int n)
{
    static int sum=0 ;
    if(n!=0)
{
    sum*=10;
    sum+=n%10;
    n/=10;
    palindrome(n);
}
else if(sum==no)
return 1;
else
return 0;
}

int prime(int num) 
{ 
    int count; 
    count=factors(num); 
    if (count==2) 
    { 
        return 1; 
    } 
    else 
    { 
        return 0; 
    } 
}
int main() 
{ 
    int i,result , count=0, sum=0 , n; 
    printf("enter the number till which you want to check prime and palindrom");
    scanf("%d",&n);
    for (i=1;i<=n;i++) 
    { 
        result=prime(i); 
        no=i;
        if(result==1 && palindrome(i))
        {
            printf("\n its is prime and palindrome");
        }
    }
    return 0;
} 
