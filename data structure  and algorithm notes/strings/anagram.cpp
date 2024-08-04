#include <iostream >

// for analgram strings length must be same and both have same set of character

int main (){
    char a[] = "decimal";
    char b[] = "medical";
    int h[26] {};
    for(int i {} ; a[i] != '\0' ; i++ ) {
        h[a[i]-97]++;
    }
    int i {};
    for( i=0 ; b[i] != '\0' ; i++){
        h[b[i]-97]--;
        if(h[b[i]-97]<0){
            std::cout << "it is not analgram" ;
            break; 
        }
    }
    if(b[i] == '\0'){
        std::cout << "it is analgram";
    }

    return 0 ;

}