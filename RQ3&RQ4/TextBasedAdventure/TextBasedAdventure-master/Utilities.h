#ifndef UTILITIES_H
#define UTILITIES_H

#include "Globals.h"

// Defines functions useful to all parts of the program.

class UtilitiesOptions { // Defines options needed by parts of the program before the program's flow reaches the Menu class.
private:
	static uint screenWidth;
	static uint screenHeight;
	static bool displayItemDescriptions;
public:
	static uint getScreenWidth(){return screenWidth;}
	static uint getScreenHeight(){return screenHeight;}
	static bool getDisplayItemDescriptions(){return displayItemDescriptions;}
	static void setScreenWidth(uint input){screenWidth = input;}
	static void setScreenHeight(uint input){screenHeight = input;}
	static void setDisplayItemDescriptions(bool input){displayItemDescriptions = input;}
	
	static string saveData();
	static void loadData(string input);
};

struct DialogStruct {
	static bool DialogEngaged;
};

// Takes a value of the Area enum as input and return's the area's name as a string.
string areaToString(Area input);

// Displays the input string with proper wrapping, i.e. no split words and no spaces at the start of a wrapped line.  This function WILL print out spaces after a newline character.
// If width is specified, the input is printed out with that width, not the set screen width.
void display(string input, uint width = 0);

// Displays the text and calls for the user to press enter to continue.  Input strings should have no line breaks at the end.
void dialog(string input);

// Truncates text to be a specfic length, and show a ... if it's too long.  If quantity is specified, it will add " (x##)" to the end.
string truncateText(string name, int length, uint quantity = 1);

// Prompts the user for input.  Returns the integer entered, unless no integer is entered, in which case it returns a -99.
int getSelection();

// Forces the user to hit enter to continue.
void enterToContinue();

// Returns 1 if leftComp goes before rightComp in alphabetical order, -1 if rightComp goes before leftComp, and 0 if they're identical.
int stringComp(string leftComp, string rightComp);

// Returns the number of digits of the input number.  Returns 1 if input == 0.
uint digits(uint input);

// Returns false if the input is '0', true otherwise (in the nature of false only being associated with zero). 
bool charToBool(char input);

#endif