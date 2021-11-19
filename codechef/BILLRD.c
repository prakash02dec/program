#include<stdio.h>
int main()
{
   int t;
   scanf("%d\n",&t);
   while(t>0)
   {
       int x , y , n , k , d=1,i=0;
        scanf("%d",&n);
        scanf("%d",&k);
        scanf("%d",&x);
        scanf("%d",&y);
        if(x==y)
        printf("\n%d %d",n ,n);
        else if(y>x)
        {
            switch(k%4)
            {
                case 1 : printf("\n%d %d",(n-(y-x)),n); break;
                case 2 : printf("\n%d %d",n,(n-(y-x))); break;
                case 3 : printf("\n%d %d",(y-x),0); break;
                case 0 : printf("\n%d %d",0 ,(y-x)); break;
            }
        }
        else
        {
            switch(k%4)
            {
                case 1 : printf("\n%d %d",n,(n-(x-y)));break;
                case 2 : printf("\n%d %d",(n-(x-y)),n);break;
                case 3 : printf("\n%d %d",0 ,(x-y));break;
                case 0 : printf("\n%d %d",((x-y)),0);break;
            }
        }
        t--;
   }
   return 0;
}