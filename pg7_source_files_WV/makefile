CXX=g++
CXXFLAGS= -std=c++11 -Wall -Wextra -pedantic -O

GPROF = -pg
GCOV = -fprofile-arcs -ftest-coverage

#binaries
all:	game

gcov: Game.cpp Game.h GameTest.cpp
	$(CXX) $(CFLAGS) $(GCOV) GameTest.cpp PlayerTest.cpp Game.h Player.h

Card.o: Card.cpp Card.h
	$(CXX) $(CFLAGS) -c Card.cpp

Game.o: Game.cpp Game.h Marketplace.h Container.h Card.h Player.h Hand.h AIPlayer.h Token.h
	$(CXX) $(CFLAGS) -c Game.cpp

GameTest.o: GameTest.cpp Game.h Marketplace.h Container.h Card.h Player.h Hand.h AIPlayer.h Token.h
	$(CXX) $(CFLAGS) -c GameTest.cpp

Hand.o: Hand.cpp Hand.h Container.h Card.h Game.h Marketplace.h Player.h AIPlayer.h Token.h
	$(CXX) $(CFLAGS) -c Hand.cpp

HandTest.o: HandTest.cpp Hand.h Container.h Card.h
	$(CXX) $(CFLAGS) -c HandTest.cpp

Marketplace.o: Marketplace.cpp Marketplace.h Container.h Card.h Game.h Player.h Hand.h AIPlayer.h Token.h
	$(CXX) $(CFLAGS) -c Marketplace.cpp

Player.o: Player.cpp Player.h Card.h Hand.h Container.h Token.h
	$(CXX) $(CFLAGS) -c Player.cpp

PlayerTest.o: PlayerTest.cpp Player.h Card.h Hand.h Container.h Player.cpp Token.h
	$(CXX) $(CFLAGS) -c PlayerTest.cpp

game: Card.o Game.o GameTest.o Hand.o HandTest.o Marketplace.o Player.o PlayerTest.o 
	$(CXX) $(CFLAGS) -o game Card.o Game.o GameTest.o Hand.o HandTest.o Marketplace.o Player.o PlayerTest.o 


clean:
	rm -i *.o *.gch