/*
 AI Player class
 inheritted from Player class
 */

#include "Player.h"

#ifndef pg7_HPlayer_h
#define pg7_HPlayer_h

class AIPlayer: public Player{
    
private:
    string name;    //player name
    int points;     //records points in round
    int seals;      //records #of seals of excellence
    Hand mine= new Hand;      //creates vector from hand class;
    bool hasCamelToken;
    
public:
    Player();
    
    void getName(){return this->name;}const;
    void getPoints(){return this->points;}const;
    void getSeals(){return this->seals;} const;
    void getCamel(){return this->hasCamelToken;}const;
    
    void take();
    //functions to take specific items
    void trade(int cards);
    void take1(const Card &c);
    void takeMult(int cards);
    void takeCamel();
    void replace1(const Card &c);
    void replaceMult(int cards);
    
    void sell();
    //functions to sell specific cards
    void sell1(const Card &c);
    void sellMult(int cards);
    
    void addPoint();
    void awardCamel();
    
    virtual ~Player();      //need to deallocate hand
};
#endif
