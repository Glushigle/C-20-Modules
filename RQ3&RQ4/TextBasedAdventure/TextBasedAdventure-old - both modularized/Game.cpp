#include "Game.h"
#include "Menu.h"
import Utilities;

Location* Game::locationMaker(Area input)
{
	switch (input) {
		case TOWNCENTER:			return new TownCenter;
		case TOWNHALL:				return new TownHall;
		case TOWNHALLLOBBY:			return new TownHallLobby;
		case THIEFSHOUSE:			return new ThiefsHouse;
		case THIEFSHOUSEINTERIOR:	return new ThiefsHouseInterior;
		default:
			display("Error: locationMaker() was given an invalid location and didn't return anything.  It is very likely that the program will crash if you do anything other than quit right now.\n");
			break;
	}
}

Game::Game()
{
	display("\nWelcome to the adventure game!\n");
	cout << endl;
	currentArea = StartingLocation;
	location = locationMaker(StartingLocation);
}

void Game::run()
{	
	while (true) {
		if (Menu::getDisplayActions()) {
			cout << endl;
			location->displayActions();
		}
		
		cout << endl <<"What will you do?\n";
		getline(cin, input);
		cout << endl;
		
		if (input == "quit" || input == "0") {
			cout << "Goodbye!\n";
			break;
		} else if (input == "menu") {
			Menu menu(Location::PC);
			menu.pauseMenu();
		} else {
			tempArea = location->getCommand(input);
			if (tempArea == TERMINATE)
				break;
			if (tempArea != currentArea) {
				location = locationMaker(tempArea);
				currentArea = tempArea;
			}
		}
	}
	
	delete Location::PC;
	cout << endl;
}