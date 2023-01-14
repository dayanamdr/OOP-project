#include "WatchList.h"

WatchList::WatchList() : currentIndex(0) {
	// constructor
}

int find_movie_watch_list(string title, string genre, vector<Movie> ms) {
	int index = 0;
	for (auto current_movie : ms) {
		if (title == current_movie.getTitle() && genre == current_movie.getGenre()) {
			return index;
		}
		++index;
	}
	return -1;
}

int WatchList::addMovieToWL(Movie m) {
	if (find_movie_watch_list(m.getTitle(), m.getGenre(), this->watchList) != -1) {
		return 0;
	}
	watchList.push_back(m);
	return 1;
}

int WatchList::deleteMovieFromWL(string title, string genre) {
	int movie_number = find_movie_watch_list(title, genre, this->watchList);
	if (movie_number == -1) {
		return 0;
	}
	watchList.erase(watchList.begin() + movie_number);
	return 1;
}

vector<Movie>& WatchList::getWatchList() {
	return watchList;
}

int WatchList::watchListSize() {
	return (int)watchList.size();
}

WatchList::~WatchList() {}