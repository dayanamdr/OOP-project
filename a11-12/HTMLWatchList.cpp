#include "HTMLWatchList.h"
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <shellapi.h>

HTMLWatchList::HTMLWatchList() {}

HTMLWatchList::~HTMLWatchList() {}


void HTMLWatchList::saveToFile(vector<Movie> watch_list_vector) {
	std::cout << "SAvING to html file\n";
	std::ofstream f("watchlist.html");

	f << "<!DOCTYPE html>" << "\n";
	f << "<html>" << "\n";

	f << "<head>" << "\n";
	f << "<title>Movie Playlist</title>" << "\n";
	f << "</head>" << "\n";

	f << "<body>" << "\n";

	f << "<table border=\"1\">" << "\n";

	f << "<tr>" << "\n";
	f << "<td>Title</td>" << "\n";
	f << "<td>Genre</td>" << "\n";
	f << "<td>Year</td>" << "\n";
	f << "<td>Likes</td>" << "\n";
	f << "<td>Trailer</td>" << "\n";
	f << "</tr>" << "\n";

	for (auto i : watch_list_vector)
	{
		f << "<tr>" << "\n";

		f << "<td>" << i.getTitle() << "</td>" << "\n";
		f << "<td>" << i.getGenre() << "</td>" << "\n";
		f << "<td>" << i.getReleaseYear() << "</td>" << "\n";
		f << "<td>" << i.getLikes() << "</td>" << "\n";
		f << "<td><a href =" << i.getTrailer() << ">Link</a></td>";

		f << "</tr>" << "\n";
	}

	f << "</table>" << "\n";

	f << "</body>" << "\n";

	f << "</html>" << "\n";
	f.close();
}

void HTMLWatchList::openInApp() {
	ShellExecuteA(NULL, NULL, "chrome.exe", "C:/Users/dayana/Documents/Documents/GitHub/a11-12-DayanaRalucaMardari/a11-12/a11-12/watchlist.html", NULL, SW_SHOWMAXIMIZED);
	system("PAUSE");
}

