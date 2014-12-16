//Game.cpp

#include "Game.h"
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>


using std::cin;		using std::cout;	using std::endl;	using std::istream;
using std::ostream;

//int Game::myrandom (int i) { return std::rand()%(this->rounds)+1;}


// Constructor
Game::Game() {
	createDeck();
	setupTokens();
	//initPlayers(name1, name2);
	dealMarket();
	//dealHand();
	//this->rounds = 1; // SET MANUALLY IN main() based on if on Game 1, Game 2, Game 3
    this->emptyTokenVectors = 0;
    std::srand ( unsigned ( std::time(0) ) );
}

/*
// Destructor
Game::~Game() {
    
}
 */

//"Driver" method governing player turns, called every turn
//prompt for either trade, sell, or take, cin choice
//call appropriate method (sell, take, trade) depending on choice

/*
void Game::playerTurn(Player &p) {
	cout<< "It is your turn " << p.getName() << ", what would you like to do?" << endl;
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
	// ***** SELL ***** decide if sell one or multiple ***** SELL *****
	//////////////////////////////////////////////////////////////////
	if (input=='1'){
		cout<<"Would you like to sell one resource card or multiple resource cards?"
			<<endl << "[1] I would like to sell one card" << "[2] I would like to sell"
			<< " multiple cards" <<endl;
		char sellInput;
		cin>>sellInput;
		cout<<endl;
		while (sellInput > '2' || sellInput < '1'){       //check user input
		cout << "Invalid input entered, please try again: ";
		cin>>sellInput;
		cout<<endl;
		}
		//SINGLE SELL
		if (sellInput=='1'){
			cout<< "Select a card from your hand by entering its index: ";
			char sellIndex;
			cin>>sellIndex;
			cout<<endl;
			p.sellOne(&clothT, &leatherT, &spiceT, sellIndex);
		}
		
		//MULTIPLE SELL
		if (sellInput=='2'){
			bool done=false;
			while (done==false){
				cout<<"Select a card from your hand by entering its index: ";
				char sellIndex;
				cin>>sellIndex;
				cout<<endl;
				long hsize = p.myHand.size();
				while (sellIndex > hsize || sellIndex < '1'){       //check user input
					cout << "Invalid input entered, please try again: ";
					cin>>sellIndex;
					cout<<endl;
				}
				handIndicesForSelling.push_back(sellIndex);
				cout<<"Card at index " << handIndicesForSelling.back() << " has been selected for sale."
					<<endl << "Would you like to add another? (y/n)";
				char sdone;
				cin>>sdone;
				cout<<endl;
				while (sdone!='y' || sdone!='n'){
					cout<< "Invalid input entered, please try again: ";
					cin>>sdone;
					cout<<endl;
				}
				if (sdone=='n')
					done=true;
				else {}
			}
			p.sellMult(&handIndicesForSelling, &bonus3, &bonus4, &bonus5, &clothT, &leatherT, &spiceT, &diamondT, &goldT, &silverT);
		}
		handIndicesForSelling.clear();
	}
	/////////////////////////////////////////////////////////////////////////
	// ***** TAKE ***** decide if take resource or all camels ***** TAKE *****
	/////////////////////////////////////////////////////////////////////////
	else if (input=='2'){
		cout<< "Select a card from the marketplace by entering its index. Note: if you select"
			<< " a camel and there are other camels present, you will take all camels."
			<<endl;
		char takeInput;
		cin>>takeInput;
		cout<<endl;
		while (takeInput > '5' || takeInput < '1'){       //check user input
		cout << "Invalid input entered, please try again: ";
		cin>>input;
		cout<<endl;
		}
		//CAMEL TAKE
		//if (market.getCard(takeInput).getType() == "Camels")
		if (market.at(takeInput).getType() == "Camels")
			p.takeCamels(&market, &deck); //IS THIS HOW TO PASS IN GAME?
		//SINGLE TAKE
		else
			p.take(&market, &deck, takeInput);
	}
	/////////////////////////////////////////////////
	// ***** TRADE ***** trade cards ***** TRADE *****
	/////////////////////////////////////////////////
	else {
		
		/////////////////////////////
		//TRADE SELECTION FROM HAND//
		/////////////////////////////
		bool done=false;
		while (done==false){
			cout<<"Select a card from your hand by entering its index: ";
			char tradeIndex;
			cin>>tradeIndex;
			cout<<endl;
			long hsize = p.myHand.size();
			while (tradeIndex > hsize || tradeIndex < '1'){       //check user input
				cout << "Invalid input entered, please try again: ";
				cin>>tradeIndex;
				cout<<endl;
			}
			playerIndicesForTrading.push_back(tradeIndex);
			cout<<"Card at index " << playerIndicesForTrading.back() << " has been selected for trade."
				<<endl << "Would you like to add another? (y/n)";
			char sdone;
			cin>>sdone;
			cout<<endl;
			while (sdone!='y' || sdone!='n'){
				cout<< "Invalid input entered, please try again: ";
				cin>>sdone;
				cout<<endl;
			}
			if (sdone=='n')
				done=true;
			else {}
		}
		
		///////////////////////////////
		//TRADE SELECTION FROM MARKET//
		///////////////////////////////
		bool done2=false;
		while (done2==false){
			cout<<"Select a card from the market by entering its index: ";
			char trade2Index;
			cin>>trade2Index;
			cout<<endl;
			long hsize = p.myHand.size();
			while (trade2Index > hsize || trade2Index < '1'){       //check user input
				cout << "Invalid input entered, please try again: ";
				cin>>trade2Index;
				cout<<endl;
			}
			marketIndicesForTrading.push_back(trade2Index);
			cout<<"Card at index " << marketIndicesForTrading.back() << " has been selected for trade."
				<<endl << "Would you like to add another? (y/n)";
			char t2done;
			cin>>t2done;
			cout<<endl;
			while (t2done!='y' || t2done!='n'){
				cout<< "Invalid input entered, please try again: ";
				cin>>t2done;
				cout<<endl;
			}
			if (t2done=='n')
				done2=true;
			else {}
		}
		//use aquired trading vectors to make trades
        //p.trade();                          ////////////////////////TRADE
		marketIndicesForTrading.clear();
		playerIndicesForTrading.clear();
	}
}
*/

/*
bool Game::endGame() {
	if (isAi){
		//if (countSE(*p1)>1 || countSE(*p2)>1){ //////fix confusion of getter methods
			return true;
		//}
	}
	else{
		//if (countSE(*p1)>1 || countSE(*p3)>1){
			return true;
		//}
	}
	return false;
}*/

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
//player.myHand and player.myHerd if camels are drawn, dealHand AFTER MARKET SET UP
void Game::dealHand() {
	//p1 deal hand
	for(int i=0; i<5; i++){
        Card adder=deck.back();
		if (adder.getType() == "Camels"){
			p1->myHerd.push_back(adder);
            deck.pop_back();
		}
		else{
			p1->myHand.push_back(adder);
            deck.pop_back();
		}
    }
	
	//p2/p3 deal hand
	for(int i=0; i<5; i++){
        Card adder=deck.back();
		if (adder.getType() == "Camels"){
			//if (isAi)
				//p3->myHerd.push_back(adder);
			//else
				p2->myHerd.push_back(adder);
                deck.pop_back();
		}
		else{
            
			//if (isAi)
				//p3->myHand.push_back(adder);
			//else
				p2->myHand.push_back(adder);
                deck.pop_back();
		}
    }
}

//award 5 points to player with largest herd, if herds are equal, no camel token 
void Game::awardCammelToken(){
	//variables for camel herd sizes
	long p1size= p1->myHerd.size();
    //long p3size= p3->myHerd.size();
    long p2size= p2->myHerd.size();
    Token cToken(5, "Camel");
	//if (isAi)
		//p3size=p3->myHerd.size();
	//else
		p2size=p2->myHerd.size();
	//if ai in game, use p3
	/*if (isAi){
		
		if (p1size>p3size){
            p1->addPoint(cToken);
			//p1->hasCamelToken=true;
		}
		else if(p3size>p1size){
			p3->addPoint(cToken);
			//p3.hasCamelToken=true;
		}
		else{}
		
	} */
    
	//if two human players, use p2 and p1
	//else{
		if (p1size>p2size){
			p1->addPoint(cToken);
			//p1->hasCamelToken=true;
		}
		else if (p2size>p1size){
			p2->addPoint(cToken);
			//p2.hasCamelToken=true;
		}
		else {}
	//}
}

/* OLD */
void Game::setupTokens(){
	// Line below assures randomization of each shuffle per round/game
    //std::srand ( unsigned ( std::time(0) ) );
	
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
    // Add to tokenBag
    //tokenBag.insert( std::pair<string, vector<Token> *>("Leather", &leatherT));
    tokenBag["Leather"] = &leatherT;
    
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
    // Add to tokenBag
    tokenBag["Cloth"] = &clothT;
    
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
    // Add to tokenBag
    tokenBag["Spice"] = &spiceT;
    
	//silver 5,5,5,5,5
	for (int i=0;i<5;i++){
		string s = "Silver";
		Token token(5,s);
		silverT.push_back(token);
	}
    // Add to tokenBag
    tokenBag["Silver"] = &silverT;

	//gold 5,5,5,6,6,
	for (int i=0;i<3;i++){
		string s = "Gold";
		Token token(5,s);
		goldT.push_back(token);
	}
	for (int i=0;i<2;i++){
		string s = "Gold";
		Token token(6,s);
		goldT.push_back(token);
	}
    // Add to tokenBag
    tokenBag["Gold"] = &goldT;

	//diamond 5,5,5,7,7
	string diamond = "Diamonds";
	Token dtoken5(5,diamond);
	diamondT.push_back(dtoken5);
	diamondT.push_back(dtoken5);
	diamondT.push_back(dtoken5);
	Token dtoken7(7,diamond);
	diamondT.push_back(dtoken7);
	diamondT.push_back(dtoken7);
    // Add to tokenBag
    tokenBag["Diamonds"] = &diamondT;
    
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
	std::random_shuffle ( bonus3.begin(), bonus3.end() );
    // Add to tokenBag
    tokenBag["bonus3"] = &bonus3;
	
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
	std::random_shuffle ( bonus4.begin(), bonus4.end() );
    // Add to tokenBag
    tokenBag["bonus4"] = &bonus4;
	
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
	std::random_shuffle ( bonus5.begin(), bonus5.end() );
    // Add to tokenBag
    tokenBag["bonus5"] = &bonus5;
}


/* NEW - WITH MAP
 void Game::setupTokens(){
	// Line below assures randomization of each shuffle per round/game
 std::srand ( unsigned ( std::time(0) ) );
	
	//create and populate vectors
	//leather 1,1,1,1,1,1,2,3,4
	string leather = "Leather";
	for (int i=0;i<6;i++){
 Token token(1,leather);
 tokenBag.at("Leather").push_back(token);
	}
	Token ltoken2(2,leather);
	tokenBag.at("Leather").push_back(ltoken2);
	Token ltoken3(3,leather);
	tokenBag.at("Leather").push_back(ltoken3);
	Token ltoken4(4,leather);
	tokenBag.at("Leather").push_back(ltoken4);
 
	//cloth 1,1,2,2,3,3,5
	string cloth = "Cloth";
	Token ctoken(1,cloth);
	tokenBag.at("Cloth").push_back(ctoken);
	tokenBag.at("Cloth").push_back(ctoken);
	Token ctoken2(2,cloth);
	tokenBag.at("Cloth").push_back(ctoken2);
	tokenBag.at("Cloth").push_back(ctoken2);
	Token ctoken3(3,cloth);
	tokenBag.at("Cloth").push_back(ctoken3);
	tokenBag.at("Cloth").push_back(ctoken3);
	Token ctoken5(5,cloth);
	tokenBag.at("Cloth").push_back(ctoken5);
	
	//spice 1,1,2,2,3,3,5
	string spice = "Spice";
	Token stoken(1,spice);
	tokenBag.at("Spice").push_back(stoken);
	tokenBag.at("Spice").push_back(stoken);
	Token stoken2(2,spice);
	tokenBag.at("Spice").push_back(stoken2);
	tokenBag.at("Spice").push_back(stoken2);
	Token stoken3(3,spice);
	tokenBag.at("Spice").push_back(stoken3);
	tokenBag.at("Spice").push_back(stoken3);
	Token stoken5(5,spice);
	tokenBag.at("Spice").push_back(stoken5);
 
	//silver 5,5,5,5,5
	for (int i=0;i<5;i++){
 string s = "Silver";
 Token token(5,s);
 tokenBag.at("Silver").push_back(token);
	}
 
	//gold 5,5,5,6,6,
	for (int i=0;i<3;i++){
 string s = "Gold";
 Token token(5,s);
 tokenBag.at("Gold").push_back(token);
	}
	for (int i=0;i<2;i++){
 string s = "Gold";
 Token token(6,s);
 tokenBag.at("Gold").push_back(token);
	}
 
	//diamond 5,5,5,7,7
	string diamond = "Diamonds";
	Token dtoken5(5,diamond);
	tokenBag.at("Diamonds").push_back(dtoken5);
	tokenBag.at("Diamonds").push_back(dtoken5);
	tokenBag.at("Diamonds").push_back(dtoken5);
	Token dtoken7(7,diamond);
	tokenBag.at("Diamonds").push_back(dtoken7);
	tokenBag.at("Diamonds").push_back(dtoken7);
 
	//bonus3 1,1,2,2,3,3
	string b3 = "3cardBonus";
	Token btoken3(3,b3);
	tokenBag.at("3cardBonus").push_back(btoken3);
	tokenBag.at("3cardBonus").push_back(btoken3);
	Token btoken2(2,b3);
	tokenBag.at("3cardBonus").push_back(btoken2);
	tokenBag.at("3cardBonus").push_back(btoken2);
	Token btoken1(1,b3);
	tokenBag.at("3cardBonus").push_back(btoken1);
	tokenBag.at("3cardBonus").push_back(btoken1);
	// Shuffle bonus3 tokens
	std::random_shuffle ( tokenBag.at("3cardBonus").begin(), tokenBag.at("3cardBonus").end() );
	
	//bonus4 6,6,5,5,4,4
	string b4 = "4cardBonus";
	Token btoken4(4,b4);
	tokenBag.at("4cardBonus").push_back(btoken4);
	tokenBag.at("4cardBonus").push_back(btoken4);
	Token btoken5(5,b4);
	tokenBag.at("4cardBonus").push_back(btoken5);
	tokenBag.at("4cardBonus").push_back(btoken5);
	Token btoken6(6,b4);
	tokenBag.at("4cardBonus").push_back(btoken6);
	tokenBag.at("4cardBonus").push_back(btoken6);
	// Shuffle bonus4 tokens
	std::random_shuffle ( tokenBag.at("4cardBonus").begin(), tokenBag.at("4cardBonus").end() );
	
	//bonus5 10,10,9,9,8,8
	string b5 = "5cardBonus";
	Token btoken8(8,b5);
	tokenBag.at("5cardBonus").push_back(btoken8);
	tokenBag.at("5cardBonus").push_back(btoken8);
	Token btoken9(9,b5);
	tokenBag.at("5cardBonus").push_back(btoken9);
	tokenBag.at("5cardBonus").push_back(btoken9);
	Token btoken10(10,b5);
	tokenBag.at("5cardBonus").push_back(btoken10);
	tokenBag.at("5cardBonus").push_back(btoken10);
	// Shuffle bonus5 tokens
	std::random_shuffle ( tokenBag.at("5cardBonus").begin(), tokenBag.at("5cardBonus").end() );
 }
 */
 
void Game::createDeck(){ //include all 55 cards in deck container
    // Line below assures randomization of each shuffle per round/game
    //std::srand ( unsigned ( std::time(0) ) );

	//create 9 leather cards
	for (int i=0;i<9;i++){
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
	for (int i=0;i<11;i++){
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

/*
// Asks users if they want to play 2-Player of Human vs. AI
bool Game::initPlayers(std::string name1, std::string name2) {
    // 1 == Human vs. Human
    // 2 == Human vs. AI
    // Then prompt for both player's names (MUST name AI Player as well)
    if (getCurrentUserInput() == 1) {
        Player pl1(name1);
        Player pl2(name2);
        p1 = &pl1;
        p2 = &pl2;
		//isAi = false;
        return true;
    } else if (getCurrentUserInput() == 2) {
        *p1 = Player(name1);
        // *p3 = AIPlayer();	// Default constructor for AIPlayer
		//this->isAi = true;
        return false;
    } else return false;
}
*/

