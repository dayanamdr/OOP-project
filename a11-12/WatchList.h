#pragma once
#include "Domain.h"
#include <vector>

class WatchList {
protected:
	vector<Movie> watchList;
	int currentIndex;
public:
	WatchList();
	int addMovieToWL(Movie m);
	int deleteMovieFromWL(string title, string genre);
	vector<Movie>& getWatchList();
	int getCurrentIndex();
	void next();
	int watchListSize();
	void playTrailer();
	~WatchList();

	virtual void saveToFile(vector<Movie> watch_list_vector) = 0;
	virtual void openInApp() = 0;
};