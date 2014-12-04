//Game.cpp

#include "Game.h"

void Game::createDeck(){ //include all 55 cards in deck container

	//create 10 leather cards
	for (int i=0;i<10;i++){
		string s= "Leather";
		Card card(s);
		deck.push_back(card);
	}
	//create 8 spice cards
	for (int i=0;i<8;i++){
		string s= "Spice";
		Card card(s);
		deck.push_back(card);
	}
	//create 6 cloth cards
	for (int i=0;i<6;i++){
		string s= "Cloth";
		Card card(s);
		deck.push_back(card);
	}
	//create 6 silver cards
	for (int i=0;i<6;i++){
		string s= "Silver";
		Card card(s);
		deck.push_back(card);
	}
	//create 6 gold cards
	for (int i=0;i<6;i++){
		string s= "Gold";
		Card card(s);
		deck.push_back(card);
	}
	//create 6 diamonds cards
	for (int i=0;i<6;i++){
		string s= "Diamonds";
		Card card(s);
		deck.push_back(card);
	}
	//create 11 camels cards
	for (int i=0;i<11;i++){
		string s= "Camels";
		Card card(s);
		deck.push_back(card);
	}
}