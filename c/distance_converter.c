#include<stdio.h>
int main()
{
    float km , m , cm , ft , inch ;
    printf(" \n enter distance between two cites in  KM \n");
    scanf("%f",&km);
    m= km * 1000 ;
    cm= m * 100;
    ft= m/3.28;
    inch= ft/12;
    printf(" \n distance in km =%d",km);
    printf(" \n distance in m =%d",m);
    printf(" \n distance in cm =%d", cm);
    printf(" \n distance in ft =%d", ft );
    printf(" \n distance in inch=%d\n ",inch);
    return 0;
}