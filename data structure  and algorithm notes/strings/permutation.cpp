#include <iostream>
template<typename T>
void swap (T &a , T &b ){
    T temp {} ;
    temp = a ;
    a =  b; 
    b = temp ;
}


void perm(char s[] , int k ){
    static int a[10] {};
    static char res[10] ;
    int i {} ;

    if(s[k] == '\0'){
        res[k] = '\0' ;
        std:: cout << res << std::endl; 
    }else{
        for ( i = 0 ; s[i] != '\0' ; i ++){
            if(a[i] == 0 ) {
                res[k] == s[i];
                a[i] =1 ;
                perm(s , k+1) ;
                a[i] = 0 ; 
            }
        }
    }

}

void perm2(char s[] , int low  , int high  ){
    if(low == high){
        std::cout << s << std::endl; 
    }else{
        for(int  i {low} ; i <= high ; i ++){
            swap(s[low] , s[i]);
            perm2(s , low , high);
            swap(s[low] , s[i]);
        } 
    }

}

int main (){
    
    
    
    
    
    return 0 ;

}