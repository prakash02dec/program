#include <iostream>
#include <iomanip>
#include <fstream>

int main (){

    std::string line ;
    std::ifstream in_file {"romeoandjuliet.txt"} ;
    std::ofstream out_file  {"romeoandjuliet_edited.txt"} ;

    int i {1} ;
    while(std::getline(in_file ,line)){
        if(line.length() != 1)
        out_file << std::setw(8) << std::left << i++ ;
        out_file << line; 
    }

    in_file.close();
    out_file.close();

    return 0;


}