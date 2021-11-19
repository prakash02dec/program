#include <bits/stdc++.h>
using namespace std;

int main() {
	   int n , q ;
    register int i,j;
    scanf("%d  %d\n",&n, &q);
    long *a=(long*)malloc(n*sizeof(long));
    for(i=0;i<n;i++)
    {
        scanf("%ld", (a+i));
    }
    sort (a,a+n);
    while(q--)
    {
        int count, x;
        scanf("\n%d",&x);
        count=lower_bound(a,a+n,x)-a;
        
       if((*(a+count)-x)==0 && count<n)
            {
                printf("0\n");
               continue;
            }
        
        if(count%2==0)
        printf("POSITIVE\n");
        else
        printf("NEGATIVE\n");
    }
    free(a);
	return 0;
	return 0;
}
