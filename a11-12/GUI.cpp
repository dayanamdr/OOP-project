#include "GUI.h"
#include <QtWidgets/QMessageBOx>
#include <Windows.h>
#include <shellapi.h>
#include <QLinearGradient>

#include <iostream>

using namespace std;

GUI::GUI(Service srv) {
	this->srv = srv;
	//this->wl = wl;
	auto* right_side = new QWidget{};

	auto* user = new QPushButton("User");
	auto* admin = new QPushButton("Admin");
	
	QLinearGradient blackGradient = QLinearGradient(0, 0, 0, height());
	blackGradient.setSpread(QGradient::RepeatSpread);
	blackGradient.setColorAt(0, QColor(255, 255, 255));
	blackGradient.setColorAt(1, QColor(0, 0, 0, 255));
	QBrush blackGradiantBrush = QBrush(blackGradient);

	auto palette = right_side->palette();
	palette.setBrush(QPalette::Window, blackGradiantBrush);
	right_side->setPalette(palette);

	auto* buttons_layout = new QHBoxLayout(right_side);
	buttons_layout->addWidget(user);
	buttons_layout->addWidget(admin);
	
	connect(admin, &QPushButton::clicked, this, &GUI::admin_mode);
	connect(user, &QPushButton::clicked, this, &GUI::user_mode);
	right_side->show();
}

void GUI::initial_list() {
	if (this->movies_list->count() > 0) {
		this->movies_list->clear();
		movies_list_vector.clear();
	}
	for (const auto& movie : this->srv.getAllMovies()) {
		QString movie_in_list = QString::fromStdString(movie.toString());
		auto* mov = new QListWidgetItem{ movie_in_list };
		movies_list_vector.push_back(movie);
		this->movies_list->addItem(mov);
	}
}

void GUI::filter_list() {
	if (this->movies_list->count() > 0) {
		this->movies_list->clear();
		movies_list_vector.clear();
	}
	for (const auto& movie : this->srv.get_movies(this->filter_items_edit->text().toStdString())) {
		QString movie_in_list = QString::fromStdString(movie.toString());
		auto* mov = new QListWidgetItem{ movie_in_list };
		movies_list_vector.push_back(movie);
		this->movies_list->addItem(mov);
	}
}

void GUI::add_to_list() {
	QString title_QString = title_edit->text();
	QString genre_QString = genre_edit->text();
	QString trailer_QString = trailer_edit->text();
	QString likes_QString = likes_edit->text();
	QString year_QString = year_edit->text();

	int year = std::stoi(year_QString.toStdString());
	int likes = std::stoi(likes_QString.toStdString());

	this->srv.addService(title_QString.toStdString(), genre_QString.toStdString(), year, likes, trailer_QString.toStdString());
	this->filter_list();

	title_edit->clear();
	genre_edit->clear();
	trailer_edit->clear();
	likes_edit->clear();
	year_edit->clear();
}

void GUI::clear_selected_item() {
	movies_list->clearSelection();
	title_edit->clear();
	genre_edit->clear();
	trailer_edit->clear();
	likes_edit->clear();
	year_edit->clear();
}

void GUI::select_item() {
	auto movie = movies_list_vector[movies_list->currentRow()];
	title_edit->setText(QString::fromStdString(movie.getTitle()));
	genre_edit->setText(QString::fromStdString(movie.getGenre()));
	trailer_edit->setText(QString::fromStdString(movie.getTrailer()));
	likes_edit->setText(QString::fromStdString(std::to_string(movie.getLikes())));
	year_edit->setText(QString::fromStdString(std::to_string(movie.getReleaseYear())));

}

void GUI::delete_item() {
	auto movie = movies_list_vector[movies_list->currentRow()];
	this->srv.deleteService(movie.getTitle());
	movies_list->clearSelection();
	title_edit->clear();
	genre_edit->clear();
	trailer_edit->clear();
	likes_edit->clear();
	year_edit->clear();
	this->filter_list();
}

void GUI::update_item() {
	QString title_QString = title_edit->text();
	QString trailer_QString = trailer_edit->text();

	this->srv.updateService(title_QString.toStdString(), trailer_QString.toStdString());
	this->filter_list();
}


void GUI::admin_mode() {
	this->setWindowTitle("Movies");
	auto* layout_wrapper = new QVBoxLayout{ this };

	auto* layout_widget = new QWidget;
	this->filter_items_edit = new QLineEdit{};

	layout_wrapper->addWidget(filter_items_edit);
	layout_wrapper->addWidget(layout_widget);

	auto* layout = new QVBoxLayout{ layout_widget };

	auto* left_side = new QWidget;
	layout->addWidget(left_side);
	auto* left_v_box = new QVBoxLayout(left_side);

	auto* movies_list_name = new QLabel{ "Movies list" };
	left_v_box->addWidget(movies_list_name);
	this->movies_list = new QListWidget;
	this->movies_list->setSelectionMode(QAbstractItemView::SingleSelection);
	left_v_box->addWidget(this->movies_list);

	auto* right_side = new QWidget;
	layout->addWidget(right_side);
	auto* right_v_box = new QVBoxLayout(right_side);

	auto* movies_data_widget = new QWidget;
	auto* fields_form = new QFormLayout{ movies_data_widget };
	right_v_box->addWidget(movies_data_widget);

	this->title_edit = new QLineEdit;
	auto* title_label = new QLabel{ "Title:" };
	fields_form->addRow(title_label, this->title_edit);

	this->genre_edit = new QLineEdit;
	auto* genre_label = new QLabel{ "Genre:" };
	fields_form->addRow(genre_label, this->genre_edit);

	this->trailer_edit = new QLineEdit;
	auto* trailer_label = new QLabel{ "Trailer:" };
	fields_form->addRow(trailer_label, this->trailer_edit);

	this->year_edit = new QLineEdit;
	auto* year_label = new QLabel{ "Year:" };
	fields_form->addRow(year_label, this->year_edit);

	this->likes_edit = new QLineEdit;
	auto* likes_label = new QLabel{ "Likes:" };
	fields_form->addRow(likes_label, this->likes_edit);

	auto* buttons_layout = new QHBoxLayout;
	this->add_button = new QPushButton("Add");
	this->delete_button = new QPushButton("Delete");
	this->update_button = new QPushButton("Update");
	this->clear_button = new QPushButton("Clear");
	buttons_layout->addWidget(this->add_button);
	buttons_layout->addWidget(this->delete_button);
	buttons_layout->addWidget(this->update_button);
	buttons_layout->addWidget(this->clear_button);
	right_v_box->addLayout(buttons_layout);


	connect(this->filter_items_edit, &QLineEdit::textChanged, this, &GUI::filter_list);
	connect(this->movies_list, &QListWidget::itemSelectionChanged, this, &GUI::select_item);
	connect(this->add_button, &QPushButton::clicked, this, &GUI::add_to_list);
	connect(this->update_button, &QPushButton::clicked, this, &GUI::update_item);
	connect(this->delete_button, &QPushButton::clicked, this, &GUI::delete_item);
	connect(this->clear_button, &QPushButton::clicked, this, &GUI::clear_selected_item);

	this->initial_list();
}

void GUI::user_mode() {
	this->setWindowTitle("Movies");
	auto* layout_wrapper = new QVBoxLayout{ this };

	auto* layout_widget = new QWidget;
	this->filter_items_edit = new QLineEdit{};

	layout_wrapper->addWidget(filter_items_edit);
	layout_wrapper->addWidget(layout_widget);

	auto* layout = new QVBoxLayout{ layout_widget };

	auto* left_side = new QWidget;
	layout->addWidget(left_side);
	auto* left_v_box = new QHBoxLayout(left_side);

	auto* movies_list_name = new QLabel{ "Movies list" };
	left_v_box->addWidget(movies_list_name);
	this->movies_list = new QListWidget;
	this->movies_list->setSelectionMode(QAbstractItemView::SingleSelection);
	left_v_box->addWidget(this->movies_list);
	auto* watch_list_name = new QLabel{ "Watch list" };
	left_v_box->addWidget(watch_list_name);
	this->watch_list = new QListWidget;
	left_v_box->addWidget(this->watch_list);

	auto* right_side = new QWidget;
	layout->addWidget(right_side);
	auto* right_v_box = new QVBoxLayout(right_side);

	auto* movies_data_widget = new QWidget;
	auto* fields_form = new QFormLayout{ movies_data_widget };
	right_v_box->addWidget(movies_data_widget);

	auto* buttons_layout = new QHBoxLayout;
	this->add_button = new QPushButton("Add");
	this->delete_button = new QPushButton("Delete");
	auto* html_button = new QPushButton("HTML");
	auto* csv_button = new QPushButton("CSV");
	like_button = new QPushButton("like");
	this->clear_button = new QPushButton("Clear");
	buttons_layout->addWidget(this->add_button);
	buttons_layout->addWidget(this->delete_button);
	buttons_layout->addWidget(html_button);
	buttons_layout->addWidget(csv_button);
	buttons_layout->addWidget(like_button);
	buttons_layout->addWidget(this->clear_button);
	right_v_box->addLayout(buttons_layout);


	connect(this->filter_items_edit, &QLineEdit::textChanged, this, &GUI::filter_list);
	connect(this->movies_list, &QListWidget::itemDoubleClicked, this, &GUI::double_clicked_item);
	connect(this->add_button, &QPushButton::clicked, this, &GUI::add_to_watch_list);
	connect(html_button, &QPushButton::clicked, this, &GUI::open_html);
	connect(csv_button, &QPushButton::clicked, this, &GUI::open_csv);
	connect(this->delete_button, &QPushButton::clicked, this, &GUI::delete_from_watch_list);
	connect(like_button, &QPushButton::clicked, this, &GUI::like_movie);
	//connect(this->clear_button, &QPushButton::clicked, this, &GUI::clear_selected_item);
	this->add_button->setEnabled(false);
	like_button->setEnabled(false);
	this->initial_list();
}

void GUI::double_clicked_item() {
	auto movie = movies_list_vector[movies_list->currentRow()];
	ShellExecuteA(NULL, "open", movie.getTrailer().c_str(), NULL, NULL, SW_SHOWNORMAL);
	this->add_button->setEnabled(true);

}

void GUI::filter_list_user() {
	if (this->watch_list->count() > 0) {
		this->watch_list->clear();
		watch_list_vector.clear();
	}
	for (const auto& movie : this->srv.getFavoriteMovies()) {
		QString movie_in_list = QString::fromStdString(movie.toString());
		auto* mov = new QListWidgetItem{ movie_in_list };
		watch_list_vector.push_back(movie);
		this->watch_list->addItem(mov);
	}
}

void GUI::open_html() {
	HTMLWatchList html_wl;
	html_wl.saveToFile(watch_list_vector);
	html_wl.openInApp();
}

void GUI::open_csv() {
	CSVWatchList csv_wl;
	csv_wl.saveToFile(watch_list_vector);
	csv_wl.openInApp();
}

void GUI::add_to_watch_list() {
	this->add_button->setEnabled(false);
	auto movie = movies_list_vector[movies_list->currentRow()];

	for (auto mov : this->srv.getFavoriteMovies())
		if (movie.getTitle() == mov.getTitle())
			return;
	this->srv.addMovieToFavorite(movie.getTitle(), movie.getGenre());
	this->filter_list_user();
}

void GUI::delete_from_watch_list() {
	auto movie = watch_list_vector[watch_list->currentRow()];
	this->last_deleted = movie;
	this->srv.deleteMovieFromFavorite(movie.getTitle(), movie.getGenre());
	this->filter_list_user();
	like_button->setEnabled(true);
}

void GUI::like_movie() {
	this->srv.likeMovieService(last_deleted.getTitle(), last_deleted.getGenre());
	like_button->setEnabled(false);
}
