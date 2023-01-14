#pragma once

#ifndef DOMAIN_H
#define DOMAIN_H

#endif

#include <string>
using namespace std;

class Movie {
private:
	string title;
	string genre;
	int release_year;
	int likes;
	string trailer;

public:
	Movie();
	Movie(const string& title, const string& genre,const int& release_year, const int& likes, const string& trailer);

	// return title
	const string& getTitle() const;

	// return genre
	const string& getGenre() const;

	// return relase year
	const int& getReleaseYear() const;

	// return likes
	const int& getLikes() const;

	// return trailer
	const string& getTrailer() const;

	// set title
	void setTitle(string new_title);

	// set genre
	void setGenre(string new_genre);

	// set release year
	void setReleaseYear(int new_release_year);

	// set trailer
	void setTrailer(string new_trailer);

	// set likes
	void setLikes(int new_likes);

	void play() const;

	friend std::ostream& operator<<(std::ostream& os, const Movie& movie);

	string toString() const;
};
