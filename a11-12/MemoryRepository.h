#pragma once

#include "Repository.h"
#include "Validator.h"

class MemoryRepository : public Repository {
protected:
	vector<Movie> movies;
	Validator validator_class;
public:
	MemoryRepository();
	~MemoryRepository();

	vector<Movie> getAllMoviesRepo() const;
	int getRepoSize() const;

	void addRepo(Movie m);
	void removeRepo(int pos);
	void updateRepo(Movie m, int pos);
	Movie likeMovie(string title, string genre);
	virtual void saveToFile();

	/*int operator-(Movie movie_to_remove);
	int operator+(Movie movie_to_add);*/
};
