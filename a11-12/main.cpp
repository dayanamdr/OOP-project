#include "a1112.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QFormLayout>

#include <iostream>
#include <fstream>
#include "HTMLWatchList.h"
#include "CSVWatchList.h"
#include "MemoryRepository.h"
#include "FileRepository.h"
#include "Service.h"
#include "UI.h"
#include "GUI.h"

int initial_settings(int argc, char** argv) {
    QApplication a(argc, argv);

	string watchListType = "";
	cout << "Watch list type? html/csv"; cin >> watchListType;

	MemoryRepository* repo = new FileRepository{ "input.txt" };
	WatchList* wl;
	HTMLWatchList html_wl;
	wl = &html_wl;

	Service* service = new Service{ repo, wl };
	GUI gui{ *service};
	gui.show();
	// here comes the GUI

	return a.exec();
}


int main(int argc, char *argv[])
{
	return initial_settings(argc, argv);

	//QApplication a(argc, argv);

	//QApplication a(argc, argv);

	/*QWidget* main = new QWidget{};
	QFormLayout* fL = new QFormLayout(main);
	QLabel* lbl = new QLabel("Name:", main);
	QLineEdit* txt = new QLineEdit(main);
	fL->addRow(lbl, txt);
	main->show();*/
	//main->setWindowTitle("Layout");
	////fix the height to the "ideal" height
	//main->setFixedHeight(main->sizeHint().height());

	//string watchListType = "html";
	////cout << "Watch list type? html/csv"; cin >> watchListType;

	//MemoryRepository* repo = new FileRepository{ "input.txt" };
	//WatchList* wl;
	//if (watchListType == "html") {
	//	wl = new HTMLWatchList();
	//}
	//else {
	//	wl = new CSVWatchList();
	//}
	//Service* service = new Service{ repo, wl };

	// here comes the GUI

	//return a.exec();
}
