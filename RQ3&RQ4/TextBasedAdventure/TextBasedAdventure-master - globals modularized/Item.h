#ifndef ITEM_H
#define ITEM_H

import "Globals.h";
#include "Utilities.h"
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

#define RUSTYSWORD Item("Rusty sword", "A worn sword from your more adventurous days.  It's unimpressive, but it'll do the job.", true)
#define LANTERN Item("Lantern", "A basic lantern that emits a strong light, allowing you to see in dark places.", true)
#define ERRORITEM Item("Error Item", "If you got this item, something in the code went wrong.")

#endif