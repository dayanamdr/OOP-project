#pragma once
#include "WatchList.h"

class HTMLWatchList : public WatchList {
public:
	HTMLWatchList();
	~HTMLWatchList();

	void saveToFile(vector<Movie> watch_list_vector);
	void openInApp();
};
