#include "Locations.h"
#include "Menu.h"

string areaToString(Area input)
{
	switch (input) {
		case TOWNCENTER:			return "Town Center";
		case TOWNHALL:				return "Town Hall";
		case TOWNHALLLOBBY:			return "Town Hall Lobby";
		case THIEFSHOUSE:			return "Thief's House";
		case THIEFSHOUSEINTERIOR:	return "Thief's House Interior";
		default:
			return "Error: areaToString() received improper input.\n";
	}
}

Location::Location(Area input) : here(input)
{
	string output = areaToString(input);
	output += '\n';
	display(output);
}

Player* Location::PC = new Player;

// This function should never return the ERROR flag.
Area Location::getCommand(string input)
{
	if (input == "actions") {
		if (Menu::getDisplayActions() == false)
			displayActions();
	} else if (input == "observe")
		displayDescription();
	else if ((input == "wait until day") || (input == "wait until night"))
		processWait(input);
	else {
		Area returner;
		returner = processCommand(input);
		if (returner == ERROR) {
			displayUnknownCommand();
			return here;
		}
		return returner;
	}
	return here;
}

bool Location::IsDay = true;

// Put a space before all displayed actions.
void Location::displayActions()
{
	stringstream output;
	output << "Your possible actions are:\n observe\n" << getActions() << (IsDay ? " wait until night\n" : " wait until day\n") << " menu\n" << " quit" << endl;
	display(output.str());
}

void Location::displayUnknownCommand()
{
	if (Menu::getDisplayActions())
		display("Whatever that is, you can't do it.");
	else
		display("Whatever that is, you can't do it.  Try using the \"actions\" command.");
	cout << endl;
}

void Location::processWait(string input)
{
	if (input == "wait until day") {
		if (IsDay == false) {
			IsDay = true;
			cout << "You wait until the sun rises.\n";
		} else
			cout << "But it already is day...\n";
	}
	else if (input == "wait until night") {
		if (IsDay == true) {
			IsDay = false;
			cout << "You wait until the sun sets.\n";
		} else
			cout << "But it is already night...\n";
	}
	else
		cout << "Error: processWait() was forced to handle an unknown input.\n";
}
