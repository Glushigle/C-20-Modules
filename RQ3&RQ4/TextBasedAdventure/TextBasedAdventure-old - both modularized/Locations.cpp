#include "Locations.h"
import Utilities;

/*	To add a new location:
 *		-add it's name to the Area enum in Globals.h
 *		-add it to the definision of areaToString() to string in Utilities.cpp
 *		-add a prototype to Locations.h
 *		-define a starting description and the processCommand(), displayDescription(), and getActions() functions in Locations.cpp
 *		-add the functionality to go to that area to the bodies of processCommand() and getActions() for the classes of the adjacent areas in Locations.cpp
 *		-add it as a case in locationMaker() in Game.cpp
 */

/*
 *		Town Center
 */

string TownCenter::description = "The center of town.  There are no people to be seen.  ";

void TownCenter::displayDescription()
{
	string output = description;
	output += (IsDay ? "It is daytime.\n" : "It is nighttime.\n");
	display(output);
}

Area TownCenter::processCommand(string input)
{
	if (input == "go to Town Hall")
		return TOWNHALL;
	if (input == "go to Thief's House")
		return THIEFSHOUSE;
	else
		return ERROR;
}

string TownCenter::getActions()
{
	return " go to Town Hall\n go to Thief's House\n";
}

/* 
 *		Town Hall
 */

string TownHall::description = "The town hall.  It is locked and abandoned.  ";
bool TownHall::DoorUnlocked = false;

void TownHall::displayDescription()
{
	string output = description;
	output += (IsDay ? "It is daytime.\n" : "It is nighttime.\n");
	display(output);
}

Area TownHall::processCommand(string input)
{
	if (input == "go to Town Center")
		return TOWNCENTER;
	else if (input == "unlock door") {
		if (DoorUnlocked == true) {
			display("The door is already unlocked.\n");
			return here;
		} else if (PC->isInInventory(LOCKPICK)) {
			DoorUnlocked = true;
			display("The door has been unlocked, although the lockpick broke in the process.\n");
			description = "The town hall.  It is abandoned, but you have unlocked the door.  ";
			PC->removeFromInventory(LOCKPICK);
			return here;
		} else {
			display("But you have nothing with which to unlock the door...\n");
			return here;
		}
	}
	else if (input == "enter Town Hall") {
		if (DoorUnlocked)
			return TOWNHALLLOBBY;
		else {
			display("The door is locked and won't budge.\n");
			return here;
		}
	} else
		return ERROR;
	}

string TownHall::getActions()
{
	string output;
	if ((DoorUnlocked == false) && (PC->isInInventory(LOCKPICK)))
		output += " unlock door\n";
	if (DoorUnlocked == true)
		output += " enter Town Hall\n";
	output += " go to Town Center\n";
	return output;
}

/*
 *		Town Hall Lobby
 */
	
string TownHallLobby::description = "The lobby of the abandoned town hall.  An old treasury chest lies in the corner.  ";
bool TownHallLobby::TreasuryChestSearched = false;

void TownHallLobby::displayDescription()
{
	string output = description;
	output += (IsDay ? "It is daytime.\n" : "It is nighttime.\n");
	display(output);
}

Area TownHallLobby::processCommand(string input)
{
	if (input == "leave Town Hall")
		return TOWNHALL;
	else if (input == "search treasury chest") {
		if (TreasuryChestSearched) {
			display("You've already searched the treasury chest.  It's empty now, you greedy son-of-an-orc.\n");
			return here;
		} else {
			display("When the dust settles, you find a sack of gold.\n");
			TreasuryChestSearched = true;
			PC->addToInventory(SACKOFGOLD);
			return here;
		}
	} else
		return ERROR;
}

string TownHallLobby::getActions()
{
	string output;
	if (TreasuryChestSearched == false)
		output += " search treasury chest\n";
	output += " leave Town Hall\n";
	return output;
}

/*
 *		Thief's House
 */

string ThiefsHouse::description = "The residence of the local thief.  ";

void ThiefsHouse::displayDescription()
{
	string output = description;
	output += (IsDay ? "It is daytime, and the thief appears to be home.\n" : "It is nighttime, and thief appears to be out thieving, as the house is empty.\n");
	display(output);
}

Area ThiefsHouse::processCommand(string input)
{
	if (input == "go to Town Center")
		return TOWNCENTER;
	else if (input == "enter house") {
		if (IsDay) {
			display("Well that wasn't particularly bright of you.  The thief killed you for breaking into his house.\n");
			return TERMINATE;
		} else
			return THIEFSHOUSEINTERIOR;
	} else 
		return ERROR;
}

string ThiefsHouse::getActions()
{
	return " enter house\n go to Town Center\n";
}

/*
 *		Thief's House Interior
 */

string ThiefsHouseInterior::description = "Inside the residence of the local thief.  He has left some lockpicks on the table.  ";
bool ThiefsHouseInterior::ThiefSawYou = false;

void ThiefsHouseInterior::displayDescription()
{
	string output = description;
	output += (IsDay ? "It is daytime.  It's a miracle the thief hasn't killed you yet.\n" : "It is nighttime.\n");
	display(output);
}

Area ThiefsHouseInterior::processCommand(string input)
{
	if (input == "take lockpick") {
		PC->addToInventory(LOCKPICK);
		display("You take a lockpick from the table.\n");
		return here;
	} else if (input == "leave house") {
		if (ThiefSawYou) {
			display("The thief must have seen you in his house, because he was waiting outside to ambush you.  He killed you.\n");
			return TERMINATE;
		} else
		return THIEFSHOUSE;
	} else
		return ERROR;
}

string ThiefsHouseInterior::getActions()
{
	string returner;
	returner += " take lockpick\n";
	returner += " leave house\n";
	return returner;
}

void ThiefsHouseInterior::processWait(string input)
{
	if (input == "wait until day") {
		if (IsDay == false) {
			IsDay = true;
			ThiefSawYou = true;
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
		cout << "Error: processWait() in ThiefsHouseInterior was forced to handle an unknown input.\n";
}
