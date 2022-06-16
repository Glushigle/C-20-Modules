#ifndef WORLDVARIABLES_H
#define WORLDVARIABLES_H

#include "Globals.h"
#include "Utilities.h"

struct WorldVariables {
	bool IsDay;
	struct {
		bool SwordRetrieved;
		bool NinaConversationHad;
	} Elffor;
	struct {	
		bool BattleFought;
	} RoadToElffor;
	
	WorldVariables();
	string saveData();
	void loadData(string input);
};

#endif