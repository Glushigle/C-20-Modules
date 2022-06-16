#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include "Globals.h"
#include "Player.h"

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