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
    
    void setType(string s){     //sets type of token
        type=s;
    }
    void setPt(int x){     //sets point value
        point=x;
    }
    
    void print();
    
    ~Token();
};

#endif
