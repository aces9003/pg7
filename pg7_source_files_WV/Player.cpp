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
#include <assert.h> // FOR TESTING
#include <algorithm>


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
	this->isActive = false;
    this->isAI = false;
}

/*
//Destructor
Player::~Player()
{
    //std::cout<<"Deleting Player "<<this->getName()<<std::endl;
}
 */

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
    } else if (market->at(marketInd).getType() == "Camels") {
        takeCamels(market, deck);
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


// NEW Player::trade()
bool Player::trade(vector<Card> *market, vector<int> *marketIndicesForTrading, vector<int> *playerIndicesForTrading)
{
    populateTradingCards();

    int camelTradeCount = 0;
    // Before prompting for hand indices, check to see if player can even trade cards for amount he/she wants
    
    // ASSERT
    //assert(marketIndicesForTrading->size() <= tradingCards.size());
    //assert(marketIndicesForTrading->size() > 1);
    // =====
    
    if ((marketIndicesForTrading->size() <= tradingCards.size()) && (marketIndicesForTrading->size() > 1))
    {
        // ==== DONE ON FRONT-END before message call to trade(); ====
        // Prompt for indices from tradingCards the player wants to trade
        // Store user input in playerIndicesForTrading
        // Input should be one line with indices spaced out, ENTER to submit indices
        
        // TODO
        // - sort trading vectors greatest to lowest
        // - reorder for loops (if necessary)
        
        // ASSERT
        //assert(marketIndicesForTrading->size() == playerIndicesForTrading->size());
        
        if ((marketIndicesForTrading->size() == playerIndicesForTrading->size()))
        {
            // check to see if trade is valid
            // use Card's overloaded == operator to compare card types
            for (int i = 0; i < (int) marketIndicesForTrading->size(); i++)
            {
                for (int j = 0; j < (int) playerIndicesForTrading->size(); j++)
                {
                    // checks to make sure no cards being traded are of the same type
                    // OR that no camels are trying to be taken out of the market
                    // Operation below uses overload == operator for Card type
                    
                    //tempMarketInd = marketIndicesForTrading->at(i);
                    //tempPlayerInd = playerIndicesForTrading->at(j);
                    
                    //std::cout << "tempMarketInd: " << tempMarketInd << " tempPlayerInd: " << tempPlayerInd << std::endl;
                    
                    // ASSERT
                    //assert(market->at(tempMarketInd).getType() != tradingCards.at(tempPlayerInd).getType());
                    
                    //assert(market->at(marketIndicesForTrading->at(i)).getType() != tradingCards.at(playerIndicesForTrading->at(j)).getType());
                    
                    //assert(market->at(marketIndicesForTrading->at(i)).getType() != "Camels");
                    //=====
                    
                    if ((market->at(marketIndicesForTrading->at(i)) == tradingCards.at(playerIndicesForTrading->at(j)))
                        || (market->at(marketIndicesForTrading->at(i)).getType() == "Camels"))
                    {
                        return false;
                        // -- UI --
                        // #Error message#
                        // Press any key to return to previous menu
                    }
                }
                
                // ASSERT
                //assert(tradingCards.at(playerIndicesForTrading->at(i)).getType() == "Camels");
                
                
                // check to see if any camels are being traded from tradingCards
                if ((tradingCards.at(playerIndicesForTrading->at(i)).getType() == "Camels")
                    || (playerIndicesForTrading->at(i) > (int)(myHand.size()-1)))
                    camelTradeCount++;
            }
            
            // SORT TRADING VECTORS
            std::sort(marketIndicesForTrading->begin(), marketIndicesForTrading->end(), std::greater<int>());
            std::sort(playerIndicesForTrading->begin(), playerIndicesForTrading->end(), std::greater<int>());
            
            // Add cards to market from myHand/myHerd
            //_______________________________________
            
            // First go through playerIndicesForTrading and delete indices for camel cards while adding
            // the appropriate amount of camels to the market from myHerd
            
            // TESTING
            //std::cout << "playerIndicesFT size(): " << (int)playerIndicesForTrading->size() << std::endl;
            
            //for (int i = 0; i < (int) marketIndicesForTrading->size(); i++)
            for (int i = (int) playerIndicesForTrading->size() - 1; i >= 0; i--)
            {
                // TESTING
                //std::cout << "Last hand index: " << myHand.size()-1 << std::endl;
                //std::cout << "playerIndicesForTrading.at(i): " << playerIndicesForTrading->at(i) << std::endl;
                
                if (playerIndicesForTrading->at(i) > (int) (myHand.size()-1))
                {
                    // delete the int in playerIndicesForTrading->at(i)
                    // NEEDS PROPER CODE - might need to fix this
                    playerIndicesForTrading->erase(playerIndicesForTrading->begin() + i);
                    //i--;
                    
                    // add camel cards to market from myHerd
                    market->push_back(myHerd.back());
                    
                    // delete a camel from myHerd
                    myHerd.pop_back();
                }
            }
            
            // Add cards from myHand to market then delete those cards from myHand
            for (int i = 0; i < (int) playerIndicesForTrading->size(); i++)
            {
                market->push_back(myHand.at(playerIndicesForTrading->at(i)));
                // MIGHT NEED TO FIX THIS:
                myHand.erase(myHand.begin() + (playerIndicesForTrading->at(i)));
            }
            
            // Add cards from market to myHand then delete cards from market
            for (int i = 0; i < (int) marketIndicesForTrading->size(); i++)
            {
                if (market->at(marketIndicesForTrading->at(i)).getType() != "Camels")
                {
                    // add card to myHand and delete from market
                    myHand.push_back(market->at(marketIndicesForTrading->at(i)));
                    
                    // deleting...
                    // WRITE CODE TO: delete card at market->at(i)
                    market->erase(market->begin() + (marketIndicesForTrading->at(i)));
                } /*else	// add card to myHerd and delete from market --> CORRECTION: Camels CANNOT be traded from market-to-player
                   {
                   // SHOULD NOT TAKE CAMELS OUT OF MARKET, but since transaction is underway, just continue with it...
                   myHerd.push_back(market->at(marketIndicesForTrading->at(i)));
                   
                   // deleting...
                   // WRITE CODE TO: delete card at market->at(i)
                   market->erase(market->begin() + (marketIndicesForTrading->at(i)));
                   }*/
            }
            
            // Clear all trading related vectors
            tradingCards.clear();
            playerIndicesForTrading->clear();
            marketIndicesForTrading->clear();
            
            return true;
        } else
        {
            return false;
            // -- UI --
            // #Error message#
            // Press any key to return to previous/main menu
        }
        
    } else
    {
        return false;
        // -- UI --
        // #Error message#
        // Press any key to return to previous/main menu
    }
    
    return false;
}

//add points to player depending on token achieved
void Player::addPoint(Token t){
    int addPt=t.getPoint();
    this->points+=addPt;
}

// Creates tradingCards vector which is a concatenation of myHand + myHerd 
void Player::populateTradingCards()
{
	// clear tradingCards for good practice
	this->tradingCards.clear();
	
	// concatenate myHand first then myHerd
	this->tradingCards.insert(tradingCards.end(), myHand.begin(), myHand.end());
	this->tradingCards.insert(tradingCards.end(), myHerd.begin(), myHerd.end());
}

// Player has access to Game (they are friends :-) )
//functions to take specific items
// using tokenBag which had following vectors
// clothT   leatherT    spiceT
bool Player::sellOne(map<string,vector<Token>*> *tokenBag, int handInd)
{
    // run isValidSaleOfOne to make sure player can sell this card
    if (isValidSaleOfOne(handInd)) {
        
        Token myToken;
        
        std::string type = myHand.at(handInd).getType();
        if(type=="Cloth"){
            myToken = tokenBag->at("Cloth")->back();
            //myToken.printToken();
            addPoint(myToken);
            tokenBag->at("Cloth")->pop_back();
            myHand.erase(myHand.begin()+handInd);
            return true;
        }
        else if(type=="Leather"){
            myToken= tokenBag->at("Leather")->back();
            //myToken.printToken();
            addPoint(myToken);
            tokenBag->at("Leather")->pop_back();
            myHand.erase(myHand.begin()+handInd);
            return true;
        }
        else if(type=="Spice"){
            myToken= tokenBag->at("Spice")->back();
            //myToken.printToken();
            addPoint(myToken);
            tokenBag->at("Spice")->pop_back();
            myHand.erase(myHand.begin()+handInd);
            return true;
        }
        else {
            //std::cout<<"Error selling card"<<std::endl;
            return false;
        }
        
    }
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
        std::cout<<"Error: No multiple cards of type "<<tp<<std::endl;
        return false;
    }
    return true;
}

//using tokenBag which contains the following vectors identified by strings
// handIndicesForSelling    bonus3 bonus4 bonus5
// vector<Token> clothT, vector<Token> leatherT, vector<Token> spiceT, int handInd
// diamondT goldT silverT
bool Player::sellMult(vector<int> *handIndicesForSelling, map<string,vector<Token>*> *tokenBag ) //need isValidSaleOfMult();
{
    std::sort(handIndicesForSelling->begin(), handIndicesForSelling->end(), std::greater<int>());
    
    int numSold=0;
    int lastInd=handIndicesForSelling->at(0);
    string tp=myHand.at(lastInd).getType();
    int hdInd=0;
    
    
    //goes through vector of indices to sell
    for(int i=0; i<(int)handIndicesForSelling->size(); i++)
    {
        hdInd=handIndicesForSelling->at(i);
        //makes sure all indices correspond to same type of card
        if(tp.compare(myHand.at(hdInd).getType())!=0){
            std::cout<<"Cannot sell cards of different types"<<std::endl;
            // -- UI --
            // #Error message#
            // Press any key to return to previous/main menu
            return false;
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
                bToken=tokenBag->at("bonus3")->back();
                addPoint(bToken);
                tokenBag->at("bonus3")->pop_back();
                //RUN OUT OF TOKENS????
            } catch (std::exception & e)
            { std::cout << "Sorry no more bonus 3 tokens for you :-(" << std::endl; }
        }
        else if(numSelling==4){
            try {
                bToken=tokenBag->at("bonus4")->back();
                addPoint(bToken);
                tokenBag->at("bonus4")->pop_back();
                //RUN OUT OF TOKENS????
            } catch (std::exception & e)
            { std::cout << "Sorry no more bonus 4 tokens for you :-(" << std::endl; }
        }
        else if(numSelling==5){
            try {
                bToken=tokenBag->at("bonus5")->back();
                addPoint(bToken);
                tokenBag->at("bonus5")->pop_back();
                //RUN OUT OF TOKENS????
            } catch (std::exception & e)
            { std::cout << "Sorry no more bonus 5 tokens for you :-(" << std::endl; }
        }
        //int howMany=(int)handIndicesForSelling->size();
        
        //if tp is not special card
        if(tp.compare("Cloth")==0 || tp.compare("Leather")==0 ||tp.compare("Spice")==0)
        {
            //goes through vector of indices to sell
            for(int i=0; i<(int)handIndicesForSelling->size(); i++)
            {
                hdInd=handIndicesForSelling->at(i);
                //sells cards at given indices
                if(numSold<numSelling){
                    //vector<Token> clothT, vector<Token> leatherT, vector<Token> spiceT, int handInd
                    sellOne(tokenBag, hdInd); ////////////this might be wrong input param for tokenBag ////////////////////
                    numSold++;
                }
                else{return true;}
            }
            if(numSold==numSelling){
                
                return true;
            }
            else{
                std::cout<<"THIS IS BAD changed hand and tokens but didn't sell correct number of cards from player hand"<<std::endl;
                return false;
            }
        }
        
        //if tp is special card
        else if (tp.compare("Gold")==0 || tp.compare("Silver")==0 || tp.compare("Diamonds")==0 ){
            Token sToken;
            //goes through vector of indices to sell
            for(int i=0; i<(int)handIndicesForSelling->size(); i++)
            {
                hdInd=handIndicesForSelling->at(i);
                //sells cards at given indices
                if(numSold<numSelling){
                    if(tp.compare("Diamonds")==0){
                        //get points from corresponding token
                        sToken=tokenBag->at("Diamonds")->back();
                        //std::cout<<"PRINTING TOKEN TO GET POINTS FROM";
                        //sToken.printToken();
                        addPoint(sToken);
                        //delete from hand
                        myHand.erase(myHand.begin()+hdInd);
                        //delete token
                        tokenBag->at("Diamonds")->pop_back();
                        numSold++;
                    }
                    else if(tp.compare("Gold")==0){
                        //get points from corresponding token
                        sToken=tokenBag->at("Gold")->back();
                        //std::cout<<"PRINTING TOKEN TO GET POINTS FROM";
                        //sToken.printToken();
                        addPoint(sToken);
                        //delete from hand
                        myHand.erase(myHand.begin()+hdInd);
                        //delete token
                        tokenBag->at("Gold")->pop_back();
                        numSold++;
                    }
                    else if(tp.compare("Silver")==0){
                        //get points from corresponding token
                        sToken=tokenBag->at("Silver")->back();
                        //std::cout<<"PRINTING TOKEN TO GET POINTS FROM";
                        //sToken.printToken();
                        addPoint(sToken);
                        //delete from hand
                        myHand.erase(myHand.begin()+hdInd);
                        //delete token
                        tokenBag->at("Silver")->pop_back();
                        numSold++;
                    }
                }
                else{return true;}
            }
            if(numSold==numSelling){
                
                return true;
            }
            else{
                std::cout<<"THIS IS BAD changed hand and tokens but didn't sell correct number of cards from player hand"<<std::endl;
                return false;
            }
        }
        else{
            // -- UI --
            std::cout<<"Card type invalid"<<std::endl;
            // Press any key to return to previous/main menu
        }
    }
    // -- UI --
    std::cout<<"Do not have multiple cards to sell"<<std::endl;
    // Press any key to return to previous/main menu
    return false;
}

void Player::makeTurn(vector<Card>* market, vector<Card>* deck, vector<int>* handIndicesForSelling,map<string,vector<Token>*>* tokenBag){
    int randPick = rand() % 4;
    if(randPick==0 && this->myHand.size()<7){
        //take
        int r= rand() % (int)market->size();
        take(market, deck, r);
    }
    else if(randPick==1){
        //trade
        randPick = 2; //just makes it sell one if lands on trade
        //trade(g);		//CHECK ONCE ALEX IS DONE
    }
    else if(randPick==2){
        //sell one
        int randPickHand = rand() % (int)myHand.size(); // need to seed random?
        sellOne(tokenBag,randPickHand);
    }
    else if(randPick==3){ //&& check is valid to sell mult){
        //sell multiple
        std::string sellType;
        int sellTypeNum=0;
        if (myHand.size()>1){
            for (int i=0;i<(int)myHand.size();i++){
                std::string typeTemp;
                typeTemp = myHand.at(i).getType();
                int countTemp =0;
                
                //gets all types in hand and keeps track of largest set
                for (int j=0; j<(int)myHand.size(); j++){
                    if (myHand.at(j).getType() == typeTemp){
                        countTemp++;
                    }
                }
                if (countTemp>sellTypeNum){
                    sellTypeNum = countTemp;
                    sellType = typeTemp;
                }
            }
            for (int x=0;x<(int)myHand.size();x++){
                if (myHand.at(x).getType() == sellType){
                    handIndicesForSelling->push_back(x);
                }
                if (isValidSaleOfMult(handIndicesForSelling, sellType)){
                    sellMult(handIndicesForSelling,tokenBag);
                    handIndicesForSelling->clear();
                }
            }
        }
        else{
            //switches to take if randomly lands on multi and cannot sell muli
            int r= rand() % (int)market->size();
            take(market, deck, r);
        }
    }
    else{
        for (int i=0;i<(int)myHand.size();i++){
            if (isValidSaleOfOne(i)){
                sellOne(tokenBag,i);
                break;
            }
        }
    }
}

