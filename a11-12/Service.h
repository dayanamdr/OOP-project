#pragma once

#ifndef SERVICE_H
#define SERVICE_H

#endif

#include "Comparator.h"
#include "MemoryRepository.h"
#include "FileRepository.h"
#include "WatchList.h"
#include "CSVWatchList.h"
#include "HTMLWatchList.h"
#include <vector>

class Service {
private:
	MemoryRepository* my_repo;
	WatchList* my_wl;
public:
	Service();
	// constructor with repository
	Service(MemoryRepository* r, WatchList* wl);

	void addService(string title, string genre, int release_year, int likes, string trailer);

	void deleteService(string movie_title);

	void updateService(string title, string trailer);

	vector<Movie> getAllMovies() const;

	int addMovieToFavorite(string title, string genre);

	int deleteMovieFromFavorite(string title, string genre);

	Movie likeMovieService(string title, string genre);

	vector<Movie>& getFavoriteMovies();

	vector<Movie> getMoviesByGenre(string genre);

	void sortMoviesByTitle(vector<Movie>& m);

	void sortMoviesByReleaseYear(vector<Movie>& m);

	void testSortingFunctions();

	vector<Movie> get_movies(string filter);

	~Service();
};
