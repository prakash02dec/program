#include<iostream>
#include "movies.hpp"

void increment_watched(movies &movies, std::string name);

void add_movie(movies &movies , std::string name, std::string rating , int watched );

void increment_watched(movies &movies, std::string name){
	if(movies.increment_watched(name)){
		std::cout<<name <<"watch incremented"<<std::endl;
	}else{
		std::cout<<"not found"<<std::endl;
	}
}

void add_movies(movies &movies, std::string name , std::string rating , int watched){
	if(movies.add_movie(name , rating , watched )){
		std::cout<< name << "added"<<std::endl;
	}else{
		std::cout<<name <<"already exists"<<std::endl;
	}
}

int main (){
	movies my_movies;

	my_movies.display();

	add_movies(my_movies, "avengers" , "PG-13", 2);
	add_movies(my_movies, "mission impossible" , "PG-13", 2);
	add_movies(my_movies, "docter strange" , "PG-13", 2);

	my_movies.display();
	add_movies(my_movies, "tomorrow lands" , "PG-13", 2);
	add_movies(my_movies, "martian" , "PG-13", 2);

	my_movies.display();
	increment_watched(my_movies, "martian");
	increment_watched(my_movies,"docter strange");

	my_movies.display();

	increment_watched(my_movies,"sdfsad");

	std::cin.get(); 
	return 0;

}