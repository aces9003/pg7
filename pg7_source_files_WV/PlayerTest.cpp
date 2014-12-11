//PlayerTest.cpp
// compile with g++ -std=c++11 -pedantic -Wall -Wextra -O PlayerTest.cpp Card.cpp Token.cpp
//

#include "Player.h"
#include "Player.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

void createDeck();
void setupTokens();
void fakeDealMarket();
void printMarket();
// temp deck for testing
vector<Card> deck;
vector<Card> market;

// TOKEN vectors
vector<Token> bonus3;   //bonus tokens traded for 3 cards
vector<Token> bonus4;
vector<Token> bonus5;

vector<Token> clothT;   //cloth tokens
vector<Token> leatherT;
vector<Token> spiceT;
vector<Token> silverT;
vector<Token> goldT;
vector<Token> diamondT;

vector<int> marketIndicesForTrading;
vector<int> playerIndicesForTrading;
vector<int> handIndicesForSelling;

int main() {
    createDeck();
    setupTokens();
    fakeDealMarket();
    
    Player p1("Player1");
    Player p2("Player2");
    
    cout << endl;

    
    cout << "Leather token vector size: " << (int)leatherT.size() << endl;
    
    // Test print tokens
    for (int i = 0; i < (int)leatherT.size(); i++) {
        cout << "Leather token [" << i << "]: " << leatherT.at(i).getPoint() << endl;
    }
    
    // Print market
    printMarket();
    
    // Print first's hand
    cout << "Herd size (before): " << p1.myHerd.size() << endl;
    for (int i = 0; i < (int) p1.myHerd.size(); i++) {
        cout << p1.myHerd.at(i).getType() << endl;
    }
    
    p1.takeCamels(&market, &deck);

    cout << "_______" << endl;
    
    cout << "Herd size (after): " << p1.myHerd.size() << endl;
    for (int i = 0; i < (int) p1.myHerd.size(); i++) {
        cout << p1.myHerd.at(i).getType() << endl;
    }
    
    cout<<endl; cout<<endl;
    
    
    
    printMarket();
    
    // Take Gold
    cout << "Before taking 1 (Gold): " << endl;
    for (int i = 0; i < (int) p1.myHand.size(); i++) {
        cout << p1.myHand.at(i).getType() << endl;
    }
    
    p1.take(&market, &deck, 1);

    cout << "_______" << endl;
    
    cout << "After taking 1 (Gold): " << endl;
    for (int i = 0; i < (int) p1.myHand.size(); i++) {
        cout << p1.myHand.at(i).getType() << endl;
    }
    
    cout<<endl; cout<<endl;
    
    
    
    printMarket();
    
    // Take Silver
    cout << "Before taking 2 (Silver): " << endl;
    for (int i = 0; i < (int) p1.myHand.size(); i++) {
        cout << p1.myHand.at(i).getType() << endl;
    }
    
    p1.take(&market, &deck, 2);

    cout << "_______" << endl;
    
    cout << "After taking 2 (Silver): " << endl;
    for (int i = 0; i < (int) p1.myHand.size(); i++) {
        cout << p1.myHand.at(i).getType() << endl;
    }
    
    cout<<endl; cout<<endl;
    
    
    
    printMarket();
    
    // Take Another Silver
    cout << "Before taking 0 (Silver): " << endl;
    for (int i = 0; i < (int) p1.myHand.size(); i++) {
        cout << p1.myHand.at(i).getType() << endl;
    }
    
    p1.take(&market, &deck, 0);
    
    cout << "_______" << endl;
    
    cout << "After taking 0 (Silver): " << endl;
    for (int i = 0; i < (int) p1.myHand.size(); i++) {
        cout << p1.myHand.at(i).getType() << endl;
    }
    cout<<endl; cout<<endl;
    
    
    
    
    printMarket();
    
    /*
    // Populate trading vectors
    
    marketIndicesForTrading.push_back(0);
    marketIndicesForTrading.push_back(1);
    marketIndicesForTrading.push_back(2);
    
    playerIndicesForTrading.push_back(0);
    playerIndicesForTrading.push_back(1);
    playerIndicesForTrading.push_back(2);
    

    cout << "Before trading 0,1,2 in market for 0,1,2 in hand: " << endl;
    for (int i = 0; i < (int) p1.myHand.size(); i++) {
        cout << p1.myHand.at(i).getType() << endl;
    }
    
    p1.trade(&market, &marketIndicesForTrading, &playerIndicesForTrading);
    
    cout << "_______" << endl;
    
    cout << "After trading: " << endl;
    for (int i = 0; i < (int) p1.myHand.size(); i++) {
        cout << p1.myHand.at(i).getType() << endl;
    }
    
    cout<<endl; cout<<endl;
    
    
    
    printMarket();
     */
    
    /*
    
    marketIndicesForTrading.push_back(0);
    marketIndicesForTrading.push_back(1);
    marketIndicesForTrading.push_back(4);
    
    playerIndicesForTrading.push_back(0);
    playerIndicesForTrading.push_back(1);
    playerIndicesForTrading.push_back(2);
    
    cout << "Before trading 0,1,4 in market for 0,1,2 in hand: " << endl;
    for (int i = 0; i < (int) p1.myHand.size(); i++) {
        cout << p1.myHand.at(i).getType() << endl;
    }
    
    p1.trade(&market, &marketIndicesForTrading, &playerIndicesForTrading);
    
    cout << "_______" << endl;
    
    cout << "After trading: " << endl;
    for (int i = 0; i < (int) p1.myHand.size(); i++) {
        cout << p1.myHand.at(i).getType() << endl;
    }
    
    cout<<endl; cout<<endl;
    
    
    
    printMarket();
     
     */
    
    /*
    // TEST SELL ONE
    
     cout << "Testing p1.sellOne(): " << endl;
     
     cout << "Before selling 0 in hand: " << endl;
     for (int i = 0; i < (int) p1.myHand.size(); i++) {
     cout << p1.myHand.at(i).getType() << endl;
     }
    
    // Player points before/after
    cout << "Player point's before: " << p1.getPoints() << endl;
     
     p1.sellOne(&clothT,  &leatherT,  &spiceT,  0);
     
     cout << "_______" << endl;
     
     cout << "After selling: " << endl;
     for (int i = 0; i < (int) p1.myHand.size(); i++) {
     cout << p1.myHand.at(i).getType() << endl;
     }
    
    // Player points before/after
    cout << "Player point's before: " << p1.getPoints() << endl;
    
    // TEST SELL ONE
    
    cout << "Testing p1.sellOne(): " << endl;
    
    cout << "Before selling 0 in hand: " << endl;
    for (int i = 0; i < (int) p1.myHand.size(); i++) {
        cout << p1.myHand.at(i).getType() << endl;
    }
    
    // Player points before/after
    cout << "Player point's before: " << p1.getPoints() << endl;
    
    p1.sellOne(&clothT,  &leatherT,  &spiceT,  0);
    
    cout << "_______" << endl;
    
    cout << "After selling: " << endl;
    for (int i = 0; i < (int) p1.myHand.size(); i++) {
        cout << p1.myHand.at(i).getType() << endl;
    }
    
    // Player points before/after
    cout << "Player point's before: " << p1.getPoints() << endl;
    */
    
    
    // TEST SELL MULT
    
    //handIndicesForSelling.push_back(0);
    handIndicesForSelling.push_back(1);
    handIndicesForSelling.push_back(2);
    
    cout << "Testing p1.sellMult(): " << endl;
    
    cout << "Before selling 0,1,2 in hand: " << endl;
    for (int i = 0; i < (int) p1.myHand.size(); i++) {
        cout << p1.myHand.at(i).getType() << endl;
    }
    
    p1.sellMult(&handIndicesForSelling,  &bonus3,  &bonus4,  &bonus5,  &clothT,  &leatherT,  &spiceT,  &diamondT,  &goldT,  &silverT);
    
    cout << "_______" << endl;
    
    cout << "After selling: " << endl;
    for (int i = 0; i < (int) p1.myHand.size(); i++) {
        cout << p1.myHand.at(i).getType() << endl;
    }
    
    
}

void printMarket() {
    // Print market
    cout << "|" << market.at(0).getType() << "|"<< market.at(1).getType() << "|" << market.at(2).getType() << "|" << market.at(3).getType() << "|" << market.at(4).getType() << "|" <<endl;
}

void fakeDealMarket() {
    for (int i = 0; i < 5; i++) {
        market.push_back(deck.back());
        deck.pop_back();
    }
}


void createDeck(){ //include all 55 cards in deck container
    
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

void setupTokens(){
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
        goldT.push_back(token);
    }
    for (int i=0;i<2;i++){
        string s = "Gold";
        Token token(6,s);
        goldT.push_back(token);
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
    std::random_shuffle ( bonus3.begin(), bonus3.end() );
    
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
}
