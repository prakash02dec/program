#include <iostream>
#include <vector>

int main (){
    int t{};
    std::cin>>t;
    while(t--){
        int n{};
        std::cin >> n;
        int a[n] , b[n];
        bool possible{true};
        for(int i{} ; i < n ; i++){
            std::cin >> b[i];
            if (i > 0 && b[i - 1] % b[i] != 0){
            possible = false;
        }
        }
       if(possible){
        for(int i {} ; i< n ; i++)
            std::cout << b[i] << " ";
            
        std::cout << std::endl;
       }
       else
       std::cout << "-1" << std::endl;


    }
    return 0;
}


