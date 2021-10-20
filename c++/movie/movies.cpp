#include "movies.hpp"
#include<iostream>
movies::movies()
{
}

movies::~movies()
{
}

bool movies::add_movie(std::string name , std::string rating, int watched){
    for(const auto &movie: Movies){
        if(movie.get_name()== name){
            return false;
        }
    }
    movie temp {name , rating , watched};
    
    Movies.push_back(temp);
    return true;
}

bool movies::increment_watched(std::string name){
    for( auto &movie :Movies){
        if(movie.get_name()==name){
        movie.increment_watched();
        return true;
    }
    }
    return false;

}

void movies::display() const{
    if(Movies.size()==0){
        std::cout<<"sorry , no movies to display \n"<< std::endl;
    }else{
        std::cout<<"\n============================================================" <<std::endl;
        for(const auto &movie:Movies)
         movie.display();

        std::cout<<"\n============================================================="<<std::endl;
    }

}
