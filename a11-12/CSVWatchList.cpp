#include "CSVWatchList.h"
#include <fstream>
#include <iostream>

CSVWatchList::CSVWatchList() {}
CSVWatchList::~CSVWatchList() {}

void CSVWatchList::saveToFile(vector<Movie> watch_list_vector) {
	std::ofstream f("watchlist.csv");
	for (auto i : watch_list_vector) {
		f << i << "\n";
	}
	f.close();
}

void CSVWatchList::openInApp() {
	system("notepad.exe watchlist.csv");
}