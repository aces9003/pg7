//
//  HPlayer.h
//  pg7
//
//  Created by Emily Johnson on 11/20/14.
//  Copyright (c) 2014 Emily Johnson. All rights reserved.
//

#include "Player.h"

#ifndef pg7_HPlayer_h
#define pg7_HPlayer_h

class HPlayer: public Player{
    
private:
    string name;    //player name
    int points;     //records points in round
    int seals;      //records #of seals of excellence
    Hand mine= new Hand;      //creates vector from hand class;
    bool hasCamelToken;
    
public:
    Player()
    
    void take()=0;
    //functions to take specific items
    void trade(int cards)=0;
    void take1(const Card &c);
    void takeMult(int cards);
    void takeCamel();
    void replace1(const Card &c);
    void replaceMult(int cards);
    
    void sell()=0;
    //functions to sell specific cards
    void sell1(const Card &c);
    void sellMult(int cards);
    
    void addPoint();
    void awardCamel();
    
    ~Player();      //need to deallocate hand
};

#endif
