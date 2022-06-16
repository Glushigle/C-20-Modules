#include "Location.h"
#include "Menu.h"

Location::Location(Player &PCin, WorldVariables &WorldVarsIn) : PC(PCin), WorldVars(WorldVarsIn)
{
	refreshActions();
}

#define ADDWAITDAYNIGHT(dayFunctionPointer, nightFunctionPointer) \
	Actions.push_back(Action("wait until day", dayFunctionPointer, ! WorldVars.IsDay)); \
	Actions.push_back(Action("wait until night", nightFunctionPointer, WorldVars.IsDay)); \
	waitDefined = true;

void Location::refreshActions()
{
	bool waitDefined = false; // Set this variable to true if an area gets its own explicitly defined wait until day/night commands.
	
	Actions.clear();
	
	Actions.push_back(Action("observe", observeAction));
	if (PC.getCurrentLocation() == ELFFORMYHOUSEINTERIOR) {
		Actions.push_back(Action("leave house", goToElfforMyHouse));
		Actions.push_back(Action("sleep in bed", ElfforHouseSleepInBed));
		ADDWAITDAYNIGHT(ElfforHouseWaitUntilDay, ElfforHouseWaitUntilNight);
	} else if (PC.getCurrentLocation() == ELFFORMYHOUSE) {
		Actions.push_back(Action("enter house", goToElfforMyHouseInterior));
		Actions.push_back(Action("go to gate", goToElfforGate));
		Actions.push_back(Action("go to tavern", goToElfforTavern));
	} else if (PC.getCurrentLocation() == ELFFORTAVERN) {
		Actions.push_back(Action("enter tavern", ElfforEnterTavern));
		Actions.push_back(Action("go to my house", goToElfforMyHouse));
		Actions.push_back(Action("go to gate", goToElfforGate));
	} else if (PC.getCurrentLocation() == ELFFORTAVERNINTERIOR) {
		Actions.push_back(Action("leave tavern", goToElfforTavern));
		if (WorldVars.IsDay) {
			Actions.push_back(Action("talk to Trent", ElfforTalkToTrent));
			Actions.push_back(Action("talk to Nina", ElfforTalktoNina));
		}
		ADDWAITDAYNIGHT(ElfforTavernWaitUntilDay, ElfforTavernWaitUntilNight)
	} else if (PC.getCurrentLocation() == ELFFORGATE) {
		Actions.push_back(Action("read sign", ElfforReadSign));
		Actions.push_back(Action("leave town", goToRoadToElfforA));
		Actions.push_back(Action("go to my house", goToElfforMyHouse));
		Actions.push_back(Action("go to tavern", goToElfforTavern));
	} else if (PC.getCurrentLocation() == ROADTOELFFORA) {
		Actions.push_back(Action("enter Elffor", goToElfforGate));
		Actions.push_back(Action("go down path", RoadToElfforGoDownPath));
	} else
		cout << "Error: Location constructor called while PC was in an invalid location.\n";
	if (! waitDefined) {
		Actions.push_back(Action("wait until day", waitUntilDay, ! WorldVars.IsDay));
		Actions.push_back(Action("wait until night", waitUntilNight, WorldVars.IsDay));
	}
}

void Location::getCommand(string input)
{
	if (input == "actions") {
		if (Menu::getDisplayActions() == false)
			displayActions();
	} else {
		vector<Action>::iterator it;
		for (it = Actions.begin(); it != Actions.end(); it++) {
			if (input == it->getCommand()) {
				it->callAction(PC, WorldVars);
				refreshActions();
				DialogStruct::DialogEngaged = false;
				return;
			}
		}
		displayUnknownCommand();
	}
}

// Put a space before all displayed actions.
void Location::displayActions()
{
	stringstream output;
	output << "Your possible actions are:\n" << getActions() << " menu\n save\n quit\n";
	display(output.str());
}

void Location::displayDescription()
{
	vector<Action>::iterator it;
	for (it = Actions.begin(); it != Actions.end(); it++) {
		if (it->getCommand() == "observe") {
			it->callAction(PC, WorldVars);
			return;
		}
	}
	cout << "Error: " << areaToString(getArea()) << " doesn't have a devined observe function.\n";
}

string Location::getActions()
{
	stringstream output;
	vector<Action>::iterator it;
	for (it = Actions.begin(); it != Actions.end(); it++) {
		if (it->getShowAction())
			output << ' ' << it->getCommand() << '\n';
	}
	return output.str();
}

void Location::displayUnknownCommand()
{
	if (Menu::getDisplayActions())
		display("Whatever that is, you can't do it.\n");
	else
		display("Whatever that is, you can't do it.  Try using the \"actions\" command.\n");
}