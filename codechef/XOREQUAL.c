#include <stdio.h>
#include<math.h>

int mod_expo(long long int x, int y, long long int p);

int main(void) {
    int T;
    scanf("%d\n",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        long long int mod=pow(10,9)+7;
        long int total =mod_expo(2,N-1,mod);   
        printf("\n%d",total);
    
    }
	return 0;
}

int mod_expo(long long int x, int y, long long int p)
{
    long int res = 1;    
 
    x = x % p; 
                
  
    if (x == 0) 
    return 0;
 
    while (y > 0)
    {
        
        if (y & 1)
        res = (res*x) % p;
 
        
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
 