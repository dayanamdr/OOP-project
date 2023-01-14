#include "Tests.h"
#include <assert.h>

// uncomment
// 
//void tests::testdomain() {
//	movie m;
//	assert(m.gettitle() == "default_t");
//	m = movie("title", "genre", 1, 0, "www.google.com");
//	assert(m.gettitle() == "title");
//	assert(m.getgenre() == "genre");
//	assert(m.getreleaseyear() == 1);
//	assert(m.getlikes() == 0);
//	assert(m.getTrailer() == "www.google.com");
//
//	m.setTitle("new title");
//	m.setGenre("new genre");
//	m.setReleaseYear(11);
//	m.setLikes(100);
//	m.setTrailer("www.coding.com");
//
//	assert(m.getTitle() == "new title");
//	assert(m.getGenre() == "new genre");
//	assert(m.getReleaseYear() == 11);
//	assert(m.getLikes() == 100);
//	assert(m.getTrailer() == "www.coding.com");
//
//	m.play();
//}

//void Tests::testDynamicVector() {
	//vector<int> v;
	//assert(v.size() == 0);
	//for (int i = 1; i <= 3; ++i) {
	//	v.push_back(i);
	//}
	//assert(v.size() == 3);
	//assert(v[0] == 1);
	//assert(v[1] == 2);
	//assert(v[2] == 3);
	//
	//v[1] = 101;
	//assert(v[1] == 101);
	//v.erase(v.begin() + 1);
	//assert(v.size() == 2); // 1 3

	//vector<int> v2(v.begin(), v.end());
	////v2(v);
	//assert(v2.size() == 2);
	//
	//v2 = v2;
	//assert(v2[0] == 1);
	//assert(v2[1] == 3);

	//vector<int> v3(v2.begin(), v2.end());
	//assert(v3.size() == 2);
//}


//void Tests::testService() {
	//MemoryRepository r{};
	//WatchList wl;
	//Service s{ r, wl };

	//for (int i = 1; i <= 3; ++i) {
	//	string title = "t" + to_string(i);
	//	string genre = "g" + to_string(i);
	//	int release_year = i;
	//	int likes = 0;
	//	string trailer = "www.google.com";
	//	s.addService(title, genre, release_year, likes, trailer);
	//}
	//vector<Movie> ms = s.getAllMovies();
	//assert(ms.size() == 3);
	//s.deleteService(1);
	//assert(s.getAllMovies().size() == 2);
	//s.updateService(0, "newt", "newg", 123, 321, "neww");
	//ms = s.getAllMovies();
	//assert(ms[0].getTitle() == "newt");
	//assert(ms[0].getGenre() == "newg");
	//assert(ms[0].getReleaseYear() == 123);
	//assert(ms[0].getLikes() == 321);
	//assert(ms[0].getTrailer() == "neww");

	//// favorites
	//// add valid movie to watch list
	//assert(s.addMovieToFavorite("newt", "newg") == 1);
	//assert(s.addMovieToFavorite("t3", "g3") == 1);
	//// ass invalid movie to watch list
	//assert(s.addMovieToFavorite("ttt", "ggg") == 0);

	//vector<Movie> favs = s.getFavoriteMovies();
	//assert(favs[0].getTitle() == "newt");
	//assert(favs[1].getTitle() == "t3");

	//// like movie - i have to make changes in the list!!!!!!!!!!
	//Movie liked_movie = s.likeMovieService("t3", "g3");
	//assert(liked_movie.getLikes() == 1);

	//// filter by genre
	//vector<Movie> movies_by_genre = s.getMoviesByGenre("newg");
	//assert(movies_by_genre.size() == 1);
	//movies_by_genre = s.getMoviesByGenre("fdsfe");
	//assert(movies_by_genre.size() == 2);

	//// teste detele from watch list
	//assert(s.deleteMovieFromFavorite("newt", "newg") == 1);
	//assert(s.deleteMovieFromFavorite("random", "random") == 0);
//}

//void Tests::testRepository() {
//	Repository repo{};
//	// test add
//	for (int i = 1; i <= 3; ++i) {
//		string title = "t" + to_string(i);
//		string genre = "g" + to_string(i);
//		int release_year = i;
//		int likes = 0;
//		string trailer = "www.google.com";
//		Movie m(title, genre, release_year, likes, trailer);
//		repo.addRepo(m);
//	}
//	assert(repo.getRepoSize() == 3);
//	// add an existing movie
//	Movie m_new("t1", "g1", 1, 0, "www.google.com");
//	assert(repo.addRepo(m_new) == 0);
//
//	// test update
//	Movie updated_m("title", "genre", 1234, 1200, "www.coding.com");
//	assert(repo.updateRepo(updated_m, 10) == 0);
//
//	repo.updateRepo(updated_m, 1);
//	vector<Movie> ms = repo.getAllMoviesRepo();
//	assert(ms[1].getTitle() == "title");
//	assert(ms[1].getGenre() == "genre");
//	assert(ms[1].getReleaseYear() == 1234);
//	assert(ms[1].getLikes() == 1200);
//	assert(ms[1].getTrailer() == "www.coding.com");
//
//	// test delete
//	repo.removeRepo(0);
//	assert(repo.removeRepo(-10) == 0);
//	ms = repo.getAllMoviesRepo();
//	assert(repo.getRepoSize() == 2);
//	assert(ms[0].getTitle() == "title");
//	assert(ms[0].getGenre() == "genre");
//	assert(ms[0].getReleaseYear() == 1234);
//	assert(ms[0].getLikes() == 1200);
//	assert(ms[0].getTrailer() == "www.coding.com");
//
//	// test give like
//	assert(ms[0].getLikes() == 1200);
//	repo.likeMovie(ms[0].getTitle(), ms[0].getGenre());
//	assert(repo.getAllMoviesRepo()[0].getLikes() == 1201);
//}

//void Tests::testWatchList() {
//	WatchList wl;
//	// add movie
//	Movie m("title1", "genre1", 1234, 0, "www.google.com");
//	assert(wl.addMovieToWL(m) == 1);
//	// add the same movie
//	assert(wl.addMovieToWL(m) == 0);
//	assert(wl.watchListSize() == 1);
//}