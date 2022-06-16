#include "WorldVariables.h"

WorldVariables::WorldVariables()
{
	IsDay = true;
	
	Elffor.SwordRetrieved = false;
	Elffor.NinaConversationHad = false;
	
	RoadToElffor.BattleFought = false;
}

string WorldVariables::saveData()
{
	stringstream output;
	output << IsDay << ' ' << SUBENDMARKER << ' ';
	output << Elffor.SwordRetrieved << ' ' << Elffor.NinaConversationHad << ' ' << SUBENDMARKER << ' ';
	output << RoadToElffor.BattleFought << ' ' << SUBENDMARKER << '\n';
	output << ENDMARKER << '\n';
	return output.str();
}

// Use to load data into each variable
#define IFSUBENDNOTREACHED(variable) \
	if ((strstr.str())[1] != SUBENDMARKER) \
		strstr >> variable;

// Use in between each block (but not after the last one)
#define IFENDNOTREACHED \
	if ((strstr.str())[3] != ENDMARKER) \
		strstr.ignore(2); \
	else \
		return;

void WorldVariables::loadData(string input)
{
	stringstream strstr(input);
	IFSUBENDNOTREACHED(IsDay)
	IFENDNOTREACHED
	IFSUBENDNOTREACHED(Elffor.SwordRetrieved)
	IFSUBENDNOTREACHED(Elffor.NinaConversationHad)
	IFENDNOTREACHED
	IFSUBENDNOTREACHED(RoadToElffor.BattleFought)

	strstr.ignore(3);
	LOADDATACHECK("WorldVariables")
}