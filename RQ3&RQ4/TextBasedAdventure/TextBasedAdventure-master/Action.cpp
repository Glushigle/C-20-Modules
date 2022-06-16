#include "Action.h"

FUNCACTION(goToElfforMyHouseInterior){PC.setCurrentLocation(ELFFORMYHOUSEINTERIOR);}
FUNCACTION(goToElfforMyHouse){PC.setCurrentLocation(ELFFORMYHOUSE);}
FUNCACTION(goToElfforTavern){PC.setCurrentLocation(ELFFORTAVERN);}
FUNCACTION(goToElfforTavernInterior){PC.setCurrentLocation(ELFFORTAVERNINTERIOR);}
FUNCACTION(goToElfforGate){PC.setCurrentLocation(ELFFORGATE);}
FUNCACTION(goToRoadToElfforA){PC.setCurrentLocation(ROADTOELFFORA);}

/*
 *		Base Actions
 */

FUNCACTION(waitUntilDay)
{
	if (WorldVars.IsDay == false) {
		WorldVars.IsDay = true;
		cout << "You wait until the sun rises.\n";
	} else
		cout << "But it already is day...\n";
}

FUNCACTION(waitUntilNight)
{
	if (WorldVars.IsDay == true) {
		WorldVars.IsDay = false;
		cout << "You wait until the sun sets.\n";
	} else
		cout << "But it is already night...\n";
}

FUNCACTION(observeAction) {
	stringstream output;
	bool DayNightAccountedFor = false;
	
	display(areaToString(PC.getCurrentLocation()));
	cout << '\n';
	
	if (PC.getCurrentLocation() == ELFFORMYHOUSEINTERIOR) {
		output << "The inside of your house.  It's small, but it's home.  ";
		if (! WorldVars.Elffor.SwordRetrieved)
			output << "Your sword usually hangs on the wall, but it's missing, dust outlining where it used to be.  ";
		else
			output << "Dust outlines the spot on the wall where your sword usually hangs.  ";
		output << "There's a bed you can sleep in.  ";
	} else if (PC.getCurrentLocation() == ELFFORMYHOUSE)
		output << "Outside of your house.  It's a quaint little place.  You can see the tavern and the gate that leads out of town.  ";
	else if (PC.getCurrentLocation() == ELFFORGATE)
		output << "The gate that leads out of the town, left open to allow free passage.  There is a sign posted on the side of the gate.  You can see the tavern and your house.  ";
	else if (PC.getCurrentLocation() == ELFFORTAVERN)
		output << "Outside of the local tavern, The Infernal Woods, a small building constructed of dark wood.  It's a modest place, but it's well-kept.\
  You can see your house and the gate that leads out of town.  ";
	else if (PC.getCurrentLocation() == ELFFORTAVERNINTERIOR) {
		if (WorldVars.IsDay) {
			output << "Inside The Infernal Woods.  Trent, the bartender, is ";
			output << (WorldVars.Elffor.SwordRetrieved ? "standing behind the bar.  " : "waving at you, trying to attract your attention.  ");
			output << "Nina is sitting at the bar, sipping a brew.  ";
		} else
			output << "There's no one inside, as the place is closed.  ";
	} else if (PC.getCurrentLocation() == ROADTOELFFORA) {
		output << "Outside of the gate to Elffor.  ";
		if (! WorldVars.RoadToElffor.BattleFought)
			output << "There's a rustling coming from in the trees.  ";
		else
			output << "All is relatively still.  ";
		if (WorldVars.IsDay)
			output << "It is daytime.";
		else {
			if (PC.isInInventory(LANTERN))
				output << "It is nighttime.";
			else
				output << "It is nighttime, and you can see that it's hard to see in the woods.";
		}
		DayNightAccountedFor = true;
	} else
		cout << "Error:  the observe action was called on an area it didn't know how to handle.";
	
	if (! DayNightAccountedFor)
		output << (WorldVars.IsDay ? "It is daytime." : "It is nighttime.");
	
	output << '\n';
	display(output.str());
}

/*
 *		Elffor Actions
 */

FUNCACTION(ElfforHouseSleepInBed)
{
	if (WorldVars.IsDay) {
		display("You lie in bed in a state of half-sleep, dreaming vividly and just feeling very relaxed.  When you finally force yourself out a bed, night has arrived.\n");
		WorldVars.IsDay = false;
	} else {
		display("You get a good night's rest, waking up with boundless energy, ready to greet the new day.\n");
		WorldVars.IsDay = true;
	}
}

FUNCACTION(ElfforHouseWaitUntilDay)
{
	if (WorldVars.IsDay == false) {
		display("But why just wait when you can sleep in your comfy bed?\n");
	} else
		display("But it already is day...\n");
}

FUNCACTION(ElfforHouseWaitUntilNight)
{
	if (WorldVars.IsDay == true) {
		display("But why just wait when you can sleep in your comfy bed?\n");
	} else
		display("But it is already night...\n");
}

FUNCACTION(ElfforReadSign)
{
	dialog("WARNING:\nWild wolves have been spotted roaming outside of the town fence.  They will attack unprotected travelers.\
  If you are travelling alone, bring something to defend yourself with.");
}

FUNCACTION(ElfforEnterTavern)
{
	if (WorldVars.IsDay)
		PC.setCurrentLocation(ELFFORTAVERNINTERIOR);
	else
		display("The tavern door is locked and won't budge.\n");
}

FUNCACTION(ElfforTalkToTrent)
{
	if (WorldVars.Elffor.SwordRetrieved) {
		dialog("\"Is life treating you well, friend?  I certainly hope it is.\"");
	} else {
		dialog("\"I'm glad you popped in!  You left something here last night.\"");
		PC.addToInventory(RUSTYSWORD);
		WorldVars.Elffor.SwordRetrieved = true;
		dialog("Trent hands you your sword.");
		dialog("\"You going somewhere?  You'll be needing that, then.  I hear we've got wolves in our midst.\"");
		dialog("\"Bah!  Wolves, you say?\" Nina shouts from her stool.  \"We haven't had a wolf problem in years, not since I showed them what's what!  The lad'll be fine!\"");
		dialog("\"You need to get out of the tavern more, Nina.  These aren't the times they used to be.\"");
		dialog("Trent turns to face you.  \"Either way, good to have your sword back, eh, friend?\"");
	}
}

FUNCACTION(ElfforTalktoNina)
{
	if (! WorldVars.Elffor.SwordRetrieved)
		dialog("\"How ye be these days, lad?\"");
	else {
		if (! WorldVars.Elffor.NinaConversationHad) {
			dialog("\"Trent's just a worry-wort.  You were quite the fighter in your day, if I recall correctly.\"");
			dialog("\"Your recall isn't what it used to be, Nina.\"");
			dialog("\"Are you doubting our boy's abilities, Trent?!\"");
			dialog("\"I'm just saying you could do with a bit less of the ale, that's all...\"");
			WorldVars.Elffor.NinaConversationHad = true;
		} else
			dialog("\"Why, I'm sure you could take down a wolf with your bare hands, lad!\"");
	}
}

FUNCACTION(ElfforTavernWaitUntilDay)
{
	if (WorldVars.IsDay == false) {
		dialog("Trent walks in and gasps when he sees you.  \"How did you get in here?!...  Well, whatever, you're harmless enough.  Just don't scare me like that again.\"");
		WorldVars.IsDay = true;
	} else
		display("But it already is day...\n");
}

FUNCACTION(ElfforTavernWaitUntilNight)
{
	if (WorldVars.IsDay == true) {
		dialog("You stay until closing, at which point Trent leads you to the door.  \"Sorry, friend, but you can't stay here for the night.\"");
		cout << '\n';
		PC.setCurrentLocation(ELFFORTAVERN);
		WorldVars.IsDay = false;
	} else
		display("But it is already night...\n");
}

/*
 *		Road to Elffor Actions
 */

FUNCACTION(EnterElffor)
{
	PC.setCurrentLocation(ELFFORGATE);
	WorldVars.RoadToElffor.BattleFought = false;
}

FUNCACTION(RoadToElfforGoDownPath)
{
	if (WorldVars.RoadToElffor.BattleFought)
		display("This is where you'd move to a new area.\n"); // temp code
	else {
		if ((! WorldVars.IsDay) && (! PC.isInInventory(LANTERN))) {
			display("In the dark of the night, made only more impregnable by the thick woods, you could only hear the wolf moving through the brush.\
  By the time you saw him, he was already at your throat.\n");
			PC.killPlayer();
		} else if (! PC.isInInventory(RUSTYSWORD)) {
			display("A wolf leaps out from the brush and sprints towards you.  Alas, with no means of defending yourself, you become its next dinner.\n");
			PC.killPlayer();
		} else {
			display("A wolf leaps out from the brush, intent on making you its dinner.  Seeing the wolf coming at you, you slay the beast with your sword.\
  The path is now safe to walk.\n");
			WorldVars.RoadToElffor.BattleFought = true;
		}
	}
}