#ifndef _movies_h_
#define _movies_h_

#include<vector>
#include<string>
#include "movie.hpp"

class movies
{
	private:
	std::vector<movie> Movies;
	public:
	movies();
	~movies();

	bool add_movie(std::string name , std::string rating, int watched);

	bool increment_watched(std::string name);

	void display() const;
};

#endif // _movies_h_
