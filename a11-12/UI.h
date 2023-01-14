#pragma once

#ifndef UI_H
#define UI_H

#endif

#include "Service.h"

class UI {
private:
	Service& my_service;

public:
	// constructor with service
	UI(Service& my_service);

	// start function
	void start_console(Service& my_service, WatchList& my_wl);

	~UI();
};