#pragma once
#include "Domain.h"
#include <exception>
#include <vector>

class Validator {
public:
	Validator();
	~Validator();

	void validate_movie(const Movie& movie);
};

class MovieException {
private:
	vector<std::string> errors;
public:
	MovieException(vector<std::string> _errors);
	vector<std::string> getErrors() const;
};