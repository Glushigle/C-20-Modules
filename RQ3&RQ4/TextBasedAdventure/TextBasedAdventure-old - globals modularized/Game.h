#ifndef GAME_H
#define GAME_H

import "Globals.h";
#include "Utilities.h"
#include "Locations.h"

using namespace std;

class Game {
private:
	Location *location;
	Area currentArea, tempArea;
	string input;
	Location *locationMaker(Area input);
public:
	Game();
	void run();
};

#endif