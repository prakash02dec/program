#include<stdio.h>
#include<math.h>
int main() 
{
    int t, k , n;

    scanf("%d",&t);
    while(t>0)
    {
	   scanf("\n%d",&n);
	   char x[n+1];
	   scanf("\n %d",&k);
	   x[n] = 0;
	   if(n>k)
	   {
	      printf("%d",-1);
	      break;
	   }
	   if(k%2==1)
	    {
	       x[n-1]=97;
	       n--;
	       k--;
	    }
	    if(n!=0)
	    {
	
          if(n==1)
	       {
		      k=log2(k);
	           x[n-1]=97+k;
		
	        }
          if(k%2==0 && k%n==0 )
	        { if((k/n)%2==1) 
	           {
				   
			   }
			   k/=n;
		       k=log2(k);
	           while(n>0)
	            {
		         x[n-1]=97+k;
		         n--;
	            }
	        }
	       else if(k%2==0 && k%n!=0)
	        {   
	            x[n-1]=96+(k%n);
	            k=k-k%n;
	            n--;
		        k=log2(k);
	            k=k/n;
	            while(n>0)
	               {
		             x[n-1]=96+k;
		              n--;
	               }

	        }
            printf("\n %s",x);
	        t--;
        }
    } 
    return 0;
}