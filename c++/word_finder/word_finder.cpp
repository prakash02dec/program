#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

int main(){

    std::ifstream file {"romeoandjuliet.txt"} ;
    
    if(!file){
        std::cerr << "due to some error , file doesnt open " ;
    }

    std::string key {};

    std::cout << "Enter the word which you want to find  : " << std::endl;  
    std::cin >> key ;


    std::string word {};
    int total_search {};
    int total_found {};

    while (file >> word ){

        total_search++;
        if(word.find(key) != std::string::npos)
        total_found++;
    }
    std::cout << "Total Searched : " << total_search << 
    std::endl << "Total words found : " << total_found ;

    file.close();
    std::cout<< std::endl ;
    return 0;
}