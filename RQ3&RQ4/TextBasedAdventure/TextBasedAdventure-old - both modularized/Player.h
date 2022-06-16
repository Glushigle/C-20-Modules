#ifndef PLAYER_H
#define PLAYER_H

import "Globals.h";
#include "Item.h"
using namespace std;
struct ItemComp {
	bool operator()(const string &left, const string &right) const {
    int i;
	string leftComp="", rightComp="";
	leftComp.assign(left);
	rightComp.assign(right);
    for (i = 0; i < left.length(); i++)
      leftComp[i] = tolower(left[i]);
    for (i = 0; i < right.length(); i++)
      rightComp[i] = tolower(right[i]);

    int compLength = min(leftComp.length(), rightComp.length());
    for (i = 0; i < compLength; i++) {
      if (leftComp[i] < rightComp[i])
        return true;
      else if (leftComp[i] > rightComp[i])
        return false;
    }

    if (leftComp.length() < rightComp.length())
      return true;
    else if (leftComp.length() > rightComp.length())
      return false;
    else
      return false;
  }
};

class Player {
private:
	multimap<string, Item, ItemComp> Inventory;
public:
//	Player();  Not required for now.
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
};

#endif