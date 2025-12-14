// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>


void ruler(){
    std::cout<< std::endl << "1234567890123456789012345678901234567890123456789012345678901234567890"<<std::endl;
    return ;
}


struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

int main()
{
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };

    ruler();
    const int  field_width {20} ;
    const int  field_width1 {20} ;
    const int  field_width2 {15} ;
    const int  field_width3 {12} ;

    int len =70-tours.title.length();
    // std::cout<<std::setw(len/2)<<std::setfill('=');
    // Unformatted display so you can see how to access the vector elements
    std::cout  << std::setw(len/2 +tours.title.length())<< std::setfill('=') << tours.title<< std::setw(len/2 +1) <<"" << std::endl ;
    
    std::cout << std::setfill(' ');

    std::cout << std::left << std::setw(field_width) << "Country" << std::setw(field_width1) << "City" 
    << std::setw(field_width2) << "Population" << std::setw(field_width3) << std::right << "Cost" << std::endl;
    
    std::cout << std::setfill('=') << std::setw(70) << "" << std::setfill(' ')  << std::endl;
    
    for(auto country : tours.countries) {   // loop through the countries
        std::cout << std::setw(field_width) << std::left<< country.name << std::endl;
        for(auto city : country.cities) {       // loop through the cities for each country
            std::cout << std::setw(field_width) << "" << std::left << std::setw(field_width1) << city.name 
                          << std::setw(field_width2) << city.population 
                          << std::setw(field_width3) << std::right << city.cost 
                          << std::endl;
        }
    }

    std::cout << std::endl << std::endl;
    return 0;
}