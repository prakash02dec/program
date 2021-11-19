#include <iostream>
int main (){
    int t;
    std::cin>>t;
    while(t--){
        int x , y , p , q;
        std::cin >> x >> y >> p >> q ;
        int cell1 {(x + y)%2} , cell2{(p + q)%2};
        if(cell1 == cell2 && (x!=p || y!=q) ){
            std::cout << "2" << std::endl;
        }else if (cell1 != cell2 && (x!=p || y!=q )){
            std::cout << "1" << std::endl;
        }else {
            std::cout << "0" << std::endl;
        }

    }
    return 0;
}

