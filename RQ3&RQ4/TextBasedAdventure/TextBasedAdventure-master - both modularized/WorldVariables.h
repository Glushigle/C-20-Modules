#ifndef WORLDVARIABLES_H
#define WORLDVARIABLES_H

import "Globals.h";
using namespace std;
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