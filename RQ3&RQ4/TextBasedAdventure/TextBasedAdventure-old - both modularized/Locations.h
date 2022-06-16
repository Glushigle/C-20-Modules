#ifndef LOCATIONS_H
#define LOCATIONS_H

import "Globals.h";
#include "Menu.h"
#include "Location.h"
using namespace std;
class TownCenter : public Location {
private:
	static string description;
public:
	TownCenter() : Location(TOWNCENTER) {if(Menu::getDisplayDescription()) displayDescription();}
	void displayDescription();
	Area processCommand(string input);
	string getActions();
};

class TownHall : public Location {
private:
	static string description;
	static bool DoorUnlocked;
public:
	TownHall() : Location(TOWNHALL) {if(Menu::getDisplayDescription()) displayDescription();}
	void displayDescription();
	Area processCommand(string input);
	string getActions();
};

class TownHallLobby : public Location {
private:
	static string description;
	static bool TreasuryChestSearched;
public:
	TownHallLobby() : Location(TOWNHALLLOBBY) {if(Menu::getDisplayDescription()) displayDescription();}
	void displayDescription();
	Area processCommand(string input);
	string getActions();
};
	
class ThiefsHouse : public Location {
private:
	static string description;
public:
	ThiefsHouse() : Location(THIEFSHOUSE) {if(Menu::getDisplayDescription()) displayDescription();}
	void displayDescription();
	Area processCommand(string input);
	string getActions();
};

class ThiefsHouseInterior : public Location {
private:
	static string description;
	static bool ThiefSawYou;
public:
	ThiefsHouseInterior() : Location(THIEFSHOUSEINTERIOR) {if(Menu::getDisplayDescription()) displayDescription();}
	void displayDescription();
	Area processCommand(string input);
	string getActions();
	void processWait(string input);
};

#endif