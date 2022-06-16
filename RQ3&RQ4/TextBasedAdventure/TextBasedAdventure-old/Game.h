#ifndef GAME_H
#define GAME_H

#include "Globals.h"
#include "Utilities.h"
#include "Locations.h"

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