#ifndef _movie_h_
#define _movie_h_

#include<string>

class movie
{
private: 
	std::string name;
	std::string rating;
	int watched;
public:
	movie(std::string name , std::string rating , int watched);	
	movie(const movie &source);
	
	void set_name(std::string name_val);
	std::string get_name() const;
	
	void set_rating(std::string rating);
	std::string get_rating() const;
	 
	void set_watch(int watched);
	int get_watch() const;
	
	void increment_watched();
	
	void display() const;
	~movie();
};

#endif // _movie_h_
