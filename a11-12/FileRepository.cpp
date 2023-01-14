//#include "Domain.h"
#include "RepositoryException.h"
#include "FileRepository.h"
#include "Utils.h"

#include <fstream>
#include <string>
#include <iostream>

FileRepository::FileRepository() {}

FileRepository::FileRepository(const string& filename) : MemoryRepository() {
	this->filename = filename;
	loadFromFile();
}

FileRepository::~FileRepository() { cout << "FILE DESTR\n"; }

void FileRepository::loadFromFile() {
	ifstream f(this->filename);

	if (!f.is_open()) {
		throw FileException("The file could not be opened!\n");
	}
	string temp;
	string* args;

	while (!f.eof()) {
		getline(f, temp);
		if (f.eof() || temp == "") {
			f.close();
			break;
		}
		args = splitString(temp);
		addRepo(Movie(args[0], args[1], stoi(args[2]), stoi(args[3]), args[4]));
	}
	f.close();
}

void FileRepository::saveToFile() {
	std::ofstream f(this->filename);
	for (auto i : this->movies)
		f << i << "\n";
	f.close();
}