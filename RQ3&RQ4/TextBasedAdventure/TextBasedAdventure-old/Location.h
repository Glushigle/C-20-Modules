#ifndef LOCATION_H
#define LOCATION_H

#include "Globals.h"
#include "Utilities.h"
#include "Player.h"

enum Area {TERMINATE = -1, ERROR = 0, TOWNCENTER, TOWNHALL, TOWNHALLLOBBY, THIEFSHOUSE, THIEFSHOUSEINTERIOR};

#define StartingLocation TOWNCENTER // Defines the area the game will start you in.

// Takes a value of the Area enum as input and return's the area's name as a string.
string areaToString(Area input);

class Location {
private:
	virtual Area processCommand(string input) = 0; // Processes the user's input string to check it against actions unique to the area.  Returns the area the player ends up in afterward.
	virtual void displayDescription() = 0; // Displays the area specific description.  Each area should have its own static description variable.
	void displayUnknownCommand(); // Displays the error message for when an unknown command is entered.
	virtual void processWait(string input); // Called when the player waits until day or night.  Can be overriden so that waiting has an effect on the area.
protected:
	const Area here;
	static bool IsDay;
	Location(Area input);
	virtual string getActions() = 0; // Displays all possible actions unique to the area.  Each listed action should start with a space and end with a newline character.
public:
	static Player *PC;
	void displayActions(); // Displays all possible actions, including those that aren't area specific.
	Area getCommand(string input); // Takes input and uses the virtual processCommand function to process it.  Returns the area the player ends up in after the command is processed.
};

#endif