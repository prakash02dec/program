#include<stdio.h>
#include<stdlib.h>
int minute(char a[8] , int i)
{
    int min=0;
    min+=600*(a[i+0]-'0');
    min+=60*(a[i+1]-'0');
    min+=10*(a[i+3]-'0');
    min+=(a[i+4]-'0');
    if((a[i+6]=='P') && ((a[i+0]!='1' && a[i+1]!='2') || (a[i+0]=='1' && a[i+1]!='2') || (a[i+0]!='1' && a[i+1]=='2')) )
    min+=12*60;
    if((a[i+6]=='A') && (a[i+0]=='1') && (a[i+1]=='2'))
    min-=12*60;
    return min;
}

int main(void) {
    int t;
    scanf("%d\n",&t);
    while(t--)
    {
        char p[9];
        int n ,pm;
        scanf(" %[^\n]s",&p);
        pm=minute(p,0);
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int lm,rm;
            char l[19];
            scanf(" %[^\n]s",&l);
            lm=minute(l,0);
            rm=minute(l,9);
            // printf("%d %d %d\n",lm,pm,rm);
            if( (lm<=pm && pm<=rm ))
            printf("1");
            else
            printf("0");
        }
        printf("\n");
    }
  return 0;
}