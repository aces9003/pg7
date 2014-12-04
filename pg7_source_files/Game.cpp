//Game.cpp

#include <stdio.h>
#include <cstdlib>
#include "Game.h"
#include <string>
#include <iostream>

using std::cin;		using std::cout;	using std::endl;	using std::istream;
using std::ostream;

// Constructor
Game::Game(std:: string name1, std::string name2) {
	initPlayers(name1, name2);
	setupTokens();
	createDeck();
	this->rounds = 1;
}

//"Driver" method governing player turns, called every turn
//prompt for either trade, sell, or take, cin choice
//call appropriate method (sell, take, trade) depending on choice
void Game::playerTurn(const Player& p) {
	cout<< "It is your turn " << p.getName << ", what would you like to do?" << endl;
	cout<< "[1] Sell cards from your hand" << endl << "[2] Take a card from the market"
		<< endl << "[3] Trade cards from your hand and herd with market cards" << endl;
	char input;
	cin>>input;
	cout << endl;
	while (input > '3' || input < '1'){       //check user input
		cout << "Invalid input entered, please try again: ";
		cin>>input;
		cout<<endl;
	}
	//////////////////////////////////////////////////////////////////
	//***** SELL ***** decide if sell one or multiple ***** SELL *****
	//////////////////////////////////////////////////////////////////
	if (input=='1'){
		cout<<"Would you like to sell one resource card or multiple resource cards?"
			<<endl << "[1] I would like to sell one card" << "[2] I would like to sell"
			<< " multiple cards" <<endl;
		char sellInput;
		cin>>sellInput;
		cout<<endl;
		while (takeInput > '2' || takeInput < '1'){       //check user input
		cout << "Invalid input entered, please try again: ";
		cin>>input;
		cout<<endl;
		}
		//SINGLE SELL
		if (sellInput=='1'){
			cout<< "Select a card from your hand by entering its index: ";
			char sellIndex;
			cin>>sellIndex;
			cout<<endl;
			p.sellOne(this,sellIndex);
		}
		
		//MULTIPLE SELL
		if (sellInput=='2'){
			bool done=false;
			while (done==false){
				cout<<"Select a card from your hand by entering its index: ";
				char sellIndex;
				cin>>sellIndex;
				cout<<endl;
				while (takeInput > '5' || takeInput < '1'){       //check user input
					cout << "Invalid input entered, please try again: ";
					cin>>input;
					cout<<endl;
				}
			}
		}
		
	/////////////////////////////////////////////////////////////////////////
	//***** TAKE ***** decide if take resource or all camels ***** TAKE *****
	/////////////////////////////////////////////////////////////////////////
	else if (input=='2'){
		cout<< "Select a card from the marketplace by entering its index. Note: if you select"
			<< " a camel and there are other camels present, you will take all camels."
			<<endl;
		char takeInput;
		cin>>takeInput;
		cout>>endl;
		while (takeInput > '5' || takeInput < '1'){       //check user input
		cout << "Invalid input entered, please try again: ";
		cin>>input;
		cout<<endl;
		}
		//CAMEL TAKE
		if (market.getCard(takeInput).getType == "Camels")
			p.takeCamels(this); //IS THIS HOW TO PASS IN GAME?
		//SINGLE TAKE
		else
			p.take(this,takeInput);
	}
	/////////////////////////////////////////////////
	//***** TRADE ***** trade cards ***** TRADE *****
	/////////////////////////////////////////////////
	else {
		p.trade();
	}
	//NEED TO CLEAR TRADING AND SELLING VECTORS
	//DO WE NEED ANYTHING ELSE AT THE END OF PLAYER TURN? LIKE PASSING TURN TO NEXT PLAYER?	
}

//count SoE, access player and count
int Game::countSE(const Player& p) {
	return p.seals;
} 

void giveSE(const Player& p) {
	p.seals++;
}

bool endGame() {
	if (this->isAi){
		if (countSE(p1)>1 || countSE(p2)>1){
			return true;
		}
	}
	else{
		if (if countSE(p1)>1 || countSE(p3)>1){
			return true;
		}
	}
	return false;
}

//Draw five cards from deck. Deck is random except first 3 cards, which are camel
//so that the market will have at least 3 camel as required DO AFTER CREATE DECK
void Game::dealMarket() {
	for(int i=0; i<5; i++){
        Card adder=deck.back();
        market.push_back(adder);
        deck.pop_back();
    }
}

//access back of deck and pop_back five times per player to deal hands, fill
//player.myhand and player.myherd if camels are drawn, dealHand AFTER MARKET SET UP
void Game::dealHand() {
	//p1 deal hand
	for(int i=0; i<5; i++){
        Card adder=deck.back();
		deck.pop_back();
		if (adder.getType == "Camels"){
			p1.myherd.addCard(adder);
		}
		else{
			p1.myhand.addCard(adder);
		}
    }
	
	//p2/p3 deal hand
	for(int i=0; i<5; i++){
        Card adder=deck.back();
		deck.pop_back();
		if (adder.getType == "Camels"){
			if (isAi)
				p3.myherd.addCard(adder);
			else
				p3.myherd.addCard(adder);
		}
		else{
			if (isAi)
				p3.myhand.addCard(adder);
			else
				p3.myhand.addCard(adder);
		}
    }
}

//award 5 points to player with largest herd, if herds are equal, no camel token 
void Game::awardCammelToken(){
	
}


void Game::setupTokens(){
	//create and populate vectors
	//leather 1,1,1,1,1,1,2,3,4
	string leather = "Leather";
	for (int i=0;i<6;i++){
		Token token(1,leather);
		leatherT.push_back(token);
	}
	Token ltoken2(2,leather);
	leatherT.push_back(ltoken2);
	Token ltoken3(3,leather);
	leatherT.push_back(ltoken3);
	Token ltoken4(4,leather);
	leatherT.push_back(ltoken4);

	//cloth 1,1,2,2,3,3,5
	string cloth = "Cloth";
	Token ctoken(1,cloth);
	clothT.push_back(ctoken);
	clothT.push_back(ctoken);
	Token ctoken2(2,cloth);
	clothT.push_back(ctoken2);
	clothT.push_back(ctoken2);
	Token ctoken3(3,cloth);
	clothT.push_back(ctoken3);
	clothT.push_back(ctoken3);
	Token ctoken5(5,cloth);
	clothT.push_back(ctoken5);
	
	//spice 1,1,2,2,3,3,5
	string spice = "Spice";
	Token stoken(1,spice);
	spiceT.push_back(stoken);
	spiceT.push_back(stoken);
	Token stoken2(2,spice);
	spiceT.push_back(stoken2);
	spiceT.push_back(stoken2);
	Token stoken3(3,spice);
	spiceT.push_back(stoken3);
	spiceT.push_back(stoken3);
	Token stoken5(5,spice);
	spiceT.push_back(stoken5);

	//silver 5,5,5,5,5
	for (int i=0;i<5;i++){
		string s = "Silver";
		Token token(5,s);
		silverT.push_back(token);
	}

	//gold 5,5,5,6,6,
	for (int i=0;i<3;i++){
		string s = "Gold";
		Token token(5,s);
		silverT.push_back(token);
	}
	for (int i=0;i<2;i++){
		string s = "Gold";
		Token token(6,s);
		silverT.push_back(token);
	}

	//diamond 5,5,5,7,7
	string diamond = "Diamonds";
	Token dtoken5(5,diamond);
	diamondT.push_back(dtoken5);
	diamondT.push_back(dtoken5);
	diamondT.push_back(dtoken5);
	Token dtoken7(7,diamond);
	diamondT.push_back(dtoken7);
	diamondT.push_back(dtoken7);

	//bonus3 1,1,2,2,3,3
	string b3 = "3cardBonus";
	Token btoken3(3,b3);
	bonus3.push_back(btoken3);
	bonus3.push_back(btoken3);
	Token btoken2(2,b3);
	bonus3.push_back(btoken2);
	bonus3.push_back(btoken2);
	Token btoken1(1,b3);
	bonus3.push_back(btoken1);
	bonus3.push_back(btoken1);
	// Shuffle bonus3 tokens
	std::random_shuffle ( btoken3.begin(), btoken3.end() );
	
	//bonus4 6,6,5,5,4,4
	string b4 = "4cardBonus";
	Token btoken4(4,b4);
	bonus4.push_back(btoken4);
	bonus4.push_back(btoken4);
	Token btoken5(5,b4);
	bonus4.push_back(btoken5);
	bonus4.push_back(btoken5);
	Token btoken6(6,b4);
	bonus4.push_back(btoken6);
	bonus4.push_back(btoken6);
	// Shuffle bonus4 tokens
	std::random_shuffle ( btoken4.begin(), btoken4.end() );
	
	//bonus5 10,10,9,9,8,8
	string b5 = "5cardBonus";
	Token btoken8(8,b5);
	bonus5.push_back(btoken8);
	bonus5.push_back(btoken8);
	Token btoken9(9,b5);
	bonus5.push_back(btoken9);
	bonus5.push_back(btoken9);
	Token btoken10(10,b5);
	bonus5.push_back(btoken10);
	bonus5.push_back(btoken10);
	// Shuffle bonus5 tokens
	std::random_shuffle ( btoken5.begin(), btoken.end() );
}

void Game::createDeck(){ //include all 55 cards in deck container

	//create 10 leather cards
	for (int i=0;i<10;i++){
		string leather = "Leather";
		Card card(leather);
		deck.push_back(card);
	}
	//create 8 spice cards
	for (int i=0;i<8;i++){
		string spice = "Spice";
		Card card(spice);
		deck.push_back(card);
	}
	//create 6 cloth cards
	for (int i=0;i<6;i++){
		string cloth = "Cloth";
		Card card(cloth);
		deck.push_back(card);
	}
	//create 6 silver cards
	for (int i=0;i<6;i++){
		string silver = "Silver";
		Card card(silver);
		deck.push_back(card);
	}
	//create 6 gold cards
	for (int i=0;i<6;i++){
		string gold = "Gold";
		Card card(gold);
		deck.push_back(card);
	}
	//create 6 diamonds cards
	for (int i=0;i<6;i++){
		string diamond = "Diamonds";
		Card card(diamond);
		deck.push_back(card);
	}
	//create 11 camels cards
	for (int i=0;i<8;i++){
		string camel = "Camels";
		Card card(camel);
		deck.push_back(card);
	}
	
	// Shuffle deck
	std::random_shuffle ( deck.begin(), deck.end() );
	
	// Add three camel to back of deck for marketplace setup
	for (int i=0;i<3;i++){
		string camel = "Camels";
		Card card(camel);
		deck.push_back(card);
	}
}

// Asks users if they want to play 2-Player of Human vs. AI
bool Game::initPlayers(std::string name1, std::string name2) {
    // 1 == Human vs. Human
    // 2 == Human vs. AI
    // Then prompt for both player's names (MUST name AI Player as well)
    if (getCurrentUserInput() == 1) {
        this->p1 = Player(name1);
        this->p2 = Player(name2);
		this->isAi = false;
        return true;
    } else if (getCurrentUserInput() == 2) {
        this->p1 = Player(name1);
        this->p3 = AIPlayer();	// Default constructor for AIPlayer
		this->isAi = true;

        return false;
    } else return false;
}





