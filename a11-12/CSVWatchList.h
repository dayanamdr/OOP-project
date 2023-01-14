#pragma once

#include "WatchList.h"

class CSVWatchList : public WatchList {
public:
	CSVWatchList();
	~CSVWatchList();

	void saveToFile(vector<Movie> watch_list_vector);
	void openInApp();
};