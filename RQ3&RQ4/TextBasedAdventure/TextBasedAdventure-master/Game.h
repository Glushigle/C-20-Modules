#ifndef GAME_H
#define GAME_H

#include "Globals.h"
#include "Utilities.h"
#include "Location.h"

class Game {
private:
	Player PC;
	WorldVariables WorldVars;
	Location LocationVar;
	
	string defaultData;
	Area lastLocation;
	
	void saveDefaultData();
	status loadDefaultData();
	
	status saveGame(string &filename);
	void saveData(string filename);
	status loadGame(string filename);
	void playGame(string filename = "");
public:
	Game();
	void run();
};

#endif