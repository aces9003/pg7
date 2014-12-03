//Game.cpp

#include "Game.h"


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