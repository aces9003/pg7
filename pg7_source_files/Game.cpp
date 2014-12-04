//Game.cpp

#include "Game.h"
#include <string>

void Game::createDeck(){ //include all 55 cards in deck container

	//create 10 leather cards
	for (int i=0;i<10;i++){
		Card card();
		card.type= "Leather";
		deck.push_back(card);
	}
	//create 8 spice cards
	for (int i=0;i<8;i++){
		Card card();
		card.type= "Spice";
		deck.push_back(card);
	}
	//create 6 cloth cards
	for (int i=0;i<6;i++){
		Card card();
		card.type= "Cloth";
		deck.push_back(card);
	}
	//create 6 silver cards
	for (int i=0;i<6;i++){
		Card card();
		card.type= "Silver";
		deck.push_back(card);
	}
	//create 6 gold cards
	for (int i=0;i<6;i++){
		Card card();
		card.type= "Gold";
		deck.push_back(card);
	}
	//create 6 diamonds cards
	for (int i=0;i<6;i++){
		Card card();
		card.type= "Diamonds";
		deck.push_back(card);
	}
	//create 11 camels cards
	for (int i=0;i<11;i++){
		Card card();
		card.type= "Camels";
		deck.push_back(card);
	}
}

// Asks users if they want to play 2-Player of Human vs. AI
bool Game::initPlayers(std::string name1, std::string name2) {
    // 1 == Human vs. Human
    // 2 == Human vs. AI
    // Then prompt for both player's names (MUST name AI Player as well)
    if (getCurrentUserInput() == 1) {
        Player player1(name1);
        Player player2(name2);
        return true;
    } else if (getCurrentUserInput() == 2) {
        Player player1(name1);
        AIPlayer player2(name2);
        return false;
    } else return false;
}


