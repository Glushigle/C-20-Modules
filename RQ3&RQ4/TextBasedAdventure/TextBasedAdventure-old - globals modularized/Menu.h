#ifndef PAUSEMENU_H
#define PAUSEMENU_H

import "Globals.h";
#include "Utilities.h"
#include "Player.h"

using namespace std;

class Menu {
private:
	Player* const PC;
	static bool DisplayDescription;
	static bool DisplayActions;
	
	void optionsMenu();
	void inventoryMenu();
public:
	Menu(Player *input);
	void pauseMenu();
	
	static bool getDisplayDescription(){return DisplayDescription;}
	static bool getDisplayActions(){return DisplayActions;}
};

#endif