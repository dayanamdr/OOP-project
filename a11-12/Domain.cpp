#include "Domain.h"
#include <windows.h>
#include <ShellApi.h>
#include <iostream>

Movie::Movie() {
	this->title = "default_t";
	this->genre = "default_g";
	this->release_year = 0;
	this->likes = 0;
	this->trailer = "default_tr";
}

Movie::Movie(const string& title, const string& genre, const int& release_year, const int& likes, const string& trailer) {
	this->title = title;
	this->genre = genre;
	this->release_year = release_year;
	this->likes = likes;
	this->trailer = trailer;
}

const string& Movie::getTitle() const {
	return this->title;
}

const string& Movie::getGenre() const {
	return this->genre;
}

const int& Movie::getReleaseYear() const {
	return this->release_year;
}

const int& Movie::getLikes() const {
	return this->likes;
}

const string& Movie::getTrailer() const {
	return this->trailer;
}

void Movie::setTitle(string new_title) {
	this->title = new_title;
}

void Movie::setGenre(string new_genre) {
	this->genre = new_genre;
}

void Movie::setReleaseYear(int new_release_year) {
	this->release_year = new_release_year;
}

void Movie::setLikes(int new_likes) {
	this->likes = new_likes;
}

void Movie::setTrailer(string new_trailer) {
	this->trailer = new_trailer;
}

void Movie::play() const {
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}

std::ostream& operator<<(std::ostream& os, const Movie& movie)
{
	os << movie.getTitle() << "," << movie.getGenre() << "," << movie.getReleaseYear() << "," << movie.getLikes() << "," << movie.getTrailer();
	return os;
}

string Movie::toString() const {
	return getTitle() + " - " + getGenre() + " - " + getTrailer() + " - " + std::to_string(getLikes()) + " - " + std::to_string(getReleaseYear()) + '\n';
}