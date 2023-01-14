#include "MemoryRepository.h"
#include "RepositoryException.h"
//#include <vector>
#include <iostream>

MemoryRepository::MemoryRepository() {
	this->validator_class = Validator();
}

MemoryRepository::~MemoryRepository() {
	cout << " MEMORY DESTRUCTOR\n";
}

bool movies_are_equal(Movie m1, Movie m2) {
	// helper function for checking the equality of two movies
	return m1.getTitle() == m2.getTitle() && m1.getGenre() == m2.getGenre();
}

int find_movie(Movie m, int repoSize, vector<Movie> ms) {
	int position = 0;
	for (auto current_movie : ms) {
		if (movies_are_equal(m, current_movie)) {
			return position;
		}
		++position;
	}
	return -1;
}

void MemoryRepository::addRepo(Movie m) {
	int movie_already_added = find_movie(m, (int)this->movies.size(), this->movies);
	validator_class.validate_movie(m);
	if (movie_already_added != -1) {
		throw DuplicateMovieException();
	}
	this->movies.push_back(m);
	this->saveToFile();
}

void MemoryRepository::removeRepo(int position) {
	if (position < 0 || position >= this->movies.size()) {
		throw RepositoryException("Enter a valid position in order to remove a movie!\n");
	}
	this->movies.erase(this->movies.begin() + position);
	this->saveToFile();
}

//int MemoryRepository::operator-(Movie movie_to_remove) {
//	this->movies.erase(remove(this->movies.begin(), this->movies.end(), movie_to_remove), this->movies.end());
//	return 1;
//}
//int MemoryRepository::operator+(Movie movie_to_add) {
//	return this->addRepo(movie_to_add);
//}


void MemoryRepository::updateRepo(Movie m, int pos) {
	if (pos < 0 || pos >= this->movies.size()) {
		throw RepositoryException("Enter a valid position in order to update a movie!\n");
	}
	validator_class.validate_movie(m);
	this->movies[pos] = m;
	this->saveToFile();
}

Movie MemoryRepository::likeMovie(string title, string genre) {
	Movie m(title, genre, 0, 0, "www.google.com");
	int movie_number = find_movie(m, (int)this->movies.size(), this->movies);
	// no validation for movie existance
	int current_likes = this->movies[movie_number].getLikes();
	this->movies[movie_number].setLikes(current_likes + 1);
	return this->movies[movie_number];
}

int MemoryRepository::getRepoSize() const {
	return (int)this->movies.size();
}

vector<Movie> MemoryRepository::getAllMoviesRepo() const {
	return this->movies;
}

void MemoryRepository::saveToFile() {}