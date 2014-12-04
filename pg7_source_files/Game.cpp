//Game.cpp

#include "Game.h"
#include <string>

void Game::setupTokens(){
	//create and populate vectors
	//leather 4,3,2,1,1,1,1,1,1
	string leather = "Leather";
	Token ltoken4(4,leather);
	leatherT.push_back(ltoken4);
	Token ltoken3(3,leather);
	leatherT.push_back(ltoken3);
	Token ltoken2(2,leather);
	leatherT.push_back(ltoken2);
	for (int i=0;i<6;i++){
		Token token(1,leather);
		leatherT.push_back(token);
	}
	//cloth 5,3,3,2,2,1,1
	string cloth = "Cloth";
	Token ctoken5(5,cloth);
	clothT.push_back(ctoken5);
	Token ctoken3(3,cloth);
	clothT.push_back(ctoken3);
	clothT.push_back(ctoken3);
	Token ctoken2(2,cloth);
	clothT.push_back(ctoken2);
	clothT.push_back(ctoken2);
	Token ctoken(1,cloth);
	clothT.push_back(ctoken);
	clothT.push_back(ctoken);
	//spice 5,3,3,2,2,1,1
	string spice = "Spice";
	Token stoken5(5,spice);
	spiceT.push_back(stoken5);
	Token stoken3(3,spice);
	spiceT.push_back(stoken3);
	spiceT.push_back(stoken3);
	Token stoken2(2,spice);
	spiceT.push_back(stoken2);
	spiceT.push_back(stoken2);
	Token stoken(1,spice);
	spiceT.push_back(stoken);
	spiceT.push_back(stoken);
	//silver 5,5,5,5,5
	for (int i=0;i<5;i++){
		string s = "Silver";
		Token token(5,s);
		silverT.push_back(token);
	}
	//gold 6,6,5,5,5
	for (int i=0;i<2;i++){
		string s = "Gold";
		Token token(6,s);
		silverT.push_back(token);
	}
	for (int i=0;i<3;i++){
		string s = "Gold";
		Token token(5,s);
		silverT.push_back(token);
	}
	//diamond 7,7,5,5,5
	string diamond = "Diamonds";
	Token dtoken7(7,diamond);
	diamondT.push_back(dtoken7);
	diamondT.push_back(dtoken7);
	Token dtoken5(5,diamond);
	diamondT.push_back(dtoken5);
	diamondT.push_back(dtoken5);
	diamondT.push_back(dtoken5);
	//bonus3 3,3,2,2,1,1
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
}

void Game::createDeck(){ //include all 55 cards in deck container
	// test
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


