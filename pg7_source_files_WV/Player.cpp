//
//  Player.cpp
//
//EMILY NEEDS TO FINISH THIS
//  Created by Alex Sharata on 12/3/14.
//
//

#include "Player.h"
#include "Token.h"
#include "Card.h"
#include <stdio.h>
#include <vector>
#include <string>
#include <stdexcept> // ********** EXCEPTION HANDLING **********

using std::string;
using std::vector;

// CONSTRUCTORS
// Default constructor - if called, creates 'generic' player
Player:: Player() : name("PlayerX"), points(0), seals(0), hasCamelToken(false) {}

// Alternate constructor - SHOULD be used preferably when first initializing Player objects
Player:: Player(std::string name) {
    this->name = name;  // Get this from user input
    this->points = 0;
    this->seals = 0;
    this->hasCamelToken = false;
}

//Destructor
Player::~Player()
{
    //std::cout<<"Deleting Player "<<this->getName()<<std::endl;
}

// MUTATORS
// Takes 1 card from Deck
//NEED market and deck
bool Player::take( vector<Card> *market, vector<Card> *deck, int marketInd)
{
    // run isValidHand to make sure player's hand.size() <= 7
    if (isValidHand() && market->at(marketInd).getType() != "Camels") {
        // adds card to this->myHand from Marketplace (call's hand's addCard() method)
        //myHand.addCard(g.market().getCard(marketInd));
        this->myHand.push_back(market->at(marketInd));
        // replaces card that was taken from Marketplace (calls "market's replace" AKA market().replaceCard())
        //g.market().replaceCard(marketInd, g.deck.back());
        market->erase(market->begin()+marketInd);
        market->push_back(deck->back());
        // Delete card from deck
        deck->pop_back();
        
        return true;
    } else return false;
    // UI: Print "Your hand is full. Press any key to return to the previous menu..."
}

//NEED market deck
bool Player::takeCamels(vector<Card> *market, vector<Card> *deck)
{
    int camelsInMarket = 0;
    // Iterature through g.market and find all camels
    for (int i = 0; i < (int) market->size(); i++) {
        /*if (g.market().getCard(i).getType() == "Camels") {
         camelsInMarket++;
         myHerd().addCard(g.market()getCard(i));	///puts camel in herd
         g.market().replaceCard(i, g.deck.back()); //replace card in market
         g.deck.pop_back();	//delete new market card from deck
         }*/
        //if (market->at(i).getType() == "Camels") {
        // FOR TESTING ONLY
        if (market->at(i).getType() == "Camels") {
            camelsInMarket++;
            this->myHerd.push_back(market->at(i));
            market->erase(market->begin()+i);
            market->push_back(deck->back());
            deck->pop_back();
            i--;
        }
    }
    
    if (camelsInMarket > 0) {
        return true;
    } else return false;
}

bool Player::trade(vector<int> *marketIndicesForTrading, vector<int> *handIndicesForTrading, vector<Card>* market)
{
    //make sure size of vectors are the same
    if(marketIndicesForTrading->size()!=handIndicesForTrading->size()){
        return false;
    }
    
    vector<string> marketTypes;
	vector<string> handTypes;
    int ind;
    //fill marketTypes and handTypes
    for(int i=0; i<(int)marketIndicesForTrading->size(); i++)
    {
        ind=marketIndicesForTrading->at(i);
        marketTypes.push_back(market->at(ind).getType());
    }
    for(int x=0; x<(int)handIndicesForTrading->size(); x++)
    {
        ind=handIndicesForTrading->at(x);
        handTypes.push_back(myHand.at(ind).getType());
    }
    
    //make sure not trading same type of card
    string type;
    for (int j=0; j< (int) marketTypes.size(); j++) {
        type= marketTypes.at(j);
        //goes through vector of indices to sell
        for(int k=0; k<(int)handTypes.size(); k++)
        {
            if(type==handTypes.at(k)){
                std::cerr<<"Cannot trade cards of same type"<<std::endl;
                return false;
            }
        }
    }
    
    //swap cards
    for (int z=0; z < (int) marketIndicesForTrading->size(); z++) {
        Card * temp;
        Card moveToHand=market->at(marketIndicesForTrading->at(z));
        temp=&myHand.at(handIndicesForTrading->at(z));
        myHand.at(handIndicesForTrading->at(z))=moveToHand;
        market->at(marketIndicesForTrading->at(z))=*temp;
    }
	
    return true;
}

//add points to player depending on token achieved
void Player::addPoint(Token t){
    int addPt=t.getPoint();
    this->points+=addPt;
}

////DO THIS
// Player has access to Game (they are friends :-) )

//functions to take specific items
//NEED clothT   leatherT    spiceT
bool Player::sellOne(vector<Token> *clothT, vector<Token> *leatherT, vector<Token> *spiceT, int handInd)
{
    // run isValidSaleOfOne to make sure player can sell this card
    if (isValidSaleOfOne(handInd)) {
        
        Token myToken;
        
        std::string type = myHand.at(handInd).getType();
        if(type=="Cloth"){
            myToken = clothT->back();
            this->addPoint(myToken);
            clothT->pop_back();
            return true;
        }
        else if(type=="Leather"){
            myToken= leatherT->back();
            this->addPoint(myToken);
            leatherT->pop_back();
            return true;
        }
        else if(type=="Spice"){
            myToken=spiceT->back();
            this->addPoint(myToken);
            spiceT->pop_back();
            return true;
        }
        else {std::cout<<"Error selling card"<<std::endl; return false;}
        
    }
    
    //ERASE CARD FROM HAND
    this->myHand.pop_back();
    return false;
}

//make sure more than one card of same type in hand
//make sure more than one card in IndforSelling vector
//NEED handIndicesForSelling
bool Player::isValidSaleOfMult( vector<int> *handIndicesForSelling, string tp)
{
    int inHand=0;
    if(handIndicesForSelling->size()<2){return false;}
    
    for(int i=0; i<(int)this->myHand.size(); i++){
        if(this->myHand.at(i).getType().compare(tp)==0){
            inHand++;
        }
    }
    if(inHand<2){
        std::cout<<"Error: No multimple cards of type "<<tp<<std::endl;
        return false;
    }
    return true;
}

//NEED handIndicesForSelling    bonus3 bonus4 bonus5
//NEED vector<Token> clothT, vector<Token> leatherT, vector<Token> spiceT, int handInd
//NEED diamondT goldT silverT
void Player::sellMult(vector<int> *handIndicesForSelling, vector<Token> *bonus3, vector<Token> *bonus4, vector<Token> *bonus5, vector<Token> *clothT, vector<Token> *leatherT, vector<Token> *spiceT, vector<Token> *diamondT, vector<Token> *goldT, vector<Token> *silverT) //need isValidSaleOfMult();
{
    int numSold=0;
    int firstInd=handIndicesForSelling->at(1);
    string tp=this->myHand.at(firstInd).getType();
    int hdInd=0;
    
    //goes through vector of indices to sell
    for(int i=0; i<(int)handIndicesForSelling->size(); i++)
    {
        hdInd=handIndicesForSelling->at(i);
        //makes sure all indices correspond to same type of card
        if(tp!=this->myHand.at(hdInd).getType()){
            std::cerr<<"Cannot sell cards of different types"<<std::endl;
        }
    }
    //make sure more than one card of same type in hand
    //make sure more than one card in IndforSelling vector
    if(isValidSaleOfMult(handIndicesForSelling,tp)){
        Token bToken;
        ///award bonus tokens
        int numSelling=(int)handIndicesForSelling->size();
        if(numSelling==3){	//run out of bonus tokens???
            try {
                bToken=bonus3->back();
                this->addPoint(bToken);
                bonus3->pop_back();
                //RUN OUT OF TOKENS????
            } catch (std::exception & e)
            { std::cout << "Sorry no more bonus 3 tokens for you :-(" << std::endl; }
        }
        else if(numSelling==4){
            try {
                bToken=bonus4->back();
                this->addPoint(bToken);
                bonus4->pop_back();
                //RUN OUT OF TOKENS????
            } catch (std::exception & e)
            { std::cout << "Sorry no more bonus 4 tokens for you :-(" << std::endl; }
        }
        else if(numSelling==5){
            try {
                bToken=bonus5->back();
                this->addPoint(bToken);
                bonus5->pop_back();
                //RUN OUT OF TOKENS????
            } catch (std::exception & e)
            { std::cout << "Sorry no more bonus 5 tokens for you :-(" << std::endl; }
        }
        int howMany=(int)handIndicesForSelling->size();
        
        //if tp is not special card
        if(tp.compare("Cloth")==0 || tp.compare("Leather")==0 ||tp.compare("Spice")==0)
        {
            //goes through vector of indices to sell
            for(int i=0; i<(int)handIndicesForSelling->size(); i++)
            {
                int hdInd=handIndicesForSelling->at(i);
                //sells cards at given indices
                if(numSold<howMany){
                    //vector<Token> clothT, vector<Token> leatherT, vector<Token> spiceT, int handInd
                    sellOne(clothT, leatherT, spiceT, hdInd);
                    numSold++;
                    //need to change vector of ind bc cards shifted
                    for(int j=(i+1); j<(int)handIndicesForSelling->size(); j++){
                        int afterhdInd= handIndicesForSelling->at(j);
                        handIndicesForSelling->at(j)=(afterhdInd--);
                    }
                    
                }
                else{break;}
            }
        }
        
        //if tp is special card
        else{
            Token sToken;
            //goes through vector of indices to sell
            for(int i=0; i<(int)handIndicesForSelling->size(); i++)
            {
                int hdInd=handIndicesForSelling->at(i);
                //sells cards at given indices
                if(numSold<howMany){
                    //sellOne(hdInd);
                    /*myToken=&g.spiceT.back();
                     this.addPoint(myToken);
                     g.spiceT.pop_back();*/
                    if(tp.compare("Diamonds")==0){
                        //get points from corresponding token
                        sToken=diamondT->back();
                        this->addPoint(sToken);
                        //delete from hand
                        this->myHand.erase(myHand.begin()+hdInd);
                        //delete token
                        diamondT->pop_back();
                    }
                    else if(tp.compare("Gold")==0){
                        //get points from corresponding token
                        sToken=goldT->back();
                        this->addPoint(sToken);
                        //delete from hand
                        this->myHand.erase(myHand.begin()+hdInd);
                        //delete token
                        goldT->pop_back();
                    }
                    else if(tp.compare("Silver")==0){
                        //get points from corresponding token
                        sToken=silverT->back();
                        this->addPoint(sToken);
                        //delete from hand
                        this->myHand.erase(myHand.begin()+hdInd);
                        //delete token
                        silverT->pop_back();
                    }
                    
                    numSold++;
                    //need to change vector of ind bc cards shifted
                    for(int j=(i+1); j<(int)handIndicesForSelling->size(); j++){
                        int afterhdInd= handIndicesForSelling->at(j);
                        handIndicesForSelling->at(j)=(afterhdInd--);
                    }
                    
                }
                else{break;}
            }
            
        }
    }
}
