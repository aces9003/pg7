/*
 
 Card class
 for all cards (camel, silver, etc)
 holds type of card in string
 
 */

#ifndef pg7_Cards_h
#define pg7_Cards_h

#include <string>
using std::string;

class Card{
private:
    string type;
    
public:
    Card(){
        type="Uninitialized Card";
    }
    const string & getType(){return this->type;}
    
    void setType(string s){
        type=s;
    }
    
    ~Card();
};

#endif
