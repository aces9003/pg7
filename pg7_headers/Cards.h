/*
 
 Card class
 for all cards (camel, silver, etc)
 holds type of card in string
 
 */

#ifndef pg7_Cards_h
#define pg7_Cards_h

#include <string>

class Card{
private:
    string type;
    
public:
    Card(){
        type="Uninitialized Card";
    }
    void getType(){return this->type;}
    
    void setType(string s){
        type=s;
    }
    
    ~Card();
};

#endif
