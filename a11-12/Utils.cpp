#include "Utils.h"

#include <sstream>
#include <algorithm>

string* splitString(string temp) {
	string* args = new string[5];
	istringstream ss(temp);
	string token;
	int i = 0;
	while (getline(ss, token, ',')) {
		args[i++] = token;
	}
	return args;
}