#include<stdio.h>
#include<math.h>

int main() 
{
    int t;
    scanf("%d\n",&t);
    
    while(t>0)
    {
        int i;
        int n,imin=0,imax=0;
        scanf("%d\n",&n);
        long long int a[n] , max=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            if(a[imin]>a[i])
            imin=i;
            if(a[imax]<a[i])
            imax=i;
            
        }
        max=2ll*abs(a[imax]-a[imin]);
        
        printf("\n%lld",max);
        t--;
    }
    
	return 0;
}


