#ifndef GLOBALS_H
#define GLOBALS_H

// Putting all the libraries I use here, because what you call laziness, I call efficiency.
#include <iostream>
#include <map>
#include <set> // Remove this after changing the inventory to have descriptions.
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

typedef unsigned int uint;

#define OnOff(X) ((X) ? "On" : "Off") // Takes a bool and turns it into an "On" output or an "Off" output.  Used in menus.

#endif