#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


int main() {

    std::ifstream responses {"responses.txt"};
    std::string answer_key;

    responses >> answer_key;
    const int ruler {30} ;
    const int field_name {15} ;
    const int field_marks {15} ;
    double average {} ;
    int total_student ;

    std::string name , response ;

    std::cout << std::setfill('-') << std::setw(ruler) << "" << std::endl <<  std::setfill(' ');
    std::cout << std::left << std::setw(field_name) << "Name" << std::setw( field_marks) << "Marks" << std::endl;
    std::cout << std::setfill('-') << std::setw(ruler) << "" << std::endl << std::setfill(' ');

    while (responses >> name >> response ){
        std::cout << std::setw(field_name) << name;
        int marks {};
        
        for(size_t i {} ; i < answer_key.length() ; i++){
            if(answer_key.at(i) == response.at(i)) marks++;
        }
        average += marks;

        std::cout << std::setw(field_marks) << marks << std::endl;
        total_student++;

    }

    average /= total_student ;

    std::cout << std::setfill('-') << std::setw(ruler) << "" << std::endl << std::setfill(' ');
    std::cout << std::left << std::setw(field_name) << "Average" << std::setw( field_marks) << average << std::endl;

    responses.close();
    std::cout << std::endl;
    return 0;
}

