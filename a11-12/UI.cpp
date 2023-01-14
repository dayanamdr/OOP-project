#include "UI.h"
#include <iostream>
#include <vector>
#include "RepositoryException.h"

using namespace std;

UI::UI(Service& my_service) : my_service{ my_service } {
	// constructor	
}

UI::~UI() {}

void print_menu_mode() {
	cout << "Choose mode:\n";
	cout << "1 - administrator\n";
	cout << "2 - user\n";
}

void print_administrator_menu() {
	cout << "Administrator menu:\n";
	cout << "1 - add movie\n";
	cout << "2 - delete movie\n";
	cout << "3 - update movie\n";
	cout << "4 - see movie list\n";
	cout << "0 - exit\n";
}

void print_user_menu() {
	cout << "User menu:\n";
	cout << "1 - get movies by GENRE\n";
	cout << "2 - delete movie from Watch List\n";
	cout << "3 - see Watch List\n";
	cout << "0 - exit\n";
}

void addMovieUI(Service& my_service) {
	string title, genre, trailer;
	int release_year, likes = 0;
	cout << "Title: ";
	cin >> title;
	cout << "Gengre: ";
	cin >> genre;
	cout << "Release year: ";
	cin >> release_year;
	cout << "Trailer: ";
	cin >> trailer;

	my_service.addService(title, genre, release_year, likes, trailer);
}

void deleteMovieUI(Service& my_service) {
	string movie_title;
	cout << "Movie title: ";
	cin >> movie_title;

	my_service.deleteService(movie_title);
}

void updateMovieUI(Service& my_service) {
	string title, genre, trailer;
	int release_year, likes = 0, movie_number;
	cout << "Number of movie: ";
	cin >> movie_number;
	cout << "Title: ";
	cin >> title;
	cout << "Gengre: ";
	cin >> genre;
	cout << "Release year: ";
	cin >> release_year;
	cout << "Trailer: ";
	cin >> trailer;

	my_service.updateService(title, trailer);
}

void addMovieToWL(Service& my_service) {
	string title, genre;
	cout << "Title: ";
	cin >> title;
	cout << "Genre: ";
	cin >> genre;
	int result = my_service.addMovieToFavorite(title, genre);
	if (result) {
		cout << "Movie added to favorites successfully!\n";
	}
	else {
		cout << "Movie addition to favorites failed!\n";
	}
}

void deleteMovieFromWL(Service& my_service) {
	string title, genre;
	cout << "Title: ";
	cin >> title;
	cout << "Genre: ";
	cin >> genre;
	int result = my_service.deleteMovieFromFavorite(title, genre);
	if (result) {
		cout << "Movie deleted from favorites successfully!\n";
		cout << "Did you like the movie?\n";
		cout << "1 - YES\n";
		cout << "2 - NO\n";
		int command;
		cin >> command;
		if (command == 1) {
			Movie m = my_service.likeMovieService(title, genre);
			cout << "The movie has got " << m.getLikes() << " likes! :)\n";
;		}
	}
	else {
		cout << "Movie deletion from favorites failed!\n";
	}
}

void print_movie_info(Movie m) {
	cout <<" Title: " << m.getTitle() << ", Genre: " << m.getGenre() << ", Release year: " << m.getReleaseYear() << ", Likes: " << m.getLikes() << "\n";
}

void print_movie_commands() {
	cout << "1 - next\n";
	cout << "2 - add to Watch List\n";
	cout << "3 - exit\n";
}

void print_movies_by_genre(Service& my_service) {
	string genre;
	int index = 0;
	cout << "Genre: ";
	cin >> genre;

	vector<Movie> movies = my_service.getMoviesByGenre(genre);
	while (1) {
		int command;
		print_movie_info(movies[index]);
		cout << "Command: ";
		print_movie_commands();
		// play trailer
		movies[index].play();
		cin >> command;
		if (command == 3) {
			break;
		}
		if (command == 2) {
			my_service.addMovieToFavorite(movies[index].getTitle(), movies[index].getGenre());
		}
		else if (command != 1) {
			cout << "ENTER A VALID COMMAND!\n";
			continue;
		}
		// go to the next movie
		index++;
		index %= (int)movies.size();
	}
}

// this needs to be edited!
void print_favorite_movies(Service& my_service, WatchList& my_wl) {
	vector<Movie> favorites = my_service.getFavoriteMovies();
	cout << "nr of fav movies = " << favorites.size() << "\n";
	for (int i = 0; i < favorites.size(); ++i) {
		cout << "#" << i + 1 << " ";
		print_movie_info(favorites[i]);
		cout << "\n";
	}
	my_wl.openInApp();
}

void print_movies(Service& my_service) {
	vector<Movie> my_movies = my_service.getAllMovies();
	for (int i = 0; i < my_movies.size(); ++i) {
		cout << "#" << i + 1 << " ";
		print_movie_info(my_movies[i]);
	}
}

void UI::start_console(Service& my_service, WatchList& my_wl) {
	//my_service.generateMovies();
	print_menu_mode();
	cout << "Mode: ";
	int mode;
	cin >> mode;
	if (mode == 1) {
		print_administrator_menu();
		while (1) {
			int command;
			cout << "Command: ";
			cin >> command;
			if (command == 0) {
				break;
			}
			if (command == 1) {
				try {
					addMovieUI(my_service);
				}
				catch (MovieException& e) {
					for (auto err : e.getErrors())
						cout << err;
				}
				catch (RepositoryException& e) {
					cout << e.what() << "\n";
				}
				catch (FileException& e) {
					cout << e.what() << "\n";
				}
			}
			else if (command == 2) {
				try {
					deleteMovieUI(my_service);
				}
				catch (MovieException& e) {
					for (auto err : e.getErrors())
						cout << err;
				}
				catch (RepositoryException& e) {
					cout << e.what() << "\n";
				}
				catch (FileException& e) {
					cout << e.what() << "\n";
				}
			}
			else if (command == 3) {
				try {
					updateMovieUI(my_service);
				}
				catch (MovieException& e) {
					for (auto err : e.getErrors())
						cout << err;
				}
				catch (RepositoryException& e) {
					cout << e.what() << "\n";
				}
				catch (FileException& e) {
					cout << e.what() << "\n";
				}
			}
			else if (command == 4) {
				print_movies(my_service);
			}
			else {
				cout << "ENTER A VALID COMMAND!\n";
			}
		}
	}
	else {
		print_user_menu();
		while (1) {
			int command;
			cout << "Command: ";
			cin >> command;
			if (command == 1) {
				print_movies_by_genre(my_service);
			}
			else if (command == 2) {
				deleteMovieFromWL(my_service);
			}
			else if (command == 3) {
				print_favorite_movies(my_service, my_wl);
			}
			else if (command == 0) {
				break;
			}
			else {
				cout << "ENTER A VALID COMMAND!\n";
			}
		}
	}
}

