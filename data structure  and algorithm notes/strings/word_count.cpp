#include <iostream>

int main(){
    char s[] = "how are   u";
    int  word {1};
    for(int i {} ; s[i] != '\0' ; i++){
        if( s[i] == ' ' && s[i-1] != ' ') word++;
    }
    std::cout << word ;
    return 0 ;
}