#include<iostream>
using namespace std;
void duplicate_bits_check(char a[]){
    int i=0;
    long long int h=0,x=0;
    while(a[i]!='\0'){
        x=0;
        int z=a[i];
        x = (1 << (z - 65));
        if((x & h) == 1)
        {
            cout<<a[i]<<" ";
        }
        else{
            h =( h | x);
        }
        i++;
    }
}

int main(){
    char ch[]="ABCABC";
    duplicate_bits_check(ch);
}