run: Utilities.o Player.o Menu.o WorldVariables.o Action.o Location.o Game.o \
Main.o
	g++ -Wall -o $@ $^

push:
	git push origin master

Utilities.o: Utilities.h Utilities.cpp

Player.o: Player.h Player.cpp

Menu.o: Menu.h Menu.cpp

WorldVariables.o: WorldVariables.h WorldVariables.cpp

Action.o: Action.h Action.cpp

Location.o: Location.h Menu.h Location.cpp

Game.o: Menu.h Game.h Game.cpp

Main.o: Game.h Main.cpp

clean:
	rm run *.o *~ *.h.gch

clear:
	rm *~