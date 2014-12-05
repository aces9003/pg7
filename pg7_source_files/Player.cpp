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

// MUTATORS
// Takes 1 card from Deck
bool Player::take( Game * g, int marketInd)
{
    // run isValidHand to make sure player's hand.size() <= 7
    if (isValidHand()) {
        // adds card to this->myHand from Marketplace (call's hand's addCard() method)
        myHand().addCard(g.market().getCard(marketInd));
        // replaces card that was taken from Marketplace (calls "market's replace" AKA market().replaceCard())
        g.market().replaceCard(marketInd, g.deck.back());
        // Delete card from deck
        g.deck.pop_back();
        
        return true;
    } else return false;
    // UI: Print "Your hand is full. Press any key to return to the previous menu..."
}


bool Player::takeCamels(Game * g)
{
    int camelsInMarket = 0;
    // Iterature through g.market and find all camels
    for (int i = 0; i < 5; i++) {
        if (g.market().getCard(i).getType() == "Camels") {
            camelsInMarket++;
            myHerd().addCard(g.market()getCard(i));	///puts camel in herd
            g.market().replaceCard(i, g.deck.back()); //replace card in market
            g.deck.pop_back();	//delete new market card from deck
        }
    }
    
    if (camelsInMarket > 0) {
        return true;
    } else return false;
}

/*
bool Player::trade(Game g)
{
    
    //ALEX DO THIS
    
}*/

//add points to player depending on token achieved
void Player::addPoint( Token * t()){
    int addPt=t->getPoint();
    this->points+=addPt;
}

////DO THIS
// Player has access to Game (they are friends :-) )

//functions to take specific items
bool Player::sellOne(Game * g, int handInd)
{
    // run isValidSaleOfOne to make sure player can sell this card
    if (isValidSaleOfOne(handInd)) {
        
        Token * myToken;
        
        std::string type = myHand().at(handInd).getType();
        if(type=="Cloth"){
            myToken= &g.clothT.back();
            this->addPoint(myToken);
            g.clothT.pop_back();
            return true;
        }
        else if(type=="Leather"){
            myToken= &g.leatherT.back();
            this->addPoint(myToken);
            g.leatherT.pop_back();
            return true;
        }
        else if(type=="Spice"){
            myToken=&g.spiceT.back();
            this->addPoint(myToken);
            g.spiceT.pop_back();
            return true;
        }
        else {std::cout<<"Error selling card"<<std::endl; return false;}
        
        //ERASE CARD FROM HAND
        this->myHand().erase(myHand().begin()+handInd);
    }
    else{
        std::cout<<"Sell One Not valid"<<std::endl;
        return false;
    }
    return false;
}

//make sure more than one card of same type in hand
//make sure more than one card in IndforSelling vector
bool Player::isValidSaleOfMult( Game * g, string tp)
{
    int inHand=0;
    if(g.handIndicesForSelling.size()<2){return false;}
    
    for(int i=0; i<this->myHand().size(); i++){
        if(this->myHand().at(i).getType().compare(tp)==0){
            inHand++;
        }
    }
    if(inHand<2){
        std::cout<<"Error: No multimple cards of type "<<tp<<std::endl;
        return false;
    }
    return true;
}

void Player::sellMult( Game * g//need isValidSaleOfMult();
{
    int numSold=0;
    int firstInd=g.handIndicesForSelling.at(1);
    string tp=this->myHand().at(firstInd).getType();
    int hdInd=0;
    
    //goes through vector of indices to sell
    for(int i=0; i<g.handIndicesForSelling.size(); i++)
    {
        hdInd=g.handIndicesForSelling.at(i);
        //makes sure all indices correspond to same type of card
        if(tp!=this->myHand().at(hdInd).getType()){
            std::cerr<<"Cannot sell cards of different types"<<std::endl;
        }
    }
        //make sure more than one card of same type in hand
        //make sure more than one card in IndforSelling vector
    if(isValidSaleOfMult(g,tp)){
        Token * bToken;
        ///award bonus tokens
        int numSelling=(int)g.handIndicesForSelling.size();
        if(numSelling==3){	//run out of bonus tokens???
            bToken=&g.bonus3.back();
            this->addPoint(bToken);
            g.bonus3.pop_back();
            //RUN OUT OF TOKENS????
        }
        else if(numSelling==4){
            bToken=&g.bonus4.back();
            this->addPoint(bToken);
            g.bonus4.pop_back();
            //RUN OUT OF TOKENS????
        }
        else if(numSelling==5){
            bToken=&g.bonus5.back();
            this->addPoint(bToken);
            g.bonus5.pop_back();
            //RUN OUT OF TOKENS????
        }
        int howMany=(int)g.handIndicesForSelling.size();
        //if tp is not special card
        if(tp.compare("Cloth")==0 || tp.compare("Leather")==0 ||tp.compare("Spice")==0)
        {
            //goes through vector of indices to sell
            for(int i=0; i<g.handIndicesForSelling.size(); i++)
            {
                int hdInd=g.handIndicesForSelling.at(i);
                //sells cards at given indices
                if(numSold<howMany){
                    sellOne(g, hdInd);
                    numSold++;
                    //need to change vector of ind bc cards shifted
                    for(int j=(i+1); j<g.handIndicesForSelling.size(); j++){
                        int afterhdInd= g.handIndicesForSelling.at(j);
                        g.handIndicesForSelling.at(j)=(afterhdInd--);
                    }
                
                }
                else{break;}
            }
        }
    
    //if tp is special card
    else{
        Token * sToken;
        //goes through vector of indices to sell
        for(int i=0; i<g.handIndicesForSelling.size(); i++)
        {
            int hdInd=g.handIndicesForSelling.at(i);
            //sells cards at given indices
            if(numSold<howMany){
                //sellOne(hdInd);
                /*myToken=&g.spiceT.back();
                 this.addPoint(myToken);
                 g.spiceT.pop_back();*/
                if(tp.compare("Diamonds")==0){
                    //get points from corresponding token
                    sToken=&g.diamondT.back();
                    this->addPoint(sToken);
                    //delete from hand
                    this->myHand().erase(myHand().begin()+hdInd);
                    //delete token
                    g.diamondT.pop_back();
                }
                else if(tp.compare("Gold")==0){
                    //get points from corresponding token
                    sToken=&g.goldT.back();
                    this->addPoint(sToken);
                    //delete from hand
                    this->myHand().erase(myHand().begin()+hdInd);
                    //delete token
                    g.goldT.pop_back();
                }
                else if(tp.compare("Silver")==0){
                    //get points from corresponding token
                    sToken=&g.silverT.back();
                    this->addPoint(sToken);
                    //delete from hand
                    this->myHand().erase(myHand().begin()+hdInd);
                    //delete token
                    g.silverT.pop_back();
                }
                
                numSold++;
                //need to change vector of ind bc cards shifted
                for(int j=(i+1); j<g.handIndicesForSelling.size(); j++){
                    int afterhdInd= g.handIndicesForSelling.at(j);
                    g.handIndicesForSelling.at(j)=(afterhdInd--);
                }
                
            }
            else{break;}
        }
        
    }
}
}
