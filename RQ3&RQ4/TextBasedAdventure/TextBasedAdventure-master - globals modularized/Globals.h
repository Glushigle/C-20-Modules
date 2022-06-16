#ifndef GLOBALS_H
#define GLOBALS_H

// Putting all the libraries I use here so I don't have to worry about whether they were included in a previous file or not as I write the code.
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

typedef unsigned int uint;

#define OnOff(X) (X ? "On" : "Off") // Takes a bool and turns it into an "On" output or an "Off" output.  Used in menus.

enum Area {TERMINATE = -1, AREASTARTMARKER, ELFFORMYHOUSEINTERIOR, ELFFORMYHOUSE, ELFFORGATE, ELFFORTAVERN, ELFFORTAVERNINTERIOR, ROADTOELFFORA, AREAENDMARKER};
#define StartingLocation ELFFORMYHOUSEINTERIOR // Defines the area the game will start you in.

enum status {OK = 1, ERROR = 0};

#define ENDMARKER '%' // Defines the character used to mark the end of a line/block of saved data.
#define SUBENDMARKER '$'

// Place at the end of every load function, with CLASSNAME being a string that is the class's name.  Depends on the stringstream being named strstr.
#define LOADDATACHECK(CLASSNAME) \
	char endTest; \
	strstr >> endTest; \
	if (endTest != ENDMARKER) \
		cout << "Error: Something went wrong with " << CLASSNAME << "::loadData().\n";

#endif