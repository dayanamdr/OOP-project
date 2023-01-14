#include "Service.h"
#include <assert.h>
#include <algorithm>
#include <iostream>

using namespace std;

Service::Service() {}

Service::Service(MemoryRepository* r, WatchList* wl) {
	// constructor with repository
	this->my_repo = r;
	this->my_wl = wl;
}

Service::~Service() {}

void Service::addService(string title, string genre, int release_year, int likes, string trailer) {
	Movie movie_to_add(title, genre, release_year, likes, trailer);
	this->my_repo->addRepo(movie_to_add);
}

void Service::deleteService(string movie_title) {
	vector<Movie> all_movies = getAllMovies();
	for (int i = 0; i < all_movies.size(); ++i) {
		if (movie_title == all_movies[i].getTitle()) {
			this->my_repo->removeRepo(i);
		}
	}
	
}

void Service::updateService(string title, string trailer) {
	// check whether the position is valid. If not, return 0.
	int pos = 0;
	vector<Movie> movies = this->getAllMovies();
	for (int i = 0; i < movies.size(); i++) {
		if (movies[i].getTitle() == title) {
			pos = i;
		}
	}
	Movie updated_movie(title, movies[pos].getGenre(), movies[pos].getReleaseYear(), movies[pos].getLikes(), trailer);
	this->my_repo->updateRepo(updated_movie, pos);
}

vector<Movie> Service::getAllMovies() const {
	return this->my_repo->getAllMoviesRepo();
}

int getMovieIndex(string title, string genre, vector<Movie> movies) {
	int index = 0;
	for (auto current_movie : movies) {
		if (current_movie.getTitle() == title && current_movie.getGenre() == genre) {
			return index;
		}
		++index;
	}
	return -1;
}

int Service::addMovieToFavorite(string title, string genre) {
	int movie_index = getMovieIndex(title, genre, my_repo->getAllMoviesRepo());
	if (movie_index == -1) {
		return 0;
	}
	int to_return = my_wl->addMovieToWL(my_repo->getAllMoviesRepo()[movie_index]);
	my_wl->saveToFile(this->my_wl->getWatchList());
	return to_return;
}

int Service::deleteMovieFromFavorite(string title, string genre) {
	int to_return = my_wl->deleteMovieFromWL(title, genre);
	my_wl->saveToFile(this->my_wl->getWatchList());
	return to_return;
}

Movie Service::likeMovieService(string title, string genre) {
	return my_repo->likeMovie(title, genre);
}

vector<Movie>& Service::getFavoriteMovies() {
	return my_wl->getWatchList();
}

vector<Movie> Service::getMoviesByGenre(string genre) {
	vector<Movie> filtered_movies;
	vector<Movie> all_movies = getAllMovies();
	for (auto current_movie : all_movies) {
		if (current_movie.getGenre() == genre) {
			filtered_movies.push_back(current_movie);
		}
	}
	if (filtered_movies.size() == 0) {
		return all_movies;
	}
	return filtered_movies;
}

void Service::sortMoviesByTitle(vector<Movie>& m) {
	ComparatorAscendingByTitle<string> c;
	for (int i = 0; i < m.size() - 1; ++i) {
		for (int j = i + 1; j < m.size(); ++j) {
			if (c.compare(m[i].getTitle(), m[j].getTitle())) {
				continue;
			}
			swap(m[i], m[j]);
		}
	}
}

void Service::sortMoviesByReleaseYear(vector<Movie>& m) {
	ComparatorDescendingByReleaseYear<int> c;
	for (int i = 0; i < m.size() - 1; ++i) {
		for (int j = i + 1; j < m.size(); ++j) {
			if (c.compare(m[i].getReleaseYear(), m[j].getReleaseYear())) {
				continue;
			}
			swap(m[i], m[j]);
		}
	}
}

void Service::testSortingFunctions() {
	vector<Movie> m;
	m.push_back(Movie("bbc", "romance", 2022, 0, "www.google.com"));
	m.push_back(Movie("acb", "romance", 2003, 0, "www.google.com"));
	m.push_back(Movie("abc", "romance", 1200, 0, "www.google.com"));
	sortMoviesByTitle(m);
	assert(m[0].getTitle() == "abc");
	assert(m[1].getTitle() == "acb");
	assert(m[2].getTitle() == "bbc");

	sortMoviesByReleaseYear(m);
	assert(m[0].getReleaseYear() == 2022);
	assert(m[1].getReleaseYear() == 2003);
	assert(m[2].getReleaseYear() == 1200);
}

vector<Movie> Service::get_movies(string filter) {
	std::vector<Movie> all_movies = getAllMovies();
	int count = (int)std::count_if(all_movies.begin(), all_movies.end(), [=](Movie m) { return m.toString().find(filter) != std::string::npos; });
	std::vector<Movie> movies(count);
	std::copy_if(all_movies.begin(), all_movies.end(), movies.begin(), [=](Movie m) { return m.toString().find(filter) != std::string::npos; });
	std::sort(movies.begin(), movies.end(), [](Movie m1, Movie m2) { return m1.getLikes() < m2.getLikes(); });
	return movies;
}