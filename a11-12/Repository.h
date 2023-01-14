#pragma once

#include "Domain.h"
#include <vector>

class Repository {
public:
	Repository();
	~Repository();

	virtual vector<Movie> getAllMoviesRepo() const = 0;
	virtual int getRepoSize() const = 0;

	virtual void addRepo(Movie m) = 0;
	virtual void removeRepo(int pos) = 0;
	virtual void updateRepo(Movie m, int pos) = 0;
	virtual Movie likeMovie(string title, string genre) = 0;
};
