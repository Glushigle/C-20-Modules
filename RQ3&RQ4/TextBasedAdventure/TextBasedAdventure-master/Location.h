#ifndef LOCATION_H
#define LOCATION_H

/*	To add a new location:
 *		-add it's name to the Area enum in Globals.h (be sure to add it right before the AREAENDMARKER one, after all the previous areas)
 *		-add it to the definision of areaToString() to string in Utilities.cpp
 *		-add any static variables it needs to the WorldVariables struct in WorldVariables.h
 *		-add those static variables to every function in WorldVariables.cpp
 *		-add its description to the observeAction() body in Action.cpp, as well as a goTo function and whatever functions the area needs in Action.h/.cpp
 *		-add the Action to go to this area to the adjacent areas in the body of Location().  Add its own functions to the body of Location().
 */

#include "Globals.h"
#include "Utilities.h"
#include "Action.h"

class Location {
private:
	void displayUnknownCommand(); // Displays the error message for when an unknown command is entered.

	WorldVariables &WorldVars;
	Player &PC;
	vector<Action> Actions;
	
	string getActions(); // Returns all possible actions in the Actions vector. Each listed action should start with a space and end with a newline character.
public:
	Location(Player &PCin, WorldVariables &WorldVarsIn);

	Area getArea(){return PC.getCurrentLocation();} // Delete this and replace all calls to it with more appropriate functions.
	void refreshActions(); // Adds all applicable actions to the Actions vector, based on WorldVars and PC.
	void displayActions(); // Displays all possible actions, including those that aren't area specific.
	void getCommand(string input); // Takes input and processCommand function to process it. Returns the area the player ends up in after the command is processed.
	void displayDescription(); // Displays the area specific description.
};

#endif