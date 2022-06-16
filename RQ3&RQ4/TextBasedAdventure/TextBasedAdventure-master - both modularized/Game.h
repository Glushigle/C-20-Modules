#ifndef GAME_H
#define GAME_H

import "Globals.h";
#include "Location.h"
using namespace std;
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