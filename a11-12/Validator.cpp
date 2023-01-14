#include "Validator.h"

Validator::Validator() {}

Validator::~Validator() {}

void Validator::validate_movie(const Movie& movie) {
	vector<std::string> errors;
	if (movie.getTitle().size() < 1) {
		errors.push_back("The title name cannot be less than 1 character!\n");
	}
	// search for "www" or "http" at the beggining of the source string
	int posWWW = movie.getTrailer().find("www");
	int posHTTP = movie.getTrailer().find("http");
	if (posWWW != 0 && posHTTP != 0) {
		errors.push_back("Enter a correct url!\n");
	}
	
	if (errors.size() > 0) {
		throw MovieException(errors);
	}
}

MovieException::MovieException(vector<std::string> _errors) {
	this->errors = _errors;
}

vector<std::string> MovieException::getErrors() const {
	return this->errors;
}