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
    int len =70-tours.title.length();
    // std::cout<<std::setw(len/2)<<std::setfill('=');
    // Unformatted display so you can see how to access the vector elements
    std::cout  << std::setw(len/2 +tours.title.length())<< std::setfill('=') << tours.title<< std::setw(len/2) <<"" << std::endl ;
    std::cout << std::setfill(' ');
    for(auto country : tours.countries) {   // loop through the countries
        std::cout << country.name << std::endl;
        for(auto city : country.cities) {       // loop through the cities for each country
            std::cout << std::setw(10) << "" << std::left << std::setw(20) << city.name 
                          << std::setw(25) << city.population 
                          << std::setw(25) << city.cost 
                          << std::endl;
        }
    }

    std::cout << std::endl << std::endl;
    return 0;
}