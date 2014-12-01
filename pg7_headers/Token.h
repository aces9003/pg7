/*
 
 Token Class
 each token has a string declaring type
 and a point value
 
 */

#ifndef pg7_Tokens_h
#define pg7_Tokens_h

#include <string>

class Token{
private:
    string type;
    int point;
    
public:
    Token(){
        type="Uninitialized Token";
        point=0;
    }
    
    void getType(){return this->type;};
    void getPt(){return this->point;};
    
    void setType(string s){type=s;}
    void setPt(int x){point=x;}
    
    void print();
    
    ~Token();
};

#endif
