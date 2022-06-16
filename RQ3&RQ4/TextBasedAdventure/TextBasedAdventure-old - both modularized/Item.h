#ifndef ITEM_H
#define ITEM_H

import "Globals.h";
using namespace std;
class Item {
private:
	const string name;
	const string description;
	const bool unique;
public:
	Item(string nameIn, string descriptionIn, bool uniqueIn = false) : name(nameIn), description(descriptionIn), unique(uniqueIn) {}
	string getName() const {return name;}
	string getDescription() const {return description;}
	bool isUnique() const {return unique;}
};

#define LOCKPICK Item("Lockpick", "A standard lockpick.  It looks pretty brittle.")
#define SACKOFGOLD Item("Sack of gold", "A small burlap sack containing a modest amount of gold coins.", true)
#define ERRORITEM Item("Error Item", "If you got this item, something in the code went wrong.")

#endif