#include<stdio.h>
int factors(int n) 
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
    static int sum=0;
    int no=n;
if(n!=0)
{
    sum*=10;
    sum+=n%10;
    n/=10;
    palindrome(n);
}
 if(sum==no)
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
    int i,result ,n ,check ; 
    printf("enter the number till which you want to check prime and palindrom\n");
    scanf("%d",&n);
    printf("%d",palindrome(n));
    for (i=1;i<=n;i++) 
    { 
        result=prime(i); 
        check=palindrome(i);
        if(result==1 && check==1)
        {
            printf("\n its is prime and palindrome");
        }

    }
    return 0;
} 
