#include "movie.hpp"
#include<iostream>

movie::movie(std::string name , std::string rating , int watched)
:name(name), rating(rating) , watched(watched){
	
}


movie::movie(const movie &source)
: movie{source.name, source.rating, source.watched}{
	
}
void movie::set_name(std::string name){
	this->name = name;
}

std::string movie::get_name() const{
	return name;
}

void movie::set_rating(std::string rating){
	this->rating = rating;
}

std::string movie::get_rating() const{
		return rating ;
	}
	
void movie::set_watch(int watched){
	this->watched= watched;	
}

int movie::get_watch() const{
	return watched;
}
	
void movie::increment_watched(){
	watched++;
}
	
	void movie::display() const{
		std::cout<<name<<" ,"<<rating<<" ,"<<watched<<std::endl;
	}


movie::~movie()
{
}

	

	
	