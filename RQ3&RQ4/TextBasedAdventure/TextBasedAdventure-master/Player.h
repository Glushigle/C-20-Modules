#ifndef PLAYER_H
#define PLAYER_H

#include "Globals.h"
#include "Utilities.h"
#include "Item.h"

struct ItemComp {
	bool operator() (const string& leftComp, const string& rightComp) const {return stringComp(leftComp, rightComp) == 1;}
};

class Player {
private:
	bool isAlive;
	Area currentLocation;
	multimap<string, Item, ItemComp> Inventory;
public:
	Player(Area currentLocationIn);
	
	Area getCurrentLocation(){return currentLocation;}
	void setCurrentLocation(Area input){currentLocation = input;}
	bool isDead(){return !isAlive;}
	void killPlayer(){isAlive = false;}
	
	void addToInventory(Item input, uint quantity = 1);
	Item getItem(string name) const;
	bool isInInventory(Item input) const;
	bool isInInventory(string name) const;
	uint numInInventory(Item input) const; // returns the number of such objects in the inventory
	uint numInInventory(string name) const;
	bool emptyInventory() const {return Inventory.empty();}
	int removeFromInventory(Item input, uint quantity = 1);// returns the number of such objects remaining in the inventory.  Returns -1 if nothing removed (i.e. if quantity > count).
	int removeFromInventory(string name, uint quantity = 1);
	string inventoryToString() const;
	
	string saveData();
	void loadData(string input);
};

#endif